#pragma once

#include <string>

//renaming to Unreal standard names
using FString= std::string;
using int32 = int;


struct fBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
public:

	FBullCowGame(); // Constructor - no inputs


	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); //TODO make a more rich return value
	bool CheckGuessValidity(FString);

	// counts bulls & cows, and increases try #. Assumes valid guess.
	fBullCowCount SubmitGuess(FString);

private:

	int32 myCurrentTry, myMaxTries;
	FString myHiddenWord;
	
};