#include "List.h"



// функция вставки первого жлемента в начало списка
// sPtr - адресс адресса начала списка
// data - данный для записи в новый узел

void insertFirst(listNode** sPtr, Data& data) 
{
	listNode* newNode = new listNode;

	newNode->data.address = data.address;
	newNode->next = *sPtr;

	*sPtr = newNode;
}