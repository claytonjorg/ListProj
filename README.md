# ListProj

### Description
Implementation of lists class with two nested classes; const_iterator and node. The list is used to manipulate integer values by using the pushing and popping functions.

### Class List Header
- Public Members
```
List(): default zero parameter constructor
List(const List &rhs): copy constructor
List(List && rhs): move constructor
explicit List(int num, const T& val = T{}): num elements with value of val

List(const_iterator start, const_iterator end): constructs with elements [start, end)
~List(): destructor
const List& operator=(const List &rhs): copys assignment operator
List & operator=(List && rhs): moves assignment operator

int size() const: number of elements
bool empty() const: checks if list is empty
void clear(): deletes all elements
void reverse(): reverse the order of the elements

T &front(): reference to the first element
const T& front() const
T &back(): reference to the last element
const T & back() const 

void push_front(const T & val): inserts to the beginning
void push_front(T && val): moves version of insert
void push_back(const T & val): inserts to the end
void push_back(T && val): moves version of insert
void pop_front(): deletes first element
void pop_back(): deletes last element

void remove(const T &val): removes all elements with value = val
void print(std::ostream& os, char ofc = ' ') const: prints out all elements. ofc is deliminitor 

iterator begin(): iterator to first element
const_iterator begin() const
iterator end(): end marker iterator
const_iterator end() const 
iterator insert(iterator itr, const T& val): inserts val ahead of itr
iterator insert(iterator itr, T && val): moves version of insert
iterator erase(iterator itr): erases one element
iterator erase(iterator start, iterator end): erases [start, end)
```
- Private Members
```
int theSize: number of elements
Node *head: head node
Node *tail: tail node
void init(): initialization
```
