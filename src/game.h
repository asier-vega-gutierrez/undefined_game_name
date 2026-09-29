#include "interface/board/board.h"
#include "interface/console/console.h"
#include "interface/bar/bar.h"
#include "ncurses/render.h"
#include "ncurses/window.h"
#include "log.h"
#include "const.h"

#ifndef _GAME_H_
#define _GAME_H_


// Esta es la clase principal de la aplicacion
class Game{

private:

    // ESTADOS
    bool running = false;

    // INTERFACE
    Board board = Board("board", 0, 0, 90, 25); // Objeto de interfaz concreto para board
    Bar bar = Bar("bar", 90, 0, 120, 30); // Objeto de interfaz concreto para bar
    Console console = Console("console", 0, 25, 90, 30); // Objeto de interfaz concreto para console
    
    // NCURSES
    Window window; // Pantalla principal cosas comunes de ncurses
    Render board_render; // Render de ncurses para board
    Render bar_render; // Render de ncurses para bar
    Render console_render; // Render de ncurses para console

    // LOG
    Log log = Log();

    

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
    int outputs();
    int print_interface();

};



#endif