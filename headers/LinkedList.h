#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(){};
    Node(int d){
        data = d;
        next = NULL;
    }
};

class LinkedList{
public:
    Node *head = NULL;
    int length=0;
	LinkedList(){};
	LinkedList(int val){
		this->addNode(val);
	}
	LinkedList(int arr[], int len){
		for(int i = 0; i < len; ++i)
		{
			this->addNode(arr[i], length);
		}
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
	void printList(){
		Node *ptr = head;
		int i=0;
		cout<<"List Length:"<<length<<"\n";
		while(ptr != NULL){
			cout<<"\tindex: "<<i<<", data:"<<ptr->data<<", next:"<<ptr->next<<"\n";
			i++;
			ptr = ptr->next;
		}
	}
	void addNode(int val, int pos=0){
		if(pos==0 || head==NULL){
			Node *newNode = new Node(val); 
			newNode->next = head; 
			head = newNode;
		}
		else if(pos>0){ 
			int tempPos = 0;
			Node* tempPtr=head; 
			
			while(tempPos!=pos-1 && tempPtr->next!= NULL){
				tempPtr = tempPtr->next;
				tempPos++;
			}
			
			Node* newNode = new Node(val); 
			newNode->next = tempPtr->next; 
			tempPtr->next = newNode;
		}
		else{
			int tempPos = 0;
			Node* firstPtr=head; 
			Node* secondPtr=head; 
			
			while(tempPos<0-pos-1 && secondPtr->next!=NULL){
				secondPtr = secondPtr->next;
				tempPos++;
			}
			bool moved=false; 
			
			while(secondPtr->next!= NULL){
				moved=true;
				firstPtr = firstPtr->next;
				secondPtr = secondPtr->next;
			}
			
			Node* newNode = new Node(val); 
			
			if(!moved && tempPos+pos+1<0){ 
				newNode->next = firstPtr;
				head = newNode;
			}
			else{ 
				newNode->next = firstPtr->next;
				firstPtr->next = newNode;
			}
		}
		++length; 
	}
	int getData(int pos=0){
		int retData;
		int tempPos=0;
		if (head==NULL)
		{
			return retData;
		}
		if (pos>=0)
		{
			Node* tempPtr = head;
			while(tempPos<pos && tempPtr->next!=NULL){
				tempPtr=tempPtr->next;
				tempPos++;
			}
			retData = tempPtr->data;
		}
		else{
			Node* firstPtr=head;
			Node* secondPtr=head;
			while(tempPos<0-pos-1 && secondPtr->next!=NULL){
				secondPtr = secondPtr->next;
				tempPos++;
			}
			while(secondPtr->next!=NULL){
				secondPtr=secondPtr->next;
				firstPtr=firstPtr->next;
			}
			retData = firstPtr->data;
		}
		return retData;
	}

	int removeNode(int pos=0){
		int retData;
		if(head==NULL){
			return retData;
		}
		if(pos==0){
			Node* tempNode = head;
			retData = tempNode->data;
			head = head->next;
			delete tempNode;
		}
		else if(pos>0){
			int tempPos = 0;
			Node* tempPtr=head; 
			
			while(tempPos!=pos-1 && tempPtr!=NULL && tempPtr->next!= NULL){
				tempPtr = tempPtr->next;
				tempPos++;
			}
			Node* tempNode = tempPtr->next;
			tempPtr->next = tempNode->next;
			retData = tempNode->data;
			delete tempNode;
		}
		else{
			Node* firstPtr = head;
			Node* secondPtr = head;
			int tempPos=0;
			while(tempPos<0-pos && secondPtr!=NULL && secondPtr->next!=NULL){
				secondPtr = secondPtr->next;
				tempPos++;
			}
			bool moved = false;
			while(secondPtr->next!=NULL){
				moved=true;
				secondPtr=secondPtr->next;
				firstPtr=firstPtr->next;
			}
			Node* tempNode;
			if(!moved && tempPos+pos<0){
				tempNode = head;
				head = head->next;
			}
			else{
				tempNode = firstPtr->next;
				firstPtr->next = tempNode->next;
			}
			retData = tempNode->data;
			delete tempNode;
		}
		--length;
		return retData;
	}
};
