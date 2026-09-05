#include <string> // string

#ifndef _INTERFACE_H_
#define _INTERFACE_H_

class Interface{
private:
    std::string title;
    int x_start;
    int y_start;
    int x_end;
    int y_end;
    
public:
    Interface(std::string title, int x_start, int y_start, int x_end, int y_end){
        this->title = title;
        this->x_start = x_start;
        this->y_start = y_start;
        this->x_end = x_end;
        this->y_end = y_end;
    }
    void set_title(std::string title) {this->title = title;}
    void set_x_start(int x_start) {this->x_start = x_start;}
    void set_y_start(int y_start) {this->y_start = y_start;}
    void set_x_end(int x_end) {this->x_end = x_end;}
    void set_y_end(int y_end) {this->y_end = y_end;}
    std::string get_title(){return title;}
    int get_x_start(){return x_start;}
    int set_y_start(){return y_start;}
    int get_x_end(){return x_end;}
    int get_y_end(){return y_end;}
};


#endif