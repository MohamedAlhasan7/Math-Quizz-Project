#include <iostream>
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

void PlayMathGame()
{
	stQuizz Quizz;

	Quizz.NumberOfQuestions = ReadHowManyQuestions();
	Quizz.QuestionLevel = ReadQuestionLevel();
	Quizz.OperationType = ReadOperationType();
}