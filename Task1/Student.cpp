#include "Student.h"

Student::Student() : Student(00000, 0, nullptr, "None") {}

Student::Student(int recordBook, int marksQuantity, int* marks, const char* surname) :
	recordBook(recordBook), marksQuantity(marksQuantity)
{
	this->marks = marks;
	int size = strlen(surname) + 1;
	this->surname = new char[size];
	strcpy_s(this->surname, size, surname);
}

Student::Student(const Student& other) :
	Student(recordBook, marksQuantity, marks, surname) {}

Student::~Student()
{
	if (surname != nullptr)
		delete[] surname;
	if (marks != nullptr)
		delete[] marks;
}

void Student::ShowMarks() const
{
	if (marks != nullptr && marksQuantity > 0)
	{
		cout << "\t    Subjects/marks  ";
		for (int i = 0; i < marksQuantity; i++)
		{
			cout << i + 1 << ":" << setw(3) << marks[i] << "  ";
		}
		cout << endl;
	}
	else
		cout << "\t    ----Student has no marks----\n";
}

void Student::SetSurname(const char* surname)
{
	if (this->surname != nullptr)
		delete[] this->surname;
	int size = strlen(surname) + 1;
	this->surname = new char[size];
	strcpy_s(this->surname, size, surname);
}

void Student::ShowFullInfo() const
{
	cout << "Surname: " << setw(11) << GetSurname() << "   Record book #" << GetRecordBook() << "\tAvarage mark: " << setprecision(4) << GetAvarageMark() << endl;
	ShowMarks();
}

double Student::GetAvarageMark() const
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

void Student::SetMark(int subjectIndex, int mark)
{
	if (subjectIndex > marksQuantity - 1 || subjectIndex < 0)
	{
		cout << "Invalid subject index.\n";
		system("pause");
	}
	else if (mark > markMaxLimit || mark < markMinLimit)
	{
		cout << "Invalid mark.\n";
		system("pause");
	}
	else
		marks[subjectIndex] = mark;
}

void Student::AddMark(int mark)
{
	if (mark > markMaxLimit || mark < markMinLimit)
	{
		cout << "\nInvalid mark.\n";
		system("pause");
	}
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

void Student::RemoveMark(int subjectIndex)
{
	if (marksQuantity == 0 || marks == nullptr)
	{
		cout << "Error. Student has no marks.\n";
		system("pause");
	}
	else if (subjectIndex > marksQuantity || subjectIndex <= 0)
	{
		cout << "\nInvalid subject index.\n";
		system("pause");
	}
	else
	{
		int* tmp = marks;
		marks = new int[marksQuantity - 1];
		for (int i = 0, j = 0; i < marksQuantity; i++)
		{
			if (i != subjectIndex - 1)
				marks[j++] = tmp[i];
		}
		delete[] tmp;
		marksQuantity--;
	}
}
