#ifndef STORAGE
#define STORAGE
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


class Storage {
protected:
	vector<string> library;
	vector<string> search;
public:
	void show_lib();
	void install_lib(string);
	void setup_lib(Storage&);
	virtual void add_lib(string);
	void find_lib(string);
	void show_search();
	bool find_item(string);
	void delete_item(string);

};
#endif