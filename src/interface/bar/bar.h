#include "../interface.h"
#include "../string_item.h"

#ifndef _BAR_H_
#define _BAR_H_

class Bar: public Interface {

private:
    static const int menu_elements = 5;
    StringItem menu[menu_elements];

public:

    Bar() : Interface() {};
    Bar(std::string title, int x_start, int y_start, int x_end, int y_end) : Interface(title, x_start, y_start, x_end, y_end){
        load_menu();
    };
    ~Bar() = default;


    // INPUT
    int input_mannagment(int key);

    // MENU
    void load_menu();
    StringItem* get_menu(){return this->menu;}
    int get_elements(){return this->menu_elements;}
    void update_menu();
    StringItem pos_1_1;
    StringItem pos_2_1;
    StringItem pos_3_1;

    



};


#endif