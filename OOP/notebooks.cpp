#include <string>
#include "notebooks.h"
#include <iostream>
using namespace std;

note::note(int pages, string orientation, string cover) {
	if (pages <= 0) throw "quite a book you have there! One without pages...";
	this->pages = pages;
	this->orientation = orientation;
	this->cover = cover;
}
string note::get_info() {
	return "Notebook:" + to_string(pages) + "," + orientation + "," + cover + "\n";
}
note::~note(){
}