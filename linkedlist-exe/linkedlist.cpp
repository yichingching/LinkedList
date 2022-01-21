#include "singlyLinkedList.hpp"

//---------------------------------------
// 		    	Linked List
//---------------------------------------
int main()
{
	std::cout << "project version:" << LINKED_LIST_VERSION << std::endl;
	
	// Input: head = [3,2,0,-4], pos = 1
	// Output: true
	// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
	std::vector<int> input = {3,2,0,-4};
	int pos = 1;
    SingleLinkedList* singleLinkedList = new SingleLinkedList();

	// Single Linked List
	std::cout << "Create a single linked list..." << std::endl;
	singleLinkedList->createSingleList(input);
	std::cout << "single linked list: "; 
	singleLinkedList->printSingleList();
	std::cout << "Delete a single linked list..." << std::endl;
	singleLinkedList->deleteSingleList();
	std::cout << "Is linked list with cycle: " << singleLinkedList->hasCycle() << std::endl;

	// Single Linked List with cycle
	std::cout << "Create a single linked list with cycle..." << std::endl;
	singleLinkedList->createCycleList(input, pos);
	std::cout << "Is linked list with cycle: " << singleLinkedList->hasCycle() << std::endl;
	std::cout << "Delete a single linked list with cycle..." << std::endl;
	delete (singleLinkedList);

	return 0;
}