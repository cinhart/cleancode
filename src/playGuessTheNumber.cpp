#include <iostream>

#include "playGuessTheNumber.h"
#include "random.h"

///
int getUserInput(); // ask an int to the player
void giveHint(int userGuess, int numberToGuess); // give a hint for the next guess
void endGame(int finalGuessCount); // end the game properly
///

int playGuessTheNumber()
{
    int numberToGuess = randint(0,100);
    bool isFinished = false;
    int guessCount = 0;
    std::cout << "Guess the number! 0 to 100 give it a try :\n";

    while(!isFinished)
    {
        int userGuess = getUserInput();
        if(userGuess == numberToGuess){
            isFinished = true;
        } else {
            giveHint(userGuess, numberToGuess);
        }
        guessCount++;
    }

    endGame(guessCount);
    return 0;
}

int getUserInput()
{
    int userInput=0;
    bool isInputValid = false;
    std::cout << "Enter a number : ";
    while(!isInputValid) {
        std::cin >> userInput;
        if(userInput>=0 && userInput<=100)
        {
            isInputValid=true;
        } else {
            std::cout << "Enter a valid number : ";
        }
    }
    return userInput;
}

void giveHint(int userGuess, int numberToGuess)
{
    if(userGuess < numberToGuess)
    {
        std::cout << "Nope! Try higher \n";
    }
    if(userGuess > numberToGuess)
    {
        std::cout << "Nope! Try lower \n";
    }
}

void endGame(int finalGuessCount)
{
    if(finalGuessCount == 1)
    {
        std::cout << "OMG FIRST TRY ?!? GG YOU ABSOLUTE LEGEND !!" << std::endl;
    }
    if(finalGuessCount>1 && finalGuessCount<=5)
    {
        std::cout << "Wow, only " << finalGuessCount <<" guesses ?\nThat was fast ! GG" << std::endl;
    }
    if(finalGuessCount>5 && finalGuessCount<=10)
    {
        std::cout << "Gg, you got it!\nIt took you "<< finalGuessCount <<" guesses" << std::endl;
    }
    if(finalGuessCount>10 && finalGuessCount<=20)
    {
        std::cout << "Meh, better late than never!\nTook you "<< finalGuessCount <<" guesses, I'm sure you can do better!" << std::endl;       
    }
    if(finalGuessCount>20 && finalGuessCount<=50)
    {
        std::cout << "Took you "<< finalGuessCount <<" guesses...\nC'mon, focus and let's try this again!" << std::endl;
    }
    if(finalGuessCount>50)
    {
         std::cout << "Did you just make "<< finalGuessCount <<" guesses ?\nNope. Can't believe it. You're doing this on purpose." << std::endl;
    }
}