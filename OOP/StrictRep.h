#pragma once
#include "Limited.h"
#include "Rep.h"
#include <iostream>
#include <fstream>
using namespace std;
class Srep : public repository {
protected:
	Limited k;
public:
	void add() {
		int pags;
		string orient;
		string cov;
		string rarity;
		string parody;
		cout << "enter number of pages:" << endl;
		cin >> pags;
		if (pags < 0) {
			throw "negative pages";
		}
		cout << "enter orientation:" << endl;
		cin >> orient;
		if ((orient != "horizontal") && (orient != "diagonal")) {
			throw "wrong orientation";
		}
		cout << "enter cover:" << endl;
		cin >> cov;
		if ((cov != "fancy") && (cov != "scientific")) {
			throw "wrong cover";
		}
		cout << "enter rarity:" << endl;
		cin >> rarity;
		cout << "enter parody:" << endl;
		cin >> parody;
		Limited L(pags, orient, cov, rarity, parody);
		ofstream fout;
		fout.open("F:\\Word\\List.txt", fstream::app);
		fout << "\n" + (L.get_info());
		fout.close();
	}
};