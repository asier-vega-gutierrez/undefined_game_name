#include "backend/board.h"
#include "backend/console/console.h"
#include "backend/bar.h"
#include "frontend/render.h"
#include "frontend/window.h"

#ifndef _GAME_H_
#define _GAME_H_

class Game{

private:
    bool running = false;
    Window window; 
    Bar bar;
    Console console;
    Board board;
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

    int inputs();
    int control();
    int outputs();

};



#endif