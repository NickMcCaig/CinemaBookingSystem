#include "Movie.h"
#include <string>

using namespace std;
Movie::Movie(string tit, int dur, string des, int I) {
	title = tit;
	duration = dur;
	description = des;
	ID = I;
}