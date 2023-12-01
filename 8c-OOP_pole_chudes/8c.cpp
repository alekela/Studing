#include "8c_1.h"
#include "windows.h"


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    Pole_chudes game;
    game.start_game();
}