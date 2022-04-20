#include <p6/p6.h>
#include <iostream>

void initializeWindow() {
    auto ctx = p6::Context{{800, 800, "Noughts and Crosses"}};
    ctx.start(); 
}

int playNoughtsAndCrosses() {
    std::cout<<"Noughts and crosses let's go!"<<std::endl;
    initializeWindow();
    return 0;
}