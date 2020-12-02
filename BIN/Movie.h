#ifndef MOVIE_H
#define MOVIE_H
#include <string>
using namespace std;
class Movie {
public:
	string title;
	double duration;
	string description;
	int ID;
	Movie(string tit, int dur, string des,int I);
};
#endif