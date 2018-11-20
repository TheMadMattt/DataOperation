#pragma once

struct ElemList
{
	ElemList *prev, *next;
	int data;
};

class List
{
private:
	ElemList *head, *tail;
	int size;
public:
	List();
	~List();
	void clearList();
	void addAtPosition(int position, int value);	//dodanie zadanej wartosci na zadana pozycje
	void addAtBegin(int value);						//dodanie zadanej wartosci na poczatek
	void addAtEnd(int value);						//dodanie zadanej wartosci na koniec
	void removeFromBegin();							//usuniecie z poczatku
	void removeFromEnd();							//usuniecie z konca
	void removeFromPosition(int position);			//usuniecie z zadanej pozycji
	void searchInList(int value) const;				//wyszukanie zadanej wartosci
	void showList() const;							//wyswietlenie listy
	void readFromFile();							//odczyt z pliku
	int getSize() const;							//zwrocenie rozmiaru listy
};

