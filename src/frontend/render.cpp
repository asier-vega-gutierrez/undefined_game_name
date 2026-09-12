
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
        win = nullptr; //asegura que el puntero desaparece
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

int Render::set_char(char c, int x, int y, int color_pair){
    wattron(this->win, COLOR_PAIR(color_pair) | A_BOLD);
    mvwaddch(this->win, y, x, c);
    wattroff(this->win, COLOR_PAIR(color_pair) | A_BOLD);
    return 0;
}