
/*****************************************************************************************
*  Program Name: ProgrammingAssignment3
*  Created Date: 3/14/19
*  Created By: Shawn Ruby
*  Purpose: Stores data into a stack and reverses
*  Acknowledgements: None
*****************************************************************************************/

#include <iostream>
#include <fstream>
#include "ProcessStack.h"

using std::ifstream;
using std::ofstream;
using std::cerr;
using std::endl;
using std::exception;



int main()
{
	try
	{
		ifstream inFile; //Get an input file of data to process
		inFile.open("Input.dat"); //Get file ready to read input

		ofstream outFile; //Get an output file to write data out to
		outFile.open("Output.txt"); //Get file ready to write data to

		Stack myStack;
		if (myStack.UserInput() == "FILE")
		{
			myStack.ProcessItems(inFile); //Read and process all words and puts them into a stack
			myStack.PrintItems(outFile); //Print out all the words to the output file
		}
		else
		{
			myStack.UserString();
			myStack.PrintItems(outFile); //Print out all the words to the output file
		}

		inFile.close(); //Need to close our input and output files
		outFile.close();
	}
	catch (exception& ex) //Catch any errors that occure and display them in the console to the user
	{
		cerr << "An error occured: " << ex.what() << endl;
		system("pause");
		return 1;
	}
	system("pause");
	return 0;
}