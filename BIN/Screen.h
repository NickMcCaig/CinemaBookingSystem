#ifndef SCREEN_H
#define SCREEN_H
#include "Seat.h"
#include <vector>
using namespace std;
const vector<Seat*> emptyseats;
class Screen {
public:
	int rows;
	int cols;
	int ID;
	vector <Seat> seats;
	void addSeat(int r, int c, bool x);
	vector<Seat> getseatsrow(int r);
	void viewscreen(vector<Seat*> bookseats = emptyseats);
	void changeaval();
	Seat* getseat(int r, int c);
	string getname() { return name; }
	Screen(int h, int l, string n, bool x, int I);
protected:
	string name;
};
#endif
