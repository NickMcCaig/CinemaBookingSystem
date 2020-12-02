#ifndef SEAT_H
#define SEAT_H
#include <string>
using namespace std;
class  Seat {
public:
	int row, col;
	bool unavalible;
	Seat(int, int, bool);
	void changeavil();
	string name(bool booked = false);
	int getrow();
	int getcol();
};
#endif