#include <bits/stdc++.h>

using namespace std;

/**
 * This class is for creating a single node
 *
 * Constructor accepts value too which is not mandatory
 */
class Node{
public:
    int data; // Data of the node
    Node *next; // Node Pointer value to point to next node

    /**
     * Default constructor
     */
    Node(){};

    /**
     * Parameterized constructor with accepting value of node
     */
    Node(int d){
        data = d;
        next = NULL;
    }
};

/**
 * This class is for linked list and methods related to it, It can be initialized with a single value OR array of values OR without values
 *
 * @methods:
 *     - Default Constructor
 *     - Parameterized Constructor accepting value of one node
 *     - Parameterized constructor accepting array of all the values
 *     - print() : To print all the elements inside linked list from first to last
 *     - addNode() : To add node in the linked list at any place
 */
class LinkedList{
public:
    Node *head = NULL; // Node Pointer pointing head of the linked list

    /**
     * Default constructor
     */
	LinkedList(){};

	/**
	 * Parameterized constructor accepting value of first node
	 */
	LinkedList(int val){
		this->addNode(val);
	}

	/**
	 * Paramterized constructor accepting array of values for nodes
	 */
	LinkedList(int arr[], int len){
		for(int i = 0; i < len; ++i)
		{
			this->addNode(arr[i], i);
		}
	}

	/**
	 * Desctructor to free the memory occupied by the linked list and its nodes
	 */
	~LinkedList(){
		Node* temp;

		// Iterate until list becomes empty
		while (head != NULL)
		{		
			temp = head;
			head = head->next;
			delete temp;
		}
	}

	/**
	 * This method print the complete linked list in below manner:
	 *     index: <i>, data: <data>, next: <next>
	 */
	void printList(){
		Node *ptr = head;
		int i=0;
		while(ptr != NULL){
			cout<<"index: "<<i<<", data:"<<ptr->data<<", next:"<<ptr->next<<"\n";
			i++;
			ptr = ptr->next;
		}
	}

	/**
	 * This method adds node at desired location as per below logic
	 *     - At beginning(default): Using pos=0
	 *     - At any place from the beginning: Using pos>=0
	 *     - At any place from the end: Using pos<0
	 *     
	 * @param    int    val    Value of data of node
	 * @param    int    pos    Position of node to be added
	 */
	void addNode(int val, int pos=0){
		if(pos==0 || head==NULL){ // At beginning
			Node *newNode = new Node(val); // Create New Node
			newNode->next = head; // Point this new node to head
			head = newNode; // Make this new node the head of list
		}
		else if(pos>0){ // At position from beginning
			int tempPos = 0;
			Node* tempPtr=head; // Pointer pointing the node before desired location

			// loop until we reach the desired position or end of the list
			while(tempPos!=pos-1 && tempPtr->next!= NULL){
				tempPtr = tempPtr->next;
				tempPos++;
			}

			// Add node to the location
			Node* newNode = new Node(val); // Create new node
			newNode->next = tempPtr->next; // Make new node pointing to next of current node
			tempPtr->next = newNode; // Make current node pointing to new node
		}
		else{
			int tempPos = 0;
			Node* firstPtr=head; // This will point head
			Node* secondPtr=head; // This will point node pos times forward than head

			// Update Second pointer to point forward node
			while(tempPos<0-pos-1 && secondPtr->next!=NULL){
				secondPtr = secondPtr->next;
				tempPos++;
			}

			bool moved=false; // To check whether we are adding node at beginning

			// Move both pointers until second pointer reaches at the end of list
			while(secondPtr->next!= NULL){
				moved=true;
				firstPtr = firstPtr->next;
				secondPtr = secondPtr->next;
			}

			// Add node
			Node* newNode = new Node(val); // Create new node
			
			if(!moved && tempPos+pos+1<0){ // Node is added at the beginning
				newNode->next = firstPtr;
				head = newNode;
			}
			else{ // Node is added not at the beginnig
				newNode->next = firstPtr->next;
				firstPtr->next = newNode;
			}
		}
	}

	/**
	 * This method return at desired location as per below logic
	 *     - At beginning(default): Using pos=0
	 *     - At any place from the beginning: Using pos>=0
	 *     - At any place from the end: Using pos<0
	 *     
	 * @param    int    pos    Position of node to be added
	 * @return   int    data at the node
	 */
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

	/**
	 * This method removes node at desired location as per below logic
	 *     - At beginning(default): Using pos=0
	 *     - At any place from the beginning: Using pos>=0
	 *     - At any place from the end: Using pos<0
	 *     
	 * @param    int    pos    Position of node to be added
	 * @return   int    data of the removed node
	 */
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
			Node* tempPtr=head; // Pointer pointing the node before desired location

			// loop until we reach the desired position or end of the list
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
		return retData;
	}
};

int main(){
	LinkedList* ll = new LinkedList(2);
	ll->addNode(5);
	ll->addNode(1,1);
	cout<<"\nList 1: Initialized with value\n";
	ll->printList();
	delete ll;

	int arr[] = {1,2,3,4,6,8};
	int len = sizeof(arr)/sizeof(arr[0]);
	LinkedList* ll2 = new LinkedList(arr, len);
	cout<<"\nRemoved: "<<ll2->removeNode(-2);
	cout<<"\nList 2: Initialized with array of values\n";
	ll2->printList();
	delete ll2;

	LinkedList* ll3 = new LinkedList();
	ll3->addNode(3);
	ll3->addNode(4);
	ll3->addNode(5,6);
	ll3->addNode(1,1);
	cout<<"\nRemoved: "<<ll3->removeNode(2);
	ll3->addNode(9,-1);
	ll3->addNode(12,-10);
	cout<<"\nList 3: Initialized without value and added element at end\n";
	ll3->printList();
	cout<<"\n2nd last ele: "<<ll3->getData(-2);
	delete ll3;
	
    return 0;
}
