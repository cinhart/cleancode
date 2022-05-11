#include <p6/p6.h>
#include <iostream>

void draw_board(int size, p6::Context& ctx)
{
    ctx.fill = p6::Color {0.05f, 0.f, 0.f};
    ctx.use_fill;
    for(int x=0; x<size; x++) {
        for(int y=0; y<size; y++) {
            ctx.square(p6::TopLeftCorner(-1,1), p6::Radius(ctx.aspect_ratio()/size));
        }
    }
}

void initializeWindow() {
    auto ctx = p6::Context{{800, 800, "Noughts and Crosses"}};
    ctx.background({0.9f, 1.f, 0.9f});
    draw_board(3, ctx);
    ctx.start(); 
}

int playNoughtsAndCrosses() {
    std::cout<<"Noughts and crosses let's go!"<<std::endl;
    initializeWindow();
    return 0;
}