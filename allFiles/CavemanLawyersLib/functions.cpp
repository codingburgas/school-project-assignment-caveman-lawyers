#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
#include <conio.h>
using namespace std;

struct questions {
	string question;
	char correctAnswer;
};

struct classes {
	questions test[5];
};

classes math = {{
		{"Total sum of angles of a triangle\nA. 100\nB. 90\nC. 180\nD. 360\n", 'C'},
		{"5x+25=100. x=\nA. 10\nB. 17\nC. 20\nD. 25\n", 'B'},
		{"sin30 = \nA. 0\nB. -1\nC. 1\nD. 0,5\n", 'D'},
		{"Square is a type of\nA. All of beyond\nB. Parallelogram\nC. Rectangle\nD. Rhombus\n", 'A'},
		{"16^2 = \nA. 12\nB. 16\nC. 17\nD. 13\n", 'B'} } };
classes lit = {{
		{"Ivan Vazov is the author of\nA. Evgeniy Onegin\nB. Under the Yoke\nC. Don Juan\nD. Gulliver\n", 'B'},
		{"Don Juan is written by\nA. George Byron\nB. Alexander Pushkin\nC. Ivan Vazov\nD. Miguel Cervantes\n", 'A'},
		{"Metaphor is \nA. A type of exaggeration\nB. When event in later chapthers go earlier in the plot\nC. An unliteral phrase\nD. A poetical arc\n", 'C'},
		{"Outcast exiles(Nemili-nedragi) is about\nA. Disables in WW2\nB. Folk of a burned village during WW1\nC. Soldiers of the Balkanian wars\nD. Refugees 1870s\n", 'D'},
		{"Hristo Botes's birthday is on \nA. 6th Jan 1848\nB. 8th Mar 1845\nC. 2th Jun 1844\nD. 15th Sep 1850\n", 'A'} } };
classes prog = { {
		{"A variable is \nA. A piece of memory of a certain type with a name\nB. An allocated in memory number of elements\nC. A positive number\nD. A type of library\n", 'A'},
		{"An int (integer) is a\nA. Number with a dot, like 3.14\nB. A number without a dot, positive and negative, like 4 or -21\nC. A single character\nD. A number of characters, like a text\n", 'B'},
		{"A string is \nA. A number with dot, like 3.14\nB. A single character\nC. A number of characters, like a text\nD. A piece of code, completing a certain task\n", 'C'},
		{"A void function \nA. Does not exist\nB. Returns any type of information, like int or double\nC. Does not return any information, as it has no 'return' operator\nD. Return either 1 or 0, so called void because of absence of any other variants of returns\n", 'C'},
		{"A pointer \nA. Can manipulate the original variable's value\nB. Itself contains only an address to another variable of the same type\nC. All of it\nD. Needs a pointer operator ('*') to be used not as an address, but as a variable\n", 'C'} } };
classes deu = {{
		{"German Alphabet (including eszett) has\nA. 25 letters\nB. 26 letters\nC. 27 letters\nD. 28 letters\n", 'C'},
		{"How to say 'Hello, my name is Gregory'?\nA. Hallo, mein name its Gregory\nB. Halo, main name is Gregory\nC. Hallo, my name ist Gregory\nD. Helo, mein name is Gregory\n", 'A'},
		{"How to say 'money' in german? \nA. der Geld\nB. das Geld\nC. die Geld\nD. die Gold\n", 'C'},
		{"How to say 'Austria' in german? \nA. der Oster\nB. die Osterreich\nC. die Ustereich\nD. das Ostria\n", 'B'},
		{"Hallo! Wie heisen Sie? \nA. Hello! Mein name is... \nB. Hello! Ich heise... \nC. Hallo! Ich heist...\nD. Hallo! Ich heise...\n", 'D'} } };

bool onlyStarted = true, textbooksOpened = false;
bool examSit[4] = { 0, 0, 0, 0 };
float grades[4] = {1, 1, 1, 1}, averageGrade = 0;
string subject[4] = {"1. Mathematics", "2. Literature", "3. Programming", "4. Deutsch"};
char readyForTheTest, answer;

void menu();

