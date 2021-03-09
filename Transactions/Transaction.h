#pragma once
#include <memory>
#include "Book.h"
#include "Corrector.h"
#include "Magazine.h"
#include "NewsPaper.h"

template <class T>
class Transaction
{
private:
	std::shared_ptr<T> current;
	std::shared_ptr<T> prev;
public:
	Transaction(const std::shared_ptr<T> current);
	void begin(std::shared_ptr<T> modification);
	void commit();
	void revoke();
	void inf();
};

template<class T>
inline Transaction<T>::Transaction(std::shared_ptr<T> current)
{
	this->current.swap(current);
}

template<class T>
inline void Transaction<T>::begin(std::shared_ptr<T> modification)
{
	prev.swap(current);
	current = std::move(modification);
}

template<class T>
inline void Transaction<T>::commit()
{
	//prev->modify(current);
	current.swap(prev);
	prev.reset();
}

template<class T>
inline void Transaction<T>::revoke()
{
	current.swap(prev);
	prev.reset();
}

template<class T>
inline void Transaction<T>::inf()
{
	switch (prev->getType())
	{
	case 0: // book
		std::cout << "Previus:" << std::endl;
		((Book *)prev.get())->inf();
		std::cout << "New:" << std::endl;
		((Book *)current.get())->inf();
		break;
	case 1: // newspaper
		std::cout << "Previus:" << std::endl;
		((NewsPaper *)prev.get())->inf();
		std::cout << "New:" << std::endl;
		((NewsPaper *)current.get())->inf();
		break;
	case 2: // magazine
		std::cout << "Previus:" << std::endl;
		((Magazine *)prev.get())->inf();
		std::cout << "New:" << std::endl;
		((Magazine *)current.get())->inf();
		break;
	default:
		break;
	}
}
