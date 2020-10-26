#pragma once
#include "Rep.h"
#include "Storage.h"
#include <iostream>
using namespace std;
class StorRep : public repository{
protected:
	Storage k;
public:
	StorRep(Storage& k) {
		this->k = k;
	}
	void remove() {
		string buf;
		cout << "Input item to delete" << endl;
		cin >> buf;
		k.delete_item(buf);
		k.setup_lib(k);
	}
	void find() {
		string buf;
		cout << "What are you looking for?" << endl;
		cin >> buf;
		k.find_lib(buf);
		k.show_search();
	}
	void add() {
		string buf;
		cin >> buf;
		k.add_lib('\n' + buf);
		k.setup_lib(k);
	}
	void show() {
		k.show_lib();
	}
};
