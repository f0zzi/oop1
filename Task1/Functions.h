#pragma once
#include "Student.h"
using namespace std;

Student Initialize()
{
	int recordBook, marksQuantity, mark; 
	char surname[20] = "";
	cout << "Enter students surname: ";
	cin >> surname;
	cout << "Enter record book number: ";
	cin >> recordBook;
	cout << "Enter marks quantity: ";
	cin >> marksQuantity;
	cout << "Enter student marks.\n";
	int* marks = new int[marksQuantity];
	for (int i = 0; i < marksQuantity; i++)
	{
		cout << "Enter subject #" << i + 1 << " mark: ";
		cin >> mark;
		marks[i] = mark;
	}
	return Student(recordBook, marksQuantity, marks, surname);
}