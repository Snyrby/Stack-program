#ifndef PROCESSSTACK_H
#define PROCESSSTACK_H

#include "StackType.h"
#include <fstream>

using std::ifstream;
using std::ofstream;

/*****************************************************************************************
*  Class Name: Stack
*  Parameters:  none
*  Return Value: none
*  Purpose: process data from textfile. Stores data into a stack. Reverses text from either user input or text file
*****************************************************************************************/

class Stack
{
private:
	StackType WordStack;
public:
	void ProcessItems(ifstream&);
	void PrintItems(ofstream&);
	string UserInput();
	void UserString();
	void ProcessString(string);
};

#endif
