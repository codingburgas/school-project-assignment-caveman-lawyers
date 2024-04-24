#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
#include <conio.h>
using namespace std;

// Created a structure for questions an right answers
struct questions {
	string question;
	char correctAnswer;
};

// Created a class with all of information about a lesson - the test itself, if it is sit, what grade do you have, etc.
class classes
{
	private:
		bool examSit;
		int grades;
		string subject;
	public:
		questions test[5];
		// making a definitiative function. If a class is tried to be defined outside functions, the error occures, so it will be done as soon, as the program starts.
		void defineClasses(int index)
		{
			switch (index)
			{
			case 0:
			{
				// In the first place comes the question and in the second the correct answer
				test[0] = { "Total sum of angles of a triangle\nA. 100\nB. 90\nC. 180\nD. 360\n", 'C' };
				test[1] = { "5x+25=100. x=\nA. 10\nB. 15\nC. 20\nD. 25\n", 'B' };
				test[2] = { "sin30 = \nA. 0\nB. -1\nC. 1\nD. 0,5\n", 'D' };
				test[3] = { "Square is a type of\nA. All of beyond\nB. Parallelogram\nC. Rectangle\nD. Rhombus\n", 'A' };
				test[4] = { "16^2 = \nA. 144\nB. 256\nC. 196\nD. 324\n", 'B' };
				subject = "1. Mathematics";
				break;
			}
			case 1:
			{
				test[0] = { "Ivan Vazov is the author of\nA. Evgeniy Onegin\nB. Under the Yoke\nC. Don Juan\nD. Gulliver\n", 'B' };
				test[1] = { "Don Juan is written by\nA. George Byron\nB. Alexander Pushkin\nC. Ivan Vazov\nD. Miguel Cervantes\n", 'A' };
				test[2] = { "Metaphor is \nA. A type of exaggeration\nB. When event in later chapthers go earlier in the plot\nC. An unliteral phrase\nD. A poetical arc\n", 'C' };
				test[3] = { "Outcast exiles(Nemili-nedragi) is about\nA. Disables in WW2\nB. Folk of a burned village during WW1\nC. Soldiers of the Balkanian wars\nD. Refugees 1870s\n", 'D' };
				test[4] = { "Hristo Botes's birthday is on \nA. 6th Jan 1848\nB. 8th Mar 1845\nC. 2th Jun 1844\nD. 15th Sep 1850\n", 'A' };
				subject = "2. Literature";
				break;
			}
			case 2:
			{
				test[0] = { "A variable is \nA. A piece of memory of a certain type with a name\nB. An allocated in memory number of elements\nC. A positive number\nD. A type of library\n", 'A' };
				test[1] = { "An int (integer) is a\nA. Number with a dot, like 3.14\nB. A number without a dot, positive and negative, like 4 or -21\nC. A single character\nD. A number of characters, like a text\n", 'B' };
				test[2] = { "A string is \nA. A number with dot, like 3.14\nB. A single character\nC. A number of characters, like a text\nD. A piece of code, completing a certain task\n", 'C' };
				test[3] = { "A void function \nA. Does not exist\nB. Returns any type of information, like int or double\nC. Does not return any information, as it has no 'return' operator\nD. Return either 1 or 0, so called void because of absence of any other variants of returns\n", 'C' };
				test[4] = { "A pointer \nA. Can manipulate the original variable's value\nB. Itself contains only an address to another variable of the same type\nC. All of it\nD. Doesn't need a pointer operator ('*') to be used not as an address, but as a variable\n", 'C' };
				subject = "3. Programming";
				break;
			}
			case 3:
			{
				test[0] = { "German Alphabet (including eszett) has\nA. 25 letters\nB. 26 letters\nC. 27 letters\nD. 28 letters\n", 'C' };
				test[1] = { "How to say 'Hello, my name is Gregory'?\nA. Hallo, mein name ist Gregory\nB. Halo, main name is Gregory\nC. Hallo, my name ist Gregory\nD. Helo, mein name is Gregory\n", 'A' };
				test[2] = { "How to say 'money' in german? \nA. der Geld\nB. das Geld\nC. die Geld\nD. die Gold\n", 'C' };
				test[3] = { "How to say 'Austria' in german? \nA. der Oster\nB. die Osterreich\nC. die Ustereich\nD. das Ostria\n", 'B' };
				test[4] = { "Hallo! Wie heisen Sie? \nA. Hello! Mein name is... \nB. Hello! Ich heise... \nC. Hallo! Ich heist...\nD. Hallo! Ich heisse...\n", 'D' };
				subject = "4. Deutsch";
				break;
			}
			}
			examSit = false;
			grades = 1;
		}
		//as soon, as most variables are in private sector, they have to be accessed through those functions
		bool returnExamSit()
		{
			return examSit;
		}
		void changeExamSit(bool changes)
		{
			examSit = changes;
		}
		int returnGrades()
		{
			return grades;
		}
		// if said so, function adds a value, given as an argument, not replacing it
		void changeGrades(int changes, bool toPlus)
		{
			if (toPlus)
			{
				grades += changes;
			}
			else
			{
				grades = changes;
			}
		}
		string returnSubject()
		{
			return subject;
		}
		void textbookMenu()
		{
			// outputs subject, question and the answer from the current subject
			cout << returnSubject() << ": " << endl;
			for (int i = 0; i < 5; i++)
			{
				cout << test[i].question << endl;
				cout << "Answer: " << test[i].correctAnswer << endl;
			}
			cout << endl;
			cout << endl;
		}
};

//initialisation of the global variables
	classes theTest[4];
	bool onlyStarted = true, textbooksOpened = false;
	float averageGrade = 0;
	char readyForTheTest, answer;

