#include "List.h"

// ������� ������ �������� � ������ �� ��������:
// � ������������ �������
// sPtr - ��������� �� ������ ������
// data - ����������� ������� � ������
void insert(listNode** sPtr, Data& data) 
{
	listNode* currentNode, * previousNode;
	
	//��������� ����
	listNode* newNode = new listNode;
	if (newNode != nullptr) 
	{
		//�������� �� ������?
		newNode->data.address = data.address;
		newNode->next = nullptr;
	}

	//���� ������ ������, ��������� ���� � ������
	if (*sPtr == nullptr) 
	{
		newNode->next = nullptr;//!
		*sPtr = newNode;
		return;
	}

	//������� � �������� ��� �����
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
			//������� � ��������
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
