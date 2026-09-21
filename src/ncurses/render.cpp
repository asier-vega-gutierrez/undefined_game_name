
#include <curses.h> // getmaxy() newwin() delwin() endwin()
#include "render.h"
#include <string>


int Render::initialize(WINDOW *win, int x_sta, int y_sta, int x_end, int y_end){
    this->x_sta = x_sta;
    this->y_sta = y_sta;
    int height = y_end - y_sta;
    int width = x_end - x_sta;
    this->win = subwin(win, height, width, y_sta, x_sta);
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

int Render::set_char(char c, int x, int y, int color_pair){
    wattron(this->win, COLOR_PAIR(color_pair) | A_BOLD);
    mvwaddch(this->win, y, x, c);
    wattroff(this->win, COLOR_PAIR(color_pair) | A_BOLD);
    return 0;
}

int Render::set_string(std::string s, int x, int y, int color_pair){
    wattron(this->win, COLOR_PAIR(color_pair) | A_BOLD);
    mvwaddstr(this->win, y, x, s.c_str());
    wattroff(this->win, COLOR_PAIR(color_pair) | A_BOLD);
    return 0;
}