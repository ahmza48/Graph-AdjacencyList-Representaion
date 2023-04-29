#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H
#include <string>
#include "Node.h"
using namespace std;

template <class T>
class ADJACENCYLIST
{
private:
	Node<T>* head;
public:

	ADJACENCYLIST();
	void insertAtTail(T);
	T getHead();
	bool isValidPath(string);
	void printList();
};
template class ADJACENCYLIST<int>;
#endif // !LIST_H

