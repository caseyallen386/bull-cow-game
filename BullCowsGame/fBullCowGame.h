#pragma once
#include <iostream>
#include <string>
#include <locale>
#include <memory>





class FBullCowGame {


private:

	//class Members
	std::string Answer = "Something";
	int wordLength = Answer.length();
	int bulls = 0;
	int cows = 0;
	int MaxTries;
	int CurrentTry;
	std::string Guess;

	bool GameWon = false;
	
	
	//Private methods
	void Reset();
	void PrintIntro();
	void PlayGame();
	
public:
	
	FBullCowGame() {
		this->MaxTries = 10;
		this->CurrentTry = 1;
	}

	//contsructor overload maybe

	/*FBullCowGame(int tries, int wLength) {
		MaxTries = tries;
		wordLength = wLength;
	}*/

	//Properties

	int getMaxTries() {
		return MaxTries;
	}

	int getWordLength() {
		return wordLength;
	}

	int getCurrentTry() {
		return CurrentTry;
	}

	void start();
	std::string GetGuess();
	bool IsGameWon(std::string Guess);
	bool IsCorrect();
	bool PlayAgain();
	int GetMaxTries();
	void DisplayResponce(bool correct);


};