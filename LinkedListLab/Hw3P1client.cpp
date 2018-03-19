//INSTRUCTION
//Look for ** to complete all of them
//The output should match my assingment sheet

//=========================================================
//HW#: HW3P1 llist
//Your name: Evan Smith
//Complier:  g++
//File type: client program (tester)
//===========================================================



#include <iostream>
#include <stdlib.h>
#include <string>
#include "llist.h"

using namespace std;

void caseOne()
{
  cout << "CASE 1:------------------- " << endl;
  llist L;   // this is my list
  int x;  // to hold a removed element

  //1 check empty and report the result  
  cout << "Step " << 1 << endl;
  if (L.isEmpty())
    cout << "List is empty" << endl;
  else
    cout << "List is not empty" << endl;

  //2 display the list  
  cout << "Step " << 2 << endl;
  L.displayAll();

  //3 add 4 integers 1,2,3,4    
  cout << "Step " << 3 << endl;
  L.addRear(1);
  L.addRear(2);
  L.addRear(3);
  L.addRear(4);
  cout << " Added 1, 2, 3 and 4 to the rear" << endl;
  
  //4 display the list  
  cout << "Step " << 4 << endl;
  L.displayAll();

  //5 remove from front twice (and display the elements removed)
  cout << "Step " << 5 << endl;
  L.deleteFront(x);
  cout << "Removed " << x << endl;
  L.deleteFront(x);
  cout << "Removed " << x << endl;

  //6 display the list
  cout << "Step " << 6 << endl;
  L.displayAll();

  //7 check empty and report the result 
  cout << "Step " << 7 << endl;
  if (L.isEmpty())
    cout << "List is empty" << endl;
  else
    cout << "List is not empty" << endl;
  
  //8 remove from the rear twice (display the element removed)
  cout << "Step " << 8 << endl;
  L.deleteRear(x);
  cout << "Removed " << x << endl;
  L.deleteRear(x);
  cout << "Removed " << x << endl;

  //9 check empty again and report the result
  cout << "Step " << 9 << endl;
  if (L.isEmpty())
    cout << "List is empty" << endl;
  else
    cout << "List is not empty" << endl;

}//end of case 1 

void caseTwo()
{
  cout << "Case 2: -----------------------" << endl;
  llist L2;  // another list
  int x;   // to hold the removed element 
  int c = 1;  // displayed step number

  // 1.add to front once   (element 5)
  cout << "Step " << c << endl; c++;
  L2.addFront(5);
  cout << "Added 5 to the front" << endl;

  // 2.add to front again  (element 4)
  cout << "Step " << c << endl; c++;
  L2.addFront(4);
  cout << "Added 4 to the front" << endl;

  // 3.delete Front
  cout << "Step " << c << endl; c++;
  L2.deleteFront(x);
  cout << "Removed " << x << endl;

  // 4.add to rear 3 times (elements 6,8,9)
  cout << "Step " << c << endl; c++;
  L2.addRear(6);
  L2.addRear(8);
  L2.addRear(9);
  cout << "Added 6, 8, 9 to the rear" << endl;

  // 5. display all
  cout << "Step " << c << endl; c++;
  L2.displayAll();

  // 6.add before the 1st  (element 4) . 4 5 6 8 9
  cout << "Step " << c << endl; c++;
  L2.addbeforeIth(1, 4);
  cout << "Added 4 before 1st element" << endl;


  // 7.add before the 4th  (element 7) . 4 5 6 7 8 9
  cout << "Step " << c << endl; c++;
L2.addbeforeIth(4, 7);
cout << "Added 7 before 4th element" << endl;

// 8.add before the 7th  (element 10) . 4 5 6 7 8 9 10
cout << "Step " << c << endl; c++;
L2.addbeforeIth(7, 10);
cout << "Added 10 before 7th element" << endl;

// 9.add before the 9th  (element 12) . error (out of range)
cout << "Step " << c << endl; c++;
try {
L2.addbeforeIth(9, 12);
cout << "Added 12 before element 9" << endl;
}
catch (llist::OutOfRange) {
cerr << "ERROR: Out of range request" << endl;
}


// 10.add before the 0th (element 0) . error (out of range)
cout << c << endl; c++;
try {
L2.addbeforeIth(0, 0);
cout << "Added 0 before element 0" << endl;
}
catch (llist::OutOfRange) {
cerr << "ERROR: Out of range request" << endl;
}

// 11.displayAll
cout << "Step " << c << endl; c++;
L2.displayAll();

// 12.delete Ith I==1 (indicate  the element removed) . 5 6 7 8 9 10
cout << "Step " << c << endl; c++;
L2.deleteIth(1, x);
cout << "Removed " << x << endl;

// 13.delete Ith I==6 (indicate the element removed)  - 5 6 7 8 9 
cout << "Step " << c << endl; c++;
L2.deleteIth(6, x);
cout << "Removed " << x << endl;

// 14.delete Ith I==3 (indicate the element removed)  - 5 6 8 9
cout << "Step " << c << endl; c++;
L2.deleteIth(3, x);
cout << "Removed " << x << endl;

// 15.delete Ith I==5 . error (out of range)
cout << "Step " << c << endl; c++;
try {
L2.deleteIth(5, x);
cout << "Removed " << x << endl;
}
catch (llist::OutOfRange) {
cerr << "ERROR: Out of range request" << endl;
}

// 16.delete Ith I==0 . error (out of range)
cout << "Step " << c << endl; c++;
try {
L2.deleteIth(0, x);
cout << "Removed " << x << endl;
}
catch (llist::OutOfRange) {
cerr << "ERROR: Out of range request" << endl;
}

// 17.displayAll
cout << "Step " << c << endl; c++;
L2.displayAll();

// 18.delete from rear until it is empty (indicate the elements removed)
cout << "Step " << c << endl; c++;
while (!L2.isEmpty()) {
L2.deleteRear(x);
cout << "Removed " << x << endl;
}

// 19.displayAll  
cout << "Step " << c << endl; c++;
L2.displayAll();

}//end of case 2

