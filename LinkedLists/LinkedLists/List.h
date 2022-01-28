#pragma once
#include "Node.h"
#include "Iterator.h"

template<typename T>
class List {
public:
	List();
	List(const List<T>& otherList);
	~List() {};

	void clearList(); //Deletes all nodes in the list

	Iterator<T> getFirstNode(); //Returns the node at the start of the list
	Iterator<T> getLastNode(); //Returns the ndoe at the end of the list
	const bool checkIfIncludes(const T object); // Checks to see if the given item is in the list

	void pushFront(const T& value); //Adds a new node at the beginning of the list
	void pushBack(const T& value); //Adds a new node to the end of the list
	bool insert(const T& value); //Adds a new node at the given index
	bool remove(const T& value); //Removes all the nodes with the given value

	void print() const; //Prints every node's value
	void initialize();  //Set the default values for the first node pointer, the last node pointer, and the node count
	bool isEmpty() const; //Returns whether or not the list has any nodes in it
	bool getData(Iterator<T>& iterator, int index); //Sets the given iterator to point at a node at the given index
	int getLength() const; //Returns the amount of nodes in the list

	const List<T>& operator =(const List<T>& otherList); //Sets a list to be equal to another
	void sort(); //Sorts the nodes in the list 

private:
	Node<T>* m_firstNode; //First node in the list
	Node<T>* m_lastNode; //Last node in the list
	int m_nodeCount; //Number of nodes in the list
};

template<typename T>
inline List<T>::List() {
	m_firstNode = nullptr;
	m_lastNode = nullptr;
	m_nodeCount = 0;
}

template<typename T>
inline List<T>::List(const List<T>& otherList) {
	m_firstNode = otherList.m_firstNode;
	m_lastNode = otherList.m_lastNode;
	m_nodeCount = otherList.m_nodeCount;
}

template<typename T>
inline void List<T>::clearList() {
	Node<T>* currentNode = m_firstNode;
	Node<T>* nextNode;

	for (int i = 0; i < m_nodeCount; i++) {
		nextNode = currentNode->nextNode(); //Holds the current node's next in a temporary variable...
		delete currentNode; //..Deletes the current node...
		currentNode = nextNode; //..And sets the current node to be the one stored in the temporary variable
	}

	initialize();
}

template<typename T>
inline Iterator<T> List<T>::getFirstNode() {
	Iterator<T> iterator(m_firstNode); //Creates an iterator that points at the first node
	return iterator;
}

template<typename T>
inline Iterator<T> List<T>::getLastNode() {
	Iterator<T> iterator(m_lastNode); //Creates an iterator that points at the last node
	return iterator;
}
