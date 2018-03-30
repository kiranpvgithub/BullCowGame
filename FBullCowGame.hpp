//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Kiran P V on 7/22/17.
//  Copyright © 2017 Kiran P V. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp


/* The Game logic (no view code or direct user interaction
 The game is simple guess word game based on Mastermind*/

#pragma once

#include <stdio.h>
#include<string>


//to make unreal user friendly
using int32 = int;
using FString = std::string;

//
struct FBullCowCount
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
    Not_LoweCase
    
};


class  FBUllCowGame {
   
public:
    FBUllCowGame(); // Constructor
    
    int32 GetMaxTries() const ;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    bool IsGameWon() const;
    EGuessStatus CheckGuessValidity(FString); //TODO make a more rich return a value
    
    void Reset(); //TODO make a more rich return value
    
    // provide a method for counting bulls & cows, and increasing try. Assumming valid guess
    FBullCowCount SubmitValidGuess(FString);
    
private:
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenword;
    bool bGameIsWon;
    bool IsIsogram(FString) const;
    bool IsLowerCase(FString) const;
    
    
};


#endif /* FBullCowGame_hpp */
