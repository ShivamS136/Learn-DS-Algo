# Linked List
In this folder we'll see implementation of Linked List using `C++` classes. Later programs are the algorithm problems based on Linked List. In the later programs header file is included for linked list.

## What is Linked List?
Linked list is a dynamic data structure in which we keep data in nodes and each node contains two values. First value is the unit data to be stored in the node and second value is a pointer to the next node. So there is a one way connection in all the nodes.

## Coding guide

#### Create a linked list
**File:** [LinkedList.cpp](LinkedList.cpp)  
There are three ways to do that:
* **Empty Linked List:** 

```cpp
  // This will create empty linked list with head=NULL

  // Just create and object with default constructor (Heap Memory)
  LinkedList ll = new LinkedList(); // Don't forget to call "delete ll;" at the end

  // Without "new" keyword (Stack memory)
  LinkedList ll();
```

* **Linked List with one node:**

```cpp
  // This will create linked with a single node having data=2, next=NULL and head pointing this node
  
  LinkedList ll = new LinkedList(2);
  // ll=2->NULL
 ```

* **Linked List with multiple values:**

```cpp
  // This will create Linked list with 6 nodes with data and order same as the array provided
  // and head pointing to first node, which is data=0 node in this case

  int arr[] = {0,1,2,3,4,5};
  int len = sizeof(arr)/sizeof(arr[i]);

  LinkedList ll = new LinkedList(arr, len);
  // ll=0->1->2->3->4->5->NULL
 ```

---

#### Linked List operations:
* **1. Add element:** 

```cpp
  LinkedList ll = new LinkedList(1);
  // ll=1->NULL

  ll->addNode(2); // At beginning, default
  // ll=2->1->NULL

  ll->addNode(5,1); // At 2nd position from the beginning
  // ll=2->5->1->NULL

  ll->addNode(10,-2); // At 2nd position from the end
  // ll=2->5->10->1->NULL
```

* **2. Remove Node:** 

```cpp
   int arr[] = {0,1,2,3,4,5,6,7};
   int len = sizeof(arr)/sizeof(arr[i]);
   LinkedList ll = new LinkedList(arr, len);
   // ll=0->1->2->3->4->5->6->7->NULL

   int dt;

   dt = ll->removeNode(); // Removes first element and returns it's data (Default)
   // dt=0, ll=1->2->3->4->5->6->7->NULL

   dt = ll->removeNode(1);  // Removes second element and returns it's data
   // dt=2, ll=1->3->4->5->6->7->NULL

   dt = ll->removeNode(-2);  // Removes second last element and returns it's data
   // dt=6, ll=1->3->4->5->7->NULL
```

* **3. Get data of a node situated at particular position:** 

```cpp
  int arr[] = {0,1,2,3,4,5,6,7};
  int len = sizeof(arr)/sizeof(arr[i]);
  LinkedList ll = new LinkedList(arr, len);
  // ll=0->1->2->3->4->5->6->7->NULL

  int dt;

  dt = ll->getData(); // Returns first element's data (Default)
  // dt=0
  dt = ll->getData(1); // Data of second element
  // dt=1
  dt = ll->getData(-2); // Data of second last element
  // dt=6
```

> In the above three methods if you choose a position out of bind then position will be considered as head if position<0 and tail if position>0

* **4. Print complete list in output window:**

```cpp
  int arr[] = {2,4,6};
  int len = sizeof(arr)/sizeof(arr[i]);
  LinkedList ll = new LinkedList(arr, len);
  // ll=0->1->2->NULL

  ll->printList();
  /*
    OUTPUT:
	  List length: 3
	  index: 0, data: 2, next: 0xf414c0
	  index: 1, data: 4, next: 0xf40d08
	  index: 2, data: 6, next: 0
  */
```

---

## Algorithms:

#### 1. Find middle element of a linked list
- **File:** [findMiddle.cpp](findMiddle.cpp)
- **Reference:** [GFG: Find the middle of a given linked list in C and Java (Method 2)](https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/) 