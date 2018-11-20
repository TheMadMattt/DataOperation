#include "Table.h"
#include <iostream>
#include <fstream>

using namespace std;

Table::Table()
{
	this->table = nullptr;		//wyzerowanie tablicy oraz rozmiaru
	this->size = 0;
}


Table::~Table()
{
	if (size != 0) {			//usuniecie calej tablicy
		delete[] table;
		table = nullptr;
		size = 0;
	}
	else {
		return;
	}
}

void Table::clearTable()
{
	if (size != 0) {
		delete[] table;
		table = nullptr;
		size = 0;
	}
	else {
		return;
	}
}

void Table::addAtPosition(int position, int value)
{
	if (position < 0 || position > size)
	{
		cout << "Podales bledne miejsce w tablicy." << endl;
		system("pause");
	}
	else if (position > 0 && position < size)	// dodanie elementu na wybrana pozycje, jesli position znajduje sie w przedziale (0; size)
	{
		int *newTable = new int[size + 1];

		for (int i = 0; i < position; i++) {
			newTable[i] = table[i];
		}
		newTable[position] = value;
		for (int i = position + 1; i < size + 1; i++) {
			newTable[i] = table[i - 1];
		}
		delete[]table;
		table = newTable;
		size++;
	}
	else if (position == size)		//dodanie elementu na koniec
	{
		addAtEnd(value);
	}
	else if (position == 0)			//dodanie elementu na poczatek
	{
		addAtBegin(value);
	}
}

void Table::addAtBegin(int value)
{
	int *newTable = new int[size + 1];

	newTable[0] = value;

	for (int i = 0; i < size; i++)
	{
		newTable[i + 1] = table[i];
	}

	delete[]table;
	table = newTable;
	size++;
}

void Table::addAtEnd(int value)
{
	int *newTable = new int[size + 1];

	newTable[size] = value;

	for (int i = 0; i < size; i++)
	{
		newTable[i] = table[i];
	}

	delete[]table;
	table = newTable;
	size++;
}

void Table::removeFromBegin()
{
	if (size == 0)
	{
		cout << "Tablica jest pusta" << endl;
		system("pause");
	}
	else
	{
		int *newTable = new int[size - 1];

		for (int i = 0; i < size-1; i++)	//skopiowanie wszystkich elementow oprocz pierwszego
		{
			newTable[i] = table[i + 1];
		}
		delete[] table;
		table = newTable;
		size--;
	}
}

void Table::removeFromEnd()
{
	if (size == 0)
	{
		cout << "Tablica jest pusta" << endl;
		system("pause");
	}
	else
	{
		int *newTable = new int[size - 1];

		for (int i = 0; i < size - 1; i++)	//skopiowanie wszystkich elementow oprocz ostatniego
		{
			newTable[i] = table[i];
		}
		delete[] table;
		table = newTable;
		size--;
	}
}

void Table::removeFromPosition(int position)
{
	if (size == 0)
	{
		cout << "Tablica jest pusta" << endl;
		system("pause");
	}
	else if (position < 0 || position >= size)
	{
		cout << "Podales bledne miejsce w tablicy." << endl;
		system("pause");
	}
	else if (position == size - 1)		//usuniecie elementu z konca
	{
		removeFromEnd();
	}
	else if (position == 0)		//usuniecie elementu z poczatku
	{
		removeFromBegin();
	}
	else if (position > 0 && position < size - 1)	//usuniecie elementu z wybranej pozycji
	{
		int *newTable = new int[size - 1];

		for (int i = 0; i < position; i++) {
			newTable[i] = table[i];
		}
		for (int i = position; i < size - 1; i++) {
			newTable[i] = table[i + 1];
		}
		delete[] table;
		table = newTable;
		size--;
	}
}

void Table::searchInTable(int value) const
{
	int counter = 0;
	if (size == 0)
	{
		cout << "Tablica jest pusta" << endl;
		system("pause");
		return;
	}
	for (int i = 0; i < size; i++)
	{
		if (table[i] == value)
		{
			counter++;
		}
	}
	if (counter == 1)
	{
		cout << "Zadana wartosc " << value << " pojawila sie " << counter << " raz." << endl;
	}
	else
	{
		cout << "Zadana wartosc " << value << " pojawila sie " << counter << " razy." << endl;
	}
}

void Table::showTable() const
{
	for (int i = 0; i < size; i++) {
		cout << "Tab[" << i << "] " << table[i] << endl;
	}
}

void Table::readFromFile()
{
	ifstream file;
	file.open("struct.txt", ios::in);
	clearTable();
	int data;
	if (file.good()) {		//jezeli plik zostal prawidlowo otwarty nastepuje odczyt
		while (!file.eof())
		{
			file >> data;
			addAtEnd(data);
		}

		cout << "Dane zostaly wczytane prawidlowo " << endl;

	}
	else
	{
		cout << "Nie udalo sie otworzyc pliku" << endl;
	}

	file.close();
}

int Table::getSize() const
{
	return size;
}
