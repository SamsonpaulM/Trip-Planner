#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <map>
using namespace std;

#include <dataLoad.h>

#define success 1
#define failure 0
#define error -1

class Client : public Data
{	
	public:
		void bookPackage(int, string);
		void viewBooking(string);
		void cancelBooking(string);
		void rateBooking(string);
};

#endif