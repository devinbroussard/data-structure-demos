#pragma once

template<typename T>
class List
{
public:
	List();
	List(const List<T>&);
	~List();

	/// <summary>
	/// Deletes all nodes in the list
	/// </summary>
	void destroyList();

	/// <summary>
	/// Returns the node at the beginning of the list
	/// </summary>
	//Iterator<T> getBeginning();
	/// <summary>
	/// Returns the node at the end of the list
	/// </summary>
	//Iterator<T> getEnding();

	/// <summary>
	/// Checks to see if the given item is in the list
	/// </summary>
	const bool checkIfIncludes(/*const T object*/);

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
	bool insert(/*const T& value*/)
};

