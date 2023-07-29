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

string PROJECTDIR = "../data/";

map<int, string> pmap;
map<int, Booking> bmap;

int Data::loadPackagedata()
{
	string package;
	int packageId = 0;
	ifstream f;

	try {
		f.open(PROJECTDIR + "packages.txt");
		if (!f.is_open())
			throw error;
	}
	catch(int e) {
		cout << "\033[1;91m\n\n\n\terror in opening file to read.....";
		return failure;
	}

	while(getline(f, package)) {
		pmap.insert({++packageId, package});
	}

	f.close();

	return packageId;
}

void Data::loadBookingdata()
{
	string str, token;
	int bid;
	ifstream f;

	try {
		f.open(PROJECTDIR + "bookings.txt");
		if (!f.is_open())
			throw error;
	}
	catch(int e) {
		cout << "\033[1;91m\n\n\terror in opening file to read.....";
		return;
	}

	while(getline(f, str)) {
		stringstream ss(str);

		Booking b; 

		bid = b.getBookingid();
		getline(ss, token, '|');  b.setName(token);
		getline(ss, token, '|');  b.setResidence(token);
		getline(ss, token, '|');  b.setEmail(token);
		getline(ss, token, '|');  b.setPhone(token);
		getline(ss, token, '|');  b.setPackage(token);
		getline(ss, token, '|');  b.setDestination(token);
		getline(ss, token, '|');  b.setDateoftravel(token);
		getline(ss, token, '|');  b.setNoofdays(token);
		getline(ss, token, '|');  b.setNoofpeople(token);
		getline(ss, token, '|');  b.setFlightrain(token);
		getline(ss, token, '|');  b.setHotel(token);
		getline(ss, token, '|');  b.setPaymentmode(token);

		bmap.insert({bid, b});
	}

	f.close();
}

void Data::logout()
{
	ofstream fp, fb;

	try {
		fp.open(PROJECTDIR + "packages.txt");
		if (!fp.is_open())
			throw error;
	}
	catch(int e) {
		cout << "\033[1;91m\n\n\terror in opening the file to write.....";
		return;
	}

	map<int, string>::iterator itp;
	for(itp = pmap.begin(); itp != pmap.end(); itp++) {
		fp << itp->second << "\n";
	}
	pmap.clear();
	fp.close();

	try {
		fb.open(PROJECTDIR + "bookings.txt");
		if (!fb.is_open())
			throw error;
	}
	catch(int e) {
		cout << "\033[1;91m\n\n\terror in opening file to write.....";
		return;
	}
	
	map<int, Booking>::iterator itb;
	for(itb = bmap.begin(); itb != bmap.end(); itb++) {
		fb << itb->second.getName() << "|" << itb->second.getResidence() << "|" << itb->second.getEmail() << "|" << itb->second.getPhone() << "|" << itb->second.getPackage() << "|" << itb->second.getDestination() << "|" << itb->second.getDateoftravel() << "|" << itb->second.getNoofdays() << "|" << itb->second.getNoofpeople() << "|" << itb->second.getFlightrain() << "|" << itb->second.getHotel() << "|" << itb->second.getPaymentmode() << "\n";
	}
	bmap.clear();
	fb.close();

	Booking::bookingId = 0;
}