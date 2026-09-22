#include "bar.h"
#include "../../const.h"
#include <string>

void Bar::load_menu(){
    this->pos_1_1 = StringItem("Health:", 5 , 2, COLOR_RED_BLACK);
    this->pos_2_1 = StringItem("Mana:", 5 , 3, COLOR_BLUE_BLACK);
    this->pos_3_1 = StringItem("Stamina:", 5 , 4, COLOR_GREEN_BLACK);
    this->pos_1_2 = StringItem(std::to_string(this->health) + "/" + std::to_string(this->max_health) , 20 , 2, COLOR_RED_BLACK);
    this->pos_2_2 = StringItem(std::to_string(this->mana) + "/" + std::to_string(this->max_mana), 20 , 3, COLOR_BLUE_BLACK);
    this->pos_3_2 = StringItem(std::to_string(this->stamina) + "/" + std::to_string(this->max_stamina), 20 , 4, COLOR_GREEN_BLACK);
    this->pos_4 = StringItem("Cursor info:", 5, 8, COLOR_WHITE_BLACK);
    update_menu();
}

void Bar::reload_menu(){

}

void Bar::update_menu(){
    this->menu[0] = pos_1_1;
    this->menu[1] = pos_2_1;
    this->menu[2] = pos_3_1;
    this->menu[3] = pos_1_2;
    this->menu[4] = pos_2_2;
    this->menu[5] = pos_3_2;
    this->menu[6] = pos_4;
}

