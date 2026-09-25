#include <string>
#include "../const.h"

#ifndef _STRING_ITEM_H_
#define _STRING_ITEM_H_

class StringItem {

private:
    std::string text = "";
    int x = 0;
    int y = 0;
    int color = COLOR_RED_BLACK;

public:

    StringItem() = default;
    StringItem(std::string text, int x, int y, int color){
        this->text = text;
        this->x = x;
        this->y = y;
        this->color = color;
    }
    ~StringItem(){

    }
    void set_text(std::string text){this->text = text;}
    void set_x(int x){this->x = x;}
    void set_y(int y){this->y = y;}
    void set_color(int color){this->color = color;}
    std::string get_text(){return this->text;}
    int get_x(){return this->x;}
    int get_y(){return this->y;}
    int get_color(){return this->color;}

    
};


#endif