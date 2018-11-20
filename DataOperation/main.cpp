#include "Menu.h"
#include <windows.h>
#include <ctime>
#include "TimeMeasure.h"

using namespace std;


int main() {
	srand(time(NULL));

	Menu Menu;

	Menu.MainMenu();

	system("pause");
	return 0;
}