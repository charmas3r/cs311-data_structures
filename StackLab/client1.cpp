//INSTRUCTION
//Look for ** to complete this program 
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack
//Your name: Evan Smith	
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <stdlib.h>
#include <string>
#include "vstack.h"

//Purpose of the program: To evaluate a postfix expression
//Algorithm: Algorithm evaluates a string postfix expression and places the operands on a stack,
//turning the character number into an integer. If an operator is encountered, the last 2 
//operands are popped and the operator is applied to the operands, the result of this is pushed
//back onto the stack.
int main()
{
	stack postfixstack;  // integer stack
	string expression;   // user entered expression

	cout << "type a postfix expression: ";
	cin >> expression;

	int i = 0;  // character position within expression
	char item;  // one char out of the expression

	int box1;  // receive things from pop
	int box2;  // receive things from pop

	int result;

	//while char within expressing is not a null character
	while (expression[i] != '\0')
	{
		try
		{
			item = expression[i];  // current char

		//2.  if it is an operand (number), 
			if (item >= '0' && item <='9')
				postfixstack.push(item - 48);
		//    push it (you might get Overflow exception)


	    //3.  else if it is an operator,
		//    pop the two operands (you might get Underflow exception), and
	    //	  apply the operator to the two operands, and
		//    push the result.

		    else if ((item == '+') || (item == '-') || (item == '*'))
			{
				postfixstack.pop(box1);
				postfixstack.pop(box2);
				//cases for different operators follow:
				if (item == '-')
					result = (box2 - box1);
				// ** also do the + and * cases 
				if (item == '+')
					 result = (box2 + box1);
				if (item == '*')
					result = (box2 * box1);

				// ** Finally push the result
				postfixstack.push(result);
			}
		else throw "invalid item";
	} // this closes try

	// Catch exceptions and report problems and quit the program now. 
	// Error messages describe what is wrong with the expression.
	catch (stack::Overflow)
	{
		cerr << "OVERFLOW ERROR: TOO MANY OBJECTS IN STACK. QUITTING.";
		exit(1);
	}
	catch (stack::Underflow) // for too few operands
	{
		cerr << "UNDERFLOW ERROR: NO OBJECTS IN STACK. QUITTING.";
		exit(1);
	}
	catch (char const* errorcode) // for invalid item
	{
		cerr << "INVALID ELEMENT: " << item << " IS NOT A VALID ELEMENT.";
		exit(1);
	}
		// go back to the loop after incrementing i
	i++;
	}// end of while

	 // After the loop successfully completes: 
	 // The result will be at the top of the stack. Pop it and show it.
	postfixstack.pop(result);
	cout << result;
	// If anything is left on the stack, an incomplete expression was found.
	// Inform the user.
	
	return 0;
}// end of the program
