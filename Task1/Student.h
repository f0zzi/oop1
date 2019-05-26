#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Student
{
private:
	static const int markMaxLimit = 100;
	static const int markMinLimit = 0;
	const int recordBook;
	char* surname;
	int marksQuantity;
	int* marks;
public:
	Student() : Student(00000, 0, nullptr, "None") {}
	Student(int recordBook, int marksQuantity, int* marks, const char* surname) :
		recordBook(recordBook), marksQuantity(marksQuantity)/*, marks(new int[marksQuantity])*/
	{
		this->marks = marks;
		int size = strlen(surname) + 1;
		this->surname = new char[size];
		strcpy_s(this->surname, size, surname);
	}
	Student(const Student& other) :
		Student(recordBook, marksQuantity, marks, surname) {}
	~Student()
	{
		if (surname != nullptr)
			delete[] surname;
		if (marks != nullptr)
			delete[] marks;
	}
	void ShowMarks() const
	{
		if (marks != nullptr && marksQuantity > 0)
		{
			cout << "Subjects/marks: ";
			for (int i = 0; i < marksQuantity; i++)
			{
				cout << i + 1 << ": " << marks[i] << "  ";
			}
			cout << endl;
		}
		else
			cout << "Student has no marks.\n";
	}
	const char* GetSurname() const
	{
		return surname;
	}
	void SetSurname(const char* surname)
	{
		if (this->surname != nullptr)
			delete[] surname;
		int size = strlen(surname) + 1;
		this->surname = new char[size];
		strcpy_s(this->surname, size, surname);
	}
	int GetRecordBook() const
	{
		return recordBook;
	}
	int GetMarksQuantity() const
	{
		return marksQuantity;
	}
	void ShowFullInfo() const
	{
		cout << "Student: " << GetSurname() << "   Record book #" << GetRecordBook() << "   Avarage mark: " << GetAvarageMark() << endl;
		ShowMarks();
	}
	double GetAvarageMark() const
	{
		if (marks != nullptr && marksQuantity > 0)
		{
			int sum = 0;
			for (int i = 0; i < marksQuantity; i++)
			{
				sum += marks[i];
			}
			return (double)sum / marksQuantity;
		}
		else
			return 0;
	}
	void SetMark(int subjectIndex, int mark)
	{
		if (subjectIndex > marksQuantity || subjectIndex < 0)
			cout << "Invalid subject index.\n";
		else if (mark > markMaxLimit || mark < markMinLimit)
			cout << "Invalid mark.\n";
		else
			marks[subjectIndex] = mark;
	}
	void AddMark(int mark)
	{
		if (mark > markMaxLimit || mark < markMinLimit)
			cout << "Invalid mark.\n";
		else
		{
			int* tmp = marks;
			marks = new int[marksQuantity + 1];
			for (int i = 0; i < marksQuantity; i++)
			{
				marks[i] = tmp[i];
			}
			delete[] tmp;
			marks[marksQuantity++] = mark;
		}
	}
	
};