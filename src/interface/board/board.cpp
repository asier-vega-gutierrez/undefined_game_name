#include "board.h"

// De forma inicila se rellena el tablero con unos valores por defecto
void Board::init_fill(){

    // inicializacion del resto de punteros
    for(int i = 0; i < BOARD_MAX_X; ++i) {
        this->actual[i] = new CharItem[BOARD_MAX_Y];
    }

    // rellenamos todos los punteros
    for (int i = 0; i < BOARD_MAX_X; i++) {
        for (int j = 0; j < BOARD_MAX_Y; j++) {
           this->actual[i][j] = CharItem('a', i, j, COLOR_RED_BLACK, "None");
        }
    }

}

// Se alamacena la posicon del ultimo clcik del raton solo si pertenece al board
void Board::input_mannagment(int key, int raw_mouse_x, int raw_mouse_y){

    // Se tiene que tener en cuenta que se pinta desfasado pero el array parte de 0,0
    int mouse_x = raw_mouse_x - BOARD_MIN_X;
    int mouse_y = raw_mouse_y - BOARD_MIN_Y;
    if (key == KEY_BUTTON1_CLICKED && mouse_x < BOARD_MAX_X && mouse_y < BOARD_MAX_Y) {
        // CASO 1: Vuelves a pulsar la casilla que ya estaba seleccionada, se deselecciona
        if (has_selection && x_selected == mouse_x && y_selected == mouse_y) {
            actual[x_selected][y_selected].set_color(actual[x_selected][y_selected].get_color() - SUM_COLOR_INVERT);
            has_selection = false;
        } 
        // CASO 2: Pulsas en una nueva casilla (o no había ninguna seleccionada)
        else {
            // Si ya había una seleccionada previamente, la deseleccionamos primero
            if (has_selection) {
                actual[x_selected][y_selected].set_color(actual[x_selected][y_selected].get_color() - SUM_COLOR_INVERT);
            }
            // Seleccionamos la nueva casilla
            this->x_selected = mouse_x;
            this->y_selected = mouse_y;
            actual[x_selected][y_selected].set_color(actual[x_selected][y_selected].get_color() + SUM_COLOR_INVERT);
            has_selection = true;
        }
    }
    
}

// Funcion para colocar una tile en el board
void Board::set_actual(char c, int x, int y, int color, std::string description){
    CharItem actual_char = CharItem(c,x,y,color,description);
    this->actual[x][y] = actual_char;
}