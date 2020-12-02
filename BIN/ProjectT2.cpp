// ProjectT2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <string>
#include <limits>
#include <ctime>
#include "func.h"
#include "consts.h"
#include "Showing.h"
#include "Reservation.h"
#include "Seat.h"
#include "Screen.h"
#include "Movie.h"
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <conio.h>

using namespace std;

vector<Screen> screens;  
vector<Movie> movies;
vector<Showing> showings;

vector <vector<string>> parseCSV(string filename)
//COPIED WORK https://www.geeksforgeeks.org/csv-file-management-using-c/
{
	ifstream  data(filename);
	string line;
	vector<vector<string> > parsedCsv;
	while (getline(data, line))
	{
		stringstream lineStream(line);
		string cell;
		vector<string> parsedRow;
		while (getline(lineStream, cell, ','))
		{
			parsedRow.push_back(cell);
		}

		parsedCsv.push_back(parsedRow);

	}
	data.close();
	return parsedCsv;
};
bool isnumber(const string& s) {  //http://www.cplusplus.com/forum/beginner/31141/
	for (int i = 0; i < s.length(); i++)
		if (!(s[i] >= '0' && s[i] <= '9' || s[i] == ' ')) return false;
	return true;
}
int getselection() {
	string choice = "Z";
	do {
		getline(cin, choice);
	} while (isnumber(choice) == false);
	//he
	return stoi(choice);
}
Screen* SelectScreen() {
	//shows all screens allows user to select one and returns a pointer to the screen selected.
	int inpu;
	int arrysize = screens.size();
	for (int i = 0; i < arrysize; i++) {
		cout << to_string(i) << "| " << screens[i].getname() << "\n";
	}
	cout << "Which screen would you like to select?\n";
	do {
		inpu = getselection();
	} while ((inpu < 0) || (inpu > arrysize));
		return &screens[inpu];
	}
Movie * SelectMovie() {
	//shows all movies allows user to select one and returns a pointer to the movie selected.
	int inpu;
	int arrysize = movies.size();
	for (int i = 0; i < arrysize; i++) {
		cout << to_string(i) << "|" <<movies[i].title << "\n";
	}
	cout << "Which movie would you like to select?\n";
	do {
		inpu = getselection();
	} while ((inpu < 0) | (inpu > arrysize));
	return &movies[inpu];
} 
void NewScreen() {
	//creates a new screen and adds to the vector
	int rows;
	int cols;
	string namex;
	cout << "How many rows would you like?\n";
	rows = getselection();
	cout << "How many cols would you like?\n";
	cols = getselection();
	cout << "Name of screen? \n";
	getline(cin, namex);
	Screen x(rows, cols, namex, false, screens.size());
	screens.push_back(x);
	system("pause");
}
void NewMovie() {
	//creates a new movie and adds to the vector
	string name;
	string desc;
	int duration;
	cout << "How long is the movie?\n";
	duration = getselection();
	cout << "What is the title of the movie?\n";
	getline(cin, name);
	cout << "What is the description of the movie\n";
	getline(cin, desc);
	Movie mymovie(name, duration, desc, movies.size());
	movies.push_back(mymovie);
}
Showing* Showingselection(int Y = TEMPY, int D = TEMPD) {
	//shows all showings speciified by the current date, retruns users selection
	int chx;
	for (int i = 0; i < showings.size(); i++) {
		if (showings[i].day == D && showings[i].year == Y) {
			cout << to_string(i) << "|" << showings[i].movie->title << " Hour: " + to_string(TEMPH) + " MIN: " + to_string(TEMPMI) + "\n";

		}
	}
	chx = getselection();
	return &showings[chx];
}
void viewMovies() {
	//shows all movies
	for (int i = 0; i < movies.size(); i++) {
		cout << to_string(i) << "| " << movies[i].title << " " << movies[i].description << "\n";
	}
}
void DisplayMainMenu() {
	//clears screen and displays menu
	system("cls");
	Color(TXT);
	cout << "				-=Main Menu=-				\n";
	cout << "				1- ADMIN					\n";
	cout << "				2- STAFF					\n";
	cout << "				3- SAVE						\n";
	cout << "				4- OPEN						\n";
}	
void DisplayStaffMenu() {
	//clears screen and displays staff menu
	system("cls");
	Color(TXT);
	cout << "				-=Staff Menu=-				\n";
	string currentTD = "Day: " + to_string(TEMPD) + " Hour: " + to_string(TEMPH) + " MIN: " + to_string(TEMPMI) + "\n";
	cout << currentTD;
	cout << "				1- View Todays shows		\n";
	cout << "				2- Make a Booking			\n";
	cout << "				3- View booking levels		\n";
	cout << "				4- Look at reports			\n";
}
void DisplayAdminMenu() {
	//clears screen and displays menu
	system("cls");
	Color(TXT);
	cout << "				-=ADMIN MENU=-				\n";
	cout << "				1- NewScreen				\n";
	cout << "				2- ViewScreen				\n";
	cout << "				3- NewMovie					\n";
	cout << "				4- viewmovies				\n";
	cout << "				5- NewShow					\n";
	cout << "				6- Changeavail				\n";
} 

