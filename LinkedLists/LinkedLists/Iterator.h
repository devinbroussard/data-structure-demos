#pragma once
#include "Node.h"

template<typename T>
class Iterator {
public:
	Iterator(); //Creates a new iterator that points at nothing
	Iterator(Node<T>* node); //Creates a new iterator that points at the given node

	Iterator<T> operator ++(); //Goes to the current node's next node
	Iterator<T> operator --(); //Goes to the current node's previous node
	const bool operator ==(const Iterator<T>& iterator); //Checks to see if two nodes are equal
	const bool operator !=(const Iterator<T>& iterator); //Checks to see if two nodes are not equal
	T operator *(); //Dereferences an iterator to get the value of a node

private:
	Node<T>* m_currentNode; //The node that the iterator is currently pointing at
};

template<typename T>
inline Iterator<T>::Iterator() {
	m_currentNode = nullptr;
}

template<typename T>
inline Iterator<T>::Iterator(Node<T>* node) {
	m_currentNode = node;
}

template<typename T>
inline Iterator<T> Iterator<T>::operator++() {
	m_currentNode = m_currentNode->nextNode();
	return Iterator<T>();
}

template<typename T>
inline Iterator<T> Iterator<T>::operator--() {
	m_currentNode = m_currentNode->previousNode();
	return Iterator<T>();
}

template<typename T>
inline const bool Iterator<T>::operator==(const Iterator<T>& iterator) {
	if (m_currentNode == iterator.m_currentNode)
		return true;
	else return false;
}

template<typename T>
inline const bool Iterator<T>::operator!=(const Iterator<T>& iterator) {
	if (m_currentNode != iterator.m_currentNode)
		return true;
	return false;
}

template<typename T>
inline T Iterator<T>::operator*() {
	return m_currentNode->data;
}
