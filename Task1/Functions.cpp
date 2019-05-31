#include "Functions.h"

const char* surnames[11] =
{ "Honcharuk", "Khlypavka", "Martynyuk", "Shkoda", "Kobalava", "Kobylyanska",
"Mayevska", "Dubina", "Semenyuk", "Malchevskyy", "Bilous" };

Student Initialize()
{
	int recordBook, marksQuantity, mark;
	char surname[20] = "";
	cout << "Enter students surname: ";
	cin >> surname;
	do
	{
		cout << "Enter record book number: ";
		cin >> recordBook;
		if (recordBook < 1)
			cout << "Invalid input. Try again.\n";
	} while (recordBook < 1);
	do
	{
		cout << "Enter marks quantity: ";
		cin >> marksQuantity;
		if (marksQuantity < 0)
			cout << "Invalid input. Try again.\n";
	} while (marksQuantity < 0);
	int* marks = nullptr;
	if (marksQuantity > 0)
	{
		cout << "Enter student marks.\n";
		marks = new int[marksQuantity];
		for (int i = 0; i < marksQuantity; i++)
		{
			do
			{
				cout << "Enter subject #" << i + 1 << " mark: ";
				cin >> mark;
				if (mark < Student::GetMarkMinLimit() || mark > Student::GetMarkMaxLimit())
					cout << "Invalid input. Mark must be in range 0-100. Try again.\n";
			} while (mark < Student::GetMarkMinLimit() || mark > Student::GetMarkMaxLimit());
			marks[i] = mark;
		}
	}
	return Student(recordBook, marksQuantity, marks, surname);
}

Student InitializeRandomly()
{
	int recordBook = rand() + 1;
	int marksQuantity = (rand() % 6);
	int* marks = nullptr;
	if (marksQuantity > 0)
	{
		marks = new int[marksQuantity];
		for (int i = 0; i < marksQuantity; i++)
		{
			marks[i] = (rand() % Student::GetMarkMaxLimit()) + 1;
		}
	}
	return Student(recordBook, marksQuantity, marks, surnames[rand() % 11]);
}

void ShowGroup(Student * *group, int groupSize)
{
	if (group == nullptr || groupSize <= 0)
		cout << "Group is empty.\n";
	else
	{
		for (int i = 0; i < groupSize; i++)
		{
			cout << "Student #" << setw(2) << i + 1 << " ";
			group[i]->ShowFullInfo();
		}
	}
}

Student& GetMaxAverage(Student * *group, int groupSize)
{
	int index = 0;
	double avarage = 0, avarageMax = 0;
	for (int i = 0; i < groupSize; i++)
	{
		avarage = group[i]->GetAvarageMark();
		if (avarageMax < avarage)
		{
			index = i;
			avarageMax = avarage;
		}
	}
	return *group[index];
}

void ShowLowMarks(Student * *group, int groupSize)
{
	if (group == nullptr || groupSize <= 0)
		cout << "Group is empty.\n";
	else
		for (int i = 0; i < groupSize; i++)
		{
			if (group[i]->GetMarksQuantity() == 0)
			{
				cout << "Student #" << setw(2) << i + 1 << " ";
				group[i]->ShowFullInfo();
			}
			for (int j = 0; j < group[i]->GetMarksQuantity(); j++)
				if (group[i]->GetMarks()[j] <= Student::GetMarkMaxLimit() / 3)
				{
					cout << "Student #" << setw(2) << i + 1 << " ";
					group[i]->ShowFullInfo();
					break;
				}
		}
}
