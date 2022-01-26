#pragma once

template<typename T>
struct Node {
public:
	Node();
	Node(T value); //Accepts a value from any type

	Node<T>* nextNode; //The next node in the linked list
	Node<T>* previousNode; //The previous node in the linked list
	T data;
};

template<typename T>
inline Node<T>::Node() {
	nextNode = nullptr;
	previousNode = nullptr;
	data = 0;
}

template<typename T>
inline Node<T>::Node(T value) {
	//Set nextNode value
	//Set previousNode value
	data = value;
}
