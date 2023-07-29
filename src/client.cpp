#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <map>
using namespace std;

#include <client.h>
#include <booking.h>

#define success 1
#define failure 0
#define error -1

extern string PROJECTDIR;

extern map<int, string> pmap;
extern map<int, Booking> bmap;

void Client::bookPackage(int pct, string clientname)
{	
	system("clear");
	
	string str[8], token[5], name, days, dest, dep, arr;
	int choice1, bid, fthid, flag, ct, dd, mm, yy;
	char choice2;
	ifstream f;
	map<int, string> fthmap;
	
	map<int, string>::iterator it;
	cout << "\n\n";
	for(it = pmap.begin(); it != pmap.end(); it++) {
		ct = 1;
			
		if((it->second).compare("") != 0) {
			cout << "\033[1;94m\n\n\n" << it->first << ".    ";
			stringstream ss(it->second);

			while(getline(ss, token[0], '|')) {
				if(ct > 4)
					cout << "\033[1;97m\n";				
				cout << token[0] << "    ";
				ct++;
			}
		}
	}

	cout << "\033[1;94m\n\n\n\tEnter package no. to book: \033[1;97m";  
	cin >> choice1;  
	getchar();

	while(choice1 > pct) {
		cout << "\033[1;91m\n\n\n\t\tpls choose between 1 and " << pct << ".....";
		cout << "\033[1;94m\n\n\n\tEnter package no. to book: \033[1;97m";  
		cin >> choice1;  
		getchar();
	}
	cout << "\033[1;94m\n\n\n\tEnter residence: \033[1;97m";  getline(cin, str[0]);
	cout << "\033[1;94m\n\n\n\tEnter email: \033[1;97m";  getline(cin, str[1]);
	cout << "\033[1;94m\n\n\n\tEnter phonenumber: \033[1;97m";  getline(cin, str[2]);
	
	cout << "\033[1;94m\n\n\n\tEnter date of travel: \033[1;97m";  
	getline(cin, str[3]);
	
	stringstream ss2(str[3]);
	
	getline(ss2, token[0], '/');  dd = stoi(token[0]);
	getline(ss2, token[0], '/');  mm = stoi(token[0]);
	getline(ss2, token[0], '/');  yy = stoi(token[0]);
	
	while((yy < tyy) || ((yy == tyy) && (mm < tmm)) || ((yy == tyy) && (mm == tmm) && (dd < tdd))) {				
		cout << "\033[1;91m\n\n\n\t\tpls choose date of travel after " << tdd << "/" << tmm << "/" << tyy << ".....";
		cout << "\033[1;94m\n\n\n\tEnter date of travel: \033[1;97m";  
		getline(cin, str[3]);
		stringstream ss2(str[3]);
	
		getline(ss2, token[0], '/');  dd = stoi(token[0]);
		getline(ss2, token[0], '/');  mm = stoi(token[0]);
		getline(ss2, token[0], '/');  yy = stoi(token[0]);
	}
	cout << "\033[1;94m\n\n\n\tEnter no. of people: \033[1;97m";  getline(cin, str[4]);
	cout << "\033[1;94m\n\n\n\tEnter payment mode: \033[1;97m";  getline(cin, str[5]);
	
	str[6] = pmap[choice1];
	stringstream ss3(str[6]);

	getline(ss3, name, '|');
	getline(ss3, days, '|');
	getline(ss3, dest, '|');
	stringstream ss4(dest);

	getline(ss4, dep, '-');
	getline(ss4, arr, '-');

	while(1) {
		system("clear");
		
		cout << "\033[1;94m\n\n\n\n\n\t1. check for flights/trains/hotels";
		cout << "\033[1;94m\n\n\n\t2. change date of travel";
		cout << "\033[1;94m\n\n\n\t3. nothing to check";
		cout << "\033[1;94m\n\n\n\t\tchoose an option: \033[1;97m";
		cin >> choice1;
		getchar();
	
		switch(choice1) {
			case 1:
				try {
					f.open(PROJECTDIR + "flightstrainshotels.txt");
					if (!f.is_open())
					throw error;
				}
				catch(int e) {
					cout << "\033[1;91m\n\n\n\terror in opening file to read.....";
					return;
				}

				flag = fthid = 0;
				cout << "\n\n";

				while(getline(f, str[7])) {
					stringstream ss5(str[7]);

					getline(ss5, token[0], '|');
					getline(ss5, token[1], '|');
					getline(ss5, token[2], '|');

					if((token[0].compare(dep) == 0) && (token[1].compare(arr) == 0) && (token[2].compare(str[3]) == 0)) {
						flag = 1;
						fthmap.insert({++fthid, str[7]});	
						cout << "\033[1;94m\n\n\n\t\t" << fthid << ".  " << fthmap[fthid];
					}
				}
				f.close();
				
				if(flag == 1) {
					cout << "\033[1;94m\n\n\n\t\t\tif you are okay with any flight/train/hotel to depart and stay, do confirm to book? (y/n): \033[1;97m";
					cin >> choice2;
					getchar();
					if(choice2 == 'n')
						break;
					
					cout << "\033[1;94m\n\n\n\t\t\tchoose an option: \033[1;97m";
					cin >> choice1;
					getchar();
					stringstream ss6(fthmap[choice1]);
					
					getline(ss6, token[0], '|');
					getline(ss6, token[1], '|');
					getline(ss6, token[2], '|');
					getline(ss6, token[3], '|');
					getline(ss6, token[4], '|');
													
					Booking b;
					
					bid = b.getBookingid();
					b.setName(clientname);
					b.setResidence(str[0]);
					b.setEmail(str[1]);
					b.setPhone(str[2]);
					b.setPackage(name);
					b.setDestination(dest);
					b.setDateoftravel(str[3]);
					b.setNoofdays(days);
					b.setNoofpeople(str[4]);
					b.setFlightrain(token[3]);
					b.setHotel(token[4]);
					b.setPaymentmode(str[5]);
					
					bmap.insert({bid, b});
				}	
				else {
					cout << "\033[1;91m\n\n\n\t\tno flights/trains/hotels available, pls change your date of travel.....";
					sleep(2);
				}
				fthmap.clear();
				break;
			case 2:
				cout << "\033[1;94m\n\n\n\t\tEnter new date of travel: \033[1;97m";
				getline(cin, str[3]);
				break;
			case 3:
				return;
				break;
			default:
				cout << "\033[1;91m\n\n\n\t\tplease choose the correct option.....";
				sleep(2);
		}
	}
}

