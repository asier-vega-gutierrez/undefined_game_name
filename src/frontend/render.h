
#include <curses.h> // WINDOW


#ifndef _RENDER_H_
#define _RENDER_H_

class Render {

private:

    WINDOW *win = {};
    
public:

    Render(){

    };
    ~Render() {
        terminate();
    }
    int initialize(int x_sta, int y_sta, int x_end, int y_end);
    int terminate();
    int update();
    int create_box();
    char get_input();
    int resize(int x_new, int y_new);
    int relocate(int x_new, int y_new);
    
};





#endif