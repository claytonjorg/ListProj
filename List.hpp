/*
	Name: Clayton Jorgensen
	Date: 02/12/2018

	Key:
	Source = Book Code
	Reference Source = Modified Book Code
*/

/*
	Function: const_iterator(): default zero-parameter constructor. Set pointer current to NULL (nullptr for c++ 2011).
*/
template<typename T> data::List<T>::const_iterator::const_iterator() : current{ nullptr } {}

/*
	Function: operator*(): returns a reference to the corresponding element in the list by calling retrieve() member function.
	Reference Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 98
*/
template<typename T> const T & data::List<T>::const_iterator::operator*() const
{
	return retrieve();
}

/*
	Function: operator++(): prefix increment operator.
	Reference Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 98
*/
template<typename T> typename data::List<T>::const_iterator & data::List<T>::const_iterator::operator++()
{
	current = current->next;
	return *this;
}

/*
	Function: operator++(int): postfix increment operator.
	Reference Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 98
*/
template<typename T> typename data::List<T>::const_iterator data::List<T>::const_iterator::operator++(int)
{
	auto copy = *this;
	current = current->next;
	return copy;
}

/*
	Function: operator--(): prefix decrement operator.
	Reference Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 98
*/
template<typename T> typename data::List<T>::const_iterator & data::List<T>::const_iterator::operator--()
{
	current = current->prev;
	return *this;
}

/*
	Function: operator--(int): postfix decrement operator.
	Reference Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 98
*/
template<typename T> typename data::List<T>::const_iterator data::List<T>::const_iterator::operator--(int)
{
	auto copy = *this;
	current = current->prev;
	return *this;
}

/*
	Function: operator==(): equal to operator.
*/
template<typename T> bool data::List<T>::const_iterator::operator==(const typename List<T>::const_iterator & rhs) const
{
	return current == rhs.current;
}

/*
	Function: operator!=(): not equal to operator.
*/
template<typename T> bool data::List<T>::const_iterator::operator!=(const typename List<T>::const_iterator & rhs) const
{
	return current != rhs.current;
}

/*
	Function: retrieve(): return a reference to the corresponding element in the list.
*/
template<typename T> T & data::List<T>::const_iterator::retrieve() const
{
	return current->data;
}

/*
	Function: const_iterator(Node *p): one-parameter constructor. Set pointer current to the given node pointer p.
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 98
*/
template<typename T> data::List<T>::const_iterator::const_iterator(typename List<T>::Node* p) : current{ p } {}

/*
	Function: iterator(): default zero-parameter constructor.
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 98
*/
template<typename T> data::List<T>::iterator::iterator()
{
	// Does Nothing
}

/*
	Function: operator*(): returns a reference to the corresponding element in the list by calling retrieve() member function.
	Reference Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 98
*/
template<typename T> T & data::List<T>::iterator::operator*()
{
	return this->current->data;
}

/*
	Function: operator*(): returns a reference to the corresponding element in the list by calling retrieve() member function.
	Reference Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 98
*/
template<typename T> const T & data::List<T>::iterator::operator*() const
{
	return this->retrieve();
}

/*
	Function: operator++(): prefix increment operator.
	Reference Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 98
*/
template<typename T> typename data::List<T>::iterator & data::List<T>::iterator::operator++()
{
	this->current = this->current->next;
	return *this;
}

/*
	Function: operator++(int): postfix increment operator.
	Reference Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 98
*/
template<typename T> typename data::List<T>::iterator List<T>::iterator::operator++(int)
{
	auto copy = *this;
	this->current = this->current->next;
	return copy;
}

/*
	Function: operator--(): prefix decrement operator.
	Reference Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 98
*/
template<typename T> typename data::List<T>::iterator & List<T>::iterator::operator--()
{
	this->current = this->current->prev;
	return *this;
}

/*
	Function: operator--(int): postfix decrement operator.
	Reference Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 98
*/
template<typename T> typename data::List<T>::iterator data::List<T>::iterator::operator--(int)
{
	auto copy = *this;
	this->current = this->current->prev;
	return *this;
}

/*
	Function: const_iterator(Node *p): one-parameter constructor.
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 98
*/
template<typename T> data::List<T>::iterator::iterator(typename List<T>::Node* p) : List<T>::const_iterator{ p } {}

/*
	Function: List(): Default zero-parameter constructor. Call init() to initialize list member variables.
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 99
*/
template<typename T> data::List<T>::List()
{
	init();
}

/*
	Function: ~List(): destructor. You should properly reclaim memory (used by head and tail nodes).
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 99
*/
template<typename T> data::List<T>::~List()
{
	clear();
	delete head;
	delete tail;
}

