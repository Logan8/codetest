/*
 * Blazing Griffin code test
 * Part 1 : Palindromes
 *
 * Trevor Fountain
 * April 2013
 *
 * Edited by Neil Logan
 */

#include <stdio.h>
#include <string>

bool isPalindrome(const char *string)
{
	//get the lengt of the string
	int size = strlen(string)-1;
	
	//For each letter in the string...
	for(int letter=0; letter<size;letter++)
	{
		//...check the letter in a position from the
		//front against the letter in the relevant
		//position from the back
		if(string[letter]==string[size-letter])
		{
			//If letters are the same, continue to next
			continue;
		}
		else
		{
			//If letters are different, return false
			return false;
		}
	}
	
	//If loop completes, its a palindrome!
	return true;
}

int main(int argc, char **argv)
{
	//The commented out sections were used to test the statement 
	//"Note: "abccba" and "abcba" are palindromes; "ABCcba" is not"

	bool pass = 
		isPalindrome("racecar") &&
		!isPalindrome("notapalindrome") &&
		isPalindrome("aaaaAAAAaaaa") &&
		!isPalindrome("((((())))))") &&
		isPalindrome("FOO OOF");

	/*bool pass1 = isPalindrome("abccba");
	bool pass2 = isPalindrome("abcba");
	bool pass3 = isPalindrome("ABCcba");*/

	printf("%s\n", pass ? "PASS" : "FAIL");

	/*printf("%s\n", pass1 ? "PASS" : "FAIL");
	printf("%s\n", pass2 ? "PASS" : "FAIL");
	printf("%s\n", pass3 ? "PASS" : "FAIL");*/

	return 0;
}
