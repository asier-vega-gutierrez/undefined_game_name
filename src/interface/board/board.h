#include "../interface.h"

#ifndef _BOARD_H_
#define _BOARD_H_

class Board: public Interface {
    using Interface::Interface;

private:
    char actual[10][10];

public:

    Board() : Interface() {};
    Board(std::string title, int x_start, int y_start, int x_end, int y_end) : Interface(title, x_start, y_start, x_end, y_end){
        
    };

    // INPUT
    void input_mannagment(int key, int mouse_x, int mouse_y);
    
};


#endif