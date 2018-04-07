#include <iostream>
#include "slist.h"

using namespace std;

//new constructor for slist, same as llist
slist::slist() {
	Front = NULL;
	Rear = NULL;
	Count = 0;
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
