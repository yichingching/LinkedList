#include <iostream>
#include <vector>

//---------------------------------------
// 		    Single Linked List
//---------------------------------------
class SingleLinkedList 
{
public:
	//---------------------------------------
	//   Definition for singly-linked list
	//---------------------------------------
	struct ListNode
	{
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};

	SingleLinkedList();
	~SingleLinkedList();

	void createSingleList(std::vector<int> vals);
	void createCycleList(std::vector<int> vals, int pos = -1);
	void deleteSingleList();
	void deleteCycleList();
	bool hasCycle();
	void printSingleList();

private:
	ListNode* head;
};