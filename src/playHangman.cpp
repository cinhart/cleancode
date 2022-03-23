#include <iostream>
#include <string>
#include <vector>

#include "playHangman.h"
//#include "random.h"

char getUserLetter(); // get a letter from the player
bool isInWord(char character, std::string word); // check if a letter is in a word
std::string refreshCurrentWord(char userGuess, std::string currentWord, std::string wordToGuess); // refresh current word with found letter
bool isWordFound(std::string currentWord, std::string wordToGuess); // check if all letters have been found
void endGame(bool isGameWon, int livesLeft); // end the game
// char* randWord(); // renvoie un mot aléatoire

char getUserLetter()
{
    char userLetter= 0;
    std::cout << "Enter a letter : ";
    std::cin >> userLetter;
    return userLetter;
}

bool isInWord(char character, std::string word)
{
   return (word.find(character) != std::string::npos); //? true : false;
}

std::string refreshCurrentWord(char userGuess, std::string currentWord, std::string wordToGuess)
{
    for(std::string::size_type i = 0; i < currentWord.size(); i++)
    {
        if(userGuess==wordToGuess[i]){
            currentWord[i]=userGuess;
        }
    }

    return currentWord;
}

bool isWordFound(std::string currentWord, std::string wordToGuess)
{
    return(currentWord == wordToGuess);
}

void endGame(bool isGameWon, int livesLeft) {
    if(!isGameWon) {
        std::cout << "Oh no! You died. Better luck next time :(" << std::endl;
    } else {
        std::cout << "GG you found the word! You had " << livesLeft << " wrong guesses left" << std::endl;
    }
}

int playHangman()
{
    std::string wordToGuess = "idontknow"; // TO DO: Randword
    std::string currentWord = "_________";

    int livesLeft = 8;
    bool isGameWon = false;

    while(livesLeft>0 && !isGameWon) 
    {

        std::cout << currentWord << std::endl;

        char userGuess = getUserLetter();

        if(!isInWord(userGuess, wordToGuess))
        {
            livesLeft--;
        } else {
            currentWord = refreshCurrentWord(userGuess, currentWord, wordToGuess);
        }
        
        if (isWordFound(currentWord, wordToGuess)) {
            isGameWon = true;
            std::cout << currentWord << std::endl;
        }

    }

    endGame(isGameWon, livesLeft);

    return 0;
}