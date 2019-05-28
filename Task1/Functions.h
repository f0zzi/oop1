#pragma once
#include "Student.h"
using namespace std;

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
		if (marksQuantity < 1)
			cout << "Invalid input. Try again.\n";
	} while (marksQuantity < 1);
	cout << "Enter student marks.\n";
	int* marks = new int[marksQuantity];
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
	return Student(recordBook, marksQuantity, marks, surname);
}