/*
 * Blazing Griffin code test
 * Part 2 : Data structures
 *
 * Trevor Fountain
 * April 2013
 *
 * Edited by Neil Logan
 */

#include <stdio.h>
#include <stack>

/**
@brief TopStack provides the standard push/pop stack methods, plus an additional
       `getHighest()` method that returns the highest-valued int currently on 
       the stack.

Feel free to make additions to the class definition, but justify any 
modifications to the existing methods!
*/
class TopStack
{
	protected:
		std::stack<int> stack;

	public:
		/// Push a value onto the top of the stack
		void push(int value);

		/// Remove the topmost value from the stack and return it
		//o required to return anything
		void pop();

		/// Return the highest value currently on the stack
		int getHighest();
};

void TopStack::push(int value)
{
	//Add to the top of the stack
	stack.push(value);
}

void TopStack::pop()
{
	//Remove from top of stack
	stack.pop();
}

int TopStack::getHighest()
{
	//Get item of first item in stack
	int highest = stack.top();

	//Use a temporary stack to ensure the actual stack is maintained
	std::stack<int> tempStack = stack;
	
	//Remove first item, as its already stored in "highest"
	tempStack.pop();
	
	//While the stack is not empty...
	while(!tempStack.empty())
	{
		//...check the next value on the stack. If higher than
		//current highest, store the value...
		if(tempStack.top() > highest) highest = tempStack.top();

		//And remove the value from the stack
		tempStack.pop();
	}
	
	//Once all values are chacked (stack is empty) return the value
	return highest;
}

int main(int argc, char **argv)
{
	bool pass = true;

	TopStack topStack;

	topStack.push(12);
	pass = pass && (topStack.getHighest() == 12);

	topStack.push(6);
	pass = pass && (topStack.getHighest() == 12);

	topStack.push(42);
	pass = pass && (topStack.getHighest() == 42);

	topStack.pop();
	pass = pass && (topStack.getHighest() == 12);

	printf("%s\n", pass ? "PASS" : "FAIL");

	return 0;
}
