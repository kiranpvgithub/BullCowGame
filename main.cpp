//
//  main.cpp
//  BullCowGame
//
//  Created by Kiran P V on 6/5/17.
//  Copyright © 2017 Kiran P V. All rights reserved.
//



/*
 This is the console exectutable, that makes use of the BullCOw class
 This acts as the view in a MVC pattern, adn is respinsible for all iser interaction.
 For game logic see the FBllCOeGame class.
*/


#pragma once

#include <iostream>
#include<string>
#include"FBullCowGame.hpp"

//to make syntax Unreal Friendly
using FText = std::string;
using int32 = int;


//function prototype as outside class

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();


FBUllCowGame BCGame;   // FBullCowGame is a template; we instantiate a new game


// Entry point for the application
int32 main()
{
    //std::cout<<BCGame.GetCurrentTry()<<std::endl;
    bool bPlayAgain = false;
    do{
        PrintIntro();
        PlayGame();
        PrintGameSummary();
        bPlayAgain = AskToPlayAgain();
    }
    while (bPlayAgain);
    return 0;
    
    
}

//Introduction to the game
void PrintIntro()
{
    std::cout<<std::endl;
    std::cout<<"            /*\\*/*\\ Welcome /*\\*/*\\"<<std::endl;
    std::cout<<std::endl;
    int32 WORD_LENGTH = BCGame.GetHiddenWordLength();
    std::cout<<"Can you guess the "<<WORD_LENGTH<<" letter isogram"<<std::endl;
    return;
}



// Plays a single game untill completion
void PlayGame()
{
    BCGame.Reset();
    int32 MaxTries =BCGame.GetMaxTries();
    while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
    {
        FText Guess = GetValidGuess();
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
        std::cout<<"Your Bulls = "<<BullCowCount.Bulls<<std::endl;
        std::cout<<"Your Cows = "<<BullCowCount.Cows<<std::endl;
 }
    return;
}


FText GetValidGuess()
{
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    FText Guess = "";
    
    do
    {   // Get a guess from the player
        int32 MaxTries =BCGame.GetMaxTries();
        int32 currentTryNo = BCGame.GetCurrentTry();
        std::cout<<std::endl;
        std::cout<<"Try "<< currentTryNo<<" of "<<MaxTries<<" Enter your Guess: ";
        getline(std::cin,Guess);
        
        
        //Check for the erranaeous inputs
        Status = BCGame.CheckGuessValidity(Guess);
        switch (Status) {
            case EGuessStatus::Wrong_Length:
                std::cout<<"Please enter a "<<BCGame.GetHiddenWordLength()<<" Letter word"<<std::endl;
                break;
            case EGuessStatus::Not_LoweCase:
                std::cout<<"Please enter the guess in lowercase letters"<<std::endl;
                break;
            case EGuessStatus::Not_Isogram:
                std::cout<<"Please enter an Isogram Guess "<<std::endl;
                break;
            default:
                break;
        }
    
    } while (Status != EGuessStatus::OK);// keep looping no errors
    
    return Guess;
    
}





bool AskToPlayAgain()
{
    std::cout<<"Do you want to play again (y/n)?";
    std:: string Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y');
    
}

void PrintGameSummary()
{
    if(BCGame.IsGameWon()){ std::cout<<"You Won!!"<<std::endl;}
    else
        std::cout<<"Better Luck Next Time"<<std::endl;
}

