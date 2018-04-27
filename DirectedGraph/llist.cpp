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
	//cout << "Calling the llist destructor" << endl;
	el_t temp = ' ';

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

//2 cases:
//-Special case: When added node is the first node, a new node is created and Front and Rear 
//are modified to point to it. Element value is added to node and Count is updated. 
//- Regular case: adds a new node at the rear and puts element value in the Elem field
//of this new node. Count is updated.
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

//2 cases:
//-Special case: When added node is the first node, a new node is created and Front and Rear 
//are modified to point to it. Element value is added to node and Count is updated. 
//- Regular case: adds a new node at the front and puts element value in the Elem field
//of this new node. Count is updated.
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

//3 cases:
//- Error case: if the List is empty, throw Underflow
//- Special case: if currently only one Node,
//   give back the front node element through OldNum (pass by reference) and
//   make sure both Front and Rear become NULL. Count is updated.
//- Regular: give back the front node element through OldNum (pass by reference)
//  and also removes the front node.  Count is updated.
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

//3 cases:
//-Error case: if empty, throw Underflow
//- Special case: if currently only one node,
//give back the rear node element through OldNum(pass by reference) and
//make sure both Front and Rear become NULL.Count is updated.
//- Regular : give back the rear node element through OldNum(pass by reference)
//and also remove the rear node.Count is updated.
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

//4 cases:
//-Error case:
//	If I is an illegal value(i.e. > Count or < 1) throw OutOfRange.
//		- Special cases : this should simply call deleteFront when I is 1 or
//		deleteRear when I is Count
//		- Regular : delete the Ith node(I starts out at 1).Count is updated.
//		<see the template loops in the notes to move 2 pointers to the right nodes;
//	and make sure you indicate the purposes of these local pointers>
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

//4 cases:
//-  Error case:
//   If I is an illegal value (i.e. > Count+1 or < 1) throw OutOfRange.
//-  Special cases: this should simply call addFront when I is 1 or addRear when
//   I is Count+1
//-  Regular: add right before the Ith node. Cout if updated.
//<see the template loops in the notes to move 2 pointers to the right nodes
//and make sure you indicate the purposes of these local pointers>
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


