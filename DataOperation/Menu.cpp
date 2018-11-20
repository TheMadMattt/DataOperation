#include "Menu.h"
#include <iostream>
#include <fstream>

using namespace std;

Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::MainMenu()
{
	string temp;
	cout << "[1] Tablica" << endl;
	cout << "[2] Lista" << endl;
	cout << "[3] Kopiec" << endl;
	cout << "[4] Wygeneruj dane do pliku" << endl;
	cout << "[5] Wyjscie" << endl;
	cout << "Wybierz zadanie do uruchomienia: ";
	cin >> temp;

	option = atoi(temp.c_str()); //konwersja ze stringa na int

	switch (option)
	{
	case 1:
		system("cls");
		Table();
		break;
	case 2:
		system("cls");
		List();
		break;
	case 3:
		system("cls");
		Heap();
		break;
	case 4:
		system("cls");
		generateStruct();
		system("pause");
		system("cls");
		MainMenu();
	case 5:
		exit(0);
		break;
	default:
		cout << "Wpisz odpowiedni numer." << endl;
		system("pause");
		system("cls");
		MainMenu();
	}
}

void Menu::Table()
{
	string temp;
	cout << "Aktualny rozmiar tablicy: " << tablica.getSize() << endl << endl;
	cout << "[1] Dodaj element na poczatek" << endl;
	cout << "[2] Dodaj element na koniec" << endl;
	cout << "[3] Dodaj element w wybrane miejsce" << endl;
	cout << "[4] Usun element z poczatku" << endl;
	cout << "[5] Usun element z konca" << endl;
	cout << "[6] Usun element z wybranego miejsca" << endl;
	cout << "[7] Wyszukaj element" << endl;
	cout << "[8] Wyswietl tablice" << endl;
	cout << "[9] Wczytaj dane z pliku" << endl;
	cout << "[10] Wyczysc tablice" << endl;
	cout << "[11] Powrot" << endl;
	cout << "Wybierz zadanie do uruchomienia: ";
	cin >> temp;

	option = atoi(temp.c_str());

	switch (option)
	{
	case 1:
		system("cls");
		tablica.addAtBegin(value());
		system("cls");
		Table();
		break;
	case 2:
		system("cls");
		tablica.addAtEnd(value());
		system("cls");
		Table();
		break;
	case 3:
		system("cls");
		tablica.addAtPosition(position(), value());
		system("cls");
		Table();
		break;
	case 4:
		system("cls");
		tablica.removeFromBegin();
		system("cls");
		Table();
		break;
	case 5:
		system("cls");
		tablica.removeFromEnd();
		system("cls");
		Table();
		break;
	case 6:
		system("cls");
		tablica.removeFromPosition(position());
		system("cls");
		Table();
		break;
	case 7:
		system("cls");
		tablica.searchInTable(value());
		system("pause");
		system("cls");
		Table();
		break;
	case 8:
		system("cls");
		tablica.showTable();
		system("pause");
		system("cls");
		Table();
		break;
	case 9:
		system("cls");
		tablica.readFromFile();
		system("pause");
		system("cls");
		Table();
	case 10:
		tablica.clearTable();
		system("cls");
		Table();
	case 11:
		system("cls");
		MainMenu();
		break;
	default:
		cout << "Wpisz odpowiedni numer." << endl;
		system("pause");
		system("cls");
		Table();
	}
}

