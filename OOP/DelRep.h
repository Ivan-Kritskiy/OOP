#pragma once
#include "deleted.h"
#include "History.h"
#include "Rep.h"
class DelRep : public repository {
protected:
	Deleted q;
	history h;
public:
	DelRep(Deleted& q, history& h) {
		this->q = q;
		this->h = h;
	}
	void add() {
		string str, str1, str2, str3, str4;
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
			F.write('\n' + F.get_order());
			cout << "success" << endl;
		}
		else {
			cout << "your order was not found" << endl;
		}
	}
	void show() {
		q.show_del();
	}
};