#ifndef HISTORY
#define HISTORY
#include "Order.h"
#include <vector>
class history {
private:
	vector<order> hist;
public:
	void add_order(order);
	void show_history();
	void install_history(history&);
	void renew_history(string haf);
	order string_to_order(string);

};
#endif