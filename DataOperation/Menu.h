#pragma once
#include "Table.h"
#include "List.h"
#include "Heap.h"

class Menu
{
private:
	int option;
	Table tablica;
	List lista;
	Heap kopiec;
public:
	Menu();
	~Menu();
	void MainMenu();
	void Table();
	void List();
	void Heap();
	static int value();
	static int position();
	static void generateStruct();
};

