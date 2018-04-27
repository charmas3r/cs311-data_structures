#ifndef DGRAPH_H
#define DGRAPH_H

//----- Globally setting up the alias and struct  ----------------
#include "slist.h"
#include "llist.h"

struct Gvertex
{
	char name; 
	int outDegree;  
	slist adjVert;

	Gvertex() {
		name = ' ';
		outDegree = 0;
	}
	
	//-std=c++11
};
//---------------------------------------------------------

class dGraph
{

	//array with 20 slots which contains 20 Gvertex structs
	struct Gvertex arry[20];
	int totalSize;

public:

	dGraph();   
	~dGraph();    

				 
	void displayGraph();
	void readInfile();
	int findOutDegree(char name);
	slist findAdjVert(char name);

};

#endif