#include <iostream>
#include <string>
#include <vector>

#include "playHangman.h"
//#include "random.h"
/*
char getUserInput(std::vector<char> testedLetters)
{
    char userInput= 0;
    std::cout << "Enter a letter : ";
    std::cin >> userInput;
    return userInput;
}
*/
bool isInWord(char character, std::string word)
{
   return (word.find(character) != std::string::npos); //? true : false;
}
/*
void currentWord(std::string wordToGuess, std::vector<char> testedLetters)
{
    std::string currentWord = "";

    for(int i = 0; i < testedLetters.size(); ++i)
    {
        if(isInWord(testedLetters[i],wordToGuess)){
            currentWord.append(testedLetters[i]);
        } else {
            currentWord.append('_');
        }
    }

    std::cout << currentWord << "\n";
}

bool isWordFound(std::string currentWord, std::string wordToGuess)
{
    return(currentWord == wordToGuess);
}

void endGame(bool isGameWon, int livesLeft) {
    if(!isGameWon) {
        std::cout << "Oh no! You died. Better luck next time" << std::endl;
    } else {
        std::cout << "GG you're saved ! You had " << livesLeft << " guesses left" << std::endl;
    }
}

int playHangman()
{
    std::string wordToGuess = "Idontknow"; // TO DO: Randword
    std::vector<char> testedLetters; // letters that have been tested
    std::string currentWord = "";

    int livesLeft = 8;
    bool isGameWon = false;

    while(livesLeft>0 && !isGameWon) 
    {

        currentWord = currentWord(testedLetters);
        std::cout << currentWord;
        std::string userGuess = getUserInput(testedLetters);
        testedLetters+=userGuess;

        if(!isInWord(userGuess, wordToGuess))
        {
            livesLeft--;
        } else if (isWordFound(testedLetters, wordToGuess)) {
            isGameWon = true;
        }

    }

    endGame(isGameWon, livesLeft);

    return 0;
}*/