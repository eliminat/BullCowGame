#include "FBullCowGame.h"

//renaming to Unreal standard names
using FString = std::string;
using int32 = int;


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";


	myCurrentTry = 1;
	myMaxTries = MAX_TRIES;
	myHiddenWord = HIDDEN_WORD;

	return;
}

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const
{
	return myMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return myCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

fBullCowCount FBullCowGame::SubmitGuess(FString)
{

	//Received a valid guess, increment turn, and returns count

	// increment turn number

	myCurrentTry++;

	//setup a return struct

	fBullCowCount BullCowCount;

	//loop through all letters in the guess

	int32 hiddenWordLength = myHiddenWord.length();

	for(int32 i = 0; i < hiddenWordLength; i++)
	{

		//compare letters against hidden word
		for (int32 j = 0; j < hiddenWordLength; j++)
		{



			// if they match
				// if they're in the same place
					//increment bulls
				// else
					// increment cows

		}
	}

	return BullCowCount;
}
