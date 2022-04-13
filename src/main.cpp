#include "playGuessTheNumber.h"
#include "playHangman.h"
#include "playNoughtsAndCrosses"
#include "menu.h"
#include <iostream>
#include <string>

int main()
{
    std::cout<<"launching program...\n";
    bool playAgain=true;

    while(playAgain){

        int chosenGame = Menu();

        switch (chosenGame)
        {
        case 1:
            playGuessTheNumber();
            break;

        case 2:
            playHangman();
            break;

        case 3:
            playNoughtsAndCrosses();
            break;
        
        default:
            std::cout<<"\nSee you next time!\n\n";
            playAgain = false;
            break;
        }

    }
}