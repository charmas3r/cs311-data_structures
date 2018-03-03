#include <iostream>
#include <vector>
/*
Author: Evan Smith
Date:   03/02/2018

Program created to simulate the final stage of merge sort which compares the elements of two ordered arrays 
or vectors and combines them into one final sorted vector. 
*/
using namespace std;

void displayVector(vector<int> X);
void combineVectors(vector<int> X, vector<int> Y, vector<int> Z);

int main()
{
  vector<int> A;
  vector<int> B;
  vector<int> R;

  int input = 0;

  cout << "Enter the values for vector A: (-99 to quit)" << endl;

  // have user enter inorder  values in vector A
  while ((cin >> input) && input != -99)
    A.push_back(input);

  // call displayVector to output vector A horizontally
  cout << endl;
  cout << "Vector A: ";
  displayVector(A);

  cout << "Enter the values for vector B: (-99 to quit)" << endl;

  // have the user enter inorder values in vector B
  while ((cin >> input) && input != -99)
    B.push_back(input);

  //diplay vector B
  cout << endl;
  cout << "Vector B: ";
  displayVector(B);

  //performs combination of ordered vectors.  
  combineVectors(A, B, R);

  return 0;
}

/*
displayVector prints the elements of a vector horizontally seperated by lines.
 
param: X is the vector to be printed.   
*/
void displayVector(vector<int> X)
{
  cout << endl;

  for (int i = 0; i < X.size(); i++)
    cout << " | " << X[i];
  
  cout << " | " << endl << endl;

}

/*
combineVectors first compares the front elements of two seperate vectors (X and Y) and places smallest
element in the result vector (Z), that element is then deleted and the process is repeated while there
are any elements in either vector being compared. If there are any elements in either vector after the
the comparison then those are added to the end of the result vector. 
 
param: X and Y are the two comparison vectors and Z is the result vector.
*/
void combineVectors(vector<int> X, vector<int> Y, vector<int> Z)
{
  while (!X.empty() && !Y.empty()) {
    
    cout << "Comparing " << X.front() << " and " << Y.front() << endl;

    if (X.front() < Y.front()) {
      Z.push_back(X.front());
      X.erase(X.begin());
      }
    else {
      Z.push_back(Y.front());
      Y.erase(Y.begin());
    }

    cout << "Comparision done!" << endl;
  }

  if (!X.empty()) {
      while (!X.empty()) {
	  Z.push_back(X.front());
	  X.erase(X.begin());
	  }
    }
   else {
      while (!Y.empty()) {
	  Z.push_back(Y.front());
          Y.erase(Y.begin());
	  }
    }

	//prints the result vector
    cout << endl << endl;
    cout << "Vector R: " << endl;
    displayVector(Z);

}
