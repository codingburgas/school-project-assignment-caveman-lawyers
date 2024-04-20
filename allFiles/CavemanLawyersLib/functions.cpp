#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
using namespace std;

struct questions {
	string question;
	char correctAnswer;
};

struct classes {
	string teachersName;
	int classroomNumber;
	questions test[5];
	int grade;
};

classes math = { "Aristotle Pythagorson", 115, {
		{"Total sum of angles of a triangle\nA. 100\nB. 90\nC. 180\nD. 360\n", 'C'},
		{"5x+25=100. x=\nA. 10\nB. 17\nC. 20\nD. 25\n", 'B'},
		{"sin30 = \nA. 0\nB. -1\nC. 1\nD. 0,5", 'D'},
		{"Square is a type of\nA. All of beyond\nB. Parallelogram\nC. Rectangle\nD. Rhombus", 'A'},
		{"16^2 = \nA. 12\nB. 16\nC. 17\nD. 13", 'B'} }, 2 };
classes lit = { "Vazan Ivanov", 114, {
		{"Ivan Vazov is the author of\nA. Evgeniy Onegin\nB. Under the Yoke\nC. Don Juan\nD. Gulliver\n", 'B'},
		{"Don Juan is written by\nA. George Byron\nB. Alexander Pushkin\nC. Ivan Vazov\nD. Miguel Cervantes\n", 'A'},
		{"Metaphor is \nA. A type of exaggeration\nB. When event in later chapthers go earlier in the plot\nC. An unliteral phrase\nD. A poetical arc", 'C'},
		{"Outcast exiles(Nemili-nedragi) is about\nA. Disables in WW2\nB. Folk of a burned village during WW1\nC. Soldiers of the Balkanian wars\nD. Refugees 1870s", 'D'},
		{"Hristo Botes's birthday is on \nA. 6th Jan 1848\nB. 8th Mar 1845\nC. 2th Jun 1844\nD. 15th Sep 1850", 'A'} }, 2 };
classes prog = { "Stoyan Viktorov", 106, {
		{"A variable is \nA. A piece of memory of a certain type with a name\nB. An allocated in memory number of elements\nC. A positive number\nD. A type of library\n", 'A'},
		{"An int (integer) is a\nA. Number with a dot, like 3.14\nB. A number without a dot, positive and negative, like 4 or -21\nC. A single character\nD. A number of characters, like a text\n", 'B'},
		{"A string is \nA. A number with dot, like 3.14\nB. A single character\nC. A number of characters, like a text\nD. A piece of code, completing a certain task", 'C'},
		{"A void function \nA. Does not exist\nB. Returns any type of information, like int or double\nC. Does not return any information, as it has no 'return' operator\nD. Return either 1 or 0, so called void because of absence of any other variants of returns", 'C'},
		{"A pointer \nA. Can manipulate the original variable's value\nB. Itself contains only an address to another variable of the same type\nC. All of it\nD. Needs a pointer operator ('*') to be used not as an address, but as a variable", 'C'} }, 2 };
classes deu = { "Johann Goette", 214, {
		{"German Alphabet (including eszett) has\nA. 25 letters\nB. 26 letters\nC. 27 letters\nD. 28 letters\n", 'C'},
		{"How to say 'Hello, my name is Gregory'?\nA. Hallo, mein name its Gregory\nB. Halo, main name is Gregory\nC. Hallo, my name ist Gregory\nD. Helo, mein name is Gregory\n", 'A'},
		{"How to say 'money' in german? \nA. der Geld\nB. das Geld\nC. die Geld\nD. die Gold", 'C'},
		{"How to say 'Austria' in german? \nA. der Oster\nB. die Osterreich\nC. die Ustereich\nD. das Ostria", 'B'},
		{"Hallo! Wie heisen Sie? \nA. Hello! Mein name is... \nB. Hello! Ich heise... \nC. Hallo! Ich heist...\nD. Hallo! Ich heise...", 'D'} }, 2 };

bool onlyStarted = true, textbooksOpened = false;
bool examSit[4] = { 0, 0, 0, 0 };
float grades[4];
string subject[4] = {"1. Mathematics", "2. Literature", "3. Programming", "4. Deutsch"};

void youPassed()
{
	cout << "You passed! Congratulations! Your average is ";
	float averageGrade = 0;
	for (int i = 0; i < 4; i++)
	{
		averageGrade += grades[i];
	}
	averageGrade /= 4;
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
	if (grades[0] >= 3 && grades[1] >= 3 && grades[2] >= 3 && grades[3] >= 3)
	{
		youPassed();
		return;
	}
	else if (grades[0] <= 2 && grades[1] <= 2 && grades[2] <= 2 && grades[3] <= 2)
	{
		youFailed();
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		cout << subject[i];
		if (examSit[i])
		{
			cout << " [" << grades[i] << "]";
		}
		cout << endl;
	}
	cout << "5. Textbooks\n\n";
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
		cout << "\n\nViel Gluck!";
		Sleep(2000);
		system("cls");
		break;
	}
	case 5:
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
		for (int i = 0; i < 4; i++)
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