#pragma once
#include "Rep.h"
#include "notebooks.h"
#include <iostream>
using namespace std;
class Nrep : public repository {
protected:
	note k;
public:
	Nrep(note k = note(24,"horizontal", "fancy")) {
		this->k = k;
	}
	void add() {
		int pages;
		string orientation;
		string cover;
		cout << " number of pages:" << endl;
		cin >> pages;
		if (pages < 0) {
			throw "negative pages";
		}
		cout << " orientation:" << endl;
		cin >> orientation;
		if ((orientation != "horizontal") && (orientation != "diagonal")) {
			throw "wrong orientation";
		}
		cout << " cover:" << endl;
		cin >> cover;
		if ((cover != "fancy") && (cover != "scientific")) {
			throw "wrong cover";
		}
		ofstream fout;
		fout.open("F:\\Word\\List.txt", fstream::app);
		fout << "\n"+( "Notebook:" + to_string(pages) + "," + orientation + "," + cover);
		fout.close();
	};
};