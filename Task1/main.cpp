#include <iostream>
#include "Student.h"
#include "Functions.h"
using namespace std;

int main()
{
	srand(time(nullptr));
	Student** group = new Student * [2];
	group[1] = new Student[10];
	//group[1] = new Student{InitializeRandomly()};
	//group[1]->ShowFullInfo();
	group[0][1].ShowFullInfo();
	return 0;
}