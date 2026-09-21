#include <curses.h> 
#include "window.h"


int Window::initialize(){
    initscr(); //iniciar la pantalla
    noecho(); //evita que se escriba lo que el usuario escribe
    curs_set(0); //eliminar el cursor
    this->win = stdscr;
    nodelay(this->win, TRUE);
    start_color();
    getmaxyx(stdscr, this->y_max, this->x_max); //medidas
    create_color_pairs(); //colores de texto y fondo
    return 0;
}

int Window::terminate(){
    if (this->win){
        delwin(this->win); //eliminar la pantalla
        win = nullptr; //no aseguramos de que el puntero desaparezca
    }
    endwin();
    return 0;
}

char Window::get_input(){
    return wgetch(this->win);
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

int Window::create_color_pairs(){
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);

    init_pair(8, COLOR_BLUE, COLOR_WHITE);
    init_pair(9, COLOR_RED, COLOR_WHITE);
    init_pair(10, COLOR_GREEN, COLOR_WHITE);
    init_pair(11, COLOR_YELLOW, COLOR_WHITE);
    init_pair(12, COLOR_MAGENTA, COLOR_WHITE);
    init_pair(13, COLOR_CYAN, COLOR_WHITE);
    init_pair(14, COLOR_BLACK, COLOR_WHITE);
    return 0;
}