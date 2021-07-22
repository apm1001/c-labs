#include <iostream>
#include "List.h"

using namespace std;


//����� (��������) ������
void printList(listNode* sPtr);
//���������� ������ �������� � ������ ������
void insertFirst(listNode** sPtr, Data& data);
void insert(listNode** sPtr, Data& data);
//�������� �������� �� ������
void deleteNode(listNode** sPtr, Data& data);
// �������� (�������) ����� ������
void clear(listNode** sPtr);
//����� ������� ��������� � ������ ��������
listNode* findNode(listNode* sPtr, Data& data);

int main() 
{
	listNode* startNode = nullptr;
	startNode = new listNode;		//�������� ������ ��� ������� ������

	startNode->data.address = 1;
	startNode->next = nullptr;		// ��������� �� ��������� �������
	//(*startPtr).d.a = 1;

	listNode* currentNode = nullptr;
	currentNode = startNode;

	currentNode = new listNode;
	startNode->next = currentNode;
	startNode->data.address = 2;
	startNode->next = nullptr;

	/*
		currentPtr->next=new listNode;
		currentPtr=currentPtr->next;

		��� � ��� ���� ������� ���������� �������� ����� ����������� ��� ������ ������� ������ ��� ������������� startPtr 
	*/

	// ������� ������ �� �����
	printList(startNode);

	Data data = { 11 };

	insertFirst(&startNode, data);
	printList(startNode);

	data = { 0 };
	insert(&startNode, data);
	data = { 5 };

	insert(&startNode, data);
	printList(startNode);

	//system("pause>null");
	return 0;
}