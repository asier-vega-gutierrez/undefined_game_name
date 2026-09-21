#include "console.h"
#include "../string_item.h"
#include "../../const.h"


int Console::input_mannagment(int key){

    switch(key) {
        case KEY_NUMBER_1:
            pos_1.set_color(COLOR_RED_WHITE);
            break;
        case KEY_NUMBER_2:
            pos_2.set_color(COLOR_RED_WHITE);
            break;
        case KEY_NUMBER_3:
            pos_3.set_color(COLOR_RED_WHITE);
            break;
        default:
            reload_menu();
            break;
    }

    return 0;
}


void Console::load_menu(){
    this->pos_1 = StringItem("Attack", 2, 2, COLOR_RED_BLACK);
    this->pos_2 = StringItem("Defend", 12 , 2, COLOR_RED_BLACK);
    this->pos_3 = StringItem("Use", 22 , 2, COLOR_RED_BLACK);
    update_menu();
}

void Console::reload_menu(){
    pos_1.set_color(COLOR_RED_BLACK);
    pos_2.set_color(COLOR_RED_BLACK);
    pos_3.set_color(COLOR_RED_BLACK);
    update_menu();
}

void Console::update_menu(){
    this->menu[0] = pos_1;
    this->menu[1] = pos_2;
    this->menu[2] = pos_3;
}