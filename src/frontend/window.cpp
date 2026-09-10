#include <curses.h> 
#include "window.h"


int Window::initialize(){
    initscr(); //iniciar la pantalla
    noecho(); //evita que se escriba lo que el usuario escribe
    curs_set(0); //eliminar el cursor
    getmaxyx(stdscr, this->y_max, this->x_max);
    return 0;
}

int Window::terminate(){
    endwin();
}

char Window::get_input(){
    return wgetch(this->win);
}