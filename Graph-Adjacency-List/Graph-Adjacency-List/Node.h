#ifndef NODE_H
#define NODE_H

// forward declaration of template class List
template<class T>
class ADJACENCYLIST;

template <class T>
class Node
{
private:
	friend ADJACENCYLIST<T>;
	T info;
	Node<T>* next;
public:
	Node();
	Node(T);
};
template class Node<int>;
#endif // !NODE_H

