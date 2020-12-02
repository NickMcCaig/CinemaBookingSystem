class Reservation {
public:
	string name;
	string number;
	string email;
	Reservation(string na, string nu, string em);
};
Reservation::Reservation(string na, string nu, string em) {
	name = na;
	number = nu;
	email = em;
}