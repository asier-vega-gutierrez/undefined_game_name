
#include <curses.h> // WINDOW
#include <string>


#ifndef _RENDER_H_
#define _RENDER_H_


// Esta clase se ocupa de pintar por pantalla todo lo necesario
class Render {

private:

    WINDOW *win = nullptr; // Se recoje un puntero de la pantalla principal 
    int x_sta = 0; // Posicion de inicio de subpantalla
    int y_sta = 0; // Posicion de inicio de subpantalla
    
public:

    Render() = default;
    Render(WINDOW *win, int x_sta, int y_sta, int x_end, int y_end){
        initialize(win, x_sta, y_sta, x_end, y_end);
    }
    ~Render() {
        terminate();
    }
    int initialize(WINDOW *win, int x_sta, int y_sta, int x_end, int y_end);
    int terminate();
    int update();
    int create_box();
    int resize(int x_new, int y_new);
    int relocate(int x_new, int y_new);
    int set_char(char c, int x, int y, int color_pair);
    int set_string(std::string s, int x, int y, int color_pair);
    
};





#endif