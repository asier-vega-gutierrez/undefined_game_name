
#include <curses.h> // getmaxy() newwin() delwin() endwin()
#include "render.h"


int Render::initialize(int x_sta, int y_sta, int x_end, int y_end){
    int height = y_end - y_sta;
    int width = x_end - x_sta;
    this->win = newwin(height, width, y_sta, x_sta); //primero los valores del final y leugo los de incio
    nodelay(this->win, TRUE);
    return 0;
}

int Render::terminate(){
    if (this->win){
        delwin(this->win); //eliminar la pantalla
        win = nullptr;
    }
    return 0;
}

int Render::update(){
    wrefresh(this->win);
    return 0;
}

int Render::create_box(){
    box(this->win, 0, 0);
    update();
    return 0;
}

char Render::get_input(){
    return wgetch(this->win);
}
