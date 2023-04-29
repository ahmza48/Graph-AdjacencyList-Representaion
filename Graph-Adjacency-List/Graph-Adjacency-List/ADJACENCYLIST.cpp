#include "ADJACENCYLIST.h"
#include "Node.h"
#include <string>
#include <iostream>
using namespace std;

template <typename T>
ADJACENCYLIST<T>::ADJACENCYLIST() {
	head = NULL;
};

template <typename T>
void ADJACENCYLIST<T>::insertAtTail(T val) {
	Node<T>*NewNode = new Node<T>(val);
	if (head == NULL) {
		head = NewNode;
		return;
	}
	else if (head != NULL) {
		Node<T>*temp = head;
		//traverse till end
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = NewNode;
	}
};

template <typename T>
T ADJACENCYLIST<T>::getHead() {
	if (!head) {
		return -1;
	}
	else {
		return head->info;
	}
};

template <typename T>
bool ADJACENCYLIST<T>::isValidPath(string trimmedPath) {
	bool flag = true;
	Node<T>*temp = head;

	while (temp->next != nullptr)
	{
		for (size_t i = 0; i < trimmedPath.length(); i++)
		{
			//converting vertices to integer as it was given in string
			int x = trimmedPath[i] - '0';
			if (temp->info == x) {
				temp = temp->next;
				cout << "OK" << endl;
				break;
			}
			else {
				cout << "NOT OK" << endl;
				return false;
			}
		}
	}
	return flag;
};
template <typename T>
void ADJACENCYLIST<T>::printList()
{
	if (head == NULL) {
		cout << "List is Empty!" << endl;
	}
	//else if (head != NULL) 
	else {
		Node<T>*temp = head;
		cout << "Elements in List are: " << endl;
		while (temp) {

			cout << temp->info << " ";
			temp = temp->next;
		}

	}
}

