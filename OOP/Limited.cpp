#include "Limited.h"
#include <string>
Limited::Limited(int pages, string orientation, string cover, string rarity, string parody) :note(pages,orientation,cover) {
	this->rarity = rarity;
	this->parody = parody;
}
string Limited::get_info() {
	return "Notebook:" + to_string(pages) + ',' + orientation + ',' + cover + ",<<" + rarity + ">>,<<" + parody + ">>";
}