void Bookingsprocess() {
	string name;
	string number;
	string email;
	//gets booking details
	cout << "Name of bookie:\n";
	getline(cin, name);
		cout << "Number: \n";
		number = getselection();
	cout << "Email: \n";
	cin.ignore();
	getline(cin, email);
	int opti = 0;
	do {
		opti = 0;
		cout << "			Show booking	\n			1- Show all shows today		\n";
		opti = getselection();
		switch (opti) {
		case 1:
			
			Showing * Showb = Showingselection();
			//gets slection of seats
			int opti2 = 1;
			Showb->screen->viewscreen(Showb->GetBookedSeats());
			do {
				cout << "1 to book show, 2 to continue";
				opti2 = getselection();
				if (opti2 == 1){
					Showb->screen->viewscreen(Showb->GetBookedSeats());
					int row = getRow(Showb->screen->rows);
					int col = getCol(Showb->screen->cols);
					//check avalablity
					Seat* seatb = Showb->screen->getseat(row, col);
					if (Showb->CheckSeat(seatb) == false) {
						//create and save booking
						Showb->NewReservation(name, number, email, seatb);
					}
					else {
						cout << "This seat is booked please try another!\n";
					}

				}
			} while (opti2 != 2);
			break;
			//program has been designed to allow for future expantion, such as view all from a given week or date range but is not included which would be added here.
		}
	} while (opti != 9);



}
void showscreensbyday(int Y = TEMPY, int D = TEMPD) {
	//shows screens on selected day if none is provided then automaticly selects today
	for (int i = 0; i < showings.size(); i++) {
		if (showings[i].day == D && showings[i].year == Y) {
			cout << i << "| " << showings[i].movie->title << " Hour: " + to_string(TEMPH) + " MIN: " + to_string(TEMPMI) + "\n";
		}
	}
		
}
void newshow() {
	int year;
	int day;
	int hour;
	int min;
	cout << "Enter year:";
	cin >> year;
	cout << "Enter day:";
	cin >> day;
	cout << "Enter hour:";
	cin >> hour;
	cout << "Enter min:";
	cin >> min;
	int showmins = (hour * 60) + min;
	cin.ignore();
	Screen* screen = SelectScreen();
	Movie* movie = SelectMovie();
	int endshowmins = showmins + movie->duration;
	bool check = false;
	for (int i = 0; i < showings.size(); i++) {
		//checks if there is a conflict
		if (screen == showings[i].screen) {
			if (year == showings[i].year) {
				if (day == showings[i].day) {
					int startmin = (showings[i].hour * 60) + showings[i].min;
					int endmin = startmin + showings[i].movie->duration;
					if (startmin <= showmins && showmins <= endmin) {
						if (startmin <= endshowmins && endshowmins <= endmin) {
							check = true;
						}
					}
				}
			}
		}
	}
	if (check == false) {
		Showing x(screen, movie, year, day, hour, min);
		showings.push_back(x);
	}
	else {
		cout << "this conflicts with a current booking!\nPlease try again with a new time!\n";
	}
}
void viewbooking() {
	Showing * Showx = Showingselection();
	float totalseats = Showx->screen->seats.size();
	float bookedseatscount = Showx->bookings.size();
	for (int i = 0; i < bookedseatscount; i++) {
		cout << "Name:" << Showx->bookings[i].name << "  Number:" << Showx->bookings[i].number << "  Email:" << Showx->bookings[i].email;
		cout << "\nRow:" << Showx->bookings[i].bookedseat->getrow() << " Col:" << Showx->bookings[i].bookedseat->getcol()<< "\n";
		if (Showx->bookings[i].bookedseat->unavalible == true) {
			Color(UNAVAIL);
			cout << "The seat above has been marked as unavalible!\n";
		}
	}
	Color(TXT);
	cout << "Tot seats:" << Showx->totalseats() << " Booked seats: " << Showx->totalbookedseats() << "Booked percentage:" << Showx->bookingpercentage() << "\n";
}
void chnageunavail() {
	//changes the avalablity of the screen
	Screen* screen = SelectScreen();
	screen->viewscreen();
	screen->changeaval();
}
void reportday() {
	int year;
	int day;
	int totshows = 0;
	double totseats = 0;
	double totboookedseats = 0;
	cout << "Enter year:";
	year = getselection();
	cout << "Enter day:";
	day = getselection();

	for (int i = 0; i < showings.size(); i++) {
		if (year == showings[i].year) {
			if (day == showings[i].day) {
				totshows++;
				totseats = totseats + showings[i].totalseats();
				totboookedseats = totboookedseats + showings[i].totalbookedseats();
			}
		}
	}
	cout << "Day report Year:" << year << " Day:" << day;
	cout << "Total shows:" << totshows << "\nBooked seats:" << totboookedseats << " Booked percentage:" << to_string(8) << "\n";
}
void reportdayrange() {
	int year;
	int day;
	int day2;
	int totshows = 0;
	double totseats = 0;
	double totboookedseats = 0;
	cout << "Enter year:";
	year = getselection();
	cout << "Enter start day:";
	day = getselection();
	cout << "Enter end day:";
	day2 = getselection();
	for (int i = 0; i < showings.size(); i++) {
		if (year == showings[i].year) {
			if ((showings[i].day >= day) && (showings[i].day <= day2)) {
				totshows++;
				totseats = totseats + showings[i].totalseats();
				totboookedseats = totboookedseats + showings[i].totalbookedseats();
			}
		}
	}
	cout << "Day report Year:" << year << " Days:" << day << "|-|" << day2;
	cout << "Total shows:" << totshows << "\nBooked seats:" << totboookedseats << " Booked percentage:" << to_string(int((totboookedseats / totseats)) * 100) << "\n";
}
void reportsmenu() {
	int choice = 0;
	do {
		choice = 0;
		cout << "				-=Report Menu=-				\n";
		cout << "				1- Day report				\n";
		cout << "				2- Date range report		\n";
		choice = getselection();
		switch (choice) {
		case 1: // day report
			reportday();
			system("pause");
			break;
		case 2: // date range report
			reportdayrange();
			system("pause");
			break;
		}
	} while (choice != 9);

}
void StaffMenu() {
	int choice = 0;
	do {
		choice = 0;
		DisplayStaffMenu();
		choice = getselection();
		switch (choice) {
		case 1: // view todays shows
			showscreensbyday();
			system("pause");
			break;
		case 2: // books show
			Bookingsprocess();
			system("pause");
			break;
		case 3:
			viewbooking();
			system("pause");
			break;
		case 4:
			reportsmenu();

		}
	} while (choice != 9);
}
void AdminMenu() {
	int choice;
	do {
		choice = 0;
		DisplayAdminMenu();
		choice = getselection();
		switch (choice) {
		case 1: // new screen
			NewScreen();
			break;
		case 2: //view screen
			if (screens.size() != 0) {
				SelectScreen()->viewscreen();
				system("pause");
			}
			else {
				cout << "There are no screens yet!\n";
				system("pause");
			}
			break;
		case 3:
				NewMovie();
				system("pause");
			break;
		case 4:
			if (movies.size() != 0) {
				viewMovies();
			}
			else {
				cout << "There are no screens yet!\n";
			}
			system("pause");
			break;
		case 5:
			newshow();
			system("pause");
			break;
		case 6:
			chnageunavail();
			system("pause");
			break;
		}
	
	} while (choice != 9);
}

