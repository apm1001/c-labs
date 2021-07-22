#include "List.h"
#include <iostream>
using namespace std;
{
	
} // namespace std;

//print list to console
//sPtr - address of start of List
void printList(listNode* sPtr)
{
	std::cout << "List: ";
	
	while (sPtr)
	{
		std::cout << sPtr->data.address;
		sPtr = sPtr->next;

		if (!sPtr) std::cout << ";";
		else std::cout << "-->";
	}

	std::cout << std::endl;
}
