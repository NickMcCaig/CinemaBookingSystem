#include <iostream>
#include "Showing.h"
using namespace std;
vector<Seat*> Showing::GetBookedSeats() {
	vector<Seat*> seats;
	for (int i = 0; i < bookings.size(); i++) {
		seats.push_back(bookings[i].bookedseat);
	}
	return seats;
}
double Showing::totalbookedseats() {
	return bookings.size();
}
double Showing::totalseats() {
	return screen->seats.size();
}
string Showing::bookingpercentage() {
	return to_string(int((totalbookedseats() / totalseats()) * 100));
}
bool Showing::CheckSeat(Seat* seatb) {
	if (seatb->unavalible == true) {
		return true;
		//returns booked
	}
	for (int j = 0; j < bookings.size(); j++) {
		if (bookings[j].bookedseat == seatb) {
			return true;
			//returns booked
		}
	}
	//will otherwise return false or free seat
	return false;
}  
void Showing::NewReservation(string na, string nu, string em, Seat* seat) {
	Reservation res(na, nu, em, seat);
	bookings.push_back(res);
}
Showing::Showing(Screen* s, Movie* m, int y , int d, int h, int mi) {
	screen = s;
	movie = m;
	year = y;
	day = d;
	hour = h;
	min = mi;
}