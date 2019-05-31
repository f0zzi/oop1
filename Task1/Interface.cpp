#include "Interface.h"

void EditProfile(Student& profile)
{
	int selection, subject, mark;
	char surname[11];
	do
	{
		system("cls");
		cout << "Edit profile:\n\n\t    ";
		profile.ShowFullInfo();
		cout << "\nEdit menu:\n";
		cout << "1 - Enter new surname.\n";
		cout << "2 - Edit marks.\n";
		cout << "3 - Add mark.\n";
		cout << "4 - Remove mark.\n";
		cout << "5 - Previous menu.\n";
		cout << "Enter your selection: ";
		cin >> selection;
		cout << endl;
		switch (selection)
		{
		case 1:
			cout << "Enter new surname: ";
			cin >> surname;
			profile.SetSurname(surname);
			break;
		case 2:
			if (profile.GetMarksQuantity() == 0)
			{
				cout << "\nError. Student has no marks.\n";
				system("pause");
			}
			else
			{
				cout << "Enter subject number: ";
				cin >> subject;
				cout << "Enter mark: ";
				cin >> mark;
				profile.SetMark(subject - 1, mark);
			}
			break;
		case 3:
			cout << "Enter mark: ";
			cin >> mark;
			profile.AddMark(mark);
			break;
		case 4:
			if (profile.GetMarksQuantity() == 1 || profile.GetMarksQuantity() == 0)
				profile.RemoveMark(1);
			else
			{
				cout << "Enter mark index to remove: ";
				cin >> subject;
				profile.RemoveMark(subject);
			}
			break;
		case 5:
			break;
		default:
			cout << "\nInvalid input. Try again.\n";
			system("pause");
			break;
		}
	} while (selection != 5);
}

void ShowInterface(Student * *group, int groupSize)
{
	int selection, profile;
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
	do
	{
		system("cls");
		cout << "Group:\n\n";
		ShowGroup(group, groupSize);
		cout << "\nGroup menu:\n";
		cout << "1 - Show student with highest avarage mark.\n";
		cout << "2 - Show list of students with low marks (1/3 from maximum mark limit).\n";
		cout << "3 - Edit profile of student.\n";
		cout << "0 - Exit.\n";
		cout << "Enter your selection: ";
		cin >> selection;
		switch (selection)
		{
		case 1:
			system("cls");
			cout << "Student with highest avarage mark:\n\n\t    ";
			GetMaxAverage(group, groupSize).ShowFullInfo();
			cout << endl;
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "Students with low marks(less than 1/3 from maximum mark limit):\n\n";
			ShowLowMarks(group, groupSize);
			cout << endl;
			system("pause");
			break;
		case 3:
			do
			{
				system("cls");
				cout << "Group:\n\n";
				ShowGroup(group, groupSize);
				cout << "\nEnter student number to edit: ";
				cin >> selection;
				if (selection <= 0 || selection > groupSize)
				{
					cout << "\nInvalid input. Try again.\n";
					system("pause");
				}
			} while (selection <= 0 || selection > groupSize);
			profile = selection - 1;
			EditProfile(*group[profile]);
			break;
		case 0:
			cout << "\nHave a nice day.\n";
			break;
		default:
			cout << "\nInvalid input. Try again.\n";
			system("pause");
			break;
		}
	} while (selection != 0);
}