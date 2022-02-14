#pragma once

template<typename T>
class DynamicArray {
public:
	DynamicArray();
	~DynamicArray();
	void addItem(T item);
	void addItem(T item[], int size);
	bool removeItem(T item);
	void sortItems();
	T getItem(int index);
	int getLength();

private:
	T* m_items;
	int m_length;
};

template<typename T>
inline DynamicArray<T>::DynamicArray() {
	m_length = 0;
	m_items = nullptr;
}

template<typename T>
inline DynamicArray<T>::~DynamicArray() {
}

template<typename T>
inline void DynamicArray<T>::addItem(T item) {
	T* tempArray = new T[getLength() + 1];
	for (int i = 0; i < getLength(); i++) {
		tempArray[i] = m_items[i];
	}

	delete[] m_items;
	tempArray[getLength()] = item;
	m_items = tempArray;
	m_length++;
}

template<typename T>
inline void DynamicArray<T>::addItem(T item[], int size) {
	T* tempArray = new T[getLength() + size];

	int j = 0;
	for (int i = 0; i < getLength(); i++) {
		tempArray[j] = m_items[i];
		j++;
	}
	for (int i = 0; i < size; i++) {
		tempArray[j] = item[i];
		j++;
	}

	m_length += size;
	m_items = tempArray;
}

template<typename T>
inline bool DynamicArray<T>::removeItem(T item) {
	bool itemRemoved = false;

	if (!item || getLength() <= 0)
		return itemRemoved;

	T* tempArray = new T[getLength() - 1];

	int j = 0;
	for (int i = 0; i < getLength(); i++) {
		if (item != m_items[i] || itemRemoved) {
			tempArray[j] = m_items[i];
			j++;
		}
		else {
			itemRemoved = true;
		}
	}

	if (itemRemoved) {
		delete[] m_items;
		m_items = tempArray;
		m_length--;
	}

	return itemRemoved;
}

template<typename T>
inline void DynamicArray<T>::sortItems() {
	T key = NULL;
	int j = 0;

	for (int i = 1; i < getLength(); i++) {
		key = m_items[i];
		j = i - 1;
		while (j >= 0 && m_items[j] > key) {
			m_items[j + 1] = m_items[j];
			j--;
		}

		m_items[j + 1] = key;
	}
}

template<typename T>
inline T DynamicArray<T>::getItem(int index) {
	if (index > 0 || index < getLength()) {
		return m_items[index];
	}
	return NULL;
}

template<typename T>
inline int DynamicArray<T>::getLength() {
	return m_length;
}
