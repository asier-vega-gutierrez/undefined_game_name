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
    StringItem attack = StringItem("Attack", 2, 2);
    StringItem defend = StringItem("Defend", 12 , 2);
    StringItem use = StringItem("Use", 22 , 2);
    this->menu[0] = attack;
    this->menu[1] = defend;
    this->menu[2] = use;
}