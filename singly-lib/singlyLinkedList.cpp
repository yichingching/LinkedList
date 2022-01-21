#include "singlyLinkedList.hpp"

//---------------------------------------
// 		    Single Linked List
//---------------------------------------
SingleLinkedList::SingleLinkedList()
{
	ListNode* head = new ListNode(-1);
};

SingleLinkedList::~SingleLinkedList()
{
	if (hasCycle() == true)
		deleteCycleList();
	else
		deleteSingleList();
};

void SingleLinkedList::createSingleList(std::vector<int> vals)
{
	head = NULL;
	ListNode* posPtr = head;
	for(int i = vals.size(); i > 0; i--)
	{
		ListNode* newNode = new ListNode(vals[i-1]);
		newNode->next = head;
		head = newNode;
	}
}

void SingleLinkedList::createCycleList(std::vector<int> vals, int pos)
{
	head = NULL;
	ListNode* posPtr = head;
	for(int i = vals.size(); i > 0; i--)
	{
		ListNode* newNode = new ListNode(vals[i-1]);
		newNode->next = head;
		head = newNode;

		if (i == vals.size()-pos)
			posPtr = newNode;
	}

	// move curr to the end of the list
	ListNode* curr = head;
	while (curr->next != NULL)
		curr = curr->next;
	
	curr->next = posPtr; // cycle the list to pos node
}

void SingleLinkedList::deleteSingleList()
{
	if (head == NULL)
		return;
	
	while (head != NULL)
	{
		ListNode* ptr = head;
		head = head->next;
		delete (ptr);
	}
}

void SingleLinkedList::deleteCycleList()
{
	if (head == NULL)
		return;

	std::vector<ListNode*> isVisited;
	while (head != NULL) 
	{
		ListNode* ptr = head;
		
		for (int i = 0; i < isVisited.size(); i++)
		{
			if (isVisited[i] == head)
			{
				isVisited.clear();
				return;
			}
		}

		isVisited.push_back(head);
		head = head->next;
		delete (ptr);
	}
}

bool SingleLinkedList::hasCycle()
{
	if (head == NULL)
		return false;

	ListNode* curr = head;
	std::vector<ListNode*> isVisited;
	while (curr != NULL) 
	{
		for (int i = 0; i < isVisited.size(); i++)
		{
			if (isVisited[i] == curr)
				return true;
		}
		
		isVisited.push_back(curr);
		curr = curr->next;
	}

	return false;
}

void SingleLinkedList::printSingleList()
{
	ListNode* curr = head;
	
	while (curr != NULL)
	{
		std::cout << "[" << curr->val << "]";
		curr = curr->next;
	}
	std::cout << std::endl;
}