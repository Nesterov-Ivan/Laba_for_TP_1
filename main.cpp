#include "stdafx.h"

class Keeper
{
public:
	Keeper();
	~Keeper();

	template<typename T>
	friend void operator<<(const string file, T data);
	template<typename T>
	friend void operator>>(const string file, T data);
	template<typename T>
	friend void operator==(const string file, T data);
	template<typename T>
	friend void operator+=(const string file, T data);
	template<typename T>
	friend void operator-=(const string file, T data);
};

Keeper::Keeper()
{
	cout << "Keeper#";
}

Keeper::~Keeper()
{
	cout << "#Keeper";
}



class Conference
{
private:

public:
	friend Keeper;
	Conference();
	~Conference();
	virtual void set()=0;
	virtual void get()=0;
};

Conference::Conference()
{
	cout << "Conference#";
}

Conference::~Conference()
{
	cout << "#Conference";
}

class Speaker:public Conference
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

class Administration:public Conference
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

class Program:public Conference
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

template<typename T>
void operator<<(const string file, T data)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	ofstream f;
	try
	{
		f.open(file, ios::binary | ios::app);
		if (!f.is_open()) {
			throw 777;
		}
		int switcha;
		while (true)
		{
			data.set();
			f.write(reinterpret_cast<char*>(&data), sizeof(T));
		LOOP2:
			cout << "Vveli vse dannyii? \n1 - YES\n2 - NO " << endl;
			cin >> switcha;
			if (switcha != 1 && switcha != 2)
			{
				cout << "Oshibka! Neverno vyibrali variant. Povtorite vvod: " << endl;
				goto LOOP2;
			}
			else if (switcha == 1)
				break;
		}
		f.close();
	}
	catch (const int &ex)
	{
		SetConsoleTextAttribute(handle, 12);
		cout << "Oshibka otkritiya faila!" << endl;
		SetConsoleTextAttribute(handle, 15);
	}
}

template<typename T>
void operator>>(const string file, T data)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	ifstream in;
	try
	{
		in.open(file, ios::binary | ios::in);
		if (!in.is_open()) {
			throw 777;
		}
		while (in.read(reinterpret_cast<char*>(&data), sizeof(T)))
			data.get();
		in.close();
	}
	catch (const int &ex)
	{
		SetConsoleTextAttribute(handle, 12);
		cout << "Oshibka otkritiya faila!" << endl;
		SetConsoleTextAttribute(handle, 15);
	}
}

template<typename T>
void operator==(const string file, T data)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	ofstream f;
	ifstream in;
	int switcha = 0, counter = 0;
	T* helper;
	try
	{
		in.open(file, ios::binary | ios::out);
		if (!in.is_open())
		{
			throw 777;
		}
		while (in.read(reinterpret_cast<char*>(&data), sizeof(T)))
			counter++;

		in.clear();
		in.seekg(0);

		helper = new T[counter];
		counter = 0;
		while (in.read(reinterpret_cast<char*>(&data), sizeof(T))) {
			helper[counter] = data;
			helper[counter].get();
			counter++;
		}
		in.close();
	}
	catch (const int &ex)
	{
		SetConsoleTextAttribute(handle, 12);
		cout << "Oshibka otkritiya faila!" << endl;
		SetConsoleTextAttribute(handle, 15);
	}

	char FIO[20];
	cout << "Vvedite FIO vistupayushego: ";
	cin >> FIO;
LOOP3:
	cout << "Chto delat'? \n1 - IZMENIT'\n2 - UDALIT' " << endl;
	cin >> switcha;

	if (switcha == 1) {
		try
		{
			f.open(file, ios::binary | ios::out);
			if (!f.is_open())
			{
				throw 777;
			}
			for (int i = 0; i < counter; i++)
			{
				if (strcmp(helper[i].FIO(), FIO) == 0)
				{
					cout << "NEW DATA: " << endl;
					helper[i].set();
					f.write(reinterpret_cast<char*>(&helper[i]), sizeof(T));
				}
				else
				{
					f.write(reinterpret_cast<char*>(&helper[i]), sizeof(T));
				}
			}
			delete[] helper;
			f.close();

		}
		catch (const int &ex)
		{
			SetConsoleTextAttribute(handle, 12);
			cout << "Oshibka otkritiya faila!" << endl;
			SetConsoleTextAttribute(handle, 15);
		}
	}
	if (switcha == 2)
	{
		try
		{
			f.open(file, ios::binary | ios::out);
			if (!f.is_open())
			{
				throw 777;
			}
			for (int i = 0; i < switcha; i++)
			{
				if (strcmp(helper[i].FIO(), FIO) != 0)
				{
					f.write(reinterpret_cast<char*>(&helper[i]), sizeof(T));
					helper[i].get();
				}
			}
			delete[] helper;
			f.close();
		}
		catch (const int &ex)
		{
			SetConsoleTextAttribute(handle, 12);
			cout << "Oshibka otkritiya faila!" << endl;
			SetConsoleTextAttribute(handle, 15);
		}
	}
	if (switcha != 1 && switcha != 2)
		goto LOOP3;
}

