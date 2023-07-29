#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <map>
using namespace std;

#include <booking.h>

#define success 1
#define failure 0
#define error -1

int Booking::bookingId = 1000;

Booking::Booking() {
	++bookingId;
	name          = "";
	residence     = "";
	email         = "";
	phone         = "";
	package       = "";
	destination   = "";
	dateOftravel  = "";
	noOfdays      = "";
	noOfpeople    = "";
	flighTrain    = "";
	hotel         = "";
	paymentMode   = "";
}

void Booking::setName(string nm) { 
	name = nm; 
}

void Booking::setResidence(string rd) { 
	residence = rd; 
}

void Booking::setEmail(string em) { 
	email = em; 
}

void Booking::setPhone(string ph) { 
	phone = ph; 
}

void Booking::setPackage(string pk) { 
	package = pk; 
}

void Booking::setDestination(string ds) { 
	destination = ds; 
}

void Booking::setDateoftravel(string dt) { 
	dateOftravel = dt; 
}

void Booking::setNoofdays(string nd) { 
	noOfdays = nd; 
}

void Booking::setNoofpeople(string np) { 
	noOfpeople = np; 
}

void Booking::setFlightrain(string ft) { 
	flighTrain = ft; 
}

void Booking::setHotel(string ht) { 
	hotel = ht; 
}

void Booking::setPaymentmode(string pm) { 
	paymentMode = pm; 
}

int Booking::getBookingid() { 
	return bookingId; 
}

string Booking::getName() { 
	return name; 
}

string Booking::getResidence() { 
	return residence; 
}

string Booking::getEmail() { 
	return email; 
}

string Booking::getPhone() { 
	return phone; 
}

string Booking::getPackage() { 
	return package; 
}

string Booking::getDestination() { 
	return destination; 
}

string Booking::getDateoftravel() { 
	return dateOftravel; 
}

string Booking::getNoofdays() { 
	return noOfdays; }

string Booking::getNoofpeople() { 
	return noOfpeople; 
}

string Booking::getFlightrain() { 
	return flighTrain; 
}

string Booking::getHotel() { 
	return hotel; 
}

string Booking::getPaymentmode() { 
	return paymentMode; 
}

Booking::~Booking() {
}