/*
	Function: List(const List &rhs): Copy constructor. Create the new list using elements in existing list rhs.
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 99
*/
template<typename T> data::List<T>::List(const List<T> & rhs)
{
	init();
	for (auto itr = rhs.begin(); itr != rhs.end(); ++itr)
	{
		push_back(*itr);
	}
}

/*
	Function: List(List &&rhs): move constructor.
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 99
*/
template<typename T> data::List<T>::List(List<T> && rhs) : theSize(rhs.theSize), head{ rhs.head }, tail{ rhs.tail }
{
	rhs.theSize = 0;
	rhs.head = nullptr;
	rhs.tail = nullptr;
}

/*
	Function: operator=(List &rhs): copy assignment operator
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 99
*/
template<typename T> const data::List<T> & data::List<T>::operator=(const List<T> & rhs)
{
	auto copy = rhs;
	std::swap(*this, copy);
	return *this;
}
/*
	Function: operator=(List &&rhs) : move assignment operator
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 99
*/
template<typename T> data::List<T> & data::List<T>::operator=(List<T> && rhs)
{
	std::swap(theSize, rhs.theSize);
	std::swap(head, rhs.head);
	std::swap(tail, rhs.tail);

	return *this;
}

/*
	Function: List(int num, const T & val = T()): Construct a list with num elements, all initialized with value val.
*/
template<typename T> data::List<T>::List(int num, const T & val)
{
	init();
	for (int i = 0; i < num; i++)
	{
		push_back(val);
	}
}

/*
	Function: List(const_iterator start, const_iterator end): construct a List with elements from another list between start and end. Including the element referred to by the start iterator, but not the end iterator, that is [start, end).
*/
template<typename T> data::List<T>::List(typename List<T>::const_iterator start, typename List<T>::const_iterator end)
{
	init();
	for (auto itr = start; itr != end; ++itr)
	{
		push_back(*itr);
	}
}

/*
	Function: size(): return the number of elements in the List.
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 94
*/
template<typename T> int data::List<T>::size() const
{
	return theSize;
}

/*
	Function: empty(): return true if no element is in the list; otherwise, return false.
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 94
*/
template<typename T> bool data::List<T>::empty() const
{
	return size() == 0;
}

/*
	Function: clear(): delete all the elements in the list
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 94
*/
template<typename T> void data::List<T>::clear()
{
	while (!empty())
	{
		pop_back();
	}
}

/*
	Function: reverse(): reverse the order of the elements in the list. That is, the original first element becomes the last, while the original last becomes the first.
*/
template<typename T> void data::List<T>::reverse()
{
	if (!empty())
	{
		auto current_ptr = head;
		while (current_ptr != nullptr)
		{
			std::swap(current_ptr->next, current_ptr->prev);
			current_ptr = current_ptr->prev;
		}
	}
	std::swap(head, tail);
}

/*
	Function: front(): return reference to the first element in the list.
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 95
*/
template<typename T> T & data::List<T>::front()
{
	return *begin();
}

/*
	Function: front() const: return reference to the first element in the list.
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 95
*/
template<typename T> const T & data::List<T>::front() const
{
	return *begin();
}

/*
	Function: back(): return reference to the last element in the list.
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 95
*/
template<typename T> T & data::List<T>::back()
{
	return *(--end());
}

/*
	Function: back() const: return reference to the last element in the list.
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 95
*/
template<typename T> const T & data::List<T>::back() const
{
	return *(--end());
}

/*
	Function: push_front(): insert the new object as the first element into the list.
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 95
*/
template<typename T> void data::List<T>::push_front(const T & val)
{
	insert(begin(), val);
}

/*
	Function: push_front(): insert the new object as the first element into the list.
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 95
*/
template<typename T> void data::List<T>::push_front(T && val)
{
	insert(begin(), std::move(val));
}

/*
	Function: push_back(): insert the new object as the last element into the list.
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 95
*/
template<typename T> void data::List<T>::push_back(const T & val)
{
	insert(end(), val);
}

/*
	Function: push_back(): insert the new object as the last element into the list.
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 95
*/
template<typename T> void data::List<T>::push_back(T && val)
{
	insert(end(), std::move(val));
}

/*
	Function: pop_front(): delete the first element in the list.
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 95
*/
template<typename T> void data::List<T>::pop_front()
{
	erase(begin());
}

/*
	Function: pop_back(): delete the last element in the list.
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 95
*/
template<typename T> void data::List<T>::pop_back()
{
	erase(--end());
}

/*
	Function: remove(const T & val): delete all nodes with value equal to val from the list.
*/
template<typename T> void data::List<T>::remove(const T & val)
{
	for (auto itr = begin(); itr != end(); ++itr)
	{
		if (*itr == val)
			erase(itr);
	}
}

