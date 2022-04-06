#include "playGuessTheNumber.h"
#include "playHangman.h"
#include "menu.h"
#include <iostream>
#include <string>

int main()
{
    std::cout<<"launch program:\n";
    std::string menuResult = Menu();
    if(menuResult=="1") {
        playGuessTheNumber();
    } else if(menuResult=="2") {
        playHangman();
    }
}