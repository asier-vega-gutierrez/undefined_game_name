#include "interface.h"

#ifndef _CONSOLE_H_
#define _CONSOLE_H_

class Console: public Interface {

private:


public:

    Console() : Interface() {};
    Console(std::string title, int x_start, int y_start, int x_end, int y_end) : Interface(title, x_start, y_start, x_end, y_end){
        
    };
    
};


#endif