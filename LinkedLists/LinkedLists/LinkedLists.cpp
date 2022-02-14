#include <iostream>
#include "List.h"
#include "Dictionary.h"



int main() {
	Dictionary<char, int> dictionary = Dictionary<char, int>();
	Dictionary<char, int> dictionary2;

	dictionary.addItem('a', 1);
	dictionary.addItem('b', 2);
	dictionary.addItem('c', 3);
	dictionary.addItem('d', 4);
	dictionary.addItem('e', 5);
	dictionary.addItem('f', 6);

	dictionary2 = dictionary;

	int num;
	//if (dictionary2.remove('b', num))
	//	std::cout << num << "\n";
	//num = 0;

	dictionary2.tryGetValue('b', num);
	std::cout << dictionary2.containsKey('d');
}