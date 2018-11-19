#include "stdafx.h"
#include "Program.h"

Program::Program()
{
	day[0] = '\0';
	time[0] = '\0';
	tema[0] = '\0';
	cout << "Program#";
}

Program::Program(char * _day, char * _time, char * _tema)
{
	strcpy_s(day, _day);
	strcpy_s(time, _time);
	strcpy_s(tema, _tema);
}

Program::~Program()
{
	cout << "#Program";
}

void Program::set()
{
LOOP:
	cout << "Vvedite datu vyistupleniya(dd.mm.yyyy): ";
	cin >> this->day;
	for (int i = 0; i < strlen(day); i++)
		if (!isdigit(day[i]) && day[i] != '.')
		{
			cout << "Nekkorektno vvedeny dannyi! Povtorite vvod:";
			goto LOOP;
		}
LOOP1:
	cout << "Vvedite vremya vyistupleniya(hh.mm): ";
	cin >> this->time;
	for (int i = 0; i < strlen(time); i++)
		if (!isdigit(time[i]) && day[i] != '.')
		{
			cout << "Nekkorektno vvedeny dannyi! Povtorite vvod:";
			goto LOOP1;
		}
	cout << "Vvedite temu doklada: ";
	cin >> this->tema;
}

void Program::get()
{
	cout << endl << "Day: " << day << endl;
	cout << "Time: " << time << endl;
	cout << "Tema doklada: " << tema << endl;
}

char * Program::DAY()
{
	return day;
}

char * Program::TIME()
{
	return time;
}

char * Program::TEMA()
{
	return tema;
}