#include "History.h"
#include "Order.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void history::add_order(order c) {
	hist.push_back(c);
}
void history::show_history() {
	for (int i = 0; i < hist.size(); i++) {
		cout << hist[i].get_order() << endl;
	}
}
order history::string_to_order(string str) {
	int count = 0;
	string date;
	string customer;
	string item;
	string p = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ',') {
			switch (count) {
			case 0:
				date = p;
				break;
			case 1:
				customer = p;
				break;
			case 2:
				item = p;
				break;
			}
			count++;
			i++;
			p = "";
		}
		p = p + str[i];
	}
	order o(date, customer, item);
	return o;
}
void history::install_history(history& p) {
	hist.clear();
	fstream H("His.txt");
	string buff;
	while (getline(H, buff, '\n')) {
			p.add_order(string_to_order(buff));
	}
	H.close();
}
void history::renew_history(string haf) {
	ofstream fout;
	fout.open("His.txt", fstream::app);
	fout << haf;
	fout.close();

}