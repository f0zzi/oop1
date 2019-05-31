#pragma once
#include <iostream>
#include <cstring>
#include <iomanip>
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
	Student();
	Student(int recordBook, int marksQuantity, int* marks, const char* surname);

	Student(const Student& other);

	~Student();

	const char* GetSurname() const
	{
		return surname;
	}
	int GetRecordBook() const
	{
		return recordBook;
	}
	int GetMarksQuantity() const
	{
		return marksQuantity;
	}
	int* GetMarks() const
	{
		return marks;
	}
	static int GetMarkMaxLimit()
	{
		return markMaxLimit;
	}
	static int GetMarkMinLimit()
	{
		return markMinLimit;
	}

	void ShowMarks() const;

	void SetSurname(const char* surname);

	void ShowFullInfo() const;

	double GetAvarageMark() const;

	void SetMark(int subjectIndex, int mark);

	void AddMark(int mark);

	void RemoveMark(int subjectIndex);
};