#ifndef CLIENTMENU_H
#define CLIENTMENU_H

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <map>
using namespace std;

#include <dataLoad.h>
#include <client.h>

#define success 1
#define failure 0
#define error -1

void clientLogin(string);
void clientSignup();

#endif