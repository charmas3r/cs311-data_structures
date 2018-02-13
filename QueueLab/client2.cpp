//INSTRUCTION
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 
//except for the trace messages

//=========================================================
//HW#: HW1P1 queue
//Your name: Evan Smith		
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

//Purpose of the program: To output up to 25 distinct permuatations of the letters
	// "A", "B", and "C" in lexigraphical order according to the number of elements
	// per string. 
//Algorithm: The letters A, B and C are addded to an array of strings. First, the letters
	// A, B, and C are added to a queue and then printed to the screen 
	// becoming the first permutations of ABC. To find the next set of permutations
	// the front element of the queue is removed and added to first letter and then
	// added to the rear of the queue. This is repeated until we reached 25 permuations. 
int main()
{
	queue ABCQueue;
	string letters[3] = { "A", "B", "C" };

	string tempString;
	string newString;
	
	try
	{ 			
		//add letter to queue and print first three single letters
		for (int i = 0; i < 3; i++) {
			ABCQueue.add(letters[i]);
			cout << letters[i] << endl;
		}
	
		//generate new string permutations of ABC
		while (!ABCQueue.isFull())
		{
			ABCQueue.remove(tempString);

			for (int i = 0; i < 3; i++) {
				newString = tempString + letters[i];
				ABCQueue.add(newString);
				cout << newString << endl;
			}

		}

	}

    catch (queue::Overflow)
	{
		cerr << "OVERFLOW ERROR: QUEUE IS FULL" << endl;
	}

	catch (queue::Underflow)
	{
		cerr << "UNDERFLOW ERROR: QUEUE IS EMPTY" << endl;
	}
    
	return 0;
}

