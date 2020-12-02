#include "Seat.h"
#include <windows.h>
#include <conio.h>
#include <windows.h>
#include "consts.h"
#include "func.h"
Seat::Seat(int a, int b, bool c) {
	row = a;
	col = b;
	unavalible = c;
}
void Seat::changeavil() {
	if (unavalible == true) {
		unavalible = false;
	}
	else {
		unavalible = true;
	}
}
string Seat::name(bool booked) {
	if (unavalible == true) {
		Color(UNAVAIL);
	}
	else if (booked == true) {
		Color(BOOKED);
	}
	else {
		Color(AVAIL);
	}
	return (to_string(row) + ":" + to_string(col) + " ");
}
int Seat::getcol() {
	return (col);
}
int Seat::getrow() {
	return (row);
}