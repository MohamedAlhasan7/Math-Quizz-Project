#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Quizz.h"
using namespace std;

short ReadHowManyQuestions()
{
	short numberOfQuestions = 0;
	do
	{
		cout << "How many questions do you want to answer? ";
		cin >> numberOfQuestions;
	} while (numberOfQuestions < 1 || numberOfQuestions > 10);

	return numberOfQuestions;
}

enQuestionLevel ReadQuestionLevel()
{
	short QuestionLevel;
	do
	{
		cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
		cin >> QuestionLevel;
	} while (QuestionLevel < 1 || QuestionLevel > 4);

	return enQuestionLevel(QuestionLevel);
}

enOperationType ReadOperationType()
{
	short OperationType;
	do
	{
		cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
		cin >> OperationType;
	} while (OperationType < 1 || OperationType > 5);

	return enOperationType(OperationType);
}

int RandomNumber(short From, short To)
{
	return rand() % (To - From + 1) + From;
}

int SimpleCalculator(int Number1, int Number2, enOperationType OperationType)
{
	switch (OperationType)
	{
	case enOperationType::Add:
		return Number1 + Number2;
	case enOperationType::Sub:
		return Number1 - Number2;
	case enOperationType::Mul:
		return Number1 * Number2;
	case enOperationType::Div:
		return Number1 / Number2;
	}
}

stQuestion GenerateQuestion(enQuestionLevel QuestionLevel, enOperationType OperationType)
{
	stQuestion Question;

	if (QuestionLevel == enQuestionLevel::Mix)
	{
		QuestionLevel = enQuestionLevel(RandomNumber(1, 3));
	}

	if (OperationType == enOperationType::MixOp)
	{
		OperationType = enOperationType(RandomNumber(1, 4));
	}

	Question.OperationType = OperationType;

	switch (QuestionLevel)
	{
	case enQuestionLevel::EasyLevel:
		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);
		Question.QuestionLevel = QuestionLevel;
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		return Question;

	case enQuestionLevel::MedLevel:
		Question.Number1 = RandomNumber(10, 50);
		Question.Number2 = RandomNumber(10, 50);
		Question.QuestionLevel = QuestionLevel;
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		return Question;

	case enQuestionLevel::HardLevel:
		Question.Number1 = RandomNumber(50, 100);
		Question.Number2 = RandomNumber(50, 100);
		Question.QuestionLevel = QuestionLevel;
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		return Question;
	}

	return Question;
}

void GenerateQuizzQuestions(stQuizz& Quizz)
{
	for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++)
	{
		Quizz.QuestionsList[QuestionNumber] = GenerateQuestion(Quizz.QuestionLevel, Quizz.OperationType);
	}
}

string GetOpTypeSymbol(enOperationType OperationType)
{
	switch (OperationType)
	{
	case enOperationType::Add:
		return "+";
	case enOperationType::Sub:
		return "-";
	case enOperationType::Mul:
		return "*";
	case enOperationType::Div:
		return "/";
	case enOperationType::MixOp:
		return "Mix";
	}
}

void PrintTheQuestion(stQuizz& Quizz, short QuestionNumber)
{
	cout << "\nQuestion " << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "]\n\n";
	cout << Quizz.QuestionsList[QuestionNumber].Number1 << "\n";
	cout << Quizz.QuestionsList[QuestionNumber].Number2 << " ";
	cout << GetOpTypeSymbol(Quizz.QuestionsList[QuestionNumber].OperationType);
	cout << "\n_________\n";
}

int ReadPlayerAnswer()
{
	int PlayerAnswer;
	cin >> PlayerAnswer;
	return PlayerAnswer;
}

void ScreenColor(bool AnswerResult)
{
	if (AnswerResult)
	{
		system("color 2F");
	}
	else
	{
		system("color 4F");
	}
}

void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber)
{
	if (Quizz.QuestionsList[QuestionNumber].PlayerAnswer != Quizz.QuestionsList[QuestionNumber].CorrectAnswer)
	{
		Quizz.QuestionsList[QuestionNumber].AnswerResult = false;
		Quizz.NumberOfWrongAnswers++;

		cout << "Wrong Answer :-( \n";
		cout << "The Right Answer is: ";
		cout << Quizz.QuestionsList[QuestionNumber].CorrectAnswer;
		cout << "\n";
	}
	else
	{
		Quizz.QuestionsList[QuestionNumber].AnswerResult = true;
		Quizz.NumberOfRightAnswers++;

		cout << "Right Answer :-) ";
		cout << "\n";
	}

	cout << "\n";

	ScreenColor(Quizz.QuestionsList[QuestionNumber].AnswerResult);
}

void AskAndCorrectQuestionListAnswers(stQuizz& Quizz)
{
	for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++)
	{
		PrintTheQuestion(Quizz, QuestionNumber);

		Quizz.QuestionsList[QuestionNumber].PlayerAnswer = ReadPlayerAnswer();

		CorrectTheQuestionAnswer(Quizz, QuestionNumber);
	}

	Quizz.IsPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers);

}

string GetFinalResultText(bool Pass)
{
	if (Pass)
	{
		return "Pass";
	}
	else
	{
		return "Fail";
	}
}

string GetQuestionLevelText(enQuestionLevel QuestionLevel)
{
	switch (QuestionLevel)
	{
	case enQuestionLevel::EasyLevel:
		return "Easy";
	case enQuestionLevel::MedLevel:
		return "Medium";
	case enQuestionLevel::HardLevel:
		return "Hard";
	case enQuestionLevel::Mix:
		return "Mix";
	}
}

void PrintQuizzResults(stQuizz Quizz)
{
	cout << "\n_______________________________\n\n";
	cout << " Final Result: " << GetFinalResultText(Quizz.IsPass);
	cout << "\n_______________________________\n\n";

	cout << " Number Of Questions     : " << Quizz.NumberOfQuestions << "\n";
	cout << " Question Level          : " << GetQuestionLevelText(Quizz.QuestionLevel) << "\n";
	cout << " Operation Type          : " << GetOpTypeSymbol(Quizz.OperationType) << "\n";
	cout << " Number Of Right Answers : " << Quizz.NumberOfRightAnswers << "\n";
	cout << " Number Of Wrong Answers : " << Quizz.NumberOfWrongAnswers;
	cout << "\n_______________________________\n\n";
}

void PlayMathGame()
{
	stQuizz Quizz;

	Quizz.NumberOfQuestions = ReadHowManyQuestions();
	Quizz.QuestionLevel = ReadQuestionLevel();
	Quizz.OperationType = ReadOperationType();

	GenerateQuizzQuestions(Quizz);

	AskAndCorrectQuestionListAnswers(Quizz);

	PrintQuizzResults(Quizz);
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char PlayAgain = 'Y';
	do
	{
		ResetScreen();
		PlayMathGame();
		cout << "Do you want to play again? Y/N? ";
		cin >> PlayAgain;
	} while (PlayAgain == 'y' || PlayAgain == 'Y');

}