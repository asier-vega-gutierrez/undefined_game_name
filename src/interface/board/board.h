#include "../interface.h"
#include "../char_item.h"

#ifndef _BOARD_H_
#define _BOARD_H_

class Board: public Interface {
    using Interface::Interface;

private:
    //la primera posicion es 0 0 (encima del borde)
    //la ultima posicion es 89 24 (encima del borde)
    CharItem** actual = new CharItem*[BOARD_MAX_X]; 
    

public:

    Board() : Interface() {};
    Board(std::string title, int x_start, int y_start, int x_end, int y_end) : Interface(title, x_start, y_start, x_end, y_end){
        init_fill();
    };
    ~Board(){
        for (int i = 0; i < BOARD_MAX_X; ++i) delete[] actual[i];
        delete[] actual;
    }

    void init_fill();
    CharItem** get_actual(){return this->actual;}

    // INPUT
    void input_mannagment(int key, int mouse_x, int mouse_y);

    // Del backend se llama aqui para poner una ficha
    void set_actual(char c, int x, int y, int color, std::string description);
    
};


#endif