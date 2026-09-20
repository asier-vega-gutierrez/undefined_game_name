
#ifndef _SCREEN_H_
#define _SCREEN_H_

// Esta clase se ocupa de identificar las propiedaes de la pantalla del usuario
class Window{
private:

    WINDOW *win = nullptr;
    int x_max, y_max;


public:

    Window() = default; // se deve inicializar por separado
    ~Window() {
        terminate();
    }
    int get_x_max(){return x_max;}
    int get_y_max(){return y_max;}
    int initialize();
    int terminate();
    int check_size();
    int create_color_pairs();
    
};

#endif