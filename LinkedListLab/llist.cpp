//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A

//- Make sure PURPOSE and PARAMETER comments are given
//  DO NOT DELETE my descriptions but USE them.
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//EMACS HINT:
//  control-K cuts and control-Y pastes
//  Esc X replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++
// ====================================================
//HW#: HW3P1 llist
//Your name: Evan Smith
//Complier:  g++
//File type: llist implementation file
//=====================================================


#include <iostream>
#include"llist.h" 

using namespace std;

llist::llist() {
	Front = NULL;
	Rear = NULL;
	Count = 0;
}
 
/*-while the list is not empty, call deleteFront repeatedly to delete all nodes.
- Please place a cout in this function "calling the llist desctructor."*/
llist::~llist() {
	cout << "Calling the llist destructor" << endl;
	int temp = 0;

	while (!isEmpty()) 
		deleteFront(temp);
}

//-return true if Front and Rear are both pointing to NULL and Count is 0.
//- (all 3 conditions must be checked)
bool llist::isEmpty() {

	if (Front == NULL && Rear == NULL && Count == 0)
		return true;
	else
		return false;

}

void llist::displayAll() {

	Node* p = new Node;
	p = Front;

	if (isEmpty())
		cout << " [ empty ] " << endl;
	else {
		while (p != NULL) {
			cout << " [ " << p->Elem << " ] ";
			p = p->Next;
		}
		cout << endl;
	}

}

void llist::addRear(el_t NewNum) {

	Node* Temp = new Node;

	//Special case:
	if (isEmpty()) {
		Front = Temp;
		Rear = Temp;
		Temp->Elem = NewNum;
		Rear->Next = NULL;
		Count++;
	}
	
	else
	{
		//Regular case:
		Rear->Next = Temp;
		Rear = Rear->Next;
		Rear->Elem = NewNum;
		Rear->Next = NULL;
		Count++;
	}

}

void llist::addFront(el_t NewNum) {
	
	Node* Temp = new Node;
	
	if (isEmpty()) {
		Front = Temp;
		Rear = Temp;
		Temp->Elem = NewNum;
		Rear->Next = NULL;
		Count++;
	}

	//Regular case:
	else {
		Temp->Next = Front;
		Front = Temp;
		Front->Elem = NewNum;
		Count++;
	}
}

void llist::deleteFront(el_t& OldNum) {

	if (isEmpty()) 
		throw Underflow();

	else if (Front == Rear && Count == 1) {
		OldNum = Front->Elem;
		delete Front;
		Front = NULL;
		Rear = NULL;
		Count = 0;
	}

	//Regular case:
	else {
		OldNum = Front->Elem;
		Node *Second;
		Second = Front->Next;
		delete Front;
		Front = Second;
		Count--;
	}
}

void llist::deleteRear(el_t& OldNum) {


      if (isEmpty()) 
		  throw Underflow(); 

	  else if (Front == Rear && Count == 1) {
		  OldNum = Rear->Elem;
		  delete Rear;
		  Front = NULL;
		  Rear = NULL;
		  Count = 0;
	  }

	  //Regular case:
	  else {

		  OldNum = Rear->Elem;

		  Node *p = Front;
		  
		  //Go to second to last element
		  while (p->Next != Rear) 
			  p = p->Next;
			   
		  delete Rear;
		  Rear = p;
		  Rear->Next = NULL;
		  Count--;
	  }
}

void llist::deleteIth(int I, el_t& OldNum) {
	
	//error checking for out of bounds request
	if (I > Count || I < 1) 
		throw OutOfRange();

	//special case:
	else if (Count == 1 || I == Count) {

		if (Count == 1)
			deleteFront(OldNum);
		else
			deleteRear(OldNum);
	}

	//regular case:
	else {
		Node* before = Front;
		Node* after;
		
		for (int i = 1; i < I; i++)
			before = before->Next;

		after = before->Next->Next;
		OldNum = before->Next->Elem;
		delete before->Next;
		before->Next = after;
		Count--;
	}
}

void llist::addbeforeIth(int I, el_t newNum) {

	if (I > Count + 1 || I < 1)
		throw OutOfRange();

	else if (I == 1 || I == Count + 1) {
		if (I == 1) 
			addFront(newNum);
		else
			addRear(newNum);
	}

	else {
		Node* p = Front;

		for (int i = 1; i < I; i++)
			p = p->Next;

		Node* after = p->Next;
		Node* newNode = new Node;
		p->Next = newNode;
		newNode->Next = after;
		newNode->Elem = newNum;
		Count++;
	}
}

