#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <map>
using namespace std;

#include <admin.h>
#include <booking.h>

#define success 1
#define failure 0
#define error -1

extern map<int, string> pmap;
extern map<int, Booking> bmap;

void Admin::displayPackages()
{
	string token;
	int ct;
	
	map<int, string>::iterator it;
	cout << "\n\n";
	for(it = pmap.begin(); it != pmap.end(); it++) {
		ct = 1;
	
		if((it->second).compare("") != 0) {
			cout << "\033[1;94m\n\n\n" << it->first << ".    ";
			stringstream ss(it->second);

			while(getline(ss, token, '|')) {
				if(ct > 4)
					cout << "\033[1;97m\n";	
				cout << token << "    ";
				ct++;	
			}
		}
	}
}

void Admin::displayBookings(int bid, Booking b)
{	
	cout << "\033[1;94m\n\n\n\tBooking Id       :  " << bid;
	cout << "\033[1;94m\n\tName             :  " << b.getName();
	cout << "\033[1;94m\n\tResidence        :  " << b.getResidence();
	cout << "\033[1;94m\n\tEmail            :  " << b.getEmail();
	cout << "\033[1;94m\n\tPhone            :  " << b.getPhone();
	cout << "\033[1;94m\n\tPackage          :  " << b.getPackage();
	cout << "\033[1;94m\n\tDestination      :  " << b.getDestination();
	cout << "\033[1;94m\n\tDate of Travel   :  " << b.getDateoftravel();
	cout << "\033[1;94m\n\tNo. of Days      :  " << b.getNoofdays();
	cout << "\033[1;94m\n\tNo. of People    :  " << b.getNoofpeople();
	cout << "\033[1;94m\n\tFlight/Train     :  " << b.getFlightrain();
	cout << "\033[1;94m\n\tHotel            :  " << b.getHotel();
	cout << "\033[1;94m\n\tPayment Mode     :  " << b.getPaymentmode();
}
			
void Admin::updatePackages(int pct)
{
	system("clear");

	string str[2], token, name, days, dest, price;
	int choice1, choice2, flag, ct;
	char choice3;
	
	while(1) {
		displayPackages();
		
		cout << "\033[1;94m\n\n\n\tEnter the package no. to update: \033[1;97m";
		cin >> choice1;
		getchar();

		while(choice1 > pct) {
			cout << "\033[1;91m\n\n\n\t\tpls choose between 1 and " << pct << ".....";
			cout << "\033[1;94m\n\n\n\tEnter the package no. to update: \033[1;97m";
			cin >> choice1;
			getchar();
		}
		flag = ct = 1;
		str[0] = pmap[choice1];

		stringstream ss(str[0]);
		getline(ss, name, '|');
		getline(ss, days, '|');
		getline(ss, dest, '|');
		getline(ss, price, '|');

		while(flag == 1) {
			system("clear");

			cout << "\033[1;94m\n\n\n\n\n\t1. update package name";
			cout << "\033[1;94m\n\n\n\t2. update package price";
			cout << "\033[1;94m\n\n\n\t3. nothing to update";
			cout << "\033[1;94m\n\n\n\t\tchoose an option: \033[1;97m";
			cin >> choice2;
			getchar();

			switch(choice2) {
				case 1:
					cout << "\033[1;94m\n\n\n\t\tEnter the new package name: \033[1;97m";
					getline(cin, name);
					break;
				case 2:
					cout << "\033[1;94m\n\n\n\t\tEnter the new package price: \033[1;97m";
					getline(cin, price);
					break;
				case 3:
					flag = 0;
					break;
				default:
					cout << "\033[1;91m\n\n\n\t\tplease choose the correct option.....";
					sleep(2);
			}
		}
		str[1] = name + '|' + days + '|' + dest + '|' + price;

		stringstream ss2(str[0]);

		while(getline(ss2, token, '|')) {
			if(ct > 4)
				str[1] = str[1] + '|' + token;
			ct++;
		}
		pmap[choice1] = str[1];

		cout << "\033[1;94m\n\n\n\t\tDo you want to update any other package? (y/n): \033[1;97m";
		cin >> choice3;
		getchar();
		if(choice3 == 'n')
			break;
	}

	system("clear");
	
	cout << "\033[1;94m\n\n\n\n\n\tupdated packages.....";
	displayPackages();

	cout << "\033[1;93m\n\n\n\tpress Enter key to return.....";
	getchar();
}

