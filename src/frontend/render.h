
#include <curses.h> // WINDOW


#ifndef _RENDER_H_
#define _RENDER_H_

class Render {

private:

    WINDOW *win = {};
    int initialize(int x_sta, int y_sta, int x_end, int y_end);
    
public:

    Render(int x_sta, int y_sta, int x_end, int y_end){
        initialize(x_sta, y_sta, x_end, y_end);
    };
    int terminate();
    int update();
    int create_box();
    
};





#endif