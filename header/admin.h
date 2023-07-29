#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <map>
using namespace std;

#include <dataLoad.h>
#include <booking.h>

#define success 1
#define failure 0
#define error -1

class Admin : public Data
{
	public:
		void displayPackages();
		void displayBookings(int, Booking);
		void updatePackages(int);
		void viewBookings();
};

#endif