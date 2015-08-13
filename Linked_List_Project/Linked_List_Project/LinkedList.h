#pragma once
#include <iostream>

using namespace std;


class ListNode
{
public:
	int nodeValue;
	ListNode *next;

	ListNode() { nodeValue = 0; next = NULL; }
};


class LinkedList
{
private:
	ListNode node;
	int count;
public:
	LinkedList();
	~LinkedList();
};

