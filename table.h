#pragma once
#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

struct hashes {
	int h1 = -1;
	int h2 = -1;
};

class table {
protected:
	int count = 0;
	int tests = 0;
	bool find = true;
	hashes worked[100];
	//hashes table[0];

public:
	table(int test) { tests = test; };

	int convert(int bi) {
		/*int real = 0;
		int add = 8;
		string num = to_string(bi);
		int len = num.length();
		while (len < 4) {
			num.insert(0, "0");
			len++;
		}

		for (int i = 0; i < len; i++) {
			if (num[i] == '1') {
				real += add;
			}
			add = add / 2;
		}

		return real;*/

		int real = 0;
		int base = 1;
		int temp = bi;
		while (temp > 0) {
			int last = temp % 10;
			temp = temp / 10;
			real += last * base;
			base = base * 2;
		}
		return real;
	}

	void fits(ifstream& input, int num) {
		int x;
		int y;
		int z;
		int stop = 0;
		int tempy;
		int tempz;
		bool fit = false;
		bool again = false;
		int change = 0;

		input >> x;
		worked[num].h2 = x;
		input >> y;
		hashes* temp = new hashes[y];
		while (change < x) {
			if (count == 1000) {
				break;
			}
			input >> y;
			input >> z;
			y = convert(y);
			z = convert(z);

			while (fit == false) {
				if (again == false) {
					if (temp[y].h1 == -1) {
						temp[y].h1 = y;
						temp[y].h2 = z;
						fit = true;
					}
					else if (temp[y].h1 != -1) {
						tempy = temp[y].h1;
						tempz = temp[y].h2;

						temp[y].h1 = y;
						temp[y].h2 = z;

						y = tempy;
						z = tempz;
						again = true;
						count++;
					}
				}
				else {
					if (count == 1000) {
						break;
					}
					else if (temp[z].h1 == -1) {
						temp[z].h1 = y;
						temp[z].h2 = z;
						fit = true;
					}
					else if (temp[z].h1 != -1) {
						tempy = temp[z].h1;
						tempz = temp[z].h2;

						temp[z].h1 = y;
						temp[z].h2 = z;

						y = tempy;
						z = tempz;
						again = true;
						count++;
					}
				}
			}
			change++;
			if (count == 1000) {
				break;
			}
			fit = false;
		}

		if (change == x) {
			if (count < 1000) {
				worked[num].h1 = 1;
				count = 0;
			}
			else {
				while (change != x) {
					input >> x;
					input >> y;
					change++;
				}
				count = 0;
			}
		}
		else {
			while (change != x) {
				input >> y;
				input >> z;
				change++;
			}
			count = 0;
		}
		delete temp;

	}

	void print(int tests) {
		for (int i = 0; i < tests; i++) {
			if (worked[i].h1 == 1) {
				cout << "valid inventory log" << endl;
			}
			else {
				cout << "INVALID INVENTORY LOG!!!" << endl;
			}
		}
	}

};