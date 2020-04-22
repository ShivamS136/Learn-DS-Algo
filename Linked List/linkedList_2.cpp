#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

class LinkedList{
public:
    Node *head = NULL;
    int length=0;

	LinkedList(int val){
		Node *newNode = new Node(val);
		head = newNode;
		length++;
	}

	~LinkedList(){
		Node* temp;

		while (head != NULL)
		{		
			temp = head;
			head = head->next;
			delete temp;
		}
	}

	void print(){
		Node *ptr = head;
		int i=0;
		while(ptr != NULL){
			cout<<"Key: "<<i<<" data:"<<ptr->data<<" next:"<<ptr->next<<"\n";
			i++;
			ptr = ptr->next;
		}
	}

	LinkedList(int arr[], int len){
		Node* lastNode;
		for (int i = 0; i < len; ++i)
		{
			Node* temp = new Node(arr[i]);
			if(head == NULL){
				head = temp;
				lastNode = temp;
			}
			else{
				lastNode->next = temp;
				lastNode = temp;
			}
			length++;
		}
	}

	void prepend(int d){
		Node *newNode = new Node(d);
		newNode->next = head;
		head = newNode;
		length++;
	}
};

int main(){
	LinkedList* ll = new LinkedList(2);
	ll->prepend(5);
	ll->prepend(3);
	ll->prepend(1);
	ll->print();
	delete ll;

	int arr[] = {1,2,3,4,6,8};
	int len = 6;
	LinkedList* ll2 = new LinkedList(arr, len);
	ll2->print();
	delete ll2;
    return 0;
}
