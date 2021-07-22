#pragma once

struct Data 
{
	int address;
};


struct listNode
{
	Data data;
	listNode* next;
	listNode* previus;
};