#include "../interface.h"
#include "../string_item.h"
#include <string>

#ifndef _CONSOLE_H_
#define _CONSOLE_H_

class Console: public Interface {

private:
    static const int elements = 5;
    StringItem menu[elements];

public:

    Console() : Interface() {};
    Console(std::string title, int x_start, int y_start, int x_end, int y_end) : Interface(title, x_start, y_start, x_end, y_end){
        load_menu();
    };
    ~Console() = default;

    int input_mannagment(int key);
    void load_menu();
    StringItem* get_menu(){return this->menu;}
    int get_elements(){return this->elements;}
    
};


#endif