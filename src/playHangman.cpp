#include <iostream>
#include <string>
#include <vector>

#include "playHangman.h"
#include "random.h"

/*
TO DO : 
- take into account uppercase letters <--
- add new wordLists files
- number of guesses depending on the word to guess
- only one guess per letter
- display hangman
*/

///
std::string setCurrentWord(std::string wordToGuess); // set the initial display of the current word
char getUserLetter(); // get a letter from the player
bool isInWord(char character, std::string word); // check if a letter is in a word
std::string refreshCurrentWord(char userGuess, std::string currentWord, std::string wordToGuess); // refresh current word with found letter
bool isWordFound(std::string currentWord, std::string wordToGuess); // check if all letters have been found
void endGame(bool isGameWon, int livesLeft); // end the game
///

std::string setCurrentWord(std::string wordToGuess){
    std::string currentWord;
    for(std::string::size_type i = 0; i < wordToGuess.size(); i++){
        currentWord+='_';
    }
    return currentWord;
}

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
    std::string wordToGuess = randword();
    std::string currentWord = setCurrentWord(wordToGuess);

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