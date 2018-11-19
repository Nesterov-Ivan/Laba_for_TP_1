#pragma once
#include "stdafx.h"
#include "Conference.h"

class Administration :public Conference
{
private:
	char fio[20];
	char position[20];
	char obl_otvet[20];
public:
	friend Keeper;
	Administration();
	~Administration();
	void set();
	void get();
	char* FIO();
	char* POSITION();
	char* OBL_OTVET();
};
