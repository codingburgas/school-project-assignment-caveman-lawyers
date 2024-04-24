#include <iostream>
#include <string>
#include <ctime>
#include "../CavemanLawyersLib/Header.h"
using namespace std;

int main()
{
	//activates the menu function, creating a loop. the program will continue only if all tests are passed (or failed)
	menu();
	float average = returnAverageGrade();
	if (average >= 3)
	{
		//if the average grade is above 3, you pass! congratulations!
		youPassed();
	}
	else
	{
		// if the average grade is below 3, you lose
		youFailed();
	}
}