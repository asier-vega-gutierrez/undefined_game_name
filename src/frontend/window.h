
#ifndef _SCREEN_H_
#define _SCREEN_H_

// Esta clase se ocupa de identificar las propiedaes de la pantalla del usuario
class Window{
private:

    WINDOW *win;
    int x_max, y_max;
    //colores "bub" texto azur fondo negro
    int bub = 1;
    int rb = 2;
    int gb = 3;
    int yb = 4;
    int mb = 5;
    int cb = 6;
    int wb = 6;


public:

    Window(){
        initialize();
    }
    ~Window() {
        terminate();
    }
    int get_x_max(){return x_max;}
    int get_y_max(){return y_max;}
    int initialize();
    int terminate();
    int check_size();
    int create_color_pairs();
    //colores "bub" texto azur fondo negro
    int get_bub(){return bub;}
    int get_rb(){return rb;}
    int get_gb(){return gb;}
    int get_yb(){return yb;}
    int get_mb(){return mb;}
    int get_cb(){return cb;}
    int get_wb(){return wb;}

};

#endif