//initialisation of the Main Menu. The program uses some type of circle - menu relates on the functions and the functions relate on the main menu, so initialisation and declaration are separate
	void menu();

// algrotithm to make a given char always uppercase
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

//return average grade
	float returnAverageGrade()
	{
		return averageGrade;
	}

// main part of the program, the test() functions asks questions and writes grades
	void test(int index)
	{
		//according to the "index" argument, it gives the player unique greetings from each professor
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
		// loops the choice menu untill player won't input either Y or N (as Yes and No). by the way, made without "cin"!
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
		// if player inputs "N" as a signal of being unready for the test, it transports him back to the main menu
		if (readyForTheTest == 'N')
		{
			menu();
		}
		// or else starts a test
		else
		{
			for (int i = 0; i < 5; i++)
			{
				// gets a question from the "test" array of type question (as seen above) and takes it from the needed subject, as it is theTest with certain index (math - 0, lit - 1, programming - 2, deutsch - 3)
				cout << theTest[index].test[i].question;
				answer = _getch();
				// anyway possible - both uppercase and lowercase, the program will get the exact answer
				if (makeCapital(answer) == theTest[index].test[i].correctAnswer)
				{
					// if the answer is correct (is the same as written in the structure)
					theTest[index].changeGrades(1, true);
					cout << "Correct! Moving on...";
					Sleep(1000);
					system("cls");
				}
				else
				{
					// if the answer is incorrect
					cout << "That's incorrect. Anyways, moving on...";
					Sleep(1000);
					system("cls");
				}
			}
		}
		// written to make sure grade doesn't get below 2. if player doesn't answer any questions or answers only one of them, he gets a bad grade, aka 2. the further correct answers strike - the bigger the grade, up to best - 6
		if (theTest[index].returnGrades() < 2)
		{
			theTest[index].changeGrades(2, false);
		}
		// shows to the program that the exact exam is done and may be flagged this way
		theTest[index].changeExamSit(true);
		menu();
	}

	void youPassed()
	{
		cout << "You passed! Congratulations! Your average is ";
		// return your average grade
		for (int i = 0; i < 4; i++)
		{
			averageGrade += theTest[i].returnGrades();
		}
		averageGrade /= 4;
		cout << averageGrade << "!\n\n";
		// shows the different messages, according to the grade gotten
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

	// the so-called "bad ending", or "try again" screen
	void youFailed()
	{
		cout << "I'm very sorry but you've failed. Good luck next time!\n\n";
		if (textbooksOpened != true)
		{
			cout << "(hint - try reading next time :) )\n\n";
		}
	}

	// second main part of the program. shows at the beginning and helps us orientate in the tests
	void menu()
	{
		int input;
		cout <<
			"___  __  ___  ___  ___" << endl <<
			" |    /  |_|   |    |" << endl <<
			"_|_  /_  |    _|_   |" << endl <<
			"       SIMULATOR\n\n\n";
		// if the program is just started, shows out the greeting message and declares the theTest array, by the reasons, written above
		if (onlyStarted)
		{
			cout << "Welcome to the IZPIT simulator! Your main task is to sit all the exams and graduate from PGKPI! Where would you wanted to start?\n\n\n";
			onlyStarted = false;
			for (int i = 0; i < 4; i++)
			{
				theTest[i].defineClasses(i);
			}
		}
		// if all tests are sitten, closes the menu function, that makes us go further in the projectCavemanLawyers.cpp file, the main in the program
		if (theTest[0].returnExamSit() && theTest[1].returnExamSit() && theTest[2].returnExamSit() && theTest[3].returnExamSit())
		{
			for (int i = 0; i < 4; i++)
			{
				averageGrade += theTest[i].returnGrades();
			}
			return;
		}
		// writes name of school subject
		for (int i = 0; i < 4; i++)
		{
			cout << theTest[i].returnSubject();
			// if the test is sitten, writes your grade
			if (theTest[i].returnExamSit())
			{
				cout << " [" << theTest[i].returnGrades() << "]";
			}
			cout << endl;
		}
		cout << "5. Textbooks\n\n";
		cout << "You are going to do the thing number: ";
		// choose between 4 tests and a textbook with answers
		cin >> input;
		switch (input)
		{
			//basically retranslates the user to the test() function with certain index
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
			Sleep(2000);
			system("cls");
			// outputs all of the content in the textbooks
			for (int i = 0; i < 4; i++)
			{
				theTest[i].textbookMenu();
			}
			// lets the player choose, if he've read all of it and can continue or not (only "Y" key)
			 cout << "Have you read it all? Can we continue?";
			while (true)
			{
				cout << "\nPress 'Y' to go to the Main Menu\n";
				readyForTheTest = makeCapital(_getch());
				if (readyForTheTest != 'Y')
				{
					cout << "Uhh... sorry, that isn't an option...";
				}
				else
				{
					break;
				}
			}
			// if the bad ending occurs, but you've read textbooks, you dont get the hint
			textbooksOpened = true;
			Sleep(500);
			system("cls");
			menu();
			break;
		}
		case 256:
		{
			// a cheat-code for testing purposes
			cout << "You know, its not good to read the exam programm code, but fine...\n\n";
			for (int i = 0; i < 4; i++)
			{
				theTest[i].changeExamSit(true);
				theTest[i].changeGrades(6, false);
			}
		}
		default:
		{
			// if the player has inputted the wrong option
			cout << "Uh... sorry, i dont think there is such an option... Please, input your choice again!";
			Sleep(3500);
			system("cls");
			menu();
		}
		}
	}