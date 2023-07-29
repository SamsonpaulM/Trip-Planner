#ifndef DATALOAD_H
#define DATALOAD_H

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <map>
using namespace std;

#define success 1
#define failure 0
#define error -1

class Data
{
	public:
		time_t now = time(0);
		tm *ltm = localtime(&now);
	
		int tdd = ltm->tm_mday;
		int tmm = 1 + ltm->tm_mon;
		int tyy = 1900 + ltm->tm_year;

		int loadPackagedata();
		void loadBookingdata();
		void logout();
};

#endif