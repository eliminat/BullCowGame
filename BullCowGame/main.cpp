// Main.cpp for the Bull-Cow Game

#include <iostream>
#include <string>
#include "FBullCowGame.h"


//renaming to Unreal standard names
using FText = std::string;
using int32 = int;



void PrintIntro();
void PlayGame();
FText GetValidGuess();
void PrintGuess(FText);
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame;

int main()
{

	do
	{

		PrintIntro();

		PlayGame();

	} while (AskToPlayAgain());
		

	return 0;
}


//Intro the game
void PrintIntro()
{

	std::cout << "\n\nWelcome to the Bulls and Cows Game!" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?" << std::endl;
}


//Get a guess from the player
FText GetValidGuess()
{
	FText playerGuess = "";

	int32 currentTry = BCGame.GetCurrentTry();

	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do
	{
		std::cout << "\nTry " << currentTry << " of " << BCGame.GetMaxTries() << "\nPlease enter your guess: ";

		std::getline(std::cin, playerGuess);

		Status = BCGame.CheckGuessValidity(playerGuess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n";
			break;
		case EGuessStatus::Not_LowerCase:
			std::cout << "Please enter the word using all lower case letters.\n";
			break;
		default:
			// assume guess is valid
			break;

		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); // Keep looping until no errors

	return playerGuess;
}


void PrintGuess(FText playerGuess)
{
	//repeat the guess back to the player
	std::cout << "\nYour guess was " << playerGuess << '.' << std::endl;
}


void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// Loop while game is NOT run and there are still tries left
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		
		// Get a guess and print it back to player
		FText Guess = GetValidGuess();
		PrintGuess(Guess);

		//submit valid guess and receive counts

		fBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		//print number of bulls and cows

		std::cout << "Bulls = " << BullCowCount.Bulls << "\nCows = " << BullCowCount.Cows << std::endl;

		
	}

	PrintGameSummary();

	return;
}


bool AskToPlayAgain()
{
	std::cout << "\nDo you want to play again (y/n)? ";
	
	std::string Response;
	getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');

}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "Well done! You've guessed the correct word!" << std::endl;
	}
	else
	{
		std::cout << "Game Over Man! Game Over!" << std::endl;
	}

	return;

}