#include <iostream>
#include <string>
#include <ctime>
#include "../CavemanLawyersLib/Header.h"
using namespace std;

int main()
{
	menu();
	float average = returnAverageGrade();
	if (average >= 3)
	{
		youPassed();
	}
	else
	{
		youFailed();
	}
}