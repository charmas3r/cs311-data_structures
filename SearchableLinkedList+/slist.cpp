#include <iostream>
#include "slist.h"

using namespace std;

//new constructor for slist, same as llist
slist::slist() {
	Front = NULL;
	Rear = NULL;
	Count = 0;
}

//PURPOSE: Boolean comparison of two seperate list objects. This function
// overloads the == operator so we can compare two lists. Returns false if 
// list counts are different or if the lists have different elements. 
//PARAM: L2 is list passed by reference. 
bool slist::operator ==(slist& L2)
{
	//immeadiately return false if counts are different
	if (this->Count != L2.Count)
		return false;
	
	else {
		Node *p = this->Front;
		Node *q = L2.Front;
		
		//iterate through both lists to compare elements
		while (p != NULL && q != NULL) {
			if (p->Elem != q->Elem)
				return false;
			p = p->Next;
			q = q->Next;
		}
		//if lists are same length and have same elements
		return true;
	}
}

//PURPOSE: To overload the = operator so we can create a copy of a list
//PARAM: slist L2 is passed by reference 
slist& slist::operator=(const slist& L2)
{
	// First make sure this-> and OtherOne are not the same object.
	// To do this, compare the pointers to the objects .
	el_t temp;

	if (&L2 != this)  // if not the same
	{
		// this-> object has to be emptied first.
		while (!this->isEmpty())
			this->deleteRear(temp);
		// this-> object has to be built up by allocating new cells (**)
		Node* P;  // local pointer for OtherOne
		P = L2.Front;
		while (P != NULL)  // This uses a loop which repeats until you reach the end of OtherOne. 
		{
			this->addRear(P->Elem);    //P’s element is added to this->
			P = P->Next;               // Go to the next node in OtherOne   
		}
	}// end of if              
	return *this;    // return the result unconditionally.
}

//PURPOSE: copy constructor creates a copy a new list object
//PARAM: original is passed by reference
slist::slist(const slist& original) {

	//initializes this->'s data members 
	this->Front = NULL;
	this->Rear = NULL;
	this->Count = 0;

	// this-> object has to be built up by allocating new cells 
	Node *p = original.Front;

	while (p != NULL)
	{
		this->addRear(p->Elem); //P’s element is added to this->
		p = p->Next; // go to next node
	}
}

//PURPOSE: Searches through the list and returns index and element
// in the linked list.
//PARAM: Searched for parameter
int slist::search(el_t Key) {

	Node* p = Front;

	for (int i = 1; i < Count + 1; i++) {
		if (p->Elem == Key)
			return i;

		p = p->Next;
	}

	return 0;
}

//PURPOSE: Searches for and replaces element at the Ith node
//PARAM: Element to be replace (passed by ref) and node index to be searched for
void slist::replace(el_t Elem, int I) {

	if (I > Count + 1 || I < 1)
		throw OutOfRange();

	else {

		Node* p = Front;

		for (int i = 1; i < I; i++)
			p = p->Next;

		p->Elem = Elem;
	}

}
