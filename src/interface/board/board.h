#include "../interface.h"
#include "../char_item.h"

#ifndef _BOARD_H_
#define _BOARD_H_


// Calse board es la interfaz de arriba la izqueirda (en esta se muestras inforamcion y el usuraio seleciona cosas)
class Board: public Interface {
    using Interface::Interface;

private:

    // Todo lo que se meta en el array se pinta por pantalla
    CharItem** actual = new CharItem*[BOARD_MAX_X]; //cada puntero es una tile

    // Esto alamacena la ultima posicion que el usuario a clicado con el raton
    int x_selected = 0;
    int y_selected = 0;
    bool has_selection = false;
    

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
    CharItem get_selected_tile(){return actual[this->x_selected][this->y_selected];}

    // INPUT
    void input_mannagment(int key, int mouse_x, int mouse_y);
    int get_x_selected(){return this->x_selected;}
    int get_y_selected(){return this->y_selected;}

    // Del backend se llama aqui para poner una tile
    void set_actual(char c, int x, int y, int color, std::string description);
    
    
};


#endif