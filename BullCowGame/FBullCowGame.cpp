#include "FBullCowGame.h"
#include <map>
#define TMap std::map 

//renaming to Unreal standard names
using FString = std::string;
using int32 = int;


void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet";


	myCurrentTry = 1;
	myHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;

	return;
}

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries{ {3,4},{4,7}, {5,10}, {6,16}, {7, 20} };
	return WordLengthToMaxTries[myHiddenWord.length()];
}

int32 FBullCowGame::GetCurrentTry() const
{
	return myCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return myHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{

	return bGameIsWon;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	// return correct error
		// If not an isogram
	if (!FBullCowGame::IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	// Isn't lowercase
	else if (!IsLowercase(Guess))
	{
		return EGuessStatus::Not_LowerCase;
	}
	// wrong length
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	// Other
	else
	{
		return EGuessStatus::OK;
	}

}

fBullCowCount FBullCowGame::SubmitValidGuess(FString tryWord)
{

	//Received a valid guess, increment try, and returns count

	myCurrentTry++;

	//setup a return struct

	fBullCowCount BullCowCount;

	//loop through all letters in the guess

	int32 hiddenWordLength = GetHiddenWordLength();

	for (int32 i = 0; i < hiddenWordLength; i++)
	{

		//compare letters against hidden word
		for (int32 j = 0; j < hiddenWordLength; j++)
		{

			// if letters match
			if (myHiddenWord[i] == tryWord[j])

				// if they're in the same place
				if (i == j)
					//increment bulls
					BullCowCount.Bulls++;
			// else
				// increment cows
				else
					BullCowCount.Cows++;

		}
	}

	if (BullCowCount.Bulls == hiddenWordLength)
	{
		bGameIsWon = true;
	}
	else
		bGameIsWon = false;
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Guess) const
{
	if (Guess.length() <= 1) 
	{
		return true;
	}

	TMap<char, bool> LetterSeen;

	for (auto Letter : Guess)
	{
		Letter = tolower(Letter); // handle mixed case

		if (!LetterSeen[Letter])
		{
			LetterSeen[Letter] = true;
		}
		else
		{
			return false;
		}
	}


	return true;
}

bool FBullCowGame::IsLowercase(FString Guess) const
{
	for (auto Letter : Guess)
	{
		if (!islower(Letter))
			return false;
	}
	return true;
}
