#pragma once
#include "fBullCowGame.h"

using FString = std::string;
using int32 = int;

void FBullCowGame::Reset()
{
	this->GameWon = false;
	this->CurrentTry = 0;
}

bool FBullCowGame::IsGameWon()
{
	return this->GameWon;
}

bool FBullCowGame::IsCorrect(FString Guess)
{
	
	if (Guess == this->Answer) {
		return this->GameWon = true;
	}
	else {
		char tempArray[100];
		this->bulls = 0;
		this->cows = 0;
		// Compiler warning consider using strcpy_s 
		
		for (int32 i = 0; i < this->wordLength; i++)
		{
			
			if (tolower(this->Answer[i]) == tolower(Guess[i])) 
			{
				this->bulls++;
			}
			else
			{
				/*
					Loop through each letter of the guess checking if the 
					letter matches but is In the wrong location
				*/
				for (int32 j = 0; j < Guess.length(); j++) {
					if (j != i && Guess[j] != this->Answer[j] && Guess[j] == this->Answer[i]) {
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

int32 FBullCowGame::GetMaxTries()
{
	return this->MaxTries;
}

int32 FBullCowGame::GetBulls(){
	return this->bulls;
}

int32 FBullCowGame::GetCows() {
	return this->cows;
}

void FBullCowGame::IncrementCurrentTry() {
	this->CurrentTry++;
}

int32 FBullCowGame::GetMaxTries() {
	return this->MaxTries;
}

int32 FBullCowGame::GetWordLength() {
	return this->wordLength;
}

int32 FBullCowGame::GetCurrentTry() {
	return this->CurrentTry;
}