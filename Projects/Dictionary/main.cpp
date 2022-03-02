#include "Dictionary.h"
#include <iostream>

int main() {
	Dictionary<int, char> dictionary = Dictionary<int, char>();
	int keys[10]; //An array to store keys for printing key/value pairs

	//Adding items to dictionary
	dictionary.addItem(1, 'a');
	keys[0] = 1;
	dictionary.addItem(2, 'b');
	keys[1] = 2;
	dictionary.addItem(3, 'c');
	keys[2] = 3;
	dictionary.addItem(4, 'd');
	keys[3] = 4;
	dictionary.addItem(5, 'f');
	keys[4] = 5;

	//Some examples of the functionality of the dictionary:


	std::cout << "Printing keys and values of dictionary:\n";

	for (int i = 0; i < dictionary.getCount(); i++) {
		char value;
		dictionary.tryGetValue(keys[i], value);

		std::cout << "Key: " << keys[i];
		std::cout << " Value: " << value << std::endl;
	}

	std::cout << "\nRemoving a key/value pair:\n";

	dictionary.remove(3);
	keys[2] = 4;
	keys[3] = 5;
	keys[4] = NULL;

	for (int i = 0; i < dictionary.getCount(); i++) {
		char value;
		dictionary.tryGetValue(keys[i], value);

		std::cout << "Key: " << keys[i];
		std::cout << " Value: " << value << std::endl;
	}

	std::cout << "\nClearing a dictionary:\n";

	dictionary.clear();

	for (int i = 0; i < dictionary.getCount(); i++) {
		char value;
		dictionary.tryGetValue(keys[i], value);

		std::cout << "Key: " << keys[i];
		std::cout << " Value: " << value << std::endl;
	}

	system("pause");
}