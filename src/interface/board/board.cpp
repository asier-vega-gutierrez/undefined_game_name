#include "board.h"


void Board::init_fill(){

    //inicializacion del resto de punteros
    for(int i = 0; i < BOARD_MAX_X; ++i) {
        this->actual[i] = new CharItem[BOARD_MAX_Y];
    }

    //rellenamos todos los punteros
    for (int i = 0; i < BOARD_MAX_X; i++) {
        for (int j = 0; j < BOARD_MAX_Y; j++) {
           this->actual[i][j] = CharItem('a', i+BOARD_MIN_X, j+BOARD_MIN_Y, COLOR_RED_BLACK, "None");
        }
    }

}

void Board::input_mannagment(int key, int mouse_x, int mouse_y){
    if(mouse_x >= BOARD_MIN_X && mouse_y >= BOARD_MIN_Y && mouse_x < BOARD_MAX_X && mouse_y < BOARD_MAX_Y ) {
        this->x_selected = mouse_x;
        this->y_selected = mouse_y;
    }
}


void Board::set_actual(char c, int x, int y, int color, std::string description){
    CharItem actual_char = CharItem(c,x,y,color,description);
    this->actual[x][y] = actual_char;
}