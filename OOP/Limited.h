#ifndef Lim
#define Lim
#include "notebooks.h"
#include <iostream>
using namespace std;
class Limited : public note {
protected:
	string rarity;
	string parody;
public:
	string get_info();
	Limited(int = 24,string="horizontal",string="fancy",string="rare",string="mumintroll");
};

#endif
