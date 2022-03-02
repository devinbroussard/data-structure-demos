#pragma once




template<typename TKey, typename TValue>
class Dictionary {

public:
	//Creates a dictionary with default values
	Dictionary<typename TKey, typename TValue>();
	//Creates a dictionary and sets it equal to another dictionary
	Dictionary<typename TKey, typename TValue>(const Dictionary<typename TKey, typename TValue>& other);
	//Calls the clear function and deletes the dictionary
	~Dictionary<TKey, TValue>();

	//Deletes all items in the dictionary
	void clear();
	//Checks to see if this dictionary contains an item with the key given
	bool containsKey(const TKey key) const;
	//Checks to see if one of the dictionary's items have the value given                                       
	bool containsValue(const TValue value) const;
	//Checks to see if the function contains a key, and if so, changes second argument to match the key's value
	bool tryGetValue(const TKey key, TValue& value) const;
	//Adds an item to the array of items 
	void addItem(const TKey& key, const TValue& value);
	//Removes an item from the array of items
	bool remove(const TKey key);
	//Remvoes an item from the array of items, and if successful, changes the second argument to match the key's value
	bool remove(const TKey key, TValue& value);
	//Returns the item count
	int getCount() const { return m_itemCount; }
	//Sets one dictionary equal to another by copying its items
	const Dictionary<typename TKey, typename TValue>& operator =(const Dictionary<typename TKey, typename TValue>& other);
	//Returns the value with the key given
	TValue operator [](const TKey key);

private:
	struct Item {
	public:
		TKey key; //The key that accesses the value
		TValue value; //The value that is accessed by the key
	};


	//The amount of items in the dictionary
	int m_itemCount = 0;
	//An array of items that store a key and a value
	Item* m_items = nullptr;
};

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::clear() {
	delete[] m_items;
	m_items = nullptr;
	m_itemCount = 0;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsKey(const TKey key) const
{
	//Loops through the items list, and returns true if one of the keys matches the key given
	for (int i = 0; i < getCount(); i++) {
		if (m_items[i].key == key)
			return true;
	}
	return false; //Returns false by default
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsValue(const TValue value) const
{
	//Loops through the list, and returns true if one of the items' value is the same as the one given
	for (int i = 0; i < getCount(); i++) {
		if (m_items[i].value == value)
			return true;
	}
	return false; //Returns false by default
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::tryGetValue(const TKey key, TValue& value) const
{
	//Loops through the items list, and returns true if one of the keys matches the key given
	for (int i = 0; i < getCount(); i++) {
		if (m_items[i].key == key) {
			value = m_items[i].value; //Sets the second argument to match the item's value
			return true;
		}

	}
	return false; //Returns false by default
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::addItem(const TKey& key, const TValue& value) {
	if (containsKey(key))
		return;

	//Create a new temporary array that is one element larger than the current items array
	Item* tempArray = new Item[getCount() + 1];

	//Copy the current item array's values onto the temporary array's
	for (int i = 0; i < m_itemCount; i++) {
		tempArray[i].key = m_items[i].key;
		tempArray[i].value = m_items[i].value;
	}

	//Sets the last item of the temp array to have the values given in the arguments list
	tempArray[m_itemCount].key = key;
	tempArray[m_itemCount].value = value;

	//Sets m_items to be equal to the tempArray
	delete[] m_items; //Deletes the old items array to prevent a memory leak
	m_items = tempArray;
	m_itemCount++; //Increments the item count
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key) {
	if (getCount() == 0) //Returns false if the dictionary is already empty
		return false;

	//Creates a temporary item array that is one element smaller than the current item array
	Item* tempArray = new Item[m_itemCount - 1];
	bool itemRemoved = false; //Creates a bool that stores whether or not an item got removed from the list

	if (getCount() == 1) {
		if (containsKey(key))
			itemRemoved = true;
	}
	else {
		int j = 0;
		for (int i = 0; i < m_itemCount; i++) {
			//If the current item's key doesn't match with the key to delete...
			if (m_items[i].key != key) {
				//Copy the current item onto the temporary array
				tempArray[j].key = m_items[i].key;
				tempArray[j].value = m_items[i].value;
				j++; //Increments j to go to the next index of the temporary array
			}
			else {
				//Otherwise, skip this item, set itemRemoved to be true, and skip incrementing j
				itemRemoved = true;
			}
		}
	}

	//If an item was removed...
	if (itemRemoved == true) {
		delete[] m_items; //Delete the current items array
		m_items = tempArray; //Set the items array to be the temporary one
		m_itemCount--; //Decrement the item count because an item was deleted
	}
	else delete[] tempArray;//Delete the temporary array to avoid a memory leak

	return itemRemoved; //Returns whether or not an item was deleted
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key, TValue& value)
{
	TValue valueOfRemovedItem; //Creates a temporary variable to hold the removed item's value

	//Passes in the key and a reference to the valueOfRemovedItem variable so that it can be changed
	if (tryGetValue(key, valueOfRemovedItem)) { //If the function found the key...
		remove(key); //Remove the key from the itemlist
		value = valueOfRemovedItem; //Set the second argument to be the removed item's value
		return true; //Returns true
	}
	else return false; //Returns false
}

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary() {
	//Initializes variables
	m_items = nullptr;
	m_itemCount = 0;
}

template<typename TKey, typename TValue>
inline const Dictionary<typename TKey, typename TValue>& Dictionary<TKey, TValue>::operator=(const Dictionary<typename TKey, typename TValue>& other) {
	clear(); //Clears the list
	//Sets m_items equal to a new items list that is equal in size to the other's
	m_items = new Item[other.getCount()]();

	//Copies the values from the other list onto this list
	for (int i = 0; i < other.getCount(); i++) {
		m_items[i] = other.m_items[i];
	}

	//Sets the count equal to the other list's count
	m_itemCount = other.getCount();

	return *this;
}

template<typename TKey, typename TValue>
inline TValue Dictionary<TKey, TValue>::operator[](const TKey key)
{
	TValue value = TValue(); //Creates a blank value varaible

	//Tries to get the key, and changes value to the key's value if successful
	tryGetValue(key, value);

	return value; //Returns value
}


template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary(const Dictionary< TKey, TValue>& other) {
	*this = other;
}

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::~Dictionary()
{
	clear(); //Clears the dictionary
}

