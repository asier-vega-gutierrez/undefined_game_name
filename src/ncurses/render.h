
#include <curses.h> // WINDOW
#include <string>


#ifndef _RENDER_H_
#define _RENDER_H_

class Render {

private:

    WINDOW *win = nullptr;
    int x_sta = 0;
    int y_sta = 0;
    
public:

    Render() = default;
    Render(int x_sta, int y_sta, int x_end, int y_end){
        initialize(x_sta, y_sta, x_end, y_end);
    }
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
    int set_char(char c, int x, int y, int color_pair);
    int set_string(std::string s, int x, int y, int color_pair);
    
};





#endif