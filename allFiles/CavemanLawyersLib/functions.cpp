#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
using namespace std;

bool onlyStarted = true, textbooksOpened = false;
bool examSit[5] = { 0, 0, 0, 0, 0 };
float grades[5];
string subject[5] = {"1. Mathematics", "2. Literature", "3. Programming", "4. English", "5. Deutsch"};

void youPassed()
{
	cout << "You passed! Congratulations! Your average is ";
	float averageGrade = 0;
	for (int i = 0; i < 5; i++)
	{
		averageGrade += grades[i];
	}
	averageGrade /= 5;
	cout << averageGrade << "!\n\n";
	if (averageGrade >= 3 && averageGrade <= 3.49)
	{
		cout << "Thats a pretty normal grade, congrats!";
	}
	else if (averageGrade >= 3.5 && averageGrade <= 4.49)
	{
		cout << "Thats a good grade, bravo!";
	}
	else if (averageGrade >= 4.5 && averageGrade <= 5.49)
	{
		cout << "Thats a very good grade! Well done!";
	}
	else if (averageGrade >= 5.5)
	{
		cout << "Thats the best grade! You did a brilliant work!\n\n\n";
	}
}

void youFailed()
{
	cout << "I'm very sorry but you've failed. Good luck next time!\n\n";
	if (textbooksOpened != true)
	{
		cout << "(hint - try reading next time :) )\n\n";
	}
}

void menu()
{
	int input;
	cout <<
		"___  __  ___  ___  ___" << endl <<
		" |    /  |_|   |    |" << endl <<
		"_|_  /_  |    _|_   |" << endl <<
		"       SIMULATOR\n\n\n";

	if (onlyStarted)
	{
		cout << "Welcome to the IZPIT simulator! Your main task is to sit all the exams and graduate from PGKPI! Where would you wanted to start?\n\n\n";
		onlyStarted = false;
	}
	if (grades[0] >= 3 && grades[1] >= 3 && grades[2] >= 3 && grades[3] >= 3 && grades[4] >= 3)
	{
		youPassed();
		return;
	}
	else if (grades[0] <= 2 && grades[1] <= 2 && grades[2] <= 2 && grades[3] <= 2 && grades[4] <= 2)
	{
		youFailed();
		return;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << subject[i];
		if (examSit[i])
		{
			cout << " [" << grades[i] << "]";
		}
		cout << endl;
	}
	cout << "6. Textbooks\n\n";
	cout << "You are going to do the thing number: ";
	cin >> input;
	switch (input)
	{
	case 1:
	{
		cout << "\n\nGood luck in maths, than!";
		Sleep(2000);
		system("cls");
		break;
	}
	case 2:
	{
		cout << "\n\nMay the spirit of Ivan Vazov help you!";
		Sleep(2000);
		system("cls");
		break;
	}
	case 3:
	{
		cout << "\n\ncout << 'Break a leg!' << endl;";
		Sleep(2000);
		system("cls");
		break;
	}
	case 4:
	{
		cout << "\n\nHave a cup of tea and there you go!";
		Sleep(2000);
		system("cls");
		break;
	}
	case 5:
	{
		cout << "\n\nViel Gluck!";
		Sleep(2000);
		system("cls");
		break;
	}
	case 6:
	{
		cout << "\n\nIt's always good to review the knowledge and go on back again!";
		textbooksOpened = true;
		Sleep(2000);
		system("cls");
		break;
	}
	case 256:
	{
		cout << "You know, its not good to read the exam programm code, but fine...\n\n";
		for (int i = 0; i < 5; i++)
		{
			examSit[i] = true;
			grades[i] = 6;
		}
	}
	default:
	{
		cout << "Uh... sorry, i dont think there is such an option... Please, input your choice again!";
		Sleep(3500);
		system("cls");
		menu();
	}
	}
}