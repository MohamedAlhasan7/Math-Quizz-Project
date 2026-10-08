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

void PlayMathGame()
{
	stQuizz Quizz;

	Quizz.NumberOfQuestions = ReadHowManyQuestions();
	Quizz.QuestionLevel = ReadQuestionLevel();
	Quizz.OperationType = ReadOperationType();

	GenerateQuizzQuestions(Quizz);
}