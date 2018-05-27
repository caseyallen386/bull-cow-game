#pragma once
#include <iostream>
#include <string>
#include <locale>
#include <memory>

using FString = std::string;
using int32 = int;


class FBullCowGame {


private:

	//class Members
	FString Answer = "Something";
	int32 wordLength = Answer.length();
	int32 bulls = 0;
	int32 cows = 0;
	int32 MaxTries;
	int32 CurrentTry;

	bool GameWon = false;
	
public:
	
	FBullCowGame() {
		this->MaxTries = 10;
		this->CurrentTry = 1;
	}

	FBullCowGame(int32 tries, FString answer) {
		MaxTries = tries;
		this->Answer = answer;
		this->wordLength = this->Answer.length();
	}


	void Reset();
	void IncrementCurrentTry();

	bool IsGameWon();
	bool IsCorrect(FString);

	int32 GetMaxTries();
	int32 GetBulls();
	int32 GetCows();
	int32 GetMaxTries();
	int32 GetWordLength();
	int32 GetCurrentTry();

};