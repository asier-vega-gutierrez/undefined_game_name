#include "interface/board/board.h"
#include "interface/console/console.h"
#include "interface/bar/bar.h"
#include "ncurses/render.h"
#include "ncurses/window.h"
#include "const.h"

#ifndef _GAME_H_
#define _GAME_H_

class Game{

private:
    // ESTADOS
    bool running = false;

    // INTERFACE
    Bar bar = Bar("bar", 90, 0, 120, 30);
    Console console = Console("console", 0, 25, 90, 30);
    Board board = Board("board", 0, 0, 90, 25);

    // NCURSES
    Window window;
    Render board_render;
    Render bar_render;
    Render console_render;
    



public:

    Game(){
        initialize();
    }
    ~Game(){
        terminate();
    }

    int initialize();
    int terminate();
    int run();
    // int print_menus();
    // int print_board();
    int print_interface();

    int inputs();
    int control();
    int outputs();

};



#endif