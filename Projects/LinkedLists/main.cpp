#include <iostream>
#include "List.h"


int main() {
	List<int> testList = List<int>();
	List<int> testListTwo = List<int>();

	Iterator<int> iter = Iterator<int>();

	++iter;

	testList.pushBack(11);
	testList.pushBack(3);
	testList.pushBack(2);
	testList.pushBack(3);
	testList.pushBack(7);

	iter = testList.begin();

	testList.clearList();

	--iter;

	testListTwo.pushBack(42);
	testListTwo.pushBack(1);
	testListTwo.pushBack(16);
	testListTwo.pushBack(55);



	std::cout << "1. Adding items to the list:\n\n";
	testList.print();
	system("pause");
	system("cls");

	std::cout << "2. Copying items from one list onto another:\n\n";
	std::cout << "List One:\n";
	testList.print();
	std::cout << "List Two:\n";
	testListTwo.print();
	std::cout << "List Two after copying:\n";
	testListTwo = testList;
	testListTwo.print();
	system("pause");
	system("cls");

	std::cout << "3. Sorting items in a list using insertion sort:\n\n";
	testList.sort();
	testList.print();
	system("pause");
	system("cls");

	std::cout << "4. Removing an item from a list\n\n";;
	std::cout << "After deleting three:\n";
	testList.remove(3);
	testList.print();
	system("pause");
	system("cls");

	std::cout << "5. Inserting an item in a list\n\n";
	std::cout << "After inserting twenty at the second index\n";
	testList.insert(20, 2);
	testList.print();
	system("pause");
	system("cls");
}