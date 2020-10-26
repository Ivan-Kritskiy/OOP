#pragma once
#include "Rep.h"
#include "History.h"
class HistRep : public repository {
protected:
	history h;
public:
	HistRep(history& h) {
		this->h = h;
	}
	void show() {
		h.show_history();
	}
};