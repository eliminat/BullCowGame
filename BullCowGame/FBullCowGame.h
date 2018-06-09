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

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_LowerCase
};

class FBullCowGame
{
public:

	FBullCowGame(); // Constructor - no inputs


	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset(); //TODO make a more rich return value
	

	// counts bulls & cows, and increases try #. Assumes valid guess.
	fBullCowCount SubmitValidGuess(FString);

private:

	int32 myCurrentTry, myMaxTries;
	FString myHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};