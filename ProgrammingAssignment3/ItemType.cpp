#include <fstream>
#include <iostream>
#include "ItemType.h"
#include <stdlib.h>
#include "ProcessStack.h"

using std::cout;
using std::endl;

/* initialized the data to be stored as an item type */
void ItemType::Initialize(char letter)
{
	CurrentWord = letter;
}
/* prints each char and stores into the outfile */
void ItemType::Print(std::ostream& out) const
{
	cout << CurrentWord;
	out << CurrentWord;
}
