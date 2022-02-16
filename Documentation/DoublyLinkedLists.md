**Devin Brousard**  
s218014  
Code Design and Data Structures  
Doubly Linked List

## **I. Requirements:**  
### 1. Description of Problem: 
* **Name:** Doubly Linked List
* **Problem Statement:**   
    * Implement a Double-Linked List
* **Problem Specifications:**  
    * Successful creation of a project which implements and demonstrates a doubly linked list
      * The created program must demonstrate a custom sorting algorithm 
    * Project submitted as an executable binary file that can be run external to an IDE  
    * Source code and project files also submitted for review  
### 2. Input Information:
* The demonstration will move on to the next step when the user presses any key on their keyboard.
### 3. Output Information:
* The program will give demonstrations of the functionality of the doubly linked list
  
## **II. Design:**
### 1. System Architecture: 
* The doubly linked list works by having a List class that stores nodes. It accesses these nodes by using pointers to the first or last nodes and fetching nodes' next node variable. Each node keeps track of the data inside of it, the node that came before it, and the node that comes after it. Iterators are used to safely access data inside the node without altering the list.
### 2. Object Information:
*  File name: Iterator.h (templated: typename T)
    * Name: m_currentNode(Node&lt;T>*)
        * Description: A pointer to the node that the iterator is focusing on
        * Visibility: Private
    * Name: Iterator(Constructor)
        * Description: Called when a new iterator is created
        * Visibility: Public
        * Arguments: None
    * Name: Iterator(Constructor)
        * Description: Creates a new iterator that points at the given node
        * Visibility: Public
        * Arguments: Node&lt;T>* node
    * Name: operator ++()
        * Description: Makes this iterator point the current node's next node
        * Visibility: Public
        * Arguments: None
    * Name: operator --();
        * Description: Makes this iterator point at the current node's previous node
        * Visibility: Public
        * Arguments: None
    * Name: operator ==()
        * Description: Checks to see if two iterators are equal by comparing their current nodes
        * Visibility: Public
        * Arguments: const Iterator&lt;T>& iterator(Takes in a reference to another iterator)
    * Name: operator !=()
        * Description: Checks tosee if two iterators are equal by comparing their current nodes
        * Visibility: Public
        * Arguments: const Iterator&lt;T>& iterator(Takes in a reference to another iterator)
    * Name: operator *()
        * Description: Returns the value that the iterator's current node holds
        * Visibility: Public
        * Arguments: None
*  File name: Node.h (templated: typename T)
    * Name: nextNode(Node&lt;T>*)
        * Description: A pointer to the next node in the linked list
        * Visibility: Public
    * Name: previousNode(Node&lt;T>*)
        * Description: A pointer to the previous node in the linked list
        * Visibility: Public
    * Name: data(T)
        * Description: The data that the node holds
        * Visibility: Public
    * Name: Node()
        * Description: Called when a new node is created.
        * Visibility: Public
        * Arguments: None
    * Name: Node()
        * Description: Sets the value of the node to the value given on creation
        * Visibility: Public
        * Arguments: T (The value that will be given to the node)
*  File name: List.h (templated: typename T)
    * Name: List()
        * Description: Called when a new list is created
        * Visibility: Public
        * Arguments: None
    * Name: List()
        * Description: Copies the values of one list onto another on creation
        * Visibility: Public
        * Arguments: const List&lt;T>& otherList(The list that is copied)
    * Name: clearList()
        * Description: Deletes all nodes in the list
        * Visibility: Public
        * Arguments: None
    * Name: begin(Iterator&lt;T>)
        * Description: Returns an iterator that points at the start of the list
        * Visibility: Public
        * Arguments: None
    * Name: end(Iterator&lt;T>)
        * Description:Returns an iterator that points at the last node of the list
        * Visibility: Public
        * Arguments: None
    * Name: contains(const bool)
        * Description: Checks to see if a node contains the value given
        * Visibility: Public
        * Arguments: const T object(The value that is searched for in the list)
    * Name: pushFront()
        * Description: Adds a new node at the beginning of the list with the given value
        * Visibility: Public
        * Arguments: const T& value(The value of the node that will be added to the list)
    * Name: pushBack()
        * Description: Adds a new node to the end of hte list with the given value 
        * Visibility: Public
        * Arguments: const T& value(THe value of the ndoe that will be added to the list)
    * Name: insert(bool)
        * Description: Adds a new node with the given value at the given index
        * Visibility: Public
        * Arguments: const T& value(The value that the given node will have), int index(the index that the node will be inserted)
    * Name: remove(bool)
        * Description: Removes the first node with the given index. Returns true if a node is deleted
        * Visibility: Public
        * Arguments: const T& value(The value of the node that will be deleted)
    * Name: print(bool) const
        * Description: Prints every node's data
        * Visibility: Public
        * Arguments: None
    * Name: initialize()
        * Description: Sets the list's variables back to default 
        * Visibility: Public
        * Arguments: None
    * Name: isEmpty(bool) const
        * Description: Returns whether or not the list has any nodes in it
        * Visibility: Public 
        * Arguments: none
    * Name: getData(bool)
        * Description: Sets the given iterator to point at a node at the given index
        * Visibility: Public
        * Arguments: Iterator&lt;T>& iterator(Sets iterator to point at a node at the given index), int index(The index of the node that the iterator will point to)
    * Name: getLength() const
        * Description: Returns the amount of nodes in the list
        * Visibility: Public
        * Arguments: None
    * Name: operator =(const List&lt;T>&)  
        * Description: Copies values of another list onto this one
        * Visibility: Public 
        * Arguments: const List&lt;T>& otherList(The list that will have its values copied)
    * Name: sort()
        * Description: Sorts the nodes in the list
        * Visibility: Public
        * Arguments: None
    * Name: remove(bool)
        * Description: Used to remove a node at a certain index
        * Visibility: Private
        * Arguments: const T& value(The value of the node that will be deleted), int index(The index of the node that will be deleted)
    * Name: m_firstNode(Node&lt;T>*)
        * Description: First node in the list
        * Visibility: Private
    * Name: m_lastNode(Node&lt;T>*)
        * Description: Last node in the list
        * Visibility: Private
   * Name: m_nodeCount(int)
        * Description: Number of nodes in the list
        * Visibility: Private