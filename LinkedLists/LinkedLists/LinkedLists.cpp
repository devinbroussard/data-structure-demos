#include <iostream>
#include "List.h"

int main() {
	List<int> list; 
	list.addToFront(2);
	list.addToFront(42);
	list.addToFront(3);
	list.addToFront(3);
	list.addToFront(4223);
	list.sort();
	list.print();
}