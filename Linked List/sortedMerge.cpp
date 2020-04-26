#include "../headers/LinkedList.h"

using namespace std;

/**
 * This is iterative method to solve the problem
 * Result is merged and gets held by list 1, list 2 becomes empty
 *
 * @param     l1    Linked List 1 (At the end: Merged list)
 * @param     l2    Linked List 2 (At the end: empty list)
 */
void sortedMerge(LinkedList* l1, LinkedList* l2){
	Node* t1 = l1->head;
	Node* t2 = l2->head;
	Node* temp = NULL;

	while(t1!=NULL && t2!=NULL){
		if(t1->data <= t2->data){
			if(temp==NULL){
				l1->head = t1;
				temp=t1;
			}
			else{
				temp->next = t1;
				temp=temp->next;
			}
			t1 = t1->next;
		}
		else{
			if(temp==NULL){
				l1->head = t2;
				temp=t2;
			}
			else{
				temp->next = t2;
				temp=temp->next;
			}
			t2 = t2->next;
		}
	}
	if(t1!=NULL){
		temp->next = t1;
	}
	else{
		temp->next=t2;
	}
	l2->head=NULL;
}

/**
 * This is recursive method to solve the problem
 *
 * @param     a    Node pointer
 * @param     b    Node Pointer
 * @return    Node pointer
 */
Node* sortedMergeRec(Node* a, Node* b){
	Node* result = NULL;

	if (a == NULL)  
        return(b);  
    else if (b == NULL)  
        return(a);

    if (a->data <= b->data)  
    {  
        result = a;  
        result->next = sortedMergeRec(a->next, b);  
    }  
    else
    {  
        result = b;  
        result->next = sortedMergeRec(a, b->next);  
    }  
    return(result);
}

int main()
{
	int arr1[] = {1,3,4,6};
	int len = sizeof(arr1)/sizeof(arr1[0]);
	LinkedList* l1 = new LinkedList(arr1, len);

	int arr2[] = {2,4,5,7,9};
	len = sizeof(arr2)/sizeof(arr2[0]);
	LinkedList* l2 = new LinkedList(arr2, len);

	// Iterative Method
	sortedMerge(l1, l2);

	// Recursive Method
	/*
	l1->head = sortedMergeRec(l1->head, l2->head);
	l2->head = NULL;
	*/

	l1->printList();
	l2->printList();
	delete l1,l2;
	return 0;
}