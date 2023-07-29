#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <map>
using namespace std;

#include <adminMenu.h>
#include <clientMenu.h>

#define success 1
#define failure 0
#define error -1

int main()
{
	string loginId;
	int choice1;
	char choice2;
	
	while(1) {
		system("clear");

		cout << "\033[1;94m\n\n\n\n\n\t1. Admin";
		cout << "\033[1;94m\n\n\n\t2. Others";
		cout << "\033[1;94m\n\n\n\t\tchoose an option: \033[1;97m";
		cin >> choice1;
		getchar();

		switch(choice1) {
			case 1:
				admin();
				break;
			case 2:
				system("clear");

				cout << "\033[1;94m\n\n\n\n\n\t1. sign up";
				cout << "\033[1;94m\n\n\n\t2. log in";
				cout << "\033[1;94m\n\n\n\t\tchoose an option: \033[1;97m";
				cin >> choice1;
				getchar();

				switch(choice1) {
					case 1:
						clientSignup();
						break;
					case 2:
						cout << "\033[1;94m\n\n\n\t\tEnter email or phone number: \033[1;97m";
						getline(cin, loginId);
						clientLogin(loginId);
						break;
				}
				break;
		}
		
		system("clear");

		cout << "\033[1;94m\n\n\n\n\n\tDo you want to continue with the application? (y/n): \033[1;97m";
		cin >> choice2;
		getchar();
		if (choice2 == 'n')
			return success;
	}
}