#include "backend/interface.h"

#ifndef _BAR_H_
#define _BAR_H_

class Bar: Interface {

private:


public:

    Bar(std::string title, int x_start, int y_start, int x_end, int y_end) : Interface(title, x_start, y_start, x_end, y_end){
    };

};


#endif