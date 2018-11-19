#include "stdafx.h"
#include "Administration.h"

Administration::Administration()
{
	fio[0] = '\0';
	position[0] = '\0';
	obl_otvet[0] = '\0';
	cout << "Administration#";
}

Administration::~Administration()
{
	cout << "#Administration";
}

void Administration::set()
{
	cout << "Vvedite FIO administratora: ";
	cin >> this->fio;
	cout << "Vvedite dolghnost': ";
	cin >> this->position;
	cout << "Vvedite oblast' otvetstvennosty: ";
	cin >> this->obl_otvet;
}

void Administration::get()
{
	cout << endl << "FIO: " << fio << endl;
	cout << "Dolghnost': " << position << endl;
	cout << "Oblast' otvetstvennosty: " << obl_otvet << endl;
}

char * Administration::FIO()
{
	return fio;
}

char * Administration::POSITION()
{
	return position;
}

char * Administration::OBL_OTVET()
{
	return obl_otvet;
}