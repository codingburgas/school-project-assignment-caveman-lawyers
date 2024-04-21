#include <iostream>
#include <string>
using namespace std;

struct Question
{
    string text;
    string options[4];
    char correctOption;
};

struct Subject
{
    string nameOfProfessor;
    int numberOfRoom;
    Question questions[5];
};

int main()
{
    cout << "Welcome to the school session!\n";

    Subject subjects[3];

    subjects[0].nameOfProfessor = "Mathematics - Dr. Ivanov";
    subjects[0].numberOfRoom = 101;
    subjects[0].questions[0] = { "What is the square root of 81?", {"9", "8", "7", "6"}, 'A' };
    subjects[0].questions[1] = { "What is the value of pi (π) to two decimal places?", {"3.14", "3.15", "3.16", "3.17"}, 'A' };
    subjects[0].questions[2] = { "What is the formula for the area of a rectangle?", {"length × width", "2 × (length + width)", "π × radius^2", "1/2 × base × height"}, 'A' };

    subjects[1].nameOfProfessor = "Literature - Prof. Petrov";
    subjects[1].numberOfRoom = 102;
    subjects[1].questions[0] = { "Who wrote 'Romeo and Juliet'?", {"William Shakespeare", "Charles Dickens", "Jane Austen", "F. Scott Fitzgerald"}, 'A' };
    subjects[1].questions[1] = { "In which novel would you find the characters Winston Smith and Big Brother?", {"1984", "Brave New World", "Fahrenheit 451", "Animal Farm"}, 'A' };
    subjects[1].questions[2] = { "Who is the author of 'To Kill a Mockingbird'?", {"Harper Lee", "John Steinbeck", "J.D. Salinger", "Mark Twain"}, 'A' };

    subjects[2].nameOfProfessor = "English - Prof. Georgieva";
    subjects[2].numberOfRoom = 103;
    subjects[2].questions[0] = { "What are the three main verb tenses in English?", {"Present Simple, Past Simple, Future Simple", "Present Continuous, Past Continuous, Future Continuous", "Present Perfect, Past Perfect, Future Perfect", "Present Simple, Past Simple, Future Simple"}, 'C' };
    subjects[2].questions[1] = { "What is the opposite of 'victory'?", {"defeat", "triumph", "success", "achievement"}, 'A' };
    subjects[2].questions[2] = { "Which word means 'a large body of water surrounded by land'?", {"lake", "ocean", "river", "sea"}, 'A' };
    cout << "Please select a subject:\n";
    for (int i = 0; i < 3; ++i)
    {
        cout << i + 1 << ". " << subjects[i].nameOfProfessor << endl;
    }
    int choice;
    cin >> choice;

    cout << "Subject: " << subjects[choice - 1].nameOfProfessor << endl;
    cout << "Professor: " << subjects[choice - 1].nameOfProfessor << endl;
    cout << "Room number: " << subjects[choice - 1].numberOfRoom << endl;

    cout << "Questions:\n";
    for (int i = 0; i < 3; ++i)
    {
        cout << i + 1 << ". " << subjects[choice - 1].questions[i].text << endl;
        cout << "   A. " << subjects[choice - 1].questions[i].options[0] << endl;
        cout << "   B. " << subjects[choice - 1].questions[i].options[1] << endl;
        cout << "   C. " << subjects[choice - 1].questions[i].options[2] << endl;
        cout << "   D. " << subjects[choice - 1].questions[i].options[3] << endl;

        char userAnswer;
        cout << "Your answer (A, B, C, D): ";
        cin >> userAnswer;

        if (userAnswer == subjects[choice - 1].questions[i].correctOption || userAnswer == subjects[choice - 1].questions[i].correctOption - 'A' + 'a')
        {
            cout << "Correct answer!\n";
        }
        else
        {
            cout << "Incorrect answer!\n";
        }
    }
    return 0;
}