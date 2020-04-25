#include "../headers/LinkedList.h"

using namespace std;

/**
 * This function uses 2 pointers, slowPointer moves by 1 while fast moves by 2
 * When we reaches list end slowPointer will be in the middle
 *
 * @link      https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/#Method-2
 * @since     2020-04-25
 * @param     ll     LinkedList Class Object
 * @return    int    value of middle element
 */
int getListMid(LinkedList* ll){
	Node* slowPtr = ll->head;
	Node* fastPtr = ll->head;
	int num;
	if(ll->head != NULL){
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
	LinkedList* ll = new LinkedList(arr, len);

	ll->printList();

	int mid;
	mid = getListMid(ll);
	cout<<"\n\nMiddle Element: "<<mid;
	return 0;
}

