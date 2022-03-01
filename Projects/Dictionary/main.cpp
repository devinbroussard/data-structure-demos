#include "Dictionary.h"
#include <iostream>

int main() {
	Dictionary<char, int> dictionary = Dictionary<char, int>();

	dictionary.addItem('a', 0);
	dictionary.addItem('b', 1);
	dictionary.addItem('c', 2);
	dictionary.addItem('d', 3);
	dictionary.addItem('e', 4);
	dictionary.addItem('f', 5);

	dictionary.clear();

	dictionary.addItem('e', 0);
	dictionary.addItem('x', 1);
	dictionary.addItem('e', 7);

	dictionary.getCount();
}