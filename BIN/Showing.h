#ifndef SHOWING_H
#define SHOWING_H
#include <string>
#include "Screen.h"
#include "Movie.h"
#include "Reservation.h"
using namespace std;
class Showing {
public:
	Screen* screen;
	Movie* movie;
	int year;
	int day;
	int hour;
	int min;
	double totalbookedseats();
	double totalseats();
	string bookingpercentage();
	vector<Reservation> bookings;
	bool CheckSeat(Seat* seatb);
	void NewReservation(string na, string nu, string em, Seat* seat);
	vector<Seat*> GetBookedSeats();
	Showing(Screen* s, Movie* m, int y , int d, int h , int mi );
};
#endif
