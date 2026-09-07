
#include "backend/board.h"
#include "backend/console.h"
#include "backend/bar.h"
#include "frontend/render.h"
#include "frontend/screen.h"

#include <chrono>
#include <thread>

#include <curses.h>



int main(int argc, char **argv){

    //Primero se inicializa la pantalla para obtenr la propiesdes de la pantalla del usuario
    Screen screen = Screen();

    //Segundo se inicializa toda la parte del backend
    std::string title = "text_box";
    Board board = Board(title, 0, 0, 5, 5); //solo esta pantalla tendra altura y longitud variables, el resto fijas
    Bar bar = Bar(title, 50, 0, screen.get_x_max(), screen.get_y_max());
    Console console = Console(title, 0, 30, bar.get_x_start(), screen.get_y_max());

    //Tercero se iniciliza la parte grafica
    Render board_render = Render();
    board_render.initialize(board.get_x_start(),board.get_y_start(),screen.get_x_max(),screen.get_y_max());
    board_render.create_box();



    //render.terminate();

    // initscr(); //iniciar la pantalla
    // noecho(); //evita que se escriba lo que el usuario escribe
    // curs_set(0); //eliminar el cursor

    // int x_max, y_max;
    // getmaxyx(stdscr, y_max, x_max);

    // WINDOW *win = newwin(y_max, x_max, 0, 0);
    // box(win, 0, 0);

    // mvwprintw(win, 0, 2, " Menu ");
    // print_options(win,1,1,1,1);


    // //Selecto de opciones del menu
    // char presed_key = {0};
    // while (presed_key = wgetch(win)){
    //     switch (presed_key){
    //     case 'n':
    //         wattron(win, A_STANDOUT);
    //         mvwprintw(win, 3, 4, "New game");
    //         wattroff(win, A_STANDOUT);
    //         print_options(win,0,1,1,1);
    //         break;
    //     case 'c':
    //         wattron(win, A_STANDOUT);
    //         mvwprintw(win, 4, 4, "Continue");
    //         wattroff(win, A_STANDOUT);
    //         print_options(win,1,0,1,1);
    //         break;
    //     case 'o':
    //         wattron(win, A_STANDOUT);
    //         mvwprintw(win, 5, 4, "Options");
    //         wattroff(win, A_STANDOUT);
    //         print_options(win,1,1,0,1);
    //         break;
    //     case 'e':
    //         wattron(win, A_STANDOUT);
    //         mvwprintw(win, 6, 4, "Exit");
    //         wattroff(win, A_STANDOUT);
    //         print_options(win,1,1,1,0);
    //         break;
    //     default:
    //         print_options(win,1,1,1,1);
    //         break;
    //     }
    // }
    
    // endwin(); //terminar la pantalla
    // return 0;

}


// Segun que varible se le pase vuelve a pintar el menu
// int print_options(WINDOW *win, bool n, bool c, bool o, bool e){
//     if (n == true) {
//         mvwprintw(win, 3, 4, "New game");
//     }
//     if (c == true) {
//         mvwprintw(win, 4, 4, "Continue");
//     }
//     if (o == true) {
//         mvwprintw(win, 5, 4, "Options");
//     }
//     if (e == true) {
//         mvwprintw(win, 6, 4, "Exit");
//     }
//     return 0;
// }
    
