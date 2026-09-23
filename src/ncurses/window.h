
#ifndef _SCREEN_H_
#define _SCREEN_H_

// Esta clase se ocupa de identificar las propiedaes de la pantalla del usuario
class Window{
private:

    WINDOW *win = nullptr;
    int x_max, y_max;
    int mouse_x_last, mouse_y_last;

    int create_color_pairs();
    void set_mousemack();
    int check_size();
    void set_mouse_last(MEVENT event);

public:

    Window() = default; // se deve inicializar por separado
    ~Window() {
        terminate();
    }

    int get_x_max(){return x_max;}
    int get_y_max(){return y_max;}
    int get_mouse_x_last(){return mouse_x_last;}
    int get_mouse_y_last(){return mouse_y_last;}
    int initialize();
    int terminate();
    int get_input();
    WINDOW* get_win(){return this->win;}
    
    
};

#endif