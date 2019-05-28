#include <iostream>
#include "Student.h"
#include "Functions.h"
using namespace std;

int main()
{
	srand(time(nullptr));
	Student group[2];
	for (int i = 0; i < 2; i++)
	{
		group[i].ShowFullInfo();
	}
	Student* group1 = new Student[2];
	for (int i = 0; i < 2; i++)
	{
		//group1[i]{ InitializeRandomly() };
	}
	return 0;
}