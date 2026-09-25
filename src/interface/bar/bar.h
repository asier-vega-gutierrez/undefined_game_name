#include "../interface.h"
#include "../string_item.h"

#ifndef _BAR_H_
#define _BAR_H_

class Bar: public Interface {

private:
    static const int menu_elements = 7;
    StringItem menu[menu_elements];
    int health = 0;
    int mana = 0;
    int stamina = 0;
    int max_health = 0;
    int max_mana = 0;
    int max_stamina = 0;

public:

    Bar() : Interface() {};
    Bar(std::string title, int x_start, int y_start, int x_end, int y_end) : Interface(title, x_start, y_start, x_end, y_end){
        load_menu();
    };
    ~Bar() = default;

    // MENU
    void load_menu();
    StringItem* get_menu(){return this->menu;}
    int get_elements(){return this->menu_elements;}
    void update_menu();
    void reload_menu();
    void set_description(std::string text){this->pos_4.set_text(text);}
    StringItem pos_1_1;
    StringItem pos_2_1;
    StringItem pos_3_1;
    StringItem pos_1_2;
    StringItem pos_2_2;
    StringItem pos_3_2;
    StringItem pos_4;


    



};


#endif