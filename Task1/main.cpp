#include <iostream>
#include <Windows.h>
#include "Student.h"
#include "Functions.h"
using namespace std;

int main()
{
	srand(time(nullptr));
	int groupSize, selection;
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
	do
	{
		system("cls");
		cout << "Choose initialization method for group:\n";
		cout << "1 - Initialize manualy\n";
		cout << "2 - Initialize with random values\n";
		cout << "Enter your selection: ";
		cin >> selection;
		switch (selection)
		{
		case 1:
			for (int i = 0; i < groupSize; i++)
			{
				system("cls");
				cout << "Student #" << i + 1 << endl;
				group[i] = new Student{ Initialize() };
			}
			break;
		case 2:
			for (int i = 0; i < groupSize; i++)
			{
				group[i] = new Student{ InitializeRandomly() };
			}
			break;
		default:
			cout << "\nInvalid input. Try again.\n";
			system("pause");
			break;
		}
	} while (selection != 1 && selection != 2);
	cout << "Group:\n";
	ShowGroup(group, groupSize);
	cout << "Best student:\n";
	GetMaxAverage(group, groupSize).ShowFullInfo();
	cout << "Low marks:\n";
	ShowLowMarks(group, groupSize);

	delete[] group;
	return 0;
}