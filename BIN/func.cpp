#include "func.h"
#include <iostream>
#include <fstream>
using namespace std;
//global functions
void Color(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
int getRow(int rows) {
	int x;
	do {
		cout << "please enter the row:\n";
		cin >> x;
		cin.ignore();
	} while (x < 0 || x > rows);
	return x;
}
int getCol(int cols) {
	int x;

	do {
		cout << "please enter the col:\n";
		cin >> x;
		cin.ignore();
	} while (x < 0 || x > cols);
	return x;
}
