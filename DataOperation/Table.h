#pragma once

class Table
{
private:
	int *table;
	int size;
public:
	Table();
	~Table();
	void clearTable();
	void addAtPosition(int position, int value);	//dodanie zadanej wartosci na zadana pozycje
	void addAtBegin(int value);						//dodanie zadanej wartosci na poczatek
	void addAtEnd(int value);						//dodanie zadanej wartosci na koniec
	void removeFromBegin();							//usuniecie z poczatku
	void removeFromEnd();							//usuniecie z konca
	void removeFromPosition(int position);			//usuniecie z zadanej pozycji
	void searchInTable(int value) const;			//wyszukanie zadanej wartosci
	void showTable() const;							//wypisanie tablicy
	void readFromFile();							//odczyt z pliku
	int getSize() const;							//zwrocenie wielkosci tablicy
};

