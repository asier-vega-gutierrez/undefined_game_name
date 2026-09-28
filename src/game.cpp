#include <thread>
#include <chrono>

#include "interface/board/board.h"
#include "interface/console/console.h"
#include "interface/bar/bar.h"
#include "ncurses/render.h"
#include "ncurses/window.h"
#include "const.h"

#include "game.h"


// Inizializa el juego
int Game::initialize(){

    // Primero se inicializa la pantalla (porpiedades y demas init de ncurse)
    window.initialize();

    // Segundo se iniciliza la parte grafica
    board_render.initialize(window.get_win(), board.get_x_start(),board.get_y_start(),board.get_x_end(),board.get_y_end());
    bar_render.initialize(window.get_win(), bar.get_x_start(),bar.get_y_start(),bar.get_x_end(),bar.get_y_end());
    console_render.initialize(window.get_win(), console.get_x_start(),console.get_y_start(),console.get_x_end(),console.get_y_end());


    return 0;

}

// Termina el juego
int Game::terminate(){
    board_render.terminate();
    bar_render.terminate();
    console_render.terminate();
    window.terminate();
    return 0;
}

// Bucle de ejecucion general
int Game::run(){
    running = true;
    while (running) {

        // Se lee la entrada de tecaldo y raton
        inputs();

        // INTERFAZ
        // Actualizar la interfaz
        bar.update_menu();
        console.update_menu();
        // Pintar la interfaz
        print_interface();
        // Renderiza la interfaz
        board_render.update();
        bar_render.update();
        console_render.update();

        //otras ejecuciones
        outputs();
        
        //Para evitar exceso uso de memoria
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    terminate();
    return 0;
}

// Gestion de la entrada del usuario
int Game::inputs(){

    // Las teclas y el raton se leen desde la pantall principal
    int key = window.get_input();
    
    // Para cada parte de la interfaz se ejecuta su getion de sus teclas y raton
    console.input_mannagment(key);
    board.input_mannagment(key, window.get_mouse_x_last(), window.get_mouse_y_last());

    //Si se 
    if(key == 'e'){
        running = false;
    }

    return 0;
}

int Game::outputs(){


    std::string s = "hola";
    board.set_actual('@', 5, 5, COLOR_BLUE_BLACK, s);


    return 0;
}

//Esto intercomunica interfaz con render para representar la informacion de la interfaz en el render
int Game::print_interface(){
    
    // Lectura del board y adpatacion al formato del render
    CharItem** board_chars = board.get_actual();
    for (int i = 0; i < BOARD_MAX_X; i++) {
        for (int j = 0; j < BOARD_MAX_Y; j++) {
           board_render.set_char(board_chars[i][j].get_char(), board_chars[i][j].get_x() + BOARD_MIN_X, board_chars[i][j].get_y() + BOARD_MIN_Y, board_chars[i][j].get_color());
        }
    }
    // no se borra el puntero por que pertenece a board, el se ocupa de borralo

    // Lectura del console y adpatacion al formato del render
    StringItem* console_menu = console.get_menu();
    for (int i = 0; i < console.get_elements(); i++){
        console_render.set_string(console_menu[i].get_text(), console_menu[i].get_x(), console_menu[i].get_y(), console_menu[i].get_color());
    }

    // Por separado se le la descipcion del elelemento de board seleccionado, ya que es un elemento unico
    CharItem tile = board.get_selected_tile();
    bar.set_description(tile.get_description());

    // Lectura del bar y adpatacion al formato del render
    StringItem* bar_menu = bar.get_menu();
    for (int i = 0; i < bar.get_elements(); i++){
        bar_render.set_string(bar_menu[i].get_text(), bar_menu[i].get_x(), bar_menu[i].get_y(), bar_menu[i].get_color());
    }

    //Se borra los punteros de console y bar por que solo pertenece a esta funcion
    console_menu = NULL;
    bar_menu = NULL;
    delete[] console_menu;
    delete[] bar_menu;

    return 0;
}