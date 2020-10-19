#include "deleted.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Deleted::Deleted(string date, string customer, string item, string fin, string to_date):order(date,customer,item) {
	this->fin = fin;
	this->to_date = to_date;
}
string Deleted::get_order() {
	return date + "," + customer + "," + item + "," + fin + "," + to_date;
}
void Deleted::write(string str) {
	ofstream F;
	F.open("Fin.txt", fstream::app);
	F << str;
	F.close();
}
void Deleted::show_del() {
		fstream lib("Fin.txt");
		string buff;
		while (getline(lib, buff, '\n')) {
			cout << buff << endl;
		}
		lib.close();
}
bool Deleted::find_del(string str) {
	ifstream F;
	string buff;
	F.open("His.txt");
	while (getline(F, buff, '\n')) {
		if (buff == str) {
			return true;
		}
	}
	return false;
}