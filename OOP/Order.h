#ifndef ORDER
#define ORDER
#include <iostream>
using namespace std;
class order {
protected:
	string date;
	string customer;
	string item;
public:
	order(string date = "", string customer = "", string item = "");
	virtual string get_order();
	~order();
};
#endif