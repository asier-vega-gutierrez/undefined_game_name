#include "interface.h"

#ifndef _SCREEN_H_
#define _SCREEN_H_

class Screen: public Interface {
    using Interface::Interface;

private:
    char actual[10][10];

public:

    Screen(std::string title, int x_start, int y_start, int x_end, int y_end) : Interface(title, x_start, y_start, x_end, y_end){
        printf("hola: %d \n", this->get_x_end());
    };
    
};


#endif