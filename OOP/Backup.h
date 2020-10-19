#ifndef Bac
#define Bac
#include "Storage.h"
using namespace std;

class Backup : public Storage {
private:
	vector<string> back;
public:
	void create_backup();
	virtual void add_lib(string);
	void show_backup();
};



#endif