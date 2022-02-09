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

	list.remove(3);
	list.print();

	List<int> list2 = list;
	//List<int> list3 = List<int>(list);

	list2.print();
	//list3.print();

	list.clearList();
	list.print();

	//list3.remove(42);


	system("pause");
}