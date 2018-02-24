#include <iostream>

using namespace std;

const int ARR_SIZE = 10;

int binSearch(int ar[], int x, int f, int l);

int main()
{
  int nums[ARR_SIZE];
  int first = 0;
  int last = 0;
  int search = 0;
  int resultLoc = -1;

  cout << "Enter values for binary search" << endl;

  //input numbers into the array, with first position at 1
  for (int i = 1; i <= ARR_SIZE; i++){
    cout << "Position[" << i << "]: ";
    cin >> nums[i];
  }
  
  //set first and last
  first = 1;
  last = ARR_SIZE;

  //prompt user for value to search for
  cout << "What value would you like to find? ";
  cin >> search;

  //program announcement
  cout << endl << endl << "Searching values..." << endl << endl;

  //call recursive binary search algorithm if there is more than one
  //element in the array. for this example there is 10.
  if (first != last)
    resultLoc = binSearch(nums, search, first, last);
  else {
    cout << "There is only one element in the array" << endl;
    resultLoc = nums[first];
  }

  //print results of the search. a sentinel value of -1 was assigned to 
  //resultLoc if the item is not in the array
  if (resultLoc != -1)
    cout << nums[resultLoc] << " was found at position " << resultLoc << endl;
  else
    cout << "Item not found" << endl;
  
  return 0;
}

int binSearch(int ar[], int x, int f, int l)
{
  //if position of first goes over last then the element is not in the array
  //and we can return -1 before going through the algorithm
  if (f > l)
    return -1;

  //compare search with middle number of the ordered list, halving the search
  //space and therefore time complexity with each iteration. middle is set to
  //the floor of (f+l)/2.
  int middle = (f + l) / 2;
  if (x == ar[middle])
    return middle;
  else if (x < ar[middle])
    l = middle - 1;
  else if (x > ar[middle])
    f = middle + 1;
  return binSearch(ar, x, f, l);
}
