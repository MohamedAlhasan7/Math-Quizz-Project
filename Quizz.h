#pragma once

#include <iostream>
using namespace std;

enum enQuestionLevel
{
	EasyLevel = 1,
	MedLevel = 2,
	HardLevel = 3,
	Mix = 4
};

enum enOperationType
{
	Add = 1,
	Sub = 2,
	Mul = 3,
	Div = 4,
	MixOp = 5
};

struct stQuestion
{
	int Number1 = 0;
	int Number2 = 0;
	enQuestionLevel QuestionLevel;
	enOperationType OperationType;
	int PlayerAnswer = 0;
	int CorrectAnswer = 0;
	bool AnswerResult = false;
};

struct stQuizz
{
	stQuestion QuestionsList[100];
	short NumberOfQuestions = 0;
	enQuestionLevel QuestionLevel;
	enOperationType OperationType;
	short NumberOfRightAnswers = 0;
	short NumberOfWrongAnswers = 0;
	bool IsPass = false;
};

short ReadHowManyQuestions();

void PlayMathGame();