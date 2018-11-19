#pragma once
#include "stdafx.h"
#include "Conference.h"

class Speaker :public Conference
{
private:
	char fio[20];
	char organization[20];
	char doklad[20];
	char anotacion[1000];
public:
	friend Keeper;
	Speaker();
	~Speaker();
	void set();
	void get();
	char* FIO();
	char* ORGANIZATION();
	char* DOKLAD();
	char* ANOTACION();
};
