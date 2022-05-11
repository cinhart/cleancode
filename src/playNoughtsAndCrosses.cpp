#include <p6/p6.h>
#include <iostream>

struct cellIndex {
    int x;
    int y;
};

void draw_board(int size, p6::Context& ctx)
{
    ctx.fill = p6::Color {1.f, 1.f, 1.f, 1.f};
    ctx.use_fill;
    ctx.stroke = p6::Color{0.1f, 0.f, 0.f, 1.f};
    for(int x=0; x<size; x++) {
        for(int y=0; y<size; y++) {
            ctx.square(p6::TopLeftCorner(-1.f+x*(2.f/size),1.f-y*(2.f/size)), p6::Radius{1/3.f});
        }
    }
}

p6::Context initializeWindow() {
    auto ctx = p6::Context{{800, 800, "Noughts and Crosses"}};
    ctx.background({0.f, 0.f, 0.f});
    draw_board(3, ctx);
    ctx.start(); 
    return ctx;
}

int playNoughtsAndCrosses() {
    std::cout<<"Noughts and crosses let's go!"<<std::endl;
    auto ctx = initializeWindow();
    return 0;
}