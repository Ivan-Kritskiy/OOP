#pragma once
#include "Rep.h"
#include "Order.h"
#include "History.h"
class OrderRep : public repository {
protected:
	order k;
	Storage s;
	history h;
public:
	OrderRep(order& k, Storage& s, history& h) {
		this->k = k;
		this->s = s;
		this->h = h;
	};
	void add() {
		string date;
		string customer;
		string item;
		cout << "enter date" << endl;
		cin >> date;
		cout << "enter customer" << endl;
		cin >> customer;
		cout << "enter full item`s name" << endl;
		cin >> item;
		if (s.find_item(item) == true) {
			order O(date, customer, "<<" + item + ">>");
			h.renew_history('\n' + O.get_order());
			h.install_history(h);
			cout << "Success, your item is found, order is set: " << O.get_order() << endl;
			s.delete_item(item);
			s.setup_lib(s);
		}
		else {
			cout << "your item is not found" << endl;
		}
	}

};