#include "backend/board.h"
#include "backend/console/console.h"
#include "backend/bar.h"
#include "frontend/render.h"
#include "frontend/window.h"

#ifndef _GAME_H_
#define _GAME_H_

class Game{

private:
    // ESTADOS
    bool running = false;

    // BACKEND
    Window window; 
    Bar bar = Bar("bar", 90, 0, 120, 30);
    Console console = Console("console", 0, 25, 90, 30);
    Board board = Board("board", 0, 0, 90, 25);

    // FRONTEND
    Render board_render;
    Render bar_render;
    Render console_render;

    // MENUS
    StringItem* console_menu = console.get_menu();





public:

    Game(){
        initialize();
    }
    ~Game(){
        console_menu = NULL;
        delete[] console_menu;
        terminate();
    }

    int initialize();
    int terminate();
    int run();
    int print_menus();

    int inputs();
    int control();
    int outputs();

};



#endif