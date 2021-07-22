#include "List.h"

// вставка нового элемента в списов по критерию:
// в возрастающем порядке
// sPtr - указатель на начало списка
// data - вставляемый элемент в список
void insert(listNode** sPtr, Data& data) 
{
	listNode* currentNode, * previousNode;
	
	//формируем узел
	listNode* newNode = new listNode;
	if (newNode != nullptr) 
	{
		//доступна ли память?
		newNode->data.address = data.address;
		newNode->next = nullptr;
	}

	//если список пустой, вставляем узел в начало
	if (*sPtr == nullptr) 
	{
		newNode->next = nullptr;//!
		*sPtr = newNode;
		return;
	}

	//вставка в середина или конец
	previousNode = nullptr;
	currentNode = *sPtr;

	if (currentNode->data.address >= newNode->data.address) 
	{
		newNode->next = currentNode;
		*sPtr = newNode;
		return;
	}

	previousNode = currentNode->next;

	while (previousNode) 
	{
		if (currentNode->data.address < newNode->data.address &&
			newNode->data.address <= previousNode->data.address) 
		{
			//вставка в середину
			currentNode->next = newNode;
			newNode->next = previousNode;
			return;
		}
		currentNode = previousNode;
		previousNode = previousNode->next;
	}

	currentNode->next = newNode;
	newNode->next = nullptr;
}
