#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <map>
using namespace std;

#include <adminMenu.h>
#include <dataLoad.h>
#include <admin.h>

#define success 1
#define failure 0
#define error -1

int checkAdmin(string password)
{
	if(password.compare("Admin") == 0)
		return success;
	else
		return failure;
}

void admin()
{
	string password;
	int ret, choice, pct;
	
	cout << "\033[1;94m\n\n\n\t\tEnter the password: \033[1;97m";
	getline(cin, password);

	ret = checkAdmin(password);

	while(1) {
		if(ret == 1) {
			cout << "\033[1;92m\n\n\n\t\tAdmin logged in.....";
			Admin a;
			cout << "\033[1;93m\n\n\n\t\tloading packages & bookings data.....";
			sleep(2);
			pct = a.loadPackagedata();
			a.loadBookingdata();

			while(1) {
				system("clear");

				cout << "\033[1;94m\n\n\n\t1. update packages";
				cout << "\033[1;94m\n\n\n\t2. view bookings";
				cout << "\033[1;94m\n\n\n\t3. logout";
				cout << "\033[1;94m\n\n\n\t\tchoose an option: \033[1;97m";
				cin >> choice;
				getchar();

				switch(choice) {
					case 1:
						a.updatePackages(pct);
						break;
					case 2:
						a.viewBookings();
						break;
					case 3:	
						a.logout();
						cout << "\033[1;92m\n\n\n\t\tAdmin logged out.....";
						sleep(2);
						return;
					default:
						cout << "\033[1;91m\n\n\n\t\tplease choose the correct option.....";
						sleep(2);
				}
			}
		}
		else {
			cout << "\033[1;91m\n\n\n\t\tpassword is incorrect.....";
			cout << "\033[1;94m\n\n\n\n\t\tEnter the password: ";
			getline(cin, password);

			ret = checkAdmin(password);
		}
	}
}