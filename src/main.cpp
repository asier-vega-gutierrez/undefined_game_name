
#include "backend/board.h"
#include "backend/console.h"
#include "backend/bar.h"
#include "frontend/render.h"
#include "frontend/window.h"

#include <curses.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <thread>
#include <chrono>

//https://www.viget.com/articles/c-games-in-ncurses-using-multiple-windows


void my_handler(int s){
    printf("Ending on key %d\n",s);
}

int main(int argc, char **argv){

    // Primero se inicializa la pantalla para obtener la propiesdes de la pantalla del usuario
    Window win = Window();

    //Segundo se inicializa toda la parte del backend
    std::string title = "text_box";
    Board board = Board(title, 0, 0, 10, 10); //solo esta pantalla tendra altura y longitud variables, el resto fijas
    Bar bar = Bar(title, board.get_x_end(), 0, win.get_x_max(), win.get_y_max());
    //Console console = Console(title, 0, 30, bar.get_x_start(), screen.get_y_max());

    //Tercero se iniciliza la parte grafica
    Render board_render = Render();
    board_render.initialize(board.get_x_start(),board.get_y_start(),board.get_x_end(),board.get_y_end());
    board_render.create_box();
    Render bar_render = Render();
    bar_render.initialize(bar.get_x_start(),bar.get_y_start(),bar.get_x_end(),bar.get_y_end());
    bar_render.create_box();



    //Cuatro bucle de la aplicacion
    bool running = true;
    while (running) {
        
        int board_key = board_render.get_input();
        if (board_key == 'e') {
            running = false;
        }
        int bar_key = bar_render.get_input();
        if (bar_key == 'e') {
            running = false;
        }

        // board_render.update();
        // bar_render.update();
    }

    board_render.terminate();
    bar_render.terminate();
    endwin();

    return 0;

}