void Client::viewBooking(string clientname)
{
	string str;
	int flag = 0;
	
	map<int, Booking>::iterator it;
	for(it = bmap.begin(); it != bmap.end(); it++) {
		str = it->second.getName();		

		if(str.compare(clientname) == 0) {
			if(flag == 0) {
				system("clear");
				cout << "\n\n";
			}
			flag = 1;		
			
			cout << "\033[1;94m\n\n\n\tBooking Id       :  " << it->first;
			cout << "\033[1;94m\n\n\tName             :  " << bmap[it->first].getName();
			cout << "\033[1;94m\n\n\tResidence        :  " << bmap[it->first].getResidence();
			cout << "\033[1;94m\n\n\tEmail            :  " << bmap[it->first].getEmail();
			cout << "\033[1;94m\n\n\tPhone            :  " << bmap[it->first].getPhone();
			cout << "\033[1;94m\n\n\tPackage          :  " << bmap[it->first].getPackage();
			cout << "\033[1;94m\n\n\tDestination      :  " << bmap[it->first].getDestination();
			cout << "\033[1;94m\n\n\tDate of Travel   :  " << bmap[it->first].getDateoftravel();
			cout << "\033[1;94m\n\n\tNo. of Days      :  " << bmap[it->first].getNoofdays();
			cout << "\033[1;94m\n\n\tNo. of People    :  " << bmap[it->first].getNoofpeople();
			cout << "\033[1;94m\n\n\tFlight/Train     :  " << bmap[it->first].getFlightrain();
			cout << "\033[1;94m\n\n\tHotel            :  " << bmap[it->first].getHotel();
			cout << "\033[1;94m\n\n\tPayment Mode     :  " << bmap[it->first].getPaymentmode();
		}
	}

	if(flag == 0) {
		cout << "\033[1;91m\n\n\n\t\tclient " << clientname << " has no bookings.....";
		sleep(2);
		return;
	}
	
	cout << "\033[1;93m\n\n\n\tpress Enter key to return.....";
	getchar();
}

