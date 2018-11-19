#include "stdafx.h"
#include "Speaker.h"

Speaker::Speaker()
{
	fio[0] = '\0';
	organization[0] = '\0';
	doklad[0] = '\0';
	anotacion[0] = '\0';
	cout << "Speaker#";
}

Speaker::~Speaker()
{
	cout << "#Speaker";
}

void Speaker::set()
{
	cout << "Vvedite FIO vistupayushego: ";
	cin >> this->fio;
	cout << "Vvedite organizaciyu ili VYZ vistupayushego: ";
	cin >> this->organization;
	cout << "Vvedite temu doklada: ";
	cin >> this->doklad;
	cout << "Vvedite anotaciyu doklada: ";
	cin >> this->anotacion;
}

void Speaker::get()
{
	cout << endl << "FIO: " << fio << endl;
	cout << "Organizaciya/VYZ: " << organization << endl;
	cout << "Tema doklada: " << doklad << endl;
	cout << "Anotaciya doklada: " << anotacion << endl;
}

char * Speaker::FIO()
{
	return fio;
}

char * Speaker::ORGANIZATION()
{
	return organization;
}

char * Speaker::DOKLAD()
{
	return doklad;
}

char * Speaker::ANOTACION()
{
	return anotacion;
}
