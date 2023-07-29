#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <map>
using namespace std;

#include <clientMenu.h>
#include <dataLoad.h>
#include <client.h>

#define success 1
#define failure 0
#define error -1

extern string PROJECTDIR;

void clientLogin(string loginId)
{
	string str, token, name, password;
	int choice, flag = 0, pct;
	ifstream f;

	try {
		f.open(PROJECTDIR + "clients.txt");
		if (!f.is_open())
			throw error;
	}
	catch(int e) {
		cout << "\033[1;91m\n\n\n\n\n\terror in opening file to read.....";
		return;
	}

	while(getline(f, str)) {
		stringstream ss(str);
		getline(ss, token, '|');

		if(token.compare(loginId) == 0) {
			flag = 1;
			getline(ss, token, '|');
			getline(ss, name, '|');
			break;
		}
	}

	if(flag == 0) {
		cout << "\033[1;91m\n\n\n\t\tloginid " << loginId << " not found.....";
		sleep(2);
		return;
	}
			
	while(1) {
		cout << "\033[1;94m\n\n\n\t\tEnter password: \033[1;97m";
		getline(cin, password);

		if(token.compare(password) == 0) {
			cout << "\033[1;92m\n\n\n\t\t" << name << " logged in.....";	
			Client c;	
			cout << "\033[1;93m\n\n\n\n\t\tloading packages & bookings data.....";
			sleep(2);					
			pct = c.loadPackagedata();
			c.loadBookingdata();

			while(1) {
				system("clear");

				cout << "\033[1;94m\n\n\n\t1. book package";
				cout << "\033[1;94m\n\n\n\t2. view booking";
				cout << "\033[1;94m\n\n\n\t3. cancel booking";
				cout << "\033[1;94m\n\n\n\t4. rate booking";
				cout << "\033[1;94m\n\n\n\t5. logout";
				cout << "\033[1;94m\n\n\n\t\tchoose an option: \033[1;97m";
				cin >> choice;
				getchar();

				switch(choice) {
					case 1:
						c.bookPackage(pct, name);
						break;
					case 2:
						c.viewBooking(name);
						break;
					case 3:
						c.cancelBooking(name);
						break;
					case 4:
						c.rateBooking(name);
						break;
					case 5:
						c.logout();
						cout << "\033[1;92m\n\n\n\t\t" << name << " logged out.....";
						sleep(2);
						return;
					default:
						cout << "\033[1;91m\n\n\n\t\tplease choose the correct option.....";
						sleep(2);
				}
			}
		}
		else
			cout << "\033[1;91m\n\n\n\t\tpassword is incorrect.....";
	}
}

void clientSignup()
{
	system("clear");

	string loginId, password, name;
	ofstream f;

	cout << "\033[1;94m\n\n\n\n\n\tEnter email or phone number: \033[1;97m";
	getline(cin, loginId);
	cout << "\033[1;94m\n\n\n\tEnter password: \033[1;97m";
	getline(cin, password);
	cout << "\033[1;94m\n\n\n\tEnter name: \033[1;97m";
	getline(cin, name);

	try {
		f.open(PROJECTDIR + "Clients.txt", ios::app);
		if (!f.is_open())
			throw error;
	}
	catch(int e) {
		cout << "\033[1;91m\n\n\n\terror in opening file to write.....";
		return;
	}

	f << loginId << "|" << password << "|" << name << "\n";
	
	cout << "\033[1;92m\n\n\n\tsigned up successfully.....";
	sleep(2);

	f.close();
}