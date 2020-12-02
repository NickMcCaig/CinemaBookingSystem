#include <iostream>
#include "Reservation.h"
#include "func.h"
#include "Seat.h"
using namespace std;
Reservation::Reservation(string na, string nu, string em, Seat* seat) {
	name = na;
	number = nu;
	email = em;
	bookedseat = seat;
}