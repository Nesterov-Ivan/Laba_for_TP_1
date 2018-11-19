#pragma once
#include "Keeper.h"

class Conference
{
private:

public:
	friend Keeper;
	Conference();
	~Conference();
	virtual void set() = 0;
	virtual void get() = 0;
};
