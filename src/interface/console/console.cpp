#include "console.h"
#include "../string_item.h"
#include "../../const.h"


int Console::input_mannagment(int key){

    // if(key == 'a'){

    // }

    return 0;
}


void Console::load_menu(){
    this->pos_1 = StringItem("Attack", 2, 2, RED_BLACK);
    this->pos_2 = StringItem("Defend", 12 , 2, RED_BLACK);
    this->pos_3 = StringItem("Use", 22 , 2, RED_BLACK);
    update_menu();
}

void Console::update_menu(){
    this->menu[0] = pos_1;
    this->menu[1] = pos_2;
    this->menu[2] = pos_3;
}