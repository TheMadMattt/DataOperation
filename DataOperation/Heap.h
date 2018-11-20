#pragma once
#include <string>
using namespace std;

class Heap
{
private:
	int *heap;
	int size;
	string cr,cp,cl;
	int leftChild(int parent) const;	//zwrocenie lewego dziecka
	int rightChild(int parent) const;	//zwrocenie prawego dziecka
	static int parent(int child);		//zwrocneie rodzica
	void heapFixUp(int position) const;	//naprawa kopca w gore
	void heapFixDown(int position) const;	//naprawa kopca w dol
	void heapFix(int position) const;		//sprawdzenie czy kopiec ma zostac naprawiony w gore czy w dol
public:
	Heap();
	~Heap();
	void clearHeap();
	void push(int value);	//dodanie zadanego elementu do kopca
	void removeRoot();		//usuniecie korzenia
	void removeFromPosition(int position);	//usuniecie elementu z wybranej pozycji
	void searchInHeap(int value) const;		//wyszukanie zadanej wartosci
	void showHeap(string sp, string sn, int pos) const;		//wyswietlenie kopca
	void readFromFile();		//odczyt z pliku
	int getSize() const;		//zwrocenie rozmiaru kopca
};

