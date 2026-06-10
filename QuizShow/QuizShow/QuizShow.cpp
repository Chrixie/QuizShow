#include <iostream>
#include <vector>

using namespace std;

struct GameInformation
{
	vector<string> users;

	int amountOfPlayers;
	int numberOfQuestions;


};

class Questions
{
public:
	void SetValues(string, string, string, string, int, int);

	void SetupQuestions();

	void AskQuestion();

private:
	string Question_Text;

	string Answer_1;
	string Answer_2;
	string Answer_3;

	int Correct_Answer;
	int Question_Score;
};

class GameLoop
{
public:
	void Loop()
	{
		Questions q1;
		Questions q2;
		Questions q3;
		Questions q4;
		Questions q5;
		GameInformation GInfo;

		int userNumberInput;
		string userStringInput;
		char ch;

		system("CLS");

		cout << "How many players? Select a number 1-3" << endl;
		cin >> userNumberInput;
		GInfo.amountOfPlayers = userNumberInput;

		for (int i = 0; i < GInfo.amountOfPlayers; i++)
		{
			cout << "Player name:";
			cin >> userStringInput;
			GInfo.users.push_back(userStringInput);
		}

		cout << "How many questions do you want? Select a number 1-10." << endl;
		cin >> userNumberInput;
		GInfo.numberOfQuestions = userNumberInput;

		q1.SetValues("What is Swedens capital?", "1: Gothenburg", "2: Stockholm", "3: Malmö", 2, 1);
		q2.SetValues("What is not part of an 'English Breakfast'?", "1: Eggs", "2: Sausage", "3: Steak", 3, 1);
		q3.SetValues("Which Web Browser has the most users?", "1: Chrome", "2: Edge", "3: Apple Safari", 1, 1);
		q4.SetValues("What does RAM stand for?", "1: Random Available Memory", "2: Random Acces Memory", "3: Random Alternative Memory", 2, 1);
		q5.SetValues("How many stars are there on the American flag?", "1: 49 stars", "2: 50 stars", "3: 51 stars", 2, 1);

		
		////////////////////////////////////////////////////////////////////////////////////////////////////////

			cout << "QUIZ GAME" << endl << endl;

			q1.AskQuestion();
			q2.AskQuestion();
			q3.AskQuestion();
			q4.AskQuestion();
			q5.AskQuestion();

		////////////////////////////////////////////////////////////////////////////////////////////////////////

		//DEBUG VALUE DISPLAY
		cout << GInfo.numberOfQuestions << "questions" << endl;
		cout << GInfo.amountOfPlayers << "players" << endl;

		for (int i = 0; i < GInfo.users.size(); i++)
		{
			cout << GInfo.users[i] << endl;
		}
	}
};

int main()
{
	GameLoop game;

	game.Loop();

	return 0;
}

void Questions::SetValues(string q, string a1, string a2, string a3, int ca, int qs)
{
	Question_Text = q;
	Answer_1 = a1;
	Answer_2 = a2;
	Answer_3 = a3;

	Correct_Answer = ca;
	Question_Score = qs;
}

void Questions::AskQuestion()
{
	int userInput;

	cout << "Question" << endl << endl;

	cout << "1. " << Answer_1 << endl;
	cout << "2. " << Answer_2 << endl;
	cout << "3. " << Answer_3 << endl << endl;

	cout << "Answer Number: ";
	cin >> userInput;

	if (userInput == Correct_Answer)
	{
		cout << "Correct!" << endl;
	}
	else
		cout << "WRONG!!!";
}