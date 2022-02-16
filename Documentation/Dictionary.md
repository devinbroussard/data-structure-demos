**Devin Brousard**  
s218014  
Code Design and Data Structures  
Key/Value Pair Dictionary
  
## **I. Design:**
### 1. System Architecture: 
* The doubly linked list works by having a List class that stores nodes. It accesses these nodes by using pointers to the first or last nodes and fetching nodes' next node variable. Each node keeps track of the data inside of it, the node that came before it, and the node that comes after it. Iterators are used to safely access data inside the node without altering the list.
### 2. Object Information:
*  File name: Iterator.h (templated: typename T)
    * Name: m_currentNode(Node&lt;T>*)
        * Description: A pointer to the node that the iterator is focusing on
        * Visibility: Private