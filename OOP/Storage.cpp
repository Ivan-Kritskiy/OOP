#include "Storage.h"
#include <iostream>
#include <fstream>
using namespace std;
void Storage::install_lib(string buff) {
	library.push_back(buff);
}
void Storage::show_lib() {
	for (int i = 0; i < library.size(); i++) {
		cout << library[i] << endl;
	}
}
void Storage::show_search() {
	for (int i = 0; i < search.size(); i++) {
		cout << search[i] << endl;
	}
}
void Storage::setup_lib(Storage& s) {
	library.clear();
	fstream lib("F:\\Word\\List.txt");
	string buff;
	while (getline(lib, buff, '\n')) {
		s.install_lib(buff);
	}
	lib.close();
}
void Storage::add_lib(string buff) {
	ofstream fout;
	fout.open("F:\\Word\\List.txt", fstream::app);
	fout << buff;
	fout.close();

}
void Storage::find_lib(string buff) {
	string p = "";
	search.clear();
	for (int i = 0; i < library.size(); i++) {
		for (int j = 0; j < library[i].size(); j++) {
			if ((library[i][j] == ':')&&(p == buff)) {
				search.push_back(library[i]);
				p = "";
				break;
			}
			else if ((library[i][j] == ':') && (p != buff)) {
				p = "";
				break;
			}
			p = p + library[i][j];
		}
	}
	
}
bool Storage::find_item(string buff) {
	string p = "";
	search.clear();
	for (int i = 0; i < library.size(); i++) {
		for (int j = 0; j <= library[i].size(); j++) {
			if (j < library[i].size()) {
				p = p + library[i][j];
			}
			if ((library[i].size()== j)&&(p == buff)) {
				search.push_back(library[i]);
				p = "";
				return true;
				break;
			}
			else if ((library[i].size() == j)&&(p != buff)) {
				p = "";
				break;
			}
		}
	}
	return false;
}
void Storage::delete_item(string f){
	library.clear();
	ifstream lib("F:\\Word\\List.txt");
	ofstream out("F:\\Word\\delete.txt");
	string buff;
	while (getline(lib, buff, '\n')) {
		if (buff != f) {
			out << buff << endl;
		}
	}
	lib.close();
	out.close();
	remove("F:\\Word\\List.txt");
	rename("F:\\Word\\delete.txt", "F:\\Word\\List.txt");
}