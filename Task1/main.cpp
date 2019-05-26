#include <iostream>
#include "Student.h"
using namespace std;

int main()
{
	Student st1(1111, 3, new int[3]{ 4,5,7 }, "test");
	st1.ShowFullInfo();
	st1.SetMark(2, 99);
	st1.ShowFullInfo();
	st1.AddMark(89);
	st1.ShowFullInfo();

	return 0;
}