#ifndef NOTE
#define NOTE
#include <string>
using namespace std;
class note {
protected:
	int pages;
	string orientation;//horizontal or diagonal
	string cover;//fancy or scientific or both
public:
	note(int = 24, string = "?",string = "?");
	virtual string get_info();
	~note();
	int get_pages() {
		return pages;
	}
	string get_ori() {
		return orientation;
	}
	string get_cover() {
		return cover;
	}
};
#endif