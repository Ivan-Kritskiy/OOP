#ifndef CMD
#define CMD
#include <iostream>
#include "Storage.h"
#include "History.h"
using namespace std;
class cmd {
public:
	void menu(Storage&, history& h);
};
#endif 
