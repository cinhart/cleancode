#include "playGuessTheNumber.h"
#include "playHangman.h"
#include "menu.h"

#include <p6/p6.h>
#include <iostream>
#include <string>

int main()
{
    std::cout<<"launching program...\n";
    bool playAgain=true;

    auto ctx = p6::Context{{1280, 720, "My p6 project"}}; // Create a context with a window
    ctx.start(); 

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
            //playNoughtsAndCrosses();
            break;
        
        default:
            std::cout<<"\nSee you next time!\n\n";
            playAgain = false;
            break;
        }

    }
}