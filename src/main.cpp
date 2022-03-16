#include "playGuessTheNumber.h"
#include "playHangman.h"
#include <iostream>

int main()
{
    //playGuessTheNumber();
    std::cout<<"lancement programme: ";
    if(isInWord('a',"abeille")){
        std::cout<<"ça marche";
    }else{
        std::cout<<"ça marche pas";
    };
    //playHangman();
}