#ifndef RESERVATION_H
#define RESERVATION_H
#include "Seat.h"
class Reservation {
public:
	string name;
	string number;
	string email;
	Seat* bookedseat;
	Reservation(string na, string nu, string em, Seat* bookedseat);
};
#endif