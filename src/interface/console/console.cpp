#include "console.h"
#include "../string_item.h"
#include "../../const.h"


// Gestion de la teclas de este menu
int Console::input_mannagment(int key){

    switch(key) {
        case KEY_NUMBER_1:
            pos_1.set_color(pos_1.get_color() + SUM_COLOR_INVERT);
            break;
        case KEY_NUMBER_2:
            pos_2.set_color(pos_2.get_color() + SUM_COLOR_INVERT);
            break;
        case KEY_NUMBER_3:
            pos_3.set_color(pos_3.get_color() + SUM_COLOR_INVERT);
            break;
        default:
            load_menu();
            break;
    }

    return 0;
}


// Carga de los objetos del menu con un valor por defecto
void Console::load_menu(){
    this->pos_1 = StringItem("Attack", 2, 2, COLOR_RED_BLACK);
    this->pos_2 = StringItem("Defend", 12 , 2, COLOR_RED_BLACK);
    this->pos_3 = StringItem("Use", 22 , 2, COLOR_RED_BLACK);
    update_menu();
}


// Actualizacion, se meten los objetos en el array para que sean pintados
void Console::update_menu(){
    this->menu[0] = pos_1;
    this->menu[1] = pos_2;
    this->menu[2] = pos_3;
}