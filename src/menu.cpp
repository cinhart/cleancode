#include "menu.h"

#include <iostream>

void listGames();
void listCommands();
std::string getUserInput();

std::string Menu(){
    listGames();
    listCommands();
    return getUserInput();
}

void listGames() {
    std::cout << "1 : Guess the Number \n";
    std::cout << "2 : Hangman \n";
}

void listCommands() {
    std::cout << "Q : Exit program \n";
}

std::string getUserInput() {
    std::cout << "";
    std::string input;
    bool isInputValid = false;
    while(!isInputValid){
        std::cin >> input;
        if(input=="1" || input=="2" || input=="Q"){
            isInputValid = true;
        }
    }
    return input;
}