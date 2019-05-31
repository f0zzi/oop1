#pragma once
#include <ctime>
#include <cstdlib>
#include "Student.h"
using namespace std;

Student Initialize();

Student InitializeRandomly();

void ShowGroup(Student** group, int groupSize);

Student& GetMaxAverage(Student** group, int groupSize);

void ShowLowMarks(Student** group, int groupSize);