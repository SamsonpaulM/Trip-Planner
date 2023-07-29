#ifndef BOOKING_H
#define BOOKING_H

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

class Booking
{
	private:
		string name;
		string residence;
		string email;
		string phone;
		string package;
		string destination;
		string dateOftravel;
		string noOfdays;
		string noOfpeople;
		string flighTrain;
		string hotel;
		string paymentMode;

	public:
		static int bookingId;;
		
		Booking();

		void setName(string);
		void setResidence(string);
		void setEmail(string);
		void setPhone(string);
		void setPackage(string);
		void setDestination(string);
		void setDateoftravel(string);
		void setNoofdays(string);
		void setNoofpeople(string);
		void setFlightrain(string);
		void setHotel(string);
		void setPaymentmode(string);
		
		int getBookingid();
		string getName();
		string getResidence();
		string getEmail();
		string getPhone();
		string getPackage();
		string getDestination();
		string getDateoftravel();
		string getNoofdays();
		string getNoofpeople();
		string getFlightrain();
		string getHotel();
		string getPaymentmode();

		~Booking();
};

#endif