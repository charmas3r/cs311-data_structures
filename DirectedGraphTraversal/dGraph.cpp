#include <iostream>
#include <string>
#include <fstream>
#include "dGraph.h"
#include "slist.h"
#include "llist.h"
#include "stack.h"

using namespace std;


dGraph::dGraph() {

	totalSize = 0;

}


dGraph::~dGraph() {

	// destroys table possibly.. check later
}

void dGraph::displayGraph() {

	//create header for directed graph
	slist temp;

	cout << "Directed Graph Table: " << endl << endl;
	cout << " Name  Visit   Deg   Adjacency List" << endl;
	cout << " ----  -----   ---   --------------" << endl;

	for (int i = 0; i < totalSize; i++) {

		cout << "  " <<  arry[i].name << "  |   "
			         << arry[i].visitNumber << "   |  "
			         << arry[i].outDegree << "  |  ";

		temp = findAdjVert(arry[i].name);
		
		temp.displayAll();

		cout << endl;

		// still need to display list
	}

}

void dGraph::readInfile() {


	ifstream fin;

	fin.open("table.txt");

	char currentChar;
	int counter = 0;

	if (fin) {

		//read while there are chars in file
		while (fin >> currentChar) {

			//look at int representation of first char
			int x = (int) currentChar;

			//if ascii value is between 65 and 90 it must be a name
			if (x >= 65 && x <= 90) {
				//add name to the table
				arry[counter].name = currentChar;
			}

			//next char in the line must be a outdegree
			else {

				//insert out degree 
				arry[counter].outDegree = x - 48;

				//read in outdegree amount of characters after we've inserted outdegree
				for (int i = 0; i < x - 48; i++) {
					fin >> currentChar;
					arry[counter].adjVert.addRear(currentChar);
				}

				//go to next line
				totalSize++;
				counter++;
			}
		

		}

	}


	fin.close();

	
}

int dGraph::findOutDegree(char name) {


	for (int i = 0; i < totalSize; i++) {
		if (arry[i].name == name) {

			return arry[i].outDegree;

		}

	}

	//if not found return -1
	return -1;
	
}

slist dGraph::findAdjVert(char name) {

	for (int i = 0; i < totalSize; i++) {
		if (arry[i].name == name) {

			return arry[i].adjVert;

		}

	}

	//error handling in case name not found
}


void dGraph::addVisitNumber(int &x, char name) {
	
	for (int i = 0; i < totalSize; i++) {
		if (arry[i].name == name) {


			arry[i].visitNumber = ++x;

		}
	}

}

bool dGraph::checkMarked(int x, char name) {
	
	for (int i = 0; i < totalSize; i++) {
		if (arry[i].name == name) {

			if (x > 0)
				return true;
			else
				return false;

		}

		
		}

}

void dGraph::depthFirstTraversal(char name) {

	slist testList;
	bool flag;
	int visitNum = 0;
	char holder;
	char v;
	bool check = false;
	int carry = 0;


	//Mark current vertex
	addVisitNumber(carry, name);

	//create a list and stack object
	for (int i = 0; i < totalSize; i++) {
		if (arry[i].name == name) {

			testList = arry[i].adjVert;

		}
	}

		stack testStack;

		//Get adj. list of A and push adj verticed onto the stack.

		while (!testList.isEmpty()) {
			testList.deleteRear(holder);
			testStack.push(holder);
		}

		cout << endl << endl;

		//Display the stack
		testStack.displayAll();
		cout << endl << endl;

		//traverse

		while (!testStack.isEmpty()) {

			testStack.pop(v);
			cout << "The name of the vertex (popped off the stack) is: " << v << endl;

			//find visit number for new vertex
			for (int i = 0; i < totalSize; i++) {
				if (arry[i].name == v) {
					visitNum = arry[i].visitNumber;
				}
			}

			//see if this vertex has been visited before
			check = checkMarked(visitNum, v);

			//if v is not yet marked
			if (!check) {

				//mark it
				addVisitNumber(carry, v);

				//display
				cout << "Visited " << v << endl;

				//get it's adj list
				testList = findAdjVert(v);

				//put adj vert on the stack
				while (!testList.isEmpty()) {
					testList.deleteRear(holder);
					testStack.push(holder);
				}

				//Display the stack
				testStack.displayAll();
				cout << endl << endl;

			}

		}

	}