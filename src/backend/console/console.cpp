#include "console.h"
#include "../string_item.h"
#include <string>

// void Console::initialize(std::string title, int x_start, int y_start, int x_end, int y_end) : Interface(title, x_start, y_start, x_end, y_end){
//     load_menu();
// }

int Console::input_mannagment(int key){

    // if(key == 'a'){

    // }

    return 0;
}

void Console::load_menu(){
    int init_x = 2;
    int init_y = 2;
    int offset_x = 5;
    StringItem attack = StringItem("Attack", init_x, init_y);
    StringItem defend = StringItem("Defend", init_x + 5 + offset_x , init_y);
    this->menu[0] = attack;
    this->menu[1] = defend;
}