
#include <curses.h> // getmaxy() newwin() delwin() endwin()
#include "render.h"


int Render::initialize(int x_sta, int y_sta, int x_end, int y_end){
    initscr(); //iniciar la pantalla
    noecho(); //evita que se escriba lo que el usuario escribe
    curs_set(0); //eliminar el cursor
    this->win = newwin(y_sta, x_sta, y_end, x_end);
    return 0;
}

int Render::terminate(){
    if (this->win){
        delwin(this->win); //eliminar la pantalla
    }
    endwin(); //terminar la pantalla
    return 0;
}

int Render::update(){
    wgetch(this->win);
    return 0;
}

int Render::create_box(){
    box(this->win, 0, 0);
    update();
    return 0;
}