#include "../headers/LinkedList.h"

using namespace std;

void reverseList(LinkedList* ll){
	Node *curr, *next, *prev=NULL;
	curr = next = ll->head;
	while(curr!=NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	ll->head = prev;
}

int main()
{
	int arr[] = {1,2,3,4,6,8,10,12,13};
	int len = sizeof(arr)/sizeof(arr[0]);
	LinkedList ll(arr, len);
	cout<<"Original List:\n";
	ll.printList();

	reverseList(&ll);

	cout<<"\n\nReversed List:\n";
	ll.printList();
	// delete ll;
	return 0;
}