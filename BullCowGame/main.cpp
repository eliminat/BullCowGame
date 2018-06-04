// Main.cpp for the Bull-Cow Game

#include <iostream>
#include <string>
#include "FBullCowGame.h"


//renaming to Unreal standard names
using FText = std::string;
using int32 = int;

const int32 WORD_LENGTH = 6;

void PrintIntro();
void PlayGame();
FText GetGuess();
void PrintGuess(FText);
bool AskToPlayAgain();

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

	std::cout << "\nWelcome to the Bulls and Cows Game!" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << std::endl;
}


//Get a guess from the player
FText GetGuess()
{
	FText playerGuess = "";

	int32 currentTry = BCGame.GetCurrentTry();

	std::cout << "\nThis is try " << currentTry
				<< "\nPlease enter your guess: ";

	//std::cin >> playerGuess;
	std::getline(std::cin, playerGuess);


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
	// loop for number of turns asking for guesses
	for (int32 count = 1; count <= MaxTries; count++)
	{
		
		// Get a guess and print it back to player
		FText Guess = GetGuess();
		PrintGuess(Guess);

		//submit valid guess and receive counts

		fBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		//print number of bulls and cows

		std::cout << "Bulls = " << BullCowCount.Bulls << "\nCows = " << BullCowCount.Cows << std::endl;

		
	}
}


bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	
	std::string Response;
	getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');

}