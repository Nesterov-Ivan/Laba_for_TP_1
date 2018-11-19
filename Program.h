#pragma once
#include "stdafx.h"
#include "Conference.h"

class Program :public Conference
{
private:
	char day[10];
	char time[10];
	char tema[10];
public:
	friend Keeper;
	Program();
	Program(char *_day, char *_time, char *_tema);
	~Program();
	void set();
	void get();
	char* DAY();
	char* TIME();
	char* TEMA();
};
