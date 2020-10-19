#include "Backup.h"
using namespace std;

void Backup::add_lib(string buff) {
	ofstream fout;
	fout.open("Bak.txt", fstream::app);
	fout << buff;
	fout.close();

}
void Backup::create_backup() {
	back.clear();
	ifstream lib("F:\\Word\\List.txt");
	ofstream out("Bak.txt");
	string buff;
	while (getline(lib, buff, '\n')) {
			out << buff << endl;
			back.push_back(buff);
	}
	lib.close();
	out.close();
}
void Backup::show_backup(){
	try {
		for (int i = 0; i < back.size(); i++) {
			cout << back[i]<< endl;
		}
	}
	catch (...) {
		cout << "Backup is damaged" << endl;
	}
}