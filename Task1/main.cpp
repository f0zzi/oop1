#include <iostream>
#include "Student.h"
#include "Functions.h"
using namespace std;

int main()
{
	Student st1(1111, 3, new int[3]{ 4,5,7 }, "test");
	st1.ShowFullInfo();
	st1.SetMark(2, 99);
	st1.ShowFullInfo();
	st1.AddMark(89);
	st1.ShowFullInfo();
	Student st2 = Initialize();
	st2.ShowFullInfo();
	Student st3 = Initialize();
	st3.ShowFullInfo();
	return 0;
}