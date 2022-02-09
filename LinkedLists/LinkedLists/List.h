#pragma once
#include "Node.h"
#include "Iterator.h"
#include <iostream>

template<typename T>
class List {
public:
	List();
	List(const List<T>& otherList);
	~List();

	void clearList(); //Deletes all nodes in the list

	Iterator<T> getFirstNode() const; //Returns the node at the start of the list
	Iterator<T> getLastNode() const; //Returns the ndoe at the end of the list
	const bool checkIfIncludes(const T object); // Checks to see if the given item is in the list

	void addToFront(const T& value); //Adds a new node at the beginning of the list
	void addToBack(const T& value); //Adds a new node to the end of the list
	bool insert(const T& value, int index); //Adds a new node at the given index
	bool remove(const T& value); //Removes the first node with the given value

	void print() const; //Prints every node's data
	void initialize();  //Set the default values for the first node pointer, the last node pointer, and the node count
	bool isEmpty() const; //Returns whether or not the list has any nodes in it
	bool getData(Iterator<T>& iterator, int index); //Sets the given backwardsIterator to point at a node at the given index
	int getLength() const; //Returns the amount of nodes in the list

	const List<T>& operator =(const List<T>& otherList); //Sets a list to be equal to another
	void sort(); //Sorts the nodes in the list 

private:
	bool remove(const T& value, int index);

	Node<T>* m_firstNode; //First node in the list
	Node<T>* m_lastNode; //Last node in the list
	int m_nodeCount; //Number of nodes in the list
};

template<typename T>
inline List<T>::List() {
	initialize();
}

template<typename T>
inline List<T>::List(const List<T>& otherList) {
	m_firstNode = otherList.m_firstNode;
	m_lastNode = otherList.m_lastNode;
	m_nodeCount = otherList.m_nodeCount;
}

template<typename T>
inline List<T>::~List()
{
	clearList();
}

template<typename T>
inline void List<T>::clearList() {
	Node<T>* currentNode = m_firstNode;
	Node<T>* nextNode;

	for (int i = 0; i < getLength(); i++) {
		nextNode = currentNode->nextNode; //Holds the current node's next in a temporary variable...
		delete currentNode;
		currentNode = nextNode; //..And sets the current node to be the one stored in the temporary variable
	}

	initialize();
}

template<typename T>
inline Iterator<T> List<T>::getFirstNode() const{
	Iterator<T> iterator(m_firstNode); //Creates an backwardsIterator that points at the first node
	return iterator;
}

template<typename T>
inline Iterator<T> List<T>::getLastNode() const {
	Iterator<T> iterator(m_lastNode->nextNode); //Creates an backwardsIterator that points at the last node
	return iterator;
}

template<typename T>
inline const bool List<T>::checkIfIncludes(const T data)
{
	//Goes through each node using the backwardsIterator and check to see if the data at the backwardsIterator's current node matches the given data
	for (Iterator<T> iterator(getFirstNode()); iterator != getLastNode(); ++iterator) { 
		if (*iterator == data)
			return true;
	}
	return false;
}

template<typename T>
inline void List<T>::addToFront(const T& data) {
	Node<T>* newNode = new Node<T>(data); //Creates a new node with the given data
	
	if (m_nodeCount == 0) {
		m_firstNode = newNode;
		m_lastNode = newNode;
	}
	else if (m_nodeCount == 1) {
		m_firstNode = newNode;
		m_firstNode->nextNode = m_lastNode;
		m_lastNode->previousNode = m_firstNode;
	}
	else {
		//Sets the current first node's previous to be the new node, and then sets the first node to point at the new node
		m_firstNode->previousNode = newNode;
		newNode->nextNode = m_firstNode;
		m_firstNode = newNode;
	}
	m_nodeCount++;
}

template<typename T>
inline void List<T>::addToBack(const T& data) {
	Node<T>* newNode = new Node<T>(data); //Creates a new node with the given data

	if (m_nodeCount == 0) {
		m_firstNode = newNode;
		m_lastNode = newNode;
	}
	else if (m_nodeCount == 1) {
		m_lastNode = newNode;
		m_firstNode->nextNode = m_lastNode;
		m_lastNode->previousNode = m_firstNode;
	}
	else {
		//Sets the current first node's previous to be the new node, and then sets the first node to point at the new nodenewNode->previousNode = m_lastNode;
		m_lastNode->nextNode = newNode;
		newNode->previousNode = m_lastNode;
		m_lastNode = newNode;
	}	
	m_nodeCount++;
}

template<typename T>
inline bool List<T>::insert(const T& data, int index) {
	//If the given index is outside the range of the list, return false
	if (index < 0 || index > m_nodeCount) 
		return false;

	Node<T>* newNode = new Node<T>(data); //Creates a new node with the given data
	
	//If the index is zero, add the new node to the front of the list
	if (index == 0) {
		addToFront(data);
		return true;
	}
	//If the index is zero, add the new node to the back of the list
	else if (index == getLength()) {
		addToBack(data);
		return true;
	}

	//Gets the node currently at the given index
	Node<T>* nodeAtGivenIndex = m_firstNode;
	for (int i = 0; i < index; i++)
		nodeAtGivenIndex = nodeAtGivenIndex->nextNode;

	//Places the new node in the place that the current node is
	newNode->nextNode = nodeAtGivenIndex;
	newNode->previousNode = nodeAtGivenIndex->previousNode;
	newNode->previousNode->nextNode = newNode;
	nodeAtGivenIndex->previousNode = newNode;
	m_nodeCount++;
}

