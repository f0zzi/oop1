#include <iostream>
#include <Windows.h>
#include "Student.h"
#include "Functions.h"
#include "Interface.h"
using namespace std;

int main()
{
	srand(time(nullptr));
	int groupSize;
	do
	{
		system("cls");
		cout << "Enter groups size: ";
		cin >> groupSize;
		if (groupSize <= 0)
		{
			cout << "\nInvalid input. Size should be bigger then zero.\n";
			system("pause");
		}
	} while (groupSize <= 0);

	Student * *group = new Student * [groupSize];
	ShowInterface(group, groupSize);

	delete[] group;
	return 0;
}