char makeCapital(char ch)
{
	if (ch >= 65 && ch <= 90)
	{
		return ch;
	}
	else if (ch >= 97 && ch <= 122)
	{
		ch -= 32;
		return ch;
	}
}

float returnAverageGrade()
{
	return averageGrade;
}

void test(int index)
{
	switch (index)
	{
	case 0:
	{
		cout << "Hello! Welcome to the Mathematics class! My name is Aristotle Pythagorson, are you ready to take the test?\n";
		break;
	}
	case 1:
	{
		cout << "Well, hello there, my dear student! How are you? My name, as you might already know, is Vazan Ivanov, I'm your Literature teacher. Are you ready to test your literature skills?\n";
		break;
	}
	case 2:
	{
		cout << "Hello. My name is Stoyan Viktorov. Are you ready to sit the test()?\n";
		break;
	}
	case 3:
	{
		cout << "Hallo! Are du ready zu take a test?\n";
		break;
	}
	}
	while (true)
	{
		cout << "\nY/N\n";
		readyForTheTest = makeCapital(_getch());
		if (readyForTheTest != 'N' && readyForTheTest != 'Y')
		{
			cout << "Uhh... sorry, that isn't an option... The options were";
			Sleep(2500);
			system("cls");
		}
		else
		{
			break;
		}
	}
	if (readyForTheTest == 'N')
	{
		menu();
	}
	else
	{
		switch (index)
		{
		case 0:
		{
			for (int i = 0; i < 5; i++)
			{
				cout << math.test[i].question;
				answer = _getch();
				if (makeCapital(answer) == math.test[i].correctAnswer)
				{
					grades[0] += 1;
					cout << "Correct! Moving on...";
					Sleep(1000);
					system("cls");
				}
				else
				{
					cout << "That's incorrect. Anyways, moving on...";
					Sleep(1000);
					system("cls");
				}
			}
			break;
		}
		case 1:
		{
			for (int i = 0; i < 5; i++)
			{
				cout << lit.test[i].question;
				answer = _getch();
				if (makeCapital(answer) == lit.test[i].correctAnswer)
				{
					grades[1] += 1;
					cout << "Bravo! Correct! To the next question...";
					Sleep(1000);
					system("cls");
				}
				else
				{
					cout << "That's... Incorrect. Anyways, moving on...";
					Sleep(1000);
					system("cls");
				}
			}
			break;
		}
		case 2:
		{
			for (int i = 0; i < 5; i++)
			{
				cout << prog.test[i].question;
				answer = _getch();
				if (makeCapital(answer) == prog.test[i].correctAnswer)
				{
					grades[2] += 1;
					cout << "Correct. Moving on...";
					Sleep(1000);
					system("cls");
				}
				else
				{
					cout << "It is incorrect. Let's go on...";
					Sleep(1000);
					system("cls");
				}
			}
			break;
		}
		case 3:
		{
			for (int i = 0; i < 5; i++)
			{
				cout << deu.test[i].question;
				answer = _getch();
				if (makeCapital(answer) == deu.test[i].correctAnswer)
				{
					grades[3] += 1;
					cout << "Das ist korrect! Moving on...";
					Sleep(1000);
					system("cls");
				}
				else
				{
					cout << "Das ist falsch. Anyways, moving on...";
					Sleep(1000);
					system("cls");
				}
			}
			break;
		}
		}
	}
	if (grades[index] < 2)
	{
		grades[index] = 2;
	}
	examSit[index] = true;
	menu();
}

void youPassed()
{
	cout << "You passed! Congratulations! Your average is ";
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
	if (examSit[0] && examSit[1] && examSit[2] && examSit[3])
	{
		for (int i = 0; i < 4; i++)
		{
			averageGrade += grades[i];
		}
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
		test(0);
		break;
	}
	case 2:
	{
		cout << "\n\nMay the spirit of Ivan Vazov help you!";
		Sleep(2000);
		system("cls");
		test(1);
		break;
	}
	case 3:
	{
		cout << "\n\ncout << 'Break a leg!' << endl;";
		Sleep(2000);
		system("cls");
		test(2);
		break;
	}
	case 4:
	{
		cout << "\n\nViel Gluck!";
		Sleep(2000);
		system("cls");
		test(3);
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