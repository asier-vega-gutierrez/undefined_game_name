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
        //    this->actual[i][j] = CharItem('a', i+BOARD_MIN_X, j+BOARD_MIN_Y, COLOR_RED_BLACK, "None");
           this->actual[i][j] = CharItem('a', i, j, COLOR_RED_BLACK, "None");
        }
    }

}

// Se alamcena la posicon del ultimo clcik del raton solo si pertenece al board
void Board::input_mannagment(int key, int raw_mouse_x, int raw_mouse_y){

    if (key == KEY_BUTTON1_CLICKED) {
        // Se tiene que tener en cuenta que se pinta desfasado pero el array parte de 0,0
        int mouse_x = raw_mouse_x - BOARD_MIN_X;
        int mouse_y = raw_mouse_y - BOARD_MIN_Y;
        // Se desselecciona el anterior si es que esta seleccionado
        if(actual[x_selected][y_selected].get_color() > SUM_COLOR_INVERT){
            actual[x_selected][y_selected].set_color(actual[x_selected][y_selected].get_color() - SUM_COLOR_INVERT);
        }
        // Si esta dentro del tablero se seleciona
        if(mouse_x >= 0 && mouse_y >= 0 && mouse_x < BOARD_MAX_X && mouse_y < BOARD_MAX_Y ) { 
            this->x_selected = mouse_x;
            this->y_selected = mouse_y;
            actual[x_selected][y_selected].set_color(actual[x_selected][y_selected].get_color() + SUM_COLOR_INVERT);
        }
    }
    
}

// Funcion para colocar una tile en el board
void Board::set_actual(char c, int x, int y, int color, std::string description){
    CharItem actual_char = CharItem(c,x,y,color,description);
    this->actual[x][y] = actual_char;
}