void Admin::viewBookings()
{	
	string str, token, name;
	int choice, flag, dd, mm, yy;
	
	while(1) {
		system("clear");
	
		cout << "\033[1;94m\n\n\n\n\n\t1. completed bookings";
		cout << "\033[1;94m\n\n\n\t2. future bookings";
		cout << "\033[1;94m\n\n\n\t3. client's booking";
		cout << "\033[1;94m\n\n\n\t4. nothing to view";
		cout << "\033[1;94m\n\n\n\t\tchoose an option: \033[1;97m";
		cin >> choice;
		getchar();

		map<int, Booking>::iterator it;

		switch(choice) {
			case 1:
				system("clear");
				cout << "\n\n";

				for(it = bmap.begin(); it != bmap.end(); it++) {
					str = it->second.getDateoftravel();
					stringstream ss(str);

					getline(ss, token, '/');  dd = stoi(token);
					getline(ss, token, '/');  mm = stoi(token);
					getline(ss, token, '/');  yy = stoi(token);
					
					if((yy < tyy) || ((yy == tyy) && (mm < tmm)) || ((yy == tyy) && (mm == tmm) && (dd < tdd)))
						displayBookings(it->first, it->second);

				}
			
				cout << "\033[1;93m\n\n\n\tpress Enter key to return.....";
				getchar();
				break;
			case 2:
				system("clear");
				cout << "\n\n";
			
				for(it = bmap.begin(); it != bmap.end(); it++) {
					str = it->second.getDateoftravel();
					stringstream ss(str);

					getline(ss, token, '/');  
					dd = stoi(token);
					getline(ss, token, '/');  
					mm = stoi(token);

					if(!((yy < tyy) || ((yy == tyy) && (mm < tmm)) || ((yy == tyy) && (mm == tmm) && (dd < tdd))))
						displayBookings(it->first, it->second);
				}
			
				cout << "\033[1;93m\n\n\n\tpress Enter key to return.....";
				getchar();
				break;
			case 3:
				system("clear");

				cout << "\033[1;94m\n\n\n\n\n\tEnter client's name: \033[1;97m";
				getline(cin, name);
				flag = 0;
	
				for(it = bmap.begin(); it != bmap.end(); it++) {
					str = it->second.getName();		

					if(str.compare(name) == 0) {
						flag = 1;		
			
						cout << "\033[1;94m\n\n\n\t\tBooking Id       :  " << it->first;
						cout << "\033[1;94m\n\n\t\tName             :  " << bmap[it->first].getName();
						cout << "\033[1;94m\n\n\t\tResidence        :  " << bmap[it->first].getResidence();
						cout << "\033[1;94m\n\n\t\tEmail            :  " << bmap[it->first].getEmail();
						cout << "\033[1;94m\n\n\t\tPhone            :  " << bmap[it->first].getPhone();
						cout << "\033[1;94m\n\n\t\tPackage          :  " << bmap[it->first].getPackage();
						cout << "\033[1;94m\n\n\t\tDestination      :  " << bmap[it->first].getDestination();
						cout << "\033[1;94m\n\n\t\tDate of Travel   :  " << bmap[it->first].getDateoftravel();
						cout << "\033[1;94m\n\n\t\tNo. of Days      :  " << bmap[it->first].getNoofdays();
						cout << "\033[1;94m\n\n\t\tNo. of People    :  " << bmap[it->first].getNoofpeople();
						cout << "\033[1;94m\n\n\t\tFlight/Train     :  " << bmap[it->first].getFlightrain();
						cout << "\033[1;94m\n\n\t\tHotel            :  " << bmap[it->first].getHotel();
						cout << "\033[1;94m\n\n\t\tPayment Mode     :  " << bmap[it->first].getPaymentmode();
					}
				}

				if(flag == 0) {
					cout << "\033[1;91m\n\n\n\tclient " << name << " has no bookings.....";
					sleep(2);
					break;
				}
	
				cout << "\033[1;93m\n\n\n\t\tpress Enter key to return.....";
				getchar();
				break;
			case 4:
				return;
				break;
			default:
				cout << "\033[1;91m\n\n\n\t\tplease choose the correct option.....";
				sleep(2);
		}
	}

	cout << "\033[1;93m\n\n\n\tpress Enter key to return.....";
	getchar();
}