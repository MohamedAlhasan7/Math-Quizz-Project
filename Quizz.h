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

enQuestionLevel ReadQuestionLevel();

enOperationType ReadOperationType();

int RandomNumber(short From, short To);

int SimpleCalculator(int Number1, int Number2, enOperationType OperationType);

stQuestion GenerateQuestion(enQuestionLevel QuestionLevel, enOperationType OperationType);

void GenerateQuizzQuestions(stQuizz& Quizz);

string GetOpTypeSymbol(enOperationType OperationType);

void PrintTheQuestion(stQuizz& Quizz, short QuestionNumber);

int ReadPlayerAnswer();

void ScreenColor(bool AnswerResult);

void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber);

void AskAndCorrectQuestionListAnswers(stQuizz& Quizz);

string GetFinalResultText(bool Pass);

string GetQuestionLevelText(enQuestionLevel QuestionLevel);

void PrintQuizzResults(stQuizz Quizz);

void PlayMathGame();

void ResetScreen();

void StartGame();