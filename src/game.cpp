#include <thread>
#include <chrono>

#include "backend/board.h"
#include "backend/console/console.h"
#include "backend/bar.h"
#include "frontend/render.h"
#include "frontend/window.h"

#include "game.h"



int Game::initialize(){

    // Primero se inicializa la pantalla para obtener la propiedades de la pantalla del usuario
    window.initialize();

    //Segundo se construyen toda la parte del backend
    std::string title = "text_box";
    bar = Bar(title, window.get_x_max() * 0.7, 0, window.get_x_max(), window.get_y_max());
    console = Console(title, 0, window.get_y_max() * 0.8, bar.get_x_start(), window.get_y_max());
    board = Board(title, 0, 0, bar.get_x_start(), console.get_y_start());

    //Tercero se iniciliza la parte grafica
    board_render.initialize(board.get_x_start(),board.get_y_start(),board.get_x_end(),board.get_y_end());
    board_render.create_box();
    bar_render.initialize(bar.get_x_start(),bar.get_y_start(),bar.get_x_end(),bar.get_y_end());
    bar_render.create_box();
    console_render.initialize(console.get_x_start(),console.get_y_start(),console.get_x_end(),console.get_y_end());
    console_render.create_box();

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

        inputs();

        outputs();


        

        board_render.update();
        bar_render.update();
        console_render.update();

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    terminate();
    return 0;
}


int Game::inputs(){
    int board_key = board_render.get_input();
    int bar_key = bar_render.get_input();
    int console_key = console_render.get_input();

    console.input_mannagment(console_key);

    if(board_key == 'e' || bar_key == 'e' || console_key == 'e'){
        running = false;
    }
    return 0;
}

int Game::outputs(){

    board_render.set_char('@', 5, 5, window.get_rb());

    StringItem* console_menu = console.get_menu();
    for (int i = 0; i < 5; i++){
        console_render.set_string(console_menu[i].get_text(), console_menu[i].get_x(), console_menu[i].get_y(), window.get_rb());
    }

    return 0;
}