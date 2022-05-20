#include "ProcessStack.h"
#include <iostream>
#include <string>
#include "ItemType.h"
#include <algorithm>

using std::cerr;
using std::cout;
using std::endl;
using std::cin;
using std::getline;

/*****************************************************************************************
*  function Name: ProcessItems(ifstream& inFile)
*  Parameters: inFile
*  Return Value: none
*  Purpose: Process all the data in the text file and reverses the text in the text file
*****************************************************************************************/

void Stack::ProcessItems(ifstream& inFile)
{
	ItemType New;
	string sentence;

	/* reads each line within the file */
	while (getline(inFile, sentence))
	{
		/* converts the get line to char for x being each char*/
		for (auto x : sentence)
		{
			/* if the char is a ' ' then it puts a space into the stack */
			if (x == ' ')
			{
				New.Initialize(x);
				if (!WordStack.IsFull())
				{
					WordStack.Push(New);
				}
				/* error if stack is full */
				else
				{
					cerr << "Error: Stack is full!\n\n";
					system("pause");
					exit(0);
				}
			}
			/* if it is anything else then it puts the item in the stack*/
			else
			{
				New.Initialize(x);
				if (!WordStack.IsFull())
				{
					WordStack.Push(New);
				}
				/* error if stack is full */
				else
				{
					cerr << "Error: Stack is full!\n\n";
					system("pause");
					exit(0);
				}
			}
		}
	}
}	

/*****************************************************************************************
*  function Name: PrintItems(ofstream& outFile)
*  Parameters: outFile
*  Return Value: none
*  Purpose: prints the data stored within the stack from the ProcessItems function
*****************************************************************************************/

void Stack::PrintItems(ofstream& outFile)
{
	ItemType item;
	
	/* loops until stack is empty */
	while (!WordStack.IsEmpty())
	{
		/* stores data at the top of the stack as an ItemType to be printed */
		item = WordStack.Top();

		/* prints each item */
		item.Print(outFile);

		/* deletes the item from the stack */
		WordStack.Pop();

		/* if the stack is empty then it closes the program */
		if (WordStack.IsEmpty())
		{
			cout << endl;
			system("pause");
			exit(0);
		}
	}
	/* if word stack is empty from the beginning then it tells the user there is no data in the input file */
	if (WordStack.IsEmpty())
	{
		cout << "There is no data in the input file\n";
		outFile << "There is no data in the input file";
	}
}

/*****************************************************************************************
*  function Name: UserInput()
*  Parameters: none
*  Return Value: int input
*  Purpose: asks the user whether they would like to read from an input file or input a string
*****************************************************************************************/

string Stack::UserInput()
{
	string input;
	/* loops until the user enters 1 or 2 for input */
	do
	{
		cout << "Would you like to read from an input file or userinput?\nType 'file' to read from an input file\nType 'type' to type your own sentence: ";
		cin >> input;
		cout << endl;
		transform(input.begin(), input.end(), input.begin(), toupper);
	} while (!(input == "FILE" || input == "TYPE"));
	return input;
}

/*****************************************************************************************
*  function Name: UserString()
*  Parameters: none
*  Return Value: none
*  Purpose: asks the user what string they would like to use then stores in a stack
*****************************************************************************************/

void Stack::UserString()
{
	string str;
	/* asks the user for the input and stores the whole input in a getline */
	cout << "What is the sentence that you would like to use? ";
	cin.ignore();
	getline(cin, str);

	/* calls function to store the string in a stack */
	ProcessString(str);
}

/*****************************************************************************************
*  function Name: ProcessString(string str)
*  Parameters: initialized str
*  Return Value: none
*  Purpose: stores the data from user input into a stack
*****************************************************************************************/

void Stack::ProcessString(string str)
{
	ItemType New;
	/* converts the get line in the UserString() function to char for x being each char*/
	for (auto x : str)
	{
		/* if the char is a ' ' then it puts a space into the stack */
		if (x == ' ')
		{
			New.Initialize(x);
			if (!WordStack.IsFull())
			{
				WordStack.Push(New);
			}
			/* error if stack is full */
			else
			{
				cerr << "Error: Stack is full!\n\n";
				system("pause");
				exit(0);
			}
		}
		/* if it is anything else then it puts the item in the stack*/
		else
		{
			New.Initialize(x);
			if (!WordStack.IsFull())
			{
				WordStack.Push(New);
			}
			/* error if stack is full */
			else
			{
				cerr << "Error: Stack is full!\n\n";
				system("pause");
				exit(0);
			}
		}
	}
}