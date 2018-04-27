#include <iostream>
#include <string>
#include <fstream>
#include "dGraph.h"
#include "slist.h"
#include "llist.h"

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
	cout << " Name  Deg   Adjacency List" << endl;
	cout << " ----  ---   --------------" << endl;

	for (int i = 0; i < totalSize; i++) {

		cout << "  " <<  arry[i].name << "  |  "
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


	for (int i = 0; i < 10; i++) {
		if (arry[i].name == name) {

			return arry[i].outDegree;

		}

	}

	//if not found return -1
	return -1;
	
}

slist dGraph::findAdjVert(char name) {

	for (int i = 0; i < 10; i++) {
		if (arry[i].name == name) {

			return arry[i].adjVert;

		}

	}

	//error handling in case name not found
}

