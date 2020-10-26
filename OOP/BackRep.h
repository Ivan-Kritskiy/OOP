#pragma once
#include "Rep.h"
#include "Backup.h"
class BackRep : public repository {
protected:
	Backup B;
public:
	BackRep(Backup& B) {
		this->B = B;
	}
	void add() {
		B.create_backup();
	}
	void show() {
		B.show_backup();
	}
};