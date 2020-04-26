#include "../headers/LinkedList.h"

using namespace std;

/**
 * This function uses 2 pointers, slowPointer moves by 1 while fast moves by 2
 * When we reaches list end slowPointer will be in the middle
 *
 * @link      https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/#Method-2
 * @since     2020-04-25
 * @param     head     Node Class Object having head pointer of linked list
 * @return    int      value of middle element
 */
int getListMid(Node* head){
	Node* slowPtr = head;
	Node* fastPtr = head;
	int num;
	if(head != NULL){
		while(fastPtr!=NULL && fastPtr->next!=NULL){
			fastPtr = fastPtr->next->next;
			slowPtr = slowPtr->next;
		}
		num = slowPtr->data;
	}
	return num;
}

int main()
{
	int arr[] = {1,2,3,4,6,8,10,12,13};
	int len = sizeof(arr)/sizeof(arr[0]);
	LinkedList ll(arr, len);

	ll.printList();

	int mid;
	mid = getListMid(ll.head);
	cout<<"\n\nMiddle Element: "<<mid;
	// delete ll;
	return 0;
}

