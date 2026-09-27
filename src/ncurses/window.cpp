#include <curses.h> 
#include "window.h"
#include "../const.h"


// Inicializacion general
int Window::initialize(){
    // Cosas de ncurses
    initscr(); // Para iniciar la pantalla
    noecho(); // Para evita que se escriba lo que el usuario escribe
    curs_set(0); // Para eliminar el cursor
    this->win = stdscr; // Establecemos esta pantalla como la totalidad de la aplicacion
    nodelay(this->win, TRUE); // Para capturar eventos sin bloquear la aplicacion
    start_color(); // Para usar colores
    keypad(this->win, TRUE); // Para leer eventos del raton
    set_mousemack(); // Para elguir que eventos del raton se van a leer
    // Cosas propias
    getmaxyx(stdscr, this->y_max, this->x_max); // Medidas
    create_color_pairs(); // Colores de texto y fondo segun constantes
    return 0;
}

// Terminacion general
int Window::terminate(){
    if (this->win){
        delwin(this->win); //eliminar la pantalla
        win = nullptr; //no aseguramos de que el puntero desaparezca
    }
    endwin();
    return 0;
}

// Lectura de teclas
int Window::get_input(){
    // Esto lee las teclas de esta pantalla
    int key = wgetch(this->win);
    // Los eventos del raton necesita un procesado aparte
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

// Esto recoje la poscion del ultimo click en pantalla
void Window::set_mouse_last(MEVENT event){
    this->mouse_x_last = event.x;
    this->mouse_y_last = event.y;
}

// Ncurses necesita inicializar los caolores de esta manera
int Window::create_color_pairs(){
    // El primer valore es una constante propia, los otros dos son de ncurses
    init_pair(COLOR_BLUE_BLACK, COLOR_BLUE, COLOR_BLACK);
    init_pair(COLOR_RED_BLACK, COLOR_RED, COLOR_BLACK);
    init_pair(COLOR_GREEN_BLACK, COLOR_GREEN, COLOR_BLACK);
    init_pair(COLOR_YELLOW_BLACK, COLOR_YELLOW, COLOR_BLACK);
    init_pair(COLOR_MAGENTA_BLACK, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(COLOR_CYAN_BLACK, COLOR_CYAN, COLOR_BLACK);
    init_pair(COLOR_WHITE_BLACK, COLOR_WHITE, COLOR_BLACK);

    init_pair(COLOR_BLUE_WHITE, COLOR_BLUE, COLOR_WHITE);
    init_pair(COLOR_RED_WHITE, COLOR_RED, COLOR_WHITE);
    init_pair(COLOR_GREEN_WHITE, COLOR_GREEN, COLOR_WHITE);
    init_pair(COLOR_YELLOW_WHITE, COLOR_YELLOW, COLOR_WHITE);
    init_pair(COLOR_MAGENTA_WHITE, COLOR_MAGENTA, COLOR_WHITE);
    init_pair(COLOR_CYAN_WHITE, COLOR_CYAN, COLOR_WHITE);
    init_pair(COLOR_BLACK_WHITE, COLOR_BLACK, COLOR_WHITE);
    return 0;
}

// Crea una mascara para ver dichos eventos del raton
void Window::set_mousemack(){
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION | 
        BUTTON1_CLICKED | BUTTON2_CLICKED | BUTTON2_CLICKED, NULL); //se ven estos eventos del raton
}