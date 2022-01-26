#pragma once
#include "Node.h"
#include "Iterator.h"

template<typename T>
class List {
public:
	List();
	List(const List<T>&);
	~List();

	void destroyList(); //Deletes all nodes in the list

	Iterator<T> getBeginning(); //Returns the node at the start of the list
	Iterator<T> getEnding(); //Returns the ndoe at the end of the list
	const bool checkIfIncludes(const T object); // Checks to see if the given item is in the list

	/// <summary>
	/// Adds a new node to the beginning of the list
	/// </summary>
	void pushFront(/*const T& value*/);

	/// <summary>
	/// Adds a new node to the end of the list
	/// </summary>
	void pushBack(/*const T& value*/);

	/// <summary>
	/// Adds a new node at the given index
	/// </summary>
	bool insert(/*const T& value*/);
};

