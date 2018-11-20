#include "List.h"
#include <iostream>
#include <fstream>

using namespace std;

List::List()
{
	head = tail = NULL;
	size = 0;
}

List::~List()
{
	if (size != 0)
	{
		ElemList *p = head;

		while (p)
		{
			ElemList *next = p->next;	//przejscie na kolejny element
			delete p;	//usuniecie p
			p = next;
		}
		size = 0;
		head = tail = NULL;
	}
	else
	{
		return;
	}
}

void List::clearList()
{
	if (size != 0)
	{
		ElemList *p = head;

		while (p)
		{
			ElemList *next = p->next;
			delete p;	//zwolnienie p
			p = next;
		}
		size = 0;
		head = tail = NULL;
	}
	else
	{
		return;
	}
}

void List::addAtBegin(int value)
{
	ElemList *p = new ElemList;
	p->data = value;	//przpisanie wartosci
	p->next = head;
	p->prev = NULL;
	if (head != NULL)
	{
		head->prev = p;
	}
	else
	{
		tail = p;
	}
	head = p;
	size++;
}

void List::addAtEnd(int value)
{
	ElemList * p = new ElemList;

	p->data = value;
	p->next = NULL;
	p->prev = tail;
	if (tail != NULL)
	{
		tail->next = p;
	}
	else {
		head = p;
	}
	tail = p;
	size++;
}

void List::addAtPosition(int position, int value)
{
	ElemList *p = new ElemList;
	ElemList *temp = head;
	int counter = 0;

	if (position < 0 || position > size)	//pozycja nie moze byc mniejsza niz 0 ani wieksza niz size
	{
		cout << "Podales bledne miejsce w liscie." << endl;
		system("pause");
	}
	else if (position == 0)
	{
		addAtBegin(value);		//dodanie na poczatek
	}
	else if (position == size)
	{
		addAtEnd(value);	//dodanie na koniec
	}
	else if (position > 0 && position < size)	//jezeli position jest wieksze od zera i mniejsze od size nastepuje dodanie elementu na wybranej pozycji
	{
		p->data = value;

		while (temp)
		{
			counter++;
			temp = temp->next;		//iterowanie po liscie az do znalezienia zadanej pozycji
			if (counter == position)
			{
				p->prev = temp->prev;		//dodanie wartosci na wybrana pozycje
				p->next = temp;
				temp->prev->next = p;
				temp->prev = p;
				size++;
				return;
			}
		}
	}

}

void List::removeFromBegin()
{
	if (size > 0)
	{
		ElemList *p = head;
		head = p->next;
		if (head != NULL)
		{
			head->prev = p->prev;
		}
		else {
			tail = p->prev;
		}
		delete p;
		size--;
	}
	else
	{
		cout << "Lista jest pusta." << endl;
		system("pause");
	}
}

void List::removeFromEnd()
{
	if (size > 0)
	{
		ElemList *p = tail;
		tail = p->prev;
		if (tail != NULL)
		{
			tail->next = NULL;
		}
		else {
			head = p->prev;
		}

		delete p;
		size--;
	}
	else
	{
		cout << "Lista jest pusta." << endl;
		system("pause");
	}
}

void List::removeFromPosition(int position)
{
	ElemList *p = new ElemList;
	ElemList *temp = head;
	int counter = 0;

	if (size == 0)
	{
		cout << "Lista jest pusta" << endl;
		system("pause");
	}
	else if (position < 0 || position >= size)
	{
		cout << "Podales bledne miejsce w liscie." << endl;
		system("pause");
	}
	else if (position == 0)			//jezeli pozycja to pierwszy element nastepuje usuniecie z poczatku
	{
		removeFromBegin();
	}
	else if (position == size - 1)		//jezeli pozycja to ostatni element nastepuje usuniecie z konca
	{
		removeFromEnd();
	}
	else
	{
		while (temp)
		{
			counter++;
			temp = temp->next;			//iterowanie po liscie az do znalezienia zadanej pozycji
			if (counter == position)
			{
				p = temp;
				temp->next->prev = temp->prev;
				temp->prev->next = temp->next;
				delete p;
				size--;
				return;
			}
		}
	}

}

void List::searchInList(int value) const
{
	ElemList *p = head;

	int counter = 0;

	if (size == 0)			//nie mozna wyszukac jesli lista jest pusta
	{
		cout << "Tablica jest pusta" << endl;
		system("pause");
		return;
	}
	while (p)
	{
		if (p->data == value)		// jezeli data jest rowne przekazanej wartosci value zwiekszenie licznika
		{
			counter++;
		}
		p = p->next;			// iterowanie po kolejnych elementach listy
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

void List::showList() const
{
	ElemList *p = head;
	int i = 0;
	while (p)
	{
		cout << "List[" << i << "] " << p->data << endl;
		i++;
		p = p->next;
	}
}

void List::readFromFile()
{
	ifstream file;
	file.open("struct.txt", ios::in);
	clearList();		//wyczyszczenie listy przez sczytaniem danych z pliku
	int data;
	if (file.good()) {
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

int List::getSize() const
{
	return size;
}
