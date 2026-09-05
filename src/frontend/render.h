
#include <curses.h> // WINDOW

#ifndef _RENDER_H_
#define _RENDER_H_

class Render {

private:

    WINDOW *win = {};
    int initialize();
    
public:

    Render(){
        initialize();
    };
    int terminate();
    void create_interface();
    void create_screen();

};





#endif