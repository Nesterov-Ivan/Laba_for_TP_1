#include "stdafx.h"

#include "Keeper.h"
#include "Conference.h"
#include "Speaker.h"
#include "Administration.h"
#include "Program.h"

/*
#include "Conference.cpp"
#include "Speaker.cpp"
#include "Administration.cpp"
#include "Program.cpp"
*/

int main()
{
	setlocale(LC_ALL, "rus");

	ofstream f;			///открытие файла для записи
	ifstream in;		///открытие файла для чтения
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 12);
	cout << "Vnimanie! Pri vvode teksta vmesto probelov ispol'zuyte: _" << endl << endl;
	SetConsoleTextAttribute(handle, 15);
	Speaker speaker;
	Administration adm;
	Program program;

	string fail1, fail2, fail3;
	cout << endl << "Vvedite nazvanye faila dlya vistupayushih(vistup.txt): ";
	cin >> fail1;
	cout << endl << "Vvedite nazvanye faila dlya administracii(adm.txt): ";
	cin >> fail2;
	cout << endl << "Vvedite nazvanye faila dlya programy(program.txt): ";
	cin >> fail3;

	int switcha, a=1;

	while (a)
	{
		cout << endl << "Vyberite deystvie: " << endl
			<< "1 - Vyvesti dannye na ekran " << endl
			<< "2 - Dobavit' novye dannye " << endl
			<< "3 - Izmenit' dannye " << endl
			<< "0 - Exit" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
			cout << "Kakie dannye vyvesti?: " << endl
				<< "1 - Vistupayushie" << endl
				<< "2 - Administraciya" << endl
				<< "3 - programma" << endl
				<< "0 - Nazad" << endl;
			cin >> switcha;
			switch (switcha) {
			case 1: fail1>>speaker;
				break;
			case 2: fail2>>adm;
				break;
			case 3: fail3>>program;
				break;
			case 0:	break;
			}
			break;
		case 2:
			cout << "Kakie dannye dobavit'?: " << endl
				<< "1 - Vistupayushie" << endl
				<< "2 - Administraciya" << endl
				<< "3 - programma" << endl
				<< "0 - Nazad" << endl;
			cin >> switcha;
			switch (switcha) {
			case 1: fail1 << speaker;
				break;
			case 2: fail2 << adm;
				break;
			case 3: fail3 << program;
				break;
			case 0:	break;
			}
			break;
		case 3:
			cout << "Kakie dannye izmenit''?: " << endl
				<< "1 - Vistupayushie" << endl
				<< "2 - Administraciya" << endl
				<< "3 - programma" << endl
				<< "0 - Nazad" << endl;
			cin >> switcha;
			switch (switcha) {
			case 1: fail1 == speaker;
				break;
			case 2: fail2 += adm;
				break;
			case 3: fail3 -= program;
				break;
			case 0:	break;
			}
			break;
		}
	}
	system("pause");
    return 0;
}
