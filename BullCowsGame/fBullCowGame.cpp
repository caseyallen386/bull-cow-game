#pragma once
#include "fBullCowGame.h"



void FBullCowGame::Reset()
{
	this->GameWon = false;
	this->CurrentTry = 0;
	
}

bool FBullCowGame::IsGameWon(std::string Guess)
{
	return IsCorrect();
}

void FBullCowGame::PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows" << std::endl;
	std::cout << "Can you guess the " << this->wordLength << " letter word I am thinking of?\n" << std::endl;

}

void FBullCowGame::start()
{
	PrintIntro();
	PlayGame();
}
 
std::string FBullCowGame::GetGuess()
{
	std::cout << "Try " << this->CurrentTry << ". Enter your Guess? ";
	std::getline(std::cin, this->Guess);
	
	return this->Guess;
}

bool FBullCowGame::IsCorrect()
{
	
	if (this->Guess == this->Answer) {
		return this->GameWon = true;
	}
	else {
		char tempArray[100];
		this->bulls = 0;
		this->cows = 0;
		// Compiler warning consider using strcpy_s 
		
		for (int i = 0; i < wordLength; i++)
		{
			
			if (tolower(this->Answer[i]) == tolower(this->Guess[i])) 
			{
				this->bulls++;
			}
			else
			{
				/*
					Loop through each letter of the guess checking if the 
					letter matches but is In the wrong location
				*/
				for (int j = 0; j < this->Guess.length(); j++) {
					if (j != i && this->Guess[j] != this->Answer[j] && this->Guess[j] == this->Answer[i]) {
						this->cows++;
					}
				}

			}
		}

		if (this->bulls == this->wordLength) {
			return this->GameWon = true;
		}

	}
	return false;
}

bool FBullCowGame::PlayAgain()
{
	std::cout << "Would you like to play again? Y/n ";

	std::string Response = "";
	std::getline(std::cin, Response);

	if (Response == "Y") {
		this->Reset();
		return true;
	}

	return false;
}

int FBullCowGame::GetMaxTries()
{
	return MaxTries;
}

void FBullCowGame::DisplayResponce(bool correct)
{
	if (correct) {
		//display correct
		std::cout << "Your Guess " << Guess << " Was Correct\n" << std::endl;
	}
	else {
		//display incorrect
		std::cout << "Nope but you have " << this->bulls << ": bulls and " << this->cows << ": cows\n" << std::endl;
	}
}

void FBullCowGame::PlayGame()
{

	do {
		//get a guess from the user
		this->GetGuess();

		if (this->Guess.length() != this->wordLength) {
			std::cout << "You must enter a " << this->wordLength << " answer. Try Again\n\n";
			this->CurrentTry++;
			continue;
		}

		this->DisplayResponce(IsGameWon(Guess));
		this->CurrentTry++;

		//DisplayNumbOfGuesses(NumOfGuesses);
	} while (this->CurrentTry != this->MaxTries && !this->GameWon);

	if (this->PlayAgain()) {
		this->PlayGame();
	}

}




/*
void DisplayNumbOfGuesses(int NumOfGuesses)
{
	std::cout << "You have " << NumOfGuesses << " Left\n" << std::endl;
}
*/

