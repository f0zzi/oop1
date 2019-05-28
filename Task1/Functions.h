#pragma once
#include <ctime>
#include <cstdlib>
#include "Student.h"
using namespace std;

const char* surnames[10] =
{ "test1", "test2", "test3", "test4", "test5",
"test6", "test7", "test8", "test9", "test10" };

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
Student InitializeRandomly()
{
	int recordBook = rand() + 1;
	int marksQuantity = (rand() % 4) + 1;
	int* marks = new int[marksQuantity];
	for (int i = 0; i < marksQuantity; i++)
	{
		marks[i] = (rand() % Student::GetMarkMaxLimit()) + 1;
	}
	return Student(recordBook, marksQuantity, marks, surnames[rand() % 10]);
}