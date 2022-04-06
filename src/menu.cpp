#include "menu.h"

#include <iostream>

/*
TO DO:
- better check of user input (template maybe ?)
*/

void listGames();
void listCommands();
int getUserChoice();

int Menu(){
    std::cout << "What do you want to do?\n";
    listCommands();
    return getUserChoice();
}

void listCommands() {
    std::cout << "1 : Guess the Number! \n";
    std::cout << "2 : Play Hangman! \n";
    std::cout << "Q : Stop playing... \n";
}

bool isInputValid(char input) {
    if(input=='1' || input=='2' || input=='Q'){
        return true;
    }
    std::cout<<"Please return one of the above\n";
    return false;
}

int getUserChoice() {
    std::cout << "";
    char input=' ';
    while(!isInputValid(input)){
        std::cin >> input;
    }
    return static_cast<int>(input)-static_cast<int>('0');
}