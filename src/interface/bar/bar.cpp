#include "bar.h"
#include "../../const.h"
#include <string>

// Carga de los objetos del menu con un valor por defecto
void Bar::load_menu(){
    this->pos_1_1 = StringItem("Health:", 5 , 2, COLOR_RED_BLACK);
    this->pos_2_1 = StringItem("Mana:", 5 , 3, COLOR_BLUE_BLACK);
    this->pos_3_1 = StringItem("Stamina:", 5 , 4, COLOR_GREEN_BLACK);
    this->pos_1_2 = StringItem(std::to_string(this->health) + "/" + std::to_string(this->max_health) , 20 , 2, COLOR_RED_BLACK);
    this->pos_2_2 = StringItem(std::to_string(this->mana) + "/" + std::to_string(this->max_mana), 20 , 3, COLOR_BLUE_BLACK);
    this->pos_3_2 = StringItem(std::to_string(this->stamina) + "/" + std::to_string(this->max_stamina), 20 , 4, COLOR_GREEN_BLACK);
    this->pos_4 = StringItem("Cursor info:", 5, 8, COLOR_WHITE_BLACK);
    // Para el paragrafo de la descripcion
    this->pos_5 = StringItem("", 5, BAR_DESCRIPTION_START_Y, COLOR_WHITE_BLACK); 
    this->pos_6 = StringItem("", 5, BAR_DESCRIPTION_START_Y+1, COLOR_WHITE_BLACK);
    this->pos_7 = StringItem("", 5, BAR_DESCRIPTION_START_Y+2, COLOR_WHITE_BLACK);
    this->pos_8 = StringItem("", 5, BAR_DESCRIPTION_START_Y+3, COLOR_WHITE_BLACK);
    this->pos_9 = StringItem("", 5, BAR_DESCRIPTION_START_Y+4, COLOR_WHITE_BLACK);
    this->pos_10 = StringItem("", 5, BAR_DESCRIPTION_START_Y+5, COLOR_WHITE_BLACK);
    this->pos_11 = StringItem("", 5, BAR_DESCRIPTION_START_Y+6, COLOR_WHITE_BLACK);
    this->pos_12 = StringItem("", 5, BAR_DESCRIPTION_START_Y+7, COLOR_WHITE_BLACK);
    update_menu();
}

// Actualizacion, se meten los objetos en el array para que sean pintados
void Bar::update_menu(){
    this->menu[0] = pos_1_1;
    this->menu[1] = pos_2_1;
    this->menu[2] = pos_3_1;
    this->menu[3] = pos_1_2;
    this->menu[4] = pos_2_2;
    this->menu[5] = pos_3_2;
    this->menu[6] = pos_4;
    this->menu[7] = pos_5;
    this->menu[8] = pos_6;
    this->menu[9] = pos_7;
    this->menu[10] = pos_8;
    this->menu[11] = pos_9;
    this->menu[12] = pos_10;
    this->menu[13] = pos_11;
    this->menu[14] = pos_12;
}


void Bar::set_description(std::string text){
    // this->pos_5.set_text(text);
    std::string sentence[8] = {};
    std::string current_word = "";
    bool sentence_full = false;

    int sentence_num = 0;
    for (char c : text) {
        sentence[sentence_num] += c;
        current_word +=c;
        if (c == ' ') {
            if (sentence[sentence_num].length() >= BAR_DESCRIPTION_MAX_X) {
                sentence_full = true;
                for(int i = 0; i < current_word.length(); i++){
                    sentence[sentence_num].pop_back();
                }
                sentence_num += 1;
                if (sentence_num < 8){
                    sentence[sentence_num] += current_word;
                }
            }
            current_word = "";
        }
    }
    this->pos_5.set_text(sentence[0]);
    this->pos_6.set_text(sentence[1]);
    this->pos_7.set_text(sentence[2]);
    this->pos_8.set_text(sentence[3]);
    this->pos_9.set_text(sentence[4]);
    this->pos_10.set_text(sentence[5]);
    this->pos_11.set_text(sentence[6]);
    this->pos_12.set_text(sentence[7]);

}