void Menu::List()
{
	string temp;
	cout << "Aktualny rozmiar listy: " << lista.getSize() << endl << endl;
	cout << "[1] Dodaj element na poczatek" << endl;
	cout << "[2] Dodaj element na koniec" << endl;
	cout << "[3] Dodaj element w wybrane miejsce" << endl;
	cout << "[4] Usun element z poczatku" << endl;
	cout << "[5] Usun element z konca" << endl;
	cout << "[6] Usun element z wybranego miejsca" << endl;
	cout << "[7] Wyszukaj element" << endl;
	cout << "[8] Wyswietl liste" << endl;
	cout << "[9] Wczytaj dane z pliku" << endl;
	cout << "[10] Wyczysc liste" << endl;
	cout << "[11] Powrot" << endl;
	cout << "Wybierz zadanie do uruchomienia: ";
	cin >> temp;

	option = atoi(temp.c_str());

	switch (option)
	{
	case 1:
		system("cls");
		lista.addAtBegin(value());
		system("cls");
		List();
		break;
	case 2:
		system("cls");
		lista.addAtEnd(value());
		system("cls");
		List();
		break;
	case 3:
		system("cls");
		lista.addAtPosition(position(), value());
		system("cls");
		List();
		break;
	case 4:
		system("cls");
		lista.removeFromBegin();
		system("cls");
		List();
		break;
	case 5:
		system("cls");
		lista.removeFromEnd();
		system("cls");
		List();
		break;
	case 6:
		system("cls");
		lista.removeFromPosition(position());
		system("cls");
		List();
		break;
	case 7:
		system("cls");
		lista.searchInList(value());
		system("pause");
		system("cls");
		List();
		break;
	case 8:
		system("cls");
		lista.showList();
		system("pause");
		system("cls");
		List();
		break;
	case 9:
		system("cls");
		lista.readFromFile();
		system("pause");
		system("cls");
		List();
		break;
	case 10:
		lista.clearList();
		system("cls");
		List();
		break;
	case 11:
		system("cls");
		MainMenu();
		break;
	default:
		cout << "Wpisz odpowiedni numer." << endl;
		system("pause");
		system("cls");
		List();
	}
}

void Menu::Heap()
{
	string temp;
	cout << "Aktualny rozmiar kopca: " << kopiec.getSize() << endl << endl;
	cout << "[1] Dodaj element" << endl;
	cout << "[2] Usun korzen" << endl;
	cout << "[3] Usun wybrany element" << endl;
	cout << "[4] Wyszukaj element" << endl;
	cout << "[5] Wyswietl kopiec" << endl;
	cout << "[6] Wczytaj dane z pliku" << endl;
	cout << "[7] Wyczysc kopiec" << endl;
	cout << "[8] Powrot" << endl;
	cout << "Wybierz zadanie do uruchomienia: ";
	cin >> temp;

	option = atoi(temp.c_str()); 

	switch (option)
	{
	case 1:
		system("cls");
		kopiec.push(value());
		system("cls");
		Heap();
		break;
	case 2:
		system("cls");
		kopiec.removeRoot();
		system("cls");
		Heap();
		break;
	case 3:
		system("cls");
		kopiec.removeFromPosition(position());
		system("cls");
		Heap();
		break;
	case 4:
		system("cls");
		kopiec.searchInHeap(value());
		system("pause");
		system("cls");
		Heap();
		break;
	case 5:
		system("cls");
		kopiec.showHeap("", "", 0);
		system("pause");
		system("cls");
		Heap();
		break;
	case 6:
		system("cls");
		kopiec.readFromFile();
		system("pause");
		system("cls");
		Heap();
		break;
	case 7:
		kopiec.clearHeap();
		system("cls");
		Heap();
	case 8:
		system("cls");
		MainMenu();
		break;
	default:
		cout << "Wpisz odpowiedni numer." << endl;
		system("pause");
		system("cls");
		Heap();
	}
}

int Menu::value()
{
	int value;
	cout << "Jaka wartosc?: ";
	cin >> value;

	return value;
}

int Menu::position()
{
	int value;
	cout << "W ktorym miejscu?: ";
	cin >> value;

	return value;
}

void Menu::generateStruct()
{
	ofstream file;
	string filename = "struct.txt";
	int A, B, count;
	file.open(filename, ios::out);

	do {
		cout << "Ile liczb chcesz wylosowac?: ";
		cin >> count;
	} while (count < 0);
	cout << "Z jakiego przedzialu dane chcesz wygenerowac? [A,B]" << endl;
	cout << "Wpisz A: ";
	cin >> A;
	cout << "Wpisz B: ";
	cin >> B;

	if (file.good())
	{
		for (int i = 0; i < count; i++)
		{
			if (i == count - 1)
			{
				int liczba = rand() % (B - A + 1) + A;
				file << liczba;
			}
			else
			{
				int liczba = rand() % (B - A + 1) + A;
				file << liczba << endl;
			}
		}
		cout << "Liczby zostaly wygenerowane do pliku: " << filename << endl;
	}

	file.close();

}
