#include <thread>
#include <chrono>

#include "interface/board/board.h"
#include "interface/console/console.h"
#include "interface/bar/bar.h"
#include "ncurses/render.h"
#include "ncurses/window.h"
#include "const.h"

#include "game.h"



int Game::initialize(){

    // Primero se inicializa la pantalla para obtener la propiedades de la pantalla del usuario
    window.initialize();

    //Tercero se iniciliza la parte grafica
    board_render.initialize(window.get_win(), board.get_x_start(),board.get_y_start(),board.get_x_end(),board.get_y_end());
    board_render.create_box();
    bar_render.initialize(window.get_win(), bar.get_x_start(),bar.get_y_start(),bar.get_x_end(),bar.get_y_end());
    bar_render.create_box();
    console_render.initialize(window.get_win(), console.get_x_start(),console.get_y_start(),console.get_x_end(),console.get_y_end());
    console_render.create_box();

    //Cuarto se pintan los menus y la parte grafica
    print_menus();

    return 0;

}

int Game::terminate(){
    board_render.terminate();
    bar_render.terminate();
    console_render.terminate();
    window.terminate();
    return 0;
}

int Game::run(){
    running = true;
    while (running) {

        //Actualizar el board
        print_board();

        //Actualizar los menus
        bar.update_menu();
        console.update_menu();
        print_menus();


        inputs();

        outputs();


        // Actualizar los render
        board_render.update();
        bar_render.update();
        console_render.update();
        

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    terminate();
    return 0;
}


int Game::inputs(){

    int key = window.get_input();
    
    console.input_mannagment(key);
    board.input_mannagment(key, window.get_mouse_x_last(), window.get_mouse_y_last());


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


int Game::print_menus(){
    StringItem* console_menu = console.get_menu();
    for (int i = 0; i < console.get_elements(); i++){
        console_render.set_string(console_menu[i].get_text(), console_menu[i].get_x(), console_menu[i].get_y(), console_menu[i].get_color());
    }
    StringItem* bar_menu = bar.get_menu();
    for (int i = 0; i < bar.get_elements(); i++){
        bar_render.set_string(bar_menu[i].get_text(), bar_menu[i].get_x(), bar_menu[i].get_y(), bar_menu[i].get_color());
    }
    //Se borra el puntero por que solo pertenece a esta funcion
    console_menu = NULL;
    bar_menu = NULL;
    delete[] console_menu;
    delete[] bar_menu;
    return 0;
}

int Game::print_board(){
    // board_render.set_char('@', 88, 23, COLOR_RED_BLACK);
    CharItem** board_chars = board.get_actual();
    for (int i = 0; i < BOARD_MAX_X; i++) {
        for (int j = 0; j < BOARD_MAX_Y; j++) {
           board_render.set_char(board_chars[i][j].get_char(), board_chars[i][j].get_x(), board_chars[i][j].get_y(), board_chars[i][j].get_color());
        }
    }

    //no se borra el puntero por que pertenece a board, el se ocupa de borralo

    return 0;
}