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

void PlayMathGame()
{
	stQuizz Quizz;

	Quizz.NumberOfQuestions = ReadHowManyQuestions();
}