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
    int length=0; // Length of the linked list

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
			this->addNode(arr[i], length);
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
	 *     List length: <length>
	 *     index: <i>, data: <data>, next: <next>
	 */
	void print(){
		Node *ptr = head;
		int i=0;
		cout<<"List Length:"<<length<<"\n";
		while(ptr != NULL){
			cout<<"\tindex: "<<i<<", data:"<<ptr->data<<", next:"<<ptr->next<<"\n";
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
		if(pos==0){ // At beginning
			Node *newNode = new Node(val); // Create New Node
			newNode->next = head; // Point this new node to head
			head = newNode; // Make this new node the head of list
			length++; // Increase length
		}
		else if(pos>0){ // At position from beginning
			int tempPos = 0;
			Node* tempPtr=head; // Pointer pointing the node before desired location

			// loop until we reach the desired position or end of the list
			while(tempPos!=pos-1 && tempPtr!=NULL && tempPtr->next!= NULL){
				tempPtr = tempPtr->next;
				tempPos++;
			}

			// Add node to the location
			Node* newNode = new Node(val); // Create new node
			newNode->next = tempPtr->next; // Make new node pointing to next of current node
			tempPtr->next = newNode; // Make current node pointing to new node
			length++; // Increase length
		}
		else{
			int tempPos = 0;
			Node* tempFirstPtr=head; // This will point head
			Node* tempSecondPtr=head; // This will point node pos times forward than head

			// Update Second pointer to point forward node
			while(tempPos<0-pos-1 && tempSecondPtr->next!=NULL){
				tempSecondPtr = tempSecondPtr->next;
				tempPos++;
			}

			bool moved=false; // To check whether we are adding node at beginning

			// Move both pointers until second pointer reaches at the end of list
			while(tempSecondPtr->next!= NULL){
				moved=true;
				tempFirstPtr = tempFirstPtr->next;
				tempSecondPtr = tempSecondPtr->next;
			}

			// Add node
			Node* newNode = new Node(val); // Create new node
			
			if(!moved && tempPos+pos+1<0){ // Node is added at the beginning
				newNode->next = tempFirstPtr;
				head = newNode;
			}
			else{ // Node is added not at the beginnig
				newNode->next = tempFirstPtr->next;
				tempFirstPtr->next = newNode;
			}
			length++; // Increase length
		}
	}
};

int main(){
	LinkedList* ll = new LinkedList(2);
	ll->addNode(5);
	ll->addNode(3);
	ll->addNode(1,1);
	cout<<"\nList 1: Initialized with value\n";
	ll->print();
	delete ll;

	int arr[] = {1,2,3,4,6,8};
	int len = sizeof(arr)/sizeof(arr[0]);
	LinkedList* ll2 = new LinkedList(arr, len);
	cout<<"\nList 2: Initialized with array of values\n";
	ll2->print();
	delete ll2;

	LinkedList* ll3 = new LinkedList();
	ll3->addNode(3);
	ll3->addNode(4);
	ll3->addNode(5,6);
	ll3->addNode(1,1);
	ll3->addNode(9,-1);
	ll3->addNode(12,-10);
	cout<<"\nList 3: Initialized without value and added element at end\n";
	ll3->print();
	delete ll3;
	
    return 0;
}
