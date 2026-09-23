#include <curses.h> 
#include "window.h"
#include "../const.h"


int Window::initialize(){
    initscr(); //iniciar la pantalla
    noecho(); //evita que se escriba lo que el usuario escribe
    curs_set(0); //eliminar el cursor
    this->win = stdscr;
    nodelay(this->win, TRUE); //Para capturar evetnos de todo tipo
    start_color(); //colores
    //Cosas mias
    getmaxyx(stdscr, this->y_max, this->x_max); //medidas
    create_color_pairs(); //colores de texto y fondo
    keypad(this->win, TRUE); //eventos de raton
    set_mousemack();
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

int Window::get_input(){
    int key = wgetch(this->win);
    //Los eventos del raton necesita un procesado aparte
    if (key == KEY_MOUSE) {
        MEVENT event;
        if (getmouse(&event) == OK) {
            if (event.bstate & BUTTON1_CLICKED) {
                set_mouse_last(event);
                return KEY_BUTTON1_CLICKED;
            }
            if (event.bstate & BUTTON2_CLICKED) {
                return KEY_BUTTON2_CLICKED;
            }
            if (event.bstate & BUTTON3_CLICKED) {
                return KEY_BUTTON3_CLICKED;
            }
        }
    }
    return key;
}

void Window::set_mouse_last(MEVENT event){
    this->mouse_x_last = event.x;
    this->mouse_y_last = event.y;
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


void Window::set_mousemack(){
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION | 
        BUTTON1_CLICKED | BUTTON2_CLICKED | BUTTON2_CLICKED, NULL); //se ven estos eventos del raton
}