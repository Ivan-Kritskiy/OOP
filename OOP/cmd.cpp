#include "cmd.h"
#include "Storage.h"
#include <algorithm>
#include "notebooks.h"
#include "History.h"
#include "Limited.h"
#include "deleted.h"
#include "Backup.h"
#include <string>
void cmd::menu(Storage& s, history& h) {
	bool exit = false;
	Deleted q;
	Backup B;
	B.create_backup();
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
			q.show_del();
			break;
		case 5: {
			string str, str1, str2,str3,str4;
			h.show_history();
			cout << "copy your order data" << endl;
			cin >> str >> str1 >> str2;
			cout << "order is finished?(finished/failed)" << endl;
			cin >> str3;
			cout << "was order finished on time?(On_time/Late)" << endl;
			cin >> str4;
			Deleted F(str, str1, str2, str3, str4);
			order F1 = F;
			cout << F1.get_order() << endl;
			if (q.find_del(F1.get_order())) {
				F.write('\n'+ F.get_order());
				cout << "success" << endl;
			}
			else{
				cout << "your order was not found" << endl;
			}
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
					s.show_lib();
					break;
				case 2:
					cin >> buf;
					s.add_lib('\n' + buf);
					s.setup_lib(s);
					break;
				case 4:
					exit1 = true;
					break;
				case 3:
					cout << "What are you looking for?" << endl;
					cin >> buf;
					s.find_lib(buf);
					s.show_search();
					break;
				case 5:
					cout << "Input item to delete" << endl;
					cin >> buf;
					s.delete_item(buf);
					s.setup_lib(s);
					break;
				case 6: {
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
					note f(pages, orientation, cover);
					s.add_lib('\n' + f.get_info());
					s.setup_lib(s);
					break;
				}
				case 7: {
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
					s.add_lib('\n' + L.get_info());
					s.setup_lib(s);
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
					h.show_history();
					break;
				case 4:
					exit2 = true;
				case 2:
					B.show_backup();
					break;
				case 3:
					B.create_backup();
					break;
				}
			}
			break;
		case 4:
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
				order O(date, customer,"<<" + item + ">>");
				h.renew_history('\n' + O.get_order());
				h.install_history(h);
				cout << "Success, your item is found, order is set: " << O.get_order() << endl;
				s.delete_item(item);
				s.setup_lib(s);
				break;
			}
			else {
				cout << "your item is not found" << endl;
				break;
			}
		
		}
	}
}