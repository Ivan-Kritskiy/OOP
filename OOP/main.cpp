#include "notebooks.h"
#include "Storage.h"
#include "cmd.h"
#include <iostream>
#include "deleted.h"
using namespace std;
void main() {
Storage s;
history h;
cmd c;
s.setup_lib(s);
h.install_history(h);
c.menu(s, h);
}