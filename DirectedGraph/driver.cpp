
//=========================================================
//HW#: Directed Graph 
//Your name: Evan Smith
//Complier:  g++
//File type: client program (tester)
//===========================================================


#include <stdio.h>
#include <iostream>
#include "slist.h"
#include "dGraph.h"

using namespace std;

int main()
{

	dGraph test;

	test.readInfile();

	// search for a vertex

	char search;
	int result;

	cout << "Enter the name of Vertex you would like to know the out degree of: ";

	search = getchar();

	result = test.findOutDegree(search);

	if (result != -1) {
		cout << "Vertex " << search << " has an out degree of: " << result;
		cout << endl << endl;
	}

	else {
		cout << "Vertex " << search << " is not found. " << endl;
		cout << endl << endl;
	}

	// search for a list
	slist tempList;
	char search2;
	cin.ignore();

	cout << "Enter the name of Vertex you would like to know the slist of: ";
	search2 = getchar();
	tempList = test.findAdjVert(search2);

	//display list
	tempList.displayAll();
	cout << endl << endl;

	//display entire graph
	test.displayGraph();

	return 0;
}
