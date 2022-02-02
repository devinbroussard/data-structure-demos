#include <iostream>
#include "List.h"

int main() {
	List<int> list;
	list.addToFront(10);
	list.addToFront(3);
	list.addToFront(4);
	list.addToFront(7);
	list.addToFront(11);
	list.print();
}