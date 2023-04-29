#include "Node.h"
//#include "ADJACENCYLIST.h"
#include <iostream>
using namespace std;

template<typename T>
Node<T>::Node() {
	info = 0;
	next = NULL;
};
template<typename T>
Node<T>::Node(T val) {
	info = val;
	next = NULL;
};
