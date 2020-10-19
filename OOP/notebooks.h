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
};
#endif