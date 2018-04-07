//INSTRUCTION:
//Llist class - header file template (by Yoshii) based on Notes-6A
// llist.h header file comments completed by Evan Smith
// =======================================================
// HW#: HW3P1 llist
// Your name: Evan Smith
// Compiler:  g++ 
// File type: headher file 
//=======================================================

//----- Globally setting up the alias and struct  ----------------
typedef int el_t ;  // elements will be integers

//a list node is defined here as a struct Node
// I could have done class Node and add the data members under public
// but it would use too much space
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:

  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //PURPOSE: Checks if the list is empty. Returns true if it is and false if it's not. 
  bool isEmpty();
    
  //PURPOSE: Prints all the elements of the list horizontally between brackets. "[ x1 ] [ x2 ] .. [ n ]".
  // If the list is empty then function prints " [ empty ] " to the screen.
  void displayAll();

  //PURPOSE: Adds an element to the front of the list, modifies Front pointer and updates Count.
  //PARAM: Element of type el_t which is to be added to the front of the list.
  void addFront(el_t);
    
  //PURPOSE: Adds an element to the rear of the list, modifies Rear pointer and updates Count.
  //PARAM: Element of type el_t which is to be added to the rear of the list.
  void addRear(el_t);

  //PURPOSE: Removes the front element of the list, modifies Front pointer and updates Count.
  //PARAM: Element of type el_t which is the removed element (value) from the list, passed by ref. 
  void deleteFront(el_t&);
    
  //PURPOSE: Removes the rear element of the list, modifies Rear pointer and updates Count.
  //PARAM: Element of type el_t which is the removed element (value) from the list, passed by ref. 
  void deleteRear(el_t&);
    
  //PURPOSE: Deletes a node and an indicated index and modifies the pointer at the previous Ith node 
  //to point to the node after the Ith index. 
  //PARAMS: Index of the node to be deleted and the value of the removed node, passed by ref.
  void deleteIth(int, el_t&);

  //PURPOSE: Adds a node before an indicated index and modifies the previous Ith node to point to
  //the new node, then sets the new node to point to the next node in the list.
  //PARAMS:  Index of the node before which the new node will be added and the value to placed
  //in the new node
  void addbeforeIth(int I, el_t newNum);

};

