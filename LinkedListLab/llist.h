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
  
 private:
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
  //2 cases:
  //-Special case: When added node is the first node, a new node is created and Front and Rear 
  //are modified to point to it. Element value is added to node and Count is updated. 
  //- Regular case: adds a new node at the front and puts element value in the Elem field
  //of this new node. Count is updated.
  //PARAM: Element of type el_t which is to be added to the front of the list.
  void addFront(el_t);
    
  //PURPOSE: Adds an element to the rear of the list, modifies Rear pointer and updates Count.
  //2 cases:
  //-Special case: When added node is the first node, a new node is created and Front and Rear 
  //are modified to point to it. Element value is added to node and Count is updated. 
  //- Regular case: adds a new node at the rear and puts element value in the Elem field
  //of this new node. Count is updated.
  //PARAM: Element of type el_t which is to be added to the rear of the list.
  void addRear(el_t);

  //PURPOSE: Removes the front element of the list, modifies Front pointer and updates Count.
  //3 cases:
  //- Error case: if the List is empty, throw Underflow
  //- Special case: if currently only one Node,
  //   give back the front node element through OldNum (pass by reference) and
  //   make sure both Front and Rear become NULL. Count is updated.
  //- Regular: give back the front node element through OldNum (pass by reference)
  //  and also removes the front node.  Count is updated.
  //PARAM: Element of type el_t which is the removed element (value) from the list, passed by ref. 
  void deleteFront(el_t&);
    
  //PURPOSE: Removes the rear element of the list, modifies Rear pointer and updates Count.
  //3 cases:
  //-Error case: if empty, throw Underflow
  //- Special case: if currently only one node,
  //give back the rear node element through OldNum(pass by reference) and
  //make sure both Front and Rear become NULL.Count is updated.
  //- Regular : give back the rear node element through OldNum(pass by reference)
  //and also remove the rear node.Count is updated.
  //PARAM: Element of type el_t which is the removed element (value) from the list, passed by ref. 
  void deleteRear(el_t&);
    
  //PURPOSE: Deletes a node and an indicated index and modifies the pointer at the previous Ith node 
  //to point to the node after the Ith index. 
  //4 cases:
  //-Error case:
  //	If I is an illegal value(i.e. > Count or < 1) throw OutOfRange.
  //		- Special cases : this should simply call deleteFront when I is 1 or
  //		deleteRear when I is Count
  //		- Regular : delete the Ith node(I starts out at 1).Count is updated.
  //		<see the template loops in the notes to move 2 pointers to the right nodes;
  //	and make sure you indicate the purposes of these local pointers>
  //PARAMS: Index of the node to be deleted and the value of the removed node, passed by ref.
  void deleteIth(int, el_t&);

  //PURPOSE: Adds a node before an indicated index and modifies the previous Ith node to point to
  //the new node, then sets the new node to point to the next node in the list.
  //4 cases:
  //-  Error case:
  //   If I is an illegal value (i.e. > Count+1 or < 1) throw OutOfRange.
  //-  Special cases: this should simply call addFront when I is 1 or addRear when
  //   I is Count+1
  //-  Regular: add right before the Ith node. Cout if updated.
  //<see the template loops in the notes to move 2 pointers to the right nodes
  //and make sure you indicate the purposes of these local pointers>
  //PARAMS:  Index of the node before which the new node will be added and the value to placed
  //in the new node
  void addbeforeIth(int, el_t);
    
};
