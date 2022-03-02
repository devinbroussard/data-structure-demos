#include "Dictionary.h"
#include <iostream>

int main() {
	Dictionary<char, int> dictionary = Dictionary<char, int>();

	dictionary.addItem('a', 1);
	dictionary.remove('2');
	dictionary.remove('a');

	dictionary.getCount();
}