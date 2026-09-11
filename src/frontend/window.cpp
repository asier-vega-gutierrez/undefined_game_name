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
    if (this->win){
        delwin(this->win); //eliminar la pantalla
        win = nullptr; //no aseguramos de que el puntero desaparezca
    }
    return 0;
}

int Window::check_size(){
    int y_new, x_new;
    getmaxyx(stdscr, y_new, x_new);
    if(this->y_max != y_new || this->x_max != x_new){
        this->y_max = y_new;
        this->x_max = x_new;
        return 0;
    }
    return 1;
}