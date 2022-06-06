#include <p6/p6.h>
#include <cmath>
#include <iostream>

struct cellIndex {
    int x;
    int y;
};

std::vector<cellIndex> initialize_cells(int size) { // INUTILE ???
    std::vector<cellIndex> cells;
    for(int x=0; x<size; x++) {
        for(int y=0; y<size; y++) {
            cellIndex a = cellIndex();
            a.x = x-1;
            a.y = y-1;
            cells.push_back(a);
        }
    }
    return cells;
}

p6::Center get_cell_center(cellIndex cell) {
    return p6::Center(cell.x*(2.f/3),cell.y*(2.f/3));
}

cellIndex get_cell_from_cursor(glm::vec2 mouse_coordinates) {
    cellIndex cell;
    cell.x = int(mouse_coordinates.x*3);
    cell.y = int(mouse_coordinates.y*3);
    return cell;
}

void draw_board(int size, p6::Context& ctx, std::vector<cellIndex> cells)
{
    ctx.fill = p6::Color {1.f, 1.f, 1.f, 1.f};
    ctx.use_fill;
    ctx.stroke = p6::Color{0.1f, 0.f, 0.f, 1.f};
    ctx.stroke_weight = 0.01f;
    for(cellIndex cell : cells) {
        ctx.square(get_cell_center(cell), p6::Radius{1/3.f});
    }
}

void draw_nought(p6::Context& ctx, std::vector<cellIndex> cells) {
    ctx.stroke_weight = 0.f;
    ctx.fill = {1, 0, 0, 1};
    ctx.circle(get_cell_center(cells[0]), p6::Radius{0.25f});
    ctx.fill = {1, 1, 1, 1};
    ctx.circle(get_cell_center(cells[0]), p6::Radius{0.20f});
}

void draw_cross(p6::Context& ctx, std::vector<cellIndex> cells) {
    if(ctx.mouse().x<=1 && ctx.mouse().x>=-1 && ctx.mouse().y<=1 && ctx.mouse().y>=-1){
        ctx.stroke_weight = 0.f;
        ctx.fill = {0, 0, 1, 1};
        ctx.rectangle(get_cell_center(get_cell_from_cursor(ctx.mouse())), p6::Radii(0.05f,0.25f), p6::Rotation{p6::Angle{45_degrees}});
        ctx.rectangle(get_cell_center(get_cell_from_cursor(ctx.mouse())), p6::Radii(0.05f,0.25f), p6::Rotation{p6::Angle{315_degrees}});
    }
}

//p6::Context initializeWindow() {
/* void initializeWindow() {    
    auto ctx = p6::Context{{800, 800, "Noughts and Crosses"}};
    ctx.background({0.f, 0.f, 0.f});
    draw_board(3, ctx);
    ctx.start(); 
    //return ctx;
} */

bool isGameFinished() {
    return true;
}

int playNoughtsAndCrosses() {
    std::cout<<"Noughts and crosses let's go!"<<std::endl;

    try {
        auto ctx = p6::Context{{800, 800, "Noughts and Crosses"}};

        int size = 3;
        std::vector<cellIndex> cells = initialize_cells(size);

        ctx.update = [&]() {
            ctx.background({0.f, 0.f, 0.f});
            draw_board(size, ctx, cells);
            draw_nought(ctx, cells);
            draw_cross(ctx, cells);
        };

        ctx.start();

    }

    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}