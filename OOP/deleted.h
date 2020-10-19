#ifndef deleted
#define deleted
#include "Order.h"
using namespace std;
class Deleted : public order {
private:
	string fin;
	string to_date;
public:
	Deleted(string date="", string customer="", string item="", string fin="", string to_date="");
	string get_order();
	void write(string);
	void show_del();
	bool find_del(string str);
};
#endif