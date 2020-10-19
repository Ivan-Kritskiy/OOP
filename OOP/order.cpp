#include "Order.h"
order::order(string date, string customer, string item) {
	this->date = date;
	this->customer = customer;
	this->item = item;
}
string order::get_order() {
	return date + "," + customer + "," + item + ",";
}
order::~order() {
}
