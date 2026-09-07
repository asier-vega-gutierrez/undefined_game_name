
#include <curses.h> // getmaxy() newwin() delwin() endwin()
#include "render.h"


int Render::initialize(int x_sta, int y_sta, int x_end, int y_end){
    this->win = newwin(y_end, x_end, y_sta, x_sta); //primero los valores del final y leugo los de incio
    return 0;
}

int Render::terminate(){
    if (this->win){
        delwin(this->win); //eliminar la pantalla
    }
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