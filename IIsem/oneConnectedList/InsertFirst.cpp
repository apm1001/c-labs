#include "List.h"



// ������� ������� ������� �������� � ������ ������
// sPtr - ������ ������� ������ ������
// data - ������ ��� ������ � ����� ����

void insertFirst(listNode** sPtr, Data& data) 
{
	listNode* newNode = new listNode;

	newNode->data.address = data.address;
	newNode->next = *sPtr;

	*sPtr = newNode;
}