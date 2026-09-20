#include "bar.h"
#include "../../const.h"

int Bar::input_mannagment(int key){

    // if(key == 'a'){

    // }

    return 0;
}

void Bar::load_menu(){
    this->pos_1_1 = StringItem("Health:", 5 , 2, RED_BLACK);
    this->pos_2_1 = StringItem("Mana:", 5 , 3, RED_BLACK);
    this->pos_3_1 = StringItem("Stamina:", 5 , 4, RED_BLACK);
    update_menu();
}

void Bar::update_menu(){
    this->menu[0] = pos_1_1;
    this->menu[1] = pos_2_1;
    this->menu[2] = pos_3_1;
}