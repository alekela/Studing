#ifndef POLE_CHUDES
#define POLE_CHUDES

#include <string>
#include "Narator.h"

class Pole_chudes { 
    public:

        void start_game();

    private:
        bool check_end();

        void end_game();

        Narator narator;
        string dictionary[3] = {"стегозавр", "мельница", "чебурашка"};
        int dictionary_len = 3;
}; 

#endif