template<typename T>
inline bool List<T>::remove(const T& value) {
	//Loops through the nodes and checks to see if their data matches the value given
	Node<T>* currentNode = m_firstNode;
	for (int i = 0; i < getLength(); i++) {
		//If the current node's data matches the value given..
		if (currentNode->data == value) {
			//If the current node matches the first node...
			if (currentNode == m_firstNode) {
				m_firstNode = currentNode->nextNode; //Set the first node to be the current first node's next node;
				m_firstNode->previousNode = nullptr;
				delete currentNode; //Deletes the current node
			}
			//Else if the current node matches the last node...
			else if (currentNode == m_lastNode) { 
				m_lastNode = currentNode->previousNode; //Set the last node to be equal to the current node's previous node
				m_lastNode->nextNode = nullptr;
				delete currentNode; //Deletes the current node
			}
			else {
				//Sets the current node's previous node's next node variable to be equal to the current node's next node
				currentNode->previousNode->nextNode = currentNode->nextNode;
				//Sets the current node's next node's previous node variable to be equal to the current node's previous node
				currentNode->nextNode->previousNode = currentNode->previousNode;
				delete currentNode; //Deletes the current node
			} 
			m_nodeCount--;
			return true;
		}
		//If the current node's data does not match the value, go to the next node
		else currentNode = currentNode->nextNode; 
	}
	return false;
}

template<typename T>
inline void List<T>::print() const {
	for (Iterator<T> iterator(m_firstNode); iterator != getLastNode(); ++iterator) {
		std::cout << *iterator << "\n";
	}
	std::cout << "\n";
}

template<typename T>
inline void List<T>::initialize() {
	m_firstNode = nullptr; 
	m_lastNode = nullptr;
	m_nodeCount = 0;
}

template<typename T>
inline bool List<T>::isEmpty() const {
	if (getLength() == 0)
		return true;
	else return false;
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iterator, int index)
{	
	if (index < 0 || index < getLength())
		return false;

	iterator = getFirstNode(); //Sets the backwardsIterator equal to the first node in this list 
	//Loops through the list until the backwardsIterator reaches the node at the given index
	while (iterator < index) 
		++iterator; 
	return true;
}

template<typename T>
inline int List<T>::getLength() const {
	return m_nodeCount;
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherList) {
	clearList(); //Clears this list
	m_firstNode = otherList.m_firstNode; //Sets this list's first node to be the other list's first node
	m_lastNode = otherList.m_lastNode; //Sets this list's last node to be the other list's last node
	m_nodeCount = otherList.m_nodeCount; //Sets the node count to be equal to the other list's node count
}

template<typename T>
inline void List<T>::sort() {
	Iterator<T> backwardsIterator(m_firstNode); //Iterator that points at the first node
	T key = NULL; //Stores the value of the node that 
	int i = 0; //Temporary variable used for for loop
	int j = 0; //Temporary variable used for for loop

	//Loops forwards through a list using an backwardsIterator
	for (Iterator<T> forwardIterator(m_firstNode->nextNode); forwardIterator != getLastNode();) {
		i++; 
		key = *forwardIterator; //Sets the key equal to the forwardIterator's current node
		j = i - 1; //Sets j to be one less than i

		backwardsIterator = forwardIterator; //Sets the backwardsIterator to be one less than the forwardIterator
		--backwardsIterator; 
		//While j is less than or greator to 0, and the backwardsIterator's current node's value is greater than the key
		while (j >= 0 && *backwardsIterator > key) {
			j--; //Decrement j
			--backwardsIterator; //Decrement the backwardsIterator
		}
		++forwardIterator; //Increment the forwardIterator
		remove(key, i); //Removes the key...
		insert(key, j + 1); //...and adds it back and the index of j + 1
	}
}

template<typename T>
inline bool List<T>::remove(const T& value, int index)
{
	if (index < 0 || index > getLength())
		return false;

	//Loops through the nodes and gets the node at the given index
	Node<T>* currentNode = m_firstNode;
	for (int i = 0; i < index; i++) {
		//Increments through the list, getting the next node
		currentNode = currentNode->nextNode;
	}

	if (currentNode->data != value)
		return false;

	//If the current node matches the first node...
	if (currentNode == m_firstNode) {
		m_firstNode = currentNode->nextNode; //Set the first node to be the current first node's next node;
		m_firstNode->previousNode = nullptr;
		delete currentNode; //Deletes the current node
	}
	//Else if the current node matches the last node...
	else if (currentNode == m_lastNode) {
		m_lastNode = currentNode->previousNode; //Set the last node to be equal to the current node's previous node
		m_lastNode->nextNode = nullptr;
		delete currentNode; //Deletes the current node
	}
	else {
		//Sets the current node's previous node's next node variable to be equal to the current node's next node
		currentNode->previousNode->nextNode = currentNode->nextNode;
		//Sets the current node's next node's previous node variable to be equal to the current node's previous node
		currentNode->nextNode->previousNode = currentNode->previousNode;
		delete currentNode; //Deletes the current node
	}
	m_nodeCount--;
	return true;
}
