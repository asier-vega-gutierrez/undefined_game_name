#include <curses.h> 
#include "screen.h"


int Screen::initialize(){
    initscr(); //iniciar la pantalla
    noecho(); //evita que se escriba lo que el usuario escribe
    curs_set(0); //eliminar el cursor
    getmaxyx(stdscr, this->y_max, this->x_max);
}

int Screen::terminate(){
    endwin();
}