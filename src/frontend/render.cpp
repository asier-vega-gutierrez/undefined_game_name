
#include <curses.h> // getmaxy() newwin() delwin() endwin()
#include "render.h"


int Render::initialize(){
    initscr(); //iniciar la pantalla
    noecho(); //evita que se escriba lo que el usuario escribe
    curs_set(0); //eliminar el cursor
    int x_max, y_max;
    getmaxyx(stdscr, y_max, x_max);
    win = newwin(y_max, x_max, 0, 0);
    return 0;
}

int Render::terminate(){
    if (win){
        delwin(win); //eliminar la pantalla
    }
    endwin(); //terminar la pantalla
    return 0;
}
