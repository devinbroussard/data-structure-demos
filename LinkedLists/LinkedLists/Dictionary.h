#pragma once

template<typename TKey, typename TValue>
struct Item {
public:
	TKey key; //The key that accesses the value
	TValue value; //The value that is accessed by the key
};


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
	bool tryGetValue(const TKey key, const TValue& value) const;
	//Adds an item to the array of items 
	void addItem(const TKey& key, const TValue& value);
	//Removes an item from the array of items
	bool remove(const TKey key);
	//Remvoes an item from the array of items, and if successful, changes the second argument to match the key's value
	bool remove(const TKey key, TValue& value);
	//Returns the item count
	int getCount() const;
	//Sets one dictionary equal to another by copying its items
	Dictionary<typename TKey, typename TValue>& operator =(const Dictionary<typename TKey, typename TValue> other) const;

private:
	//The amount of items in the dictionary
	int m_count = 0;
	//An array of items that store a key and a value
	Item<typename TKey, typename TValue>* m_items = nullptr;
};

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::clear() {
	delete[] m_items;
	m_count = 0;
}

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary() {
	m_count = 0;
	m_items = nullptr;
}

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary(const Dictionary<typename TKey, typename TValue>& other) {
	this = other;
}

template<typename TKey, typename TValue>
inline Dictionary<typename TKey, typename TValue>& Dictionary<TKey, TValue>::operator=(const Dictionary<typename TKey, typename TValue> other) const
{
	clear();

	for (int i = 0; i < other.getCount(); i++) {
		m_items[i] = other.m_items[i];
	}
}

