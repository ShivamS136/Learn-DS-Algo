#include "../headers/LinkedList.h"

using namespace std;

/**
 * This method finds the length of the loop present in the link list
 * Uses Floyd's cycle-finding algorithm
 *
 * @link      Floyd's cycle-finding algorithm     https://en.wikipedia.org/wiki/Cycle_detection#Floyd's_Tortoise_and_Hare 
 * @link      GFG:Detect loop in a linked list    https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/
 * @param     head    Node class pointer pointing head of linked list
 * @return    int     Length of the loop
 */
int findLoopLength(Node* head){
	// Detect Loop
	Node* slowPtr = head;
	Node* fastPtr = head;

	Node* loopNode = NULL;
	int loopLength = 0;

	while(fastPtr!=NULL && fastPtr->next!=NULL){
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		if(slowPtr==fastPtr){
			loopNode = slowPtr;
			break;
		}
	}

	// Find length of loop
	if(loopNode!=NULL){
		do
		{
			++loopLength;
			slowPtr = slowPtr->next;
		} while (loopNode!=slowPtr);
	}

	return loopLength;
}

int main()
{
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(4);
	Node* n4 = new Node(5);
	Node* n5 = new Node(8);
	
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n2;

	cout<<findLoopLength(n1);
	delete n1,n2,n3,n4,n5;
	return 0;
}