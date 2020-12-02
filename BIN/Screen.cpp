#include <iostream>
#include "Screen.h"
#include "func.h"
#include "Seat.h"
using namespace std;
vector<Seat> Screen::getseatsrow(int r) {
	//returns a vector of seats 
	vector<Seat> rowSeats;
	for (int i = 0; i < seats.size(); i++) {
		if (seats[i].getrow() == r) {
			rowSeats.push_back(seats[i]);
		}
	}
	return rowSeats;
}
void Screen::addSeat(int r, int c, bool x) {
	Seat aseat(r, c, x);
	seats.push_back(aseat);
}

Seat* Screen::getseat(int r, int c) {
	//returns pointer to seat from row and col
	for (int i = 0; i < seats.size(); i++) {
		if (seats[i].row == r) {
			if (seats[i].col == c) {
				return &seats[i];
			}
		}
	}
}
void Screen::viewscreen(vector<Seat*> bookseats) {
	Color(15);
	cout << "Screen: " << name << "\n";
	for (int j = 0; j < rows; j++) {
		vector <Seat> seatrow = getseatsrow(j);
		for (int i = 0; i < seatrow.size(); i++) {
			bool booked = false;
			if (bookseats.empty() == true) {
				cout << seatrow[i].name() << " ";
			}
			else {
				for (int z = 0; z < bookseats.size(); z++) {
					int rowx = seatrow[i].getrow();
					int colx = seatrow[i].getcol();
					if (rowx == bookseats[z]->getrow()) {
						if (colx == bookseats[z]->getcol()) {
							booked = true;
						}
					}
				}
				cout << seatrow[i].name(booked) << " ";
			}
		}

		cout << "\n";
		Color(15);
	}
}
void Screen::changeaval() {
	int row = getRow(rows);
	int col = getCol(cols);
	for (int i = 0; i < seats.size(); i++) {
		if (seats[i].getcol() == col) {
			if (seats[i].getrow() == row) {
				seats[i].changeavil();
			}
		}
	}
}
Screen::Screen(int h, int l, string n, bool x, int I) {
	rows = h;
	cols = l;
	name = n;
	ID = I;
	if (x == false) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			addSeat(i, j, x);
		}
	}
	}
}