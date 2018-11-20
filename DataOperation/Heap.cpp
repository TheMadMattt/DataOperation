#include "Heap.h"
#include <iostream>
#include <fstream>

Heap::Heap()
{
	cr = cl = cp = "  ";			//zmienne potrzebne do ladnego wypisania kopca
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;

	this->size = 0;
	this->heap = nullptr;
}


Heap::~Heap()
{
	if (size != 0) {
		delete[]heap;
		heap = nullptr;
		size = 0;
	}
	else {
		return;
	}
}

int Heap::leftChild(int parent) const
{
	const int leftChild = 2 * parent + 1;		//zwroc pozycje lewego dziecka
	if (leftChild < size)		// lewe dziecko nie moze byc wieksze od size
	{
		return leftChild;
	}
	else
	{
		return -1;
	}
}

int Heap::rightChild(int parent) const
{
	const int rightChild = 2 * parent + 2;		//zwroc pozycje prawego dziecka
	if (rightChild < size)			// prawe dziecko nie moze byc wieksze od size
	{
		return rightChild;
	}
	else
	{
		return -1;
	}
}

int Heap::parent(int child)
{
	const int parent = (child - 1) / 2;		//zwroc pozycje rodzica
	if (child == 0)				// jezeli dziecko jest rowne 0 zworc -1 (dziecko nigdy nie moze miec pozycji 0)
	{
		return -1;
	}
	else
	{
		return parent;
	}
}

void Heap::heapFixUp(int position) const
{
	if (position >= 0 && parent(position) >= 0 && heap[parent(position)] < heap[position])		//naprawa kopca w gore, funkcja rekurencyjna
	{
		int temp = heap[position];
		heap[position] = heap[parent(position)];
		heap[parent(position)] = temp;
		heapFixUp(parent(position));
	}
}

void Heap::heapFixDown(int position) const
{
	int child = 2*position+1;
	while (child<size)
	{
		if(child+1<size && heap[child+1] > heap[child]) child++;
		if(heap[child] <= heap[position]) break;
		swap(heap[position], heap[child]);
		position = child;
		child = 2*position+1;
	}
}

void Heap::heapFix(int position) const
{
	if(heap[position] > heap[parent(position)])		//sprawdzenie ktora naprawa kopca powinna zostac wykonana
	{
		heapFixUp(position);
	}else
	{
		heapFixDown(position);
	}
}

void Heap::clearHeap()
{
	if (size != 0) {
		delete[]heap;
		heap = nullptr;
		size = 0;
	}
	else {
		return;
	}
}


void Heap::push(int value)
{
	int *newHeap = new int[size + 1];		//dodanie elementu na koniec kopca
	for (int i = 0; i < size; i++)
	{
		newHeap[i] = heap[i];
	}
	newHeap[size] = value;
	size++;
	delete heap;
	heap = newHeap;
	heapFixUp(size - 1); //naprawa kopca w gore
}

void Heap::removeRoot()
{
	if (size == 0)
	{
		cout << "Kopiec jest pusty" << endl;
		system("pause");
	}
	else
	{
		heap[0] = heap[size - 1];		//usuniecie korzenia poprzez nadpisanie pozycji 0 pozycja ostatnia w tablicy
		size--;
		int *newHeap = new int[size];
		for (int i = 0; i < size; i++)
		{
			newHeap[i] = heap[i];
		}
		delete heap;
		heap = newHeap;
		heapFixDown(0);		// naprawa kopca w dol
	}
}

void Heap::removeFromPosition(int position)
{
	if (size == 0)
	{
		cout << "Kopiec jest pusty" << endl;
		system("pause");
	}else if(position < 0 || position >= size)
	{
		cout << "Podales bledne miejsce w kopcu." << endl;
		system("pause");
	}
	else if(position > 0 && position < size - 1)	//usuniecie z wybranej pozycji jesli position miesci sie w zakresie (0; size-1)
	{
		heap[position] = heap[size - 1];
		size--;
		int *newHeap = new int[size];
		for (int i = 0; i < size; i++)
		{
			newHeap[i] = heap[i];
		}
		delete heap;
		heap = newHeap;
		heapFix(position);
	} else if(position == size - 1)		//usuniecie ostatniego elementu
	{
		size--;
		int *newHeap = new int[size];
		for (int i = 0; i < size; i++)
		{
			newHeap[i] = heap[i];
		}
		delete heap;
		heap = newHeap;
	} else if(position == 0)		//usuniecie korzenia
	{
		removeRoot();
	}
}

void Heap::searchInHeap(int value) const
{
	int counter = 0;
	if (size == 0)
	{
		cout << "Kopiec jest pusty" << endl;
		system("pause");
		return;
	}
	for (int i = 0; i < size; i++)
	{
		if (heap[i] == value)	//zwiekszenie licznika jezeli odnalazlo szukany element w kopcu
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

void Heap::showHeap(string sp, string sn, int pos) const
{
	string s;

	if (pos < size)			//wypisanie kopca
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		showHeap(s + cp, cr, 2 * pos + 2);

		s = s.substr(0, sp.length() - 2);

		cout << s << sn << heap[pos] << endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		showHeap(s + cp, cl, 2 * pos + 1);
	}
}

void Heap::readFromFile()
{
	ifstream file;
	file.open("struct.txt", ios::in);
	clearHeap();
	int data;
	if (file.good()) {
		while (!file.eof())
		{
			file >> data;
			push(data);
		}

		cout << "Dane zostaly wczytane prawidlowo " << endl;

	}
	else
	{
		cout << "Nie udalo sie otworzyc pliku" << endl;
	}

	file.close();
}

int Heap::getSize() const
{
	return size;
}
