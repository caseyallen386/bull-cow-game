#include <iostream>
#include <string>
#include "fBullCowGame.h"

using FText = std::string;
using int32 = int;

FBullCowGame BCGame;

void main()
{
	// Intro into the game

	

	PrintIntro();

	GameStart();
	
	
	//repeat the guess to the user
	
}

void PrintIntro()
{
	int32 wordLength = BCGame.GetWordLength();
	std::cout << "Welcome to Bulls and Cows" << std::endl;
	std::cout << "Can you guess the " << wordLength << " letter word I am thinking of?\n" << std::endl;

}

void GameStart()
{
	do {
		//get a guess from the user
		FText Guess = GetGuess();
		int32 wordLength = BCGame.GetWordLength();

		if (Guess.length() != wordLength) {
			std::cout << "You must enter a " << wordLength << " answer. Try Again\n\n";
			
			continue;
		}

		DisplayResponce(BCGame.IsGameWon(), Guess);
		BCGame.IncrementCurrentTry();

		//DisplayNumbOfGuesses(NumOfGuesses);
	} while (BCGame.GetCurrentTry() != BCGame.GetMaxTries() && !BCGame.IsGameWon());

	if (PlayAgain()) {
		Gamestart();
	}
}

bool PlayAgain()
{
	std::cout << "Would you like to play again? Y/n ";

	FString Response = "";
	std::getline(std::cin, Response);

	if (Response == "Y") {
		BCGame.Reset();
		return true;
	}

	return false;
}

FText GetGuess()
{
	FText Guess;
	std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your Guess? ";
	std::getline(std::cin, Guess);
	
	return Guess;
}

void DisplayResponce(bool correct, FText Guess)
{
	if (correct) {
		//display correct
		std::cout << "Your Guess " << Guess << " Was Correct\n" << std::endl;
	}
	else {
		//display incorrect
		std::cout << "Nope but you have " << BCGame.GetBulls() << ": bulls and " << BCGame.GetCows() << ": cows\n" << std::endl;
	}
}








