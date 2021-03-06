#pragma once
#include <memory>

template <class T>
class Transaction
{
private:
	std::shared_ptr<T> current;
	std::shared_ptr<T> prev;
public:
	Transaction(const std::shared_ptr<T> current);
	void begin(std::unique_ptr<T> modification);
	void commit();
	void revoke();
};

template<class T>
inline Transaction<T>::Transaction(std::shared_ptr<T> current)
{
	this->current.swap(current);
}

template<class T>
inline void Transaction<T>::begin(std::unique_ptr<T> modification)
{
	prev.swap(current);
	current = std::move(modification);
}

template<class T>
inline void Transaction<T>::commit()
{
	prev->modify(current);
	current.swap(prev);
	prev.reset();
}

template<class T>
inline void Transaction<T>::revoke()
{
	current.swap(prev);
	prev.reset();
}