/*
	Function: print(ostream &os, char ofc = ' '): print all elements in the list, using character ofc as the deliminator between elements in the list.
*/
template<typename T> void data::List<T>::print(std::ostream & os, char ofc) const
{
	for (auto itr = begin(); itr != end(); ++itr)
	{
		os << *itr << ofc;
	}
}

/*
	Function: begin(): return iterator to the first element in the list.
	Reference Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 94
*/
template<typename T> typename data::List<T>::iterator List<T>::begin()
{
	if (!empty())
	{
		typename List<T>::iterator itr{ head->next };
		return itr;
	}
}

/*
	Function: begin(): return const_iterator to the first element in the list.
	Reference Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 94
*/
template<typename T> typename data::List<T>::const_iterator List<T>::begin() const
{
	if (!empty()) 
	{
		typename List<T>::const_iterator const_itr{ head->next };
		return const_itr;
	}
}

/*
	Function: end(): return iterator to the end marker of the list (tail).
	Reference Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 94
*/
template<typename T> typename data::List<T>::iterator List<T>::end()
{
	typename List<T>::iterator itr{ tail };
	return itr;
}

/*
	Function: end(): return const_iterator to the end marker of the list (tail).
	Reference Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 94
*/
template<typename T> typename data::List<T>::const_iterator List<T>::end() const
{
	typename List<T>::const_iterator const_itr{ tail };
	return const_itr;
}

/*
	Function: insert(iterator itr, const T & val): insert value val ahead of the node referred to by itr; and its move version
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 100
*/
template<typename T> typename data::List<T>::iterator data::List<T>::insert(typename List<T>::iterator itr, const T & val)
{
	auto *p = itr.current;
	theSize++;
	return { p->prev = p->prev->next = new List<T>::Node{ val, p->prev, p } };
}

/*
	Function: insert(iterator itr, const T && val): insert value val ahead of the node referred to by itr; and its move version
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 100
*/
template<typename T> typename data::List<T>::iterator data::List<T>::insert(typename List<T>::iterator itr, T && val)
{
	auto *p = itr.current;
	theSize++;
	return { p->prev = p->prev->next = new List<T>::Node{ std::move(val), p->prev, p } };
}

/*
	Function: erase(iterator itr): delete node referred to by itr. The return value is an iterator to the following node.
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 101
*/
template<typename T> typename data::List<T>::iterator data::List<T>::erase(typename List<T>::iterator itr)
{
	auto* p = itr.current;
	typename List<T>::iterator retVal{ p->next };
	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
	theSize--;
	return retVal;
}

/*
	Function: erase(iterator start, iterator end): delete all nodes between start and end (including start but not end), that is, all elements in the range [start, end).
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 101
*/
template<typename T> typename data::List<T>::iterator data::List<T>::erase(typename List<T>::iterator start, typename List<T>::iterator end)
{
	for (auto itr = start; itr != end; )
	{
		itr = erase(itr);
	}
	return end;
}

/*
	Function: init(): initialize the member variables of list.
	Source: "Data Structures And Algorithm Analysis in C++ 4th Edition" By Mark Allen Weiss, page 99
*/
template<typename T> void data::List<T>::init()
{
	theSize = 0;
	head = new Node;
	tail = new Node;
	head->next = tail;
	tail->prev = head;
}

/*
	Function: operator==(const List<T> & lhs, const List<T> & rhs): check if two lists contain the same sequence of elements. Two lists are equal if they have the same number of elements and the elements at the corresponding position are equal.
*/
template<typename T> bool operator==(const List<T> & lhs, const data::List<T> & rhs)
{
	bool flag = true;
	if (lhs.size() == rhs.size())
	{
		auto rhs_itr = rhs.begin();
		for (auto lhs_itr = lhs.begin(); lhs_itr != lhs.end(); ++lhs_itr)
		{
			if (*lhs_itr != *rhs_itr)
			{
				flag = false;
				break;
			}
			++rhs_itr;
		}
		return flag;
	}
	else
	{
		return false;
	}
}

/*
	Function: operator!=(const List<T> & lhs, const List<T> & rhs): opposite of operator==().
*/
template<typename T> bool operator!=(const List<T> & lhs, const data::List<T> & rhs)
{
	return !(lhs == rhs);
}

/*
	Function: operator<<(ostream & os, const List<T> & l): print out all elements in list l by calling List<T>::print() function.
*/
template<typename T> std::ostream & operator<<(std::ostream & os, const data::List<T> & lst)
{
	lst.print(os);
	return os;
}