void Client::cancelBooking(string clientname)
{
	string str;
	int choice, flag = 0;
	
	map<int, Booking>::iterator it;
	for(it = bmap.begin(); it != bmap.end(); it++) {
		str = it->second.getName();
		
		if(str.compare(clientname) == 0) {
			if(flag == 0) {
				system("clear");
				cout << "\n\n";
			}
			flag = 1;
			
			cout << "\033[1;94m\n\n\n\t" << it->first << " : " << it->second.getPackage() << "|" << it->second.getDestination();
		}
	} 
	
	if(flag == 0) {
		cout << "\033[1;91m\n\n\n\t\tClient " << clientname << " has no bookings.....";
		sleep(2);
		return;
	}
	
	cout << "\033[1;94m\n\n\n\t\tEnter the booking id to cancel: \033[1;97m";
	cin >> choice;
	getchar();
	
	bmap.erase(choice);
		
	cout << "\033[1;93m\n\n\n\tpress Enter key to return.....";
	getchar();
}

void Client::rateBooking(string clientname)
{
	string str[2], rate, token;
	int choice, flag = 0, dd, mm, yy;
	
	map<int, Booking>::iterator it;
	for(it = bmap.begin(); it != bmap.end(); it++) {
		str[0] = it->second.getName();
		
		if(str[0].compare(clientname) == 0) {
			if(flag == 0) {
				system("clear");
				cout << "\n\n";
			}
			flag = 1;
			
			cout << "\033[1;94m\n\n\n\t" << it->first << " : " << it->second.getPackage() << "|" << it->second.getDestination();
		}
	} 
	
	if(flag == 0) {
		cout << "\033[1;91m\n\n\n\t\tClient " << clientname << " has no bookings.....";
		sleep(2);
		return;
	}
	
	cout << "\033[1;94m\n\n\n\t\tEnter the booking id to rate: \033[1;97m";
	cin >> choice;
	getchar();
	str[1] = bmap[choice].getDateoftravel();	
	stringstream ss(str[1]);

	getline(ss, token, '/');  dd = stoi(token);
	getline(ss, token, '/');  mm = stoi(token);
	getline(ss, token, '/');  yy = stoi(token);
					
	if((yy < tyy) || ((yy == tyy) && (mm < tmm)) || ((yy == tyy) && (mm == tmm) && (dd < tdd))) {
		cout << "\033[1;94m\n\n\n\t\thow much you are satisfied with our " << bmap[choice].getPackage() << " out of * * * * *: \033[1;97m";
		getline(cin, rate);

		map<int, string>::iterator it;
		for(it = pmap.begin(); it != pmap.end(); it++) {
			stringstream ss2(it->second);
				getline(ss2, token, '|');

				if(token.compare(bmap[choice].getPackage()) == 0)
					it->second = it->second + '|' + rate;
		}
	}
	else {
		cout << "\033[1;94m\n\n\n\t\tclient " << clientname <<", please rate your " << bmap[choice].getPackage() << " package after completing it.....";
		sleep(2);
		return;	
	}
	
	cout << "\033[1;93m\n\n\n\t\tpress Enter key to return.....";
	getchar();
}