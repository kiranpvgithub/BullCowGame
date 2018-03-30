//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Kiran P V on 7/22/17.
//  Copyright © 2017 Kiran P V. All rights reserved.
//

#pragma once

#include "FBullCowGame.hpp"
#include<iostream>
#include<map>
#define TMap std::map



using FString = FString;
using int32 = int;


FBUllCowGame::FBUllCowGame() { Reset(); }// default constructor
int32 FBUllCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBUllCowGame::GetHiddenWordLength() const { return MyHiddenword.length();}
bool FBUllCowGame:: IsGameWon( ) const { return bGameIsWon; }


int32 FBUllCowGame::GetMaxTries() const {
    
    TMap<int32, int32> WordLengthToMaxTries { {3,4} , {4,7}, {5,10}, {6,15}, {7,20}};
        return WordLengthToMaxTries[MyHiddenword.length()];
    }



 
void FBUllCowGame::Reset()
{
    const FString HIDDEN_WORD ="plane";
    MyHiddenword = HIDDEN_WORD;
    bGameIsWon = false;
    MyCurrentTry = 1;
    
//    constexpr int32 MAX_TRIES = 5;
//    MyMaxTries = MAX_TRIES;
   
  
   
    
    
}









EGuessStatus FBUllCowGame:: CheckGuessValidity(FString Guess)
{
    if(!IsIsogram(Guess)) // if the guess isn't an isogram
    {
        return EGuessStatus::Not_Isogram;
    }
    else if (!IsLowerCase(Guess))
    {
        return EGuessStatus::Not_LoweCase;
    }
    else if(Guess.length() != MyHiddenword.length())
    {
        return EGuessStatus::Wrong_Length;
    }
    else
    {
        return EGuessStatus::OK;
    }
}




// receives a VALID guess, increments turn and returns
FBullCowCount FBUllCowGame::SubmitValidGuess(FString Guess)
{
  //increment the turn number
    MyCurrentTry++;
    
    
    //setup a return variable
    FBullCowCount BullCowCount;
    
    //loop through all letters in the guess
    int32 WordLength = MyHiddenword.length();
    for(int32 i = 0; i< WordLength; i++)
    {
        // compare letters against the hidden word
        for(int32 j= 0; j<WordLength;j++)
        {
            
            // if they match then
            if(Guess[i]==MyHiddenword[j])
            {
                if(i==j){
                    BullCowCount.Bulls++;
                    break;
                }
                else{
                    BullCowCount.Cows++;
                    break;
                }
                
            }
                // increment bulls if they are in the same place
            // else increment cows
        }
    }
    
    if(BullCowCount.Bulls == WordLength){
        bGameIsWon = true;
    }
    else
        bGameIsWon = false;
    
    
    return BullCowCount;
}

bool FBUllCowGame::IsIsogram(FString Word)const
{
    // Conside or treat 0 or 1 letter word as Isograms
    if(Word.length() <=1){ return true;}
    
    TMap<char, bool> LetterSeen;
    
    for(auto Letter: Word )
    {
        Letter = tolower(Letter); // handle mixed cases
        
        if(LetterSeen[Letter])
        {
            return false;
        } else {
            LetterSeen[Letter] = true;
        }
        
    }
    
    // loop through the words as Isogram
    //if the letter is in the dictionary
    //we do not have isogram
    
    return true; //for
}

bool FBUllCowGame::IsLowerCase(FString Word) const
{
    
    for(auto Letter: Word)
    {
        if(!islower(Letter))
           {
               return false;
           }
    }
    return true;
    
    
}
