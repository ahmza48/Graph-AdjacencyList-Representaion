#include <iostream>
#include "Node.h"
#include "ADJACENCYLIST.h"
#include <string>
using namespace std;

void initializeGraph(ADJACENCYLIST<int>*arr,int vertices) {
	cout << "\t------------------ Initialization Begins ------------------" << endl;
	cout << "Enter vertices numbers to which respective vertix is connected" << endl;
	cout << "Enter -1 to stop Entering connecting vertices for current Vertix otherwise Enter Vertix Number." << endl;

	for (int i = 0; i < vertices; i++)
	{
		cout << endl;
		int choice;
		cout << "Enter vertices that are connected with Vertix # " << i + 1 << endl;
		do
		{
			cout << "Enter vertix: ";
			cin >> choice;
			if (choice != -1) {
				arr[i].insertAtTail(choice);
			}

		} while (choice != -1);
	}
};
string removeSpaces(string path) {
	string trimmedPath = "";
	//removing spaces from path string
	for (size_t i = 0; i < path.length(); i++)
	{
		if (path[i] != ' ') {
			trimmedPath += path[i];
		}
	}
	return trimmedPath;
};

//string removeSpaces(string path) {
//	string trimmedPath = "";
//	//removing spaces from path string
//	for (int i = 0; i < path.length(); i++)
//	{
//		if (path[i] != ' ') {
//			trimmedPath += path[i];
//		}
//	}
//	return trimmedPath;
//};
bool doesPathExists(ADJACENCYLIST<int>*arr, int vertices, string path) {
	//removing spaces from Path:
	string trimmedPath = removeSpaces(path);
	//Taking First vertex from path and checking if this vertex contains existing paths or not
	int firstVertex = trimmedPath[0] - '0';
	cout << endl;
	bool flag;
	flag = arr[firstVertex - 1].isValidPath(trimmedPath);
	return flag;
};

int main() {
	int vertices;
	cout << "Enter the Number of Vertices in Graph: ";
	cin >> vertices;
	ADJACENCYLIST<int>* arr = new ADJACENCYLIST<int>[vertices];
	//Initializing Graph
	initializeGraph(arr,vertices);
	cout << endl;

	for (int i = 0; i < vertices; i++)
	{
		cout << "List index: " << i << endl;
		arr[i].printList();
		cout << endl;
	}

	//Checking for Paths

	cout << "\t******** Checking Path ********" << endl;
	cout << endl;
	cout << "Enter the path in format 1 2 3 to check if path from 1->2->3 exists or not e.g." << endl;
	cout << "Enter 1 to check Path, 0 to Exit." << endl;
	int choice;
	do
	{
		cout << "Do you want to check path? ";
		cin >> choice;
		if (choice == 1) {
			string path;
			cin.ignore();
			cout << "Enter the Path: ";
			getline(cin, path);
			bool existsOrNot = doesPathExists(arr, vertices, path);
			if (existsOrNot) {
				cout << "This Path Exists." << endl;
			}
			else {
				cout << "Sorry, This Path Doesn't Exist!" << endl;
			}
			
		}

	} while (choice != 0);

	return 0;
}
