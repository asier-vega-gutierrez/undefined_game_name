#include "../interface.h"
#include "../string_item.h"
#include <string>

#ifndef _CONSOLE_H_
#define _CONSOLE_H_

class Console: public Interface {

private:
    StringItem menu[5] = {};

public:

    Console() : Interface() {};
    Console(std::string title, int x_start, int y_start, int x_end, int y_end) : Interface(title, x_start, y_start, x_end, y_end){
        load_menu();
    };

    int input_mannagment(int key);
    void load_menu();
    StringItem* get_menu(){return this->menu;}
    
};


#endif