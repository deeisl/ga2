#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"
#include "table.h"

using namespace std;

int main() {
	ifstream input("input21.txt");
	BST mytree;
	int tests;
	int num_of_tests;
	int table_size;
	input >> tests;
	table myTable(tests);

	int fake_test = 0;   //a temp variable
	while (fake_test < tests) {
		myTable.fits(input, fake_test);
		fake_test++;
	}

	myTable.print(tests);
}
