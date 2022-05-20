#ifndef ITEMTYPE_H
#define ITEMTYPE_H

// The following declarations and definitions go into file 
// ItemType.h. 

#include <fstream>
#include <string>
using std::string;


const int MAX_ITEMS = 50;
//typedef int ItemType;

/*****************************************************************************************
*  Class Name:  ItemType
*  Parameters:  none
*  Return Value: none
*  Purpose: initializes data and print function
*****************************************************************************************/

class ItemType
{
public:
	void Initialize(char);
	void Print(std::ostream&) const;
private:
	char CurrentWord;
};

#endif