
#ifndef _SCREEN_H_
#define _SCREEN_H_

// Esta clase se ocupa de identificar las propiedaes de la pantalla del usuario
class Screen{
private:
    int x_max, y_max;

public:

    Screen(){
        initialize();
    }
    int get_x_max(){return x_max;}
    int get_y_max(){return y_max;}
    int initialize();
    int terminate();

};

#endif