void caseThree()
{
cout << "Case 3:-------------------- " << endl;
llist L3;
int x;  // to hold the removed element

// 1.add before the 0th . error (out of range)
cout << "Step " << 1 << endl;;
try {
L3.addbeforeIth(0, 0);
cout << "Added 0 before element 0" << endl;
}
catch (llist::OutOfRange) {
cerr << "ERROR: Out of range request" << endl;
}

//2.delete front . error (underflow)
cout << "Step " << 2 << endl;
try { L3.deleteFront(x); }
catch (llist::Underflow) { 
cerr << "ERROR: Underflow occured!" << endl;
}
}   //end of case 3

void caseFour()
{
cout << "Case 4:------------------------ " << endl;
llist L4;
int x;  // to hold the removed element

//   1.delete 2nd . error (out of range)
cout << "Step " << 1 << endl;
try {
L4.deleteIth(2, x);
cout << "Removed " << x << endl;
}
catch (llist::OutOfRange) {
cerr << "ERROR: Out of range request" << endl;
}
//    2.delete rear . error (underflow)
cout << "Step " << 2 << endl;
 try { L4.deleteRear(x); }
 catch (llist::Underflow) {
   cerr << "ERROR: Underflow occured!" << endl;
 }
} // end of case 4


//PURPOSE of the Program: To test various conditions of linked lists. Programs gives the user an option to select from 
// different preset case groups for testing. 
//Algorithm/Design: 4 test cases are divided into 4 functions and can be selected by the user. User enters the sentinel value of 0 to quit the
// the program. 
int main()
{
  int selection; // this will indicate what the user wants to do

  do
    {
      cout << endl << "MENU: These are your options: " << endl << endl;
      cout << "   (1) Case 1  " << endl;
      cout << "   (2) Case 2  " << endl;
      cout << "   (3) Case 3  " << endl;
      cout << "   (4) Case 4 " << endl;
      cout << "    Enter ( 0 ) to quit " << endl;
      cout << "===>";

      cin >> selection;

      switch (selection)
	{
	case 1: caseOne(); break;
	case 2: caseTwo(); break;
	case 3: caseThree(); break;
	case 4: caseFour(); break;
	}
    } while (selection != 0);

  return 0;

}// end of main
