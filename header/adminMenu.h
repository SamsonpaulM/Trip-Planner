#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <map>
using namespace std;

#include <dataLoad.h>
#include <admin.h>

#define success 1
#define failure 0
#define error -1

int checkAdmin(string);
void admin();

#endif