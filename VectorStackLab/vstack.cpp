//INSTRUCTION
//Look for **. (do control-S)
//Update the comments using the HOW TO COMMENT file, 
//  complete exception handling and 
//  finish ClearIt to make this complete - Yoshii (CS311)
// When done, compile stack.cpp to make sure there are no syntax errors.

//=========================================================
//HW#: HW1P2 vstack
//Your name: Evan Smith
//Complier:  g++
//File type: vstack implementation file
//=========================================================

using namespace std;
#include <iostream>
#include <vector>
#include "vstack.h"

//PURPOSE:  Constructor has not have any work to do
stack::stack()
{
}

//PURPOSE:  Destructor clears the vector object of contents
stack::~stack()
{ 
   // clear cells
  el.clear();

}

//PURPOSE:  If there are no elements in the vector return is "Empty", otherwise
//       return false.
bool stack::isEmpty()
{
	if (el.size()  == 0)
		return true;
	else
		return false;
}

//PURPOSE: vector implemented stack is never full due to the nature
//    of vectors
bool stack::isFull()
{
		return false;
}

//PURPOSE: calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el.
//PARAMETER: pass the element (elem) to be pushed 
void stack::push(el_t elem)
{
	if (isFull())
		throw Overflow();
	else {
		el.push_back(elem);
	}
}

//PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, gives the top element and then removes it from the vector
//PARAMETER: provide a holder (elem) for the element popped (pass by ref)
void stack::pop(el_t& elem)
{
	if (isEmpty())
		throw Underflow();
	else { 
	    elem = el.back();
	    el.pop_back();
	}
}

// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
void stack::topElem(el_t& elem)
{
	if (isEmpty())
		throw Underflow();
	else { 
	  elem = el.back(); 
	}
}

//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//          Otherwise, diplays the elements vertically.
void stack::displayAll()
{
	if (isEmpty())
		cout << "[ empty ]" << endl;
	else {
	  for (int i = el.size() - 1; i >= 0; i--)
	    {
	      cout << el.at(i) << endl;
	    }
		cout << "--------------" << endl;
	}
}


//PURPOSE: pops all elements from the stack to make it empty if it is not empty yet.
void stack::clearIt()
{
	if (!isEmpty())
	{
		//use vector clear modifier
		el.clear();
	}
}


