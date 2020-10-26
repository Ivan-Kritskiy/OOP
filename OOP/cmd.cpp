#include "cmd.h"
#include "Storage.h"
#include <algorithm>
#include "notebooks.h"
#include "History.h"
#include "Limited.h"
#include "deleted.h"
#include "Backup.h"
#include <string>
#include "NoteRep.h"
#include "StrictRep.h"
#include "StorRep.h"
#include "OrderRep.h"
#include "DelRep.h"
#include "HistRep.h"
#include "BackRep.h"
void cmd::menu(Storage& s, history& h) {
	bool exit = false;
	bool ord = false;
	order k;
	OrderRep O2 = OrderRep(k,s,h);
	Nrep n0;
	Srep n1;
	HistRep  h1= HistRep(h);
	StorRep s1 = StorRep(s);
	Deleted q;
	DelRep q1 = DelRep(q, h);
	Backup B;
	BackRep B1 = BackRep(B);
	B1.add();
	bool exit1 = false;
	bool exit2 = false;
	string buf;
	int choice;
	while (true) {
		if (exit == true) {
			break;
		}
		exit1 = false;
		exit2 = false;
		cout << "         Welcome to shop`s database" << endl;
		cout << endl;
		cout << "1 -- open shop`s storage" << endl;
		cout << "2 -- open order history" << endl;
		cout << "3 -- show confirmed order history" << endl;
		cout << "4 -- arrange an order" << endl;
		cout << "5 -- confirm an order" << endl;
		cout << "6 -- exit the program" << endl;
		cin >> choice;
		switch (choice) {                                    //
		case 6:
			exit = true;
			break;
		case 3:
			q1.show();
			break;
		case 5: {
			q1.add();
			break;
		}
		case 1:
			while (true) {
				if (exit1 == true) {
					break;
				}
				cout << "         Welcome to shop`s storage" << endl;
				cout << endl;
				cout << "1 -- show storage" << endl;
				cout << "2 -- add new item" << endl;
				cout << "3 -- find item" << endl;
				cout << "4 -- get back" << endl;
				cout << "5 -- delete item" << endl;
				cout << "6 -- add strict notebook" << endl;
				cout << "7 -- add limited notebook" << endl;
				cin >> choice;                              //
				switch (choice) {
				case 1:
					s1.show();
					break;
				case 2:
					s1.add();
					break;
				case 4:
					exit1 = true;
					break;
				case 3:
					s1.find();
					break;
				case 5:
					s1.remove();
					break;
				case 6: {
					n0.add();
					break;
				}
				case 7: {
					n1.add();
					break;
				}
				}
			}
		case 2:
			int count;
			while (true) {
				if (exit2 == true) {
					break;
				}
				cout << "         Welcome to shop`s history" << endl;
				cout << endl;
				cout << "1 -- show history" << endl;
				cout << "2 -- show backup" << endl;
				cout << "3 -- create backup" << endl;
				cout << "4 -- back" << endl;
				cin >> count;
				switch (count) {
				case 1:
					h1.show();
					break;
				case 4:
					exit2 = true;
				case 2:
					B1.show();
					break;
				case 3:
					B1.add();
					break;
				}
			}
			break;
		case 4:
			O2.add();
			break;
		
		}
	}
}