template<typename T>
void operator+=(const string file, T data)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	ofstream f;
	ifstream in;
	int switcha = 0, counter = 0;
	T* helper;
	try
	{
		in.open(file, ios::binary | ios::out);
		if (!in.is_open())
		{
			throw 777;
		}
		while (in.read(reinterpret_cast<char*>(&data), sizeof(T)))
			counter++;

		in.clear();
		in.seekg(0);

		helper = new T[counter];
		counter = 0;
		while (in.read(reinterpret_cast<char*>(&data), sizeof(T))) {
			helper[counter] = data;
			helper[counter].get();
			counter++;
		}
		in.close();
	}
	catch (const int &ex)
	{
		SetConsoleTextAttribute(handle, 12);
		cout << "Oshibka otkritiya faila!" << endl;
		SetConsoleTextAttribute(handle, 15);
	}

	char FIO[20];
	cout << "Vvedite FIO administratora: ";
	cin >> FIO;
LOOP4:
	cout << "Chto delat'? \n1 - IZMENIT'\n2 - UDALIT' " << endl;
	cin >> switcha;

	if (switcha == 1) {
		try
		{
			f.open(file, ios::binary | ios::out);
			if (!f.is_open())
			{
				throw 777;
			}
			for (int i = 0; i < counter; i++)
			{
				if (strcmp(helper[i].FIO(), FIO) == 0)
				{
					cout << "NEW DATA: " << endl;
					helper[i].set();
					f.write(reinterpret_cast<char*>(&helper[i]), sizeof(T));
				}
				else
				{
					f.write(reinterpret_cast<char*>(&helper[i]), sizeof(T));
				}
			}
			delete[] helper;
			f.close();

		}
		catch (const int &ex)
		{
			SetConsoleTextAttribute(handle, 12);
			cout << "Oshibka otkritiya faila!" << endl;
			SetConsoleTextAttribute(handle, 15);
		}
	}
	if (switcha == 2)
	{
		try
		{
			f.open(file, ios::binary | ios::out);
			if (!f.is_open())
			{
				throw 777;
			}
			for (int i = 0; i < switcha; i++)
			{
				if (strcmp(helper[i].FIO(), FIO) != 0)
				{
					f.write(reinterpret_cast<char*>(&helper[i]), sizeof(T));
					helper[i].get();
				}
			}
			delete[] helper;
			f.close();
		}
		catch (const int &ex)
		{
			SetConsoleTextAttribute(handle, 12);
			cout << "Oshibka otkritiya faila!" << endl;
			SetConsoleTextAttribute(handle, 15);
		}
	}
	if (switcha != 1 && switcha != 2)
		goto LOOP4;
}

template<typename T>
void operator-=(const string file, T data)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	ofstream f;
	ifstream in;
	int switcha = 0, counter = 0;
	T* helper;
	try
	{
		in.open(file, ios::binary | ios::out);
		if (!in.is_open())
		{
			throw 777;
		}
		while (in.read(reinterpret_cast<char*>(&data), sizeof(T)))
			counter++;

		in.clear();
		in.seekg(0);

		helper = new T[counter];
		counter = 0;
		while (in.read(reinterpret_cast<char*>(&data), sizeof(T))) {
			helper[counter] = data;
			helper[counter].get();
			counter++;
		}
		in.close();
	}
	catch (const int &ex)
	{
		SetConsoleTextAttribute(handle, 12);
		cout << "Oshibka otkritiya faila!" << endl;
		SetConsoleTextAttribute(handle, 15);
	}

	char tema[20];
	cout << "Vvedite temu doklada: ";
	cin >> tema;
LOOP5:
	cout << "Chto delat'? \n1 - IZMENIT'\n2 - UDALIT' " << endl;
	cin >> switcha;

	if (switcha == 1) {
		try
		{
			f.open(file, ios::binary | ios::out);
			if (!f.is_open())
			{
				throw 777;
			}
			for (int i = 0; i < counter; i++)
			{
				if (strcmp(helper[i].TEMA(), tema) == 0)
				{
					cout << "NEW DATA: " << endl;
					helper[i].set();
					f.write(reinterpret_cast<char*>(&helper[i]), sizeof(T));
				}
				else
				{
					f.write(reinterpret_cast<char*>(&helper[i]), sizeof(T));
				}
			}
			delete[] helper;
			f.close();

		}
		catch (const int &ex)
		{
			SetConsoleTextAttribute(handle, 12);
			cout << "Oshibka otkritiya faila!" << endl;
			SetConsoleTextAttribute(handle, 15);
		}
	}
	if (switcha == 2)
	{
		try
		{
			f.open(file, ios::binary | ios::out);
			if (!f.is_open())
			{
				throw 777;
			}
			for (int i = 0; i < switcha; i++)
			{
				if (strcmp(helper[i].TEMA(), tema) != 0)
				{
					f.write(reinterpret_cast<char*>(&helper[i]), sizeof(T));
					helper[i].get();
				}
			}
			delete[] helper;
			f.close();
		}
		catch (const int &ex)
		{
			SetConsoleTextAttribute(handle, 12);
			cout << "Oshibka otkritiya faila!" << endl;
			SetConsoleTextAttribute(handle, 15);
		}
	}
	if (switcha != 1 && switcha != 2)
		goto LOOP5;
}