void openFiles() {
	//open file function 
	screens.clear();
	movies.clear();
	showings.clear();
	vector < vector<string>> scrn = parseCSV("screens.csv");
	for (int i = 0; i < scrn.size(); i++) {
		string name = scrn[i][1];
		int rows = stoi(scrn[i][2]);
		int cols = stoi(scrn[i][3]);
		scrn[i].erase(scrn[i].begin());
		scrn[i].erase(scrn[i].begin());
		scrn[i].erase(scrn[i].begin());
		scrn[i].erase(scrn[i].begin());
		Screen screen(rows, cols, name, true, i);
		for (int j = 0; j < scrn[i].size(); j = j +3) {
			bool avl;
			if (scrn[i][j +2] == "0") {
				avl = false;
			}
			else {
				avl = true;
			}
			screen.addSeat(stoi(scrn[i][j]), stoi(scrn[i][j +1]), avl);
		}
		screens.push_back(screen);
	}
	vector < vector<string>> movs = parseCSV("Movies.csv");
	for (int i = 0; i < movs.size(); i++) {
		Movie movie(movs[i][1], stoi(movs[i][2]), movs[i][3], stoi(movs[i][0]));
		movies.push_back(movie);
	}
	vector < vector<string>> shows = parseCSV("Showings.csv");
	for (int i = 0; i < shows.size(); i++) {
		Screen* screenptr = &screens[stoi(shows[i][1])];
		Movie* movieptr = &movies[stoi(shows[i][2])];
		Showing showing(screenptr,movieptr, stoi(shows[i][3]), stoi(shows[i][4]), stoi(shows[i][5]), stoi(shows[i][6]));
		showings.push_back(showing);
	}
	vector < vector<string>> reservations = parseCSV("Bookings.csv");
	for (int i = 0; i < reservations.size(); i++) {
		Seat* bookedseat = showings[stoi(reservations[i][0])].screen->getseat(stoi(reservations[i][4]), stoi(reservations[i][5]));
		showings[stoi(reservations[i][0])].NewReservation(reservations[i][1], reservations[i][2], reservations[i][3],bookedseat);
	}
	cout << "I worked.";
}
void SaveFiles() {
	//save file
	ofstream file;
	file.open("screens.csv", ofstream::trunc);
	for (int i = 0; i < screens.size(); i++) {
		file << screens[i].ID << ",";
		file << screens[i].getname() << ",";
		file << screens[i].rows << ",";
		file << screens[i].cols << ",";
		for (int j = 0; j < screens[i].seats.size(); j++) {
			file << screens[i].seats[j].getrow() << ",";
			file << screens[i].seats[j].getcol() << ",";
			file << screens[i].seats[j].unavalible << ",";
		}
		file << "\n";
		
	}
	file.close();
	file.open("Movies.csv", ofstream::trunc);
	for (int i = 0; i < screens.size(); i++) {
		file << movies[i].ID << ",";
		file << movies[i].title << ",";
		file << movies[i].duration << ",";
		file << movies[i].description << ",";
		file << "\n";
	}
	file.close();
	file.open("Showings.csv", ofstream::trunc);
	for (int i = 0; i < showings.size(); i++) {
		file << i << ",";
		file << showings[i].movie->ID << ",";
		file << showings[i].screen->ID << ",";
		file << showings[i].year << ",";
		file << showings[i].day << ",";
		file << showings[i].hour << ",";
		file << showings[i].min << ",";
		file << "\n";
	}
	file.close();
	file.open("Bookings.csv", ofstream::trunc);
		for (int i = 0; i < showings.size(); i++) {
			for (int j = 0; j < showings[i].bookings.size(); j++) {
				file << i << ",";
				file << showings[i].bookings[j].name << ",";
				file << showings[i].bookings[j].number << ",";
				file << showings[i].bookings[j].email << ",";
				file << showings[i].bookings[j].bookedseat->getrow() << ",";
				file << showings[i].bookings[j].bookedseat->getcol() << ",";
				file << "\n";
			}
		}
		file.close();
		cout << "Sucsess!\n";
}
int main() {
	int choice = 0;
	do
	{
		DisplayMainMenu();
		choice = getselection();
		switch (choice) {
		case 1:
			//admin menu
			AdminMenu();
			break;
		case 2:
			//staff menu
			StaffMenu();
			break;
		case 3:
			//saves files
			SaveFiles();
			break;
		case 4:
			//opens files
			openFiles();
			break;
		}
	} while (choice != 9);
	return 0; // exits with no error.
}