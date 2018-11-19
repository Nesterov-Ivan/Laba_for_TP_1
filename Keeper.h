#pragma once

class Keeper
{
public:
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