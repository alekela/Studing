#include <iostream>
#include <array>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;


int sign(int x) {
    if (x > 0) {
        return 1;
    }
    else if (x < 0) {
        return -1;
    }
    else {
        return 0;
    }
}


void random_place(array<array<int, 8>, 8>& field) {
    // place white rook
    int col1, col2, col3;
    int row1, row2, row3;
    srand(time(nullptr));
    col1 = rand() % 8;
    Sleep(500);
    srand(time(nullptr));
    row1 = rand() % 8;
    field[row1][col1] = 3;

    // place black king
    bool flag = true;
    while (flag) {
        srand(time(nullptr));
        col2 = rand() % 8;
        Sleep(500);
        srand(time(nullptr));
        row2 = rand() % 8;

        if (col1 != col2 && row1 != row2) {
            field[row2][col2] = 1;
            flag = false;
        }
    }

    // place white king
    flag = true;
    while (flag) {
        srand(time(nullptr));
        col3 = rand() % 8;
        Sleep(500);
        srand(time(nullptr));
        row3 = rand() % 8;

        if (not (row3 == row1 && col3 == col1)) {
            if ((row3 > row2 + 1 || row3 < row2 - 1) && (col3 > col2 + 1 || col3 < col2 - 1)) {
                field[row3][col3] = 2;
                flag = false;
            }
        }
    }
}


bool check(array<array<int, 8>, 8>& field) {
    int bkcol, bkrow, wkcol, wkrow, wrrow, wrcol;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (field[i][j] == 1) {
                bkcol = j;
                bkrow = i;
            }
            else if (field[i][j] == 2) {
                wkcol = j;
                wkrow = i;
            }
            else if (field[i][j] == 2) {
                wrcol = j;
                wrrow = i;
            }
        }
    }
    if (bkcol == wrcol || bkrow == wrrow || (abs(wkcol - bkcol) == 1 && abs(wkrow - bkrow) == 1)) {
        return true;
    }
    return false;
}


void print_board(array<array<int, 8>, 8>& field) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (field[i][j] == 0) {
                cout << "__ ";
            } 
            else if (field[i][j] == 1) {
                cout << "BK ";
            }
            else if (field[i][j] == 2) {
                cout << "WK ";
            }
            else if (field[i][j] == 3) {
                cout << "WR ";
            }
        }
        cout << abs(i - 8) << "\n";
    }
    cout << " a  b  c  d  e  f  g  h\n";
}


void get_pos(array<array<int, 8>, 8>& field) {
    string input;
    int row;
    int col;
    cin >> input;
    col = input[1] - 'a';
    row = 8 - (input[2] - '0');

    int startrow, startcol;
    while (row > 7 || row < 0 || col > 7 || col < 0) {
        cout << "Вы ввели некорректную позицию, CLTk это ещё раз" << endl;
        cin >> input;
        col = input[1] - 'a';
        row = 8 - (input[2] - '0');
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (field[i][j] == 1) {
                startrow = i;
                startcol = j;
            }
        }
    }

    
    field[row][col] = 1;
    field[startrow][startcol] = 0;
    while (check(field) && !(0 < abs(startcol - col) < 2 && 0 < abs(startrow - row) < 2)) {
        field[row][col] = 0;
        field[startrow][startcol] = 1;
        cout << "Вы ввели некорректную позицию, сделайте это ещё раз" << endl;
        cin >> input;
        col = input[1] - 'a';
        row = 8 - (input[2] - '0');
        field[row][col] = 1;
        field[startrow][startcol] = 0;
    }
}


void algorithm(array<array<int, 8>, 8>& field) {
    int bkcol, bkrow, wkcol, wkrow, wrrow, wrcol;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (field[i][j] == 1) {
                bkcol = j;
                bkrow = i;
            }
            else if (field[i][j] == 2) {
                wkcol = j;
                wkrow = i;
            }
            else if (field[i][j] == 3) {
                wrcol = j;
                wrrow = i;
            }
        }
    }
    if (abs(bkcol - wkcol) == 1 && abs(bkrow - wkrow) == 2) {
        field[wrrow][wrcol] = 0;
        field[wrrow][wkcol] = 3;
    }
    else if (abs(bkcol - wrcol) < 2 && abs(bkrow - wrrow) < 2) {
        field[wrrow][wrcol] = 0;
        if (bkcol + 4 < 8) {
            field[wrrow][bkcol + 4] = 3;
        }
        else {
            field[wrrow][bkcol - 4] = 3;
        }
    }
    else if (abs(bkrow - wrrow) > 1) {
        if (abs(bkcol - wrcol) < 2) {
            field[wrrow][wrcol] = 0;
            field[bkrow + 2 * sign(wkrow - bkrow)][wrcol] = 3;
        }
        else {
            field[wrrow][wrcol] = 0;
            field[bkrow + sign(wkrow - bkrow)][wrcol] = 3;
        }
    }
    else if (abs(wkrow - bkrow) > 2) {
        field[wkrow][wkcol] = 0;
        field[wkrow + sign(bkrow - wkrow)][wkcol] = 2;
    }
    else if (abs(bkrow - wrrow) == 1 && abs(bkcol - wrcol) > 1 && abs(bkrow - wkrow) == 2 && bkcol == wkcol) {
        field[wrrow][wrcol] = 0;
        field[wrrow + sign(bkrow - wkrow)][wrcol] = 3;
    }
    else {
        field[wkrow][wkcol] = 0;
        field[wkrow][wkcol + sign(bkcol - wkcol)] = 2;
    }
}


int main() {
    /*
    black king - 1
    white king - 2
    white rook - 3
    */
    array<array<int, 8>, 8> field;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            field[i][j] = 0;
        }
    }
    random_place(field);
    print_board(field);
    bool flag = true;
    while (flag) {
        get_pos(field);
        print_board(field);
        algorithm(field);
        print_board(field);
        if (check(field)) {
            flag = false;
        }
    }

}