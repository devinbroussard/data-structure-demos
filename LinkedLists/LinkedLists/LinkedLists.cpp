#include <iostream>
#include "List.h"
#include "Dictionary.h"



int main() {
	List<int> list = List<int>();


	list.pushBack(20);
	list.pushBack(10);
	list.pushBack(11);
	list.pushBack(1);
	list.pushBack(1);
	list.pushBack(1);
	list.pushFront(33);
	list.print();
	list.sort();
	list.print();

		
}