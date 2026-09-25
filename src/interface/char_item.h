#include <string>
#include "../const.h"

#ifndef _CHAR_ITEM_H_
#define _CHAR_ITEM_H_

class CharItem {

private:
    char c = 'a';
    int x = 0;
    int y = 0;
    int color = COLOR_RED_BLACK;
    std::string description = "None";

public:

    CharItem() = default;
    CharItem(char c, int x, int y, int color, std::string description){
        this->c = c;
        this->x = x;
        this->y = y;
        this->color = color;
        this->description = description;
    }
    ~CharItem(){

    }

    void set_char(char c){this->c = c;}
    void set_x(int x){this->x = x;}
    void set_y(int y){this->y = y;}
    void set_color(int color){this->color = color;}
    void set_description(std::string description){this->description = description;}
    char get_char(){return this->c;}
    int get_x(){return this->x;}
    int get_y(){return this->y;}
    int get_color(){return this->color;}
    std::string get_description(){return this->description;}

    
};


#endif