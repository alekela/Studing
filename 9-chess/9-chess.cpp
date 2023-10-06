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
        cout << "\n";
    }
    cout << "\n";
}


void get_pos(array<array<int, 8>, 8>& field) {
    string input;
    char figure;
    int row;
    int col;
    cin >> input;
    figure = input[0];
    col = input[1] - 'a';
    row = input[2] - '0' - 1;
    int startrow, startcol;
    if (row > 7 || row < 0 || col > 7 || col < 0) {
        return;
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (field[i][j] == 1) {
                startrow = i;
                startcol = j;
            }
        }
    }
    if (abs(startcol - col) < 2 && abs(startrow - row) < 2) {
        if (figure == 'K') {
            field[row][col] = 1;
            field[startrow][startcol] = 0;
        }
    }
}


void algorithm(array<array<int, 8>, 8>& field, bool queue) {
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

    if (abs(wrrow - wkrow) > 1 && sign(wrrow - wkrow) == sign(bkrow - wkrow)) {
        field[wrrow][wrcol] = 0;
        field[wkrow + sign(bkrow - wkrow)][wrcol] = 3;
    }
    else if (abs(wrcol - wkcol) > 1 && sign(wrcol - wkcol) == sign(bkcol - wkcol)) {
        field[wrrow][wrcol] = 0;
        field[wrrow][wkcol + sign(bkcol - wkcol)] = 3;
    }

    else if (abs(wrrow - bkrow) > 1) {
        if (queue) {
            field[wrrow + sign(bkrow - wrrow)][wrcol] = 3;
            field[wrrow][wrcol] = 0;
        }
        else {
            field[wkrow + sign(bkrow - wkrow)][wkcol] = 2;
            field[wkrow][wkcol] = 0;
        }
    }

    else if (abs(wrcol - bkcol) > 1) {
        if (queue) {
            field[wrrow][wrcol + sign(bkcol - wrcol)] = 3;
            field[wrrow][wrcol] = 0;
        }
        else {
            field[wkrow][wkcol + sign(bkcol - wkcol)] = 2;
            field[wkrow][wkcol] = 0;
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
    if (bkcol == 7 && bkrow == 7 || bkcol == 0 && bkrow == 7 || bkcol == 7 && bkrow == 0 || bkcol == 0 && bkrow == 0) {
        if (abs(wrrow - bkrow) == 1 && abs(wrcol - bkcol) == 1) {
            return true;
        }
    }
    return false;
}


void playing(array<array<int, 8>, 8>& field) {
    random_place(field);
    print_board(field);
    bool queue = false;
    bool flag = true;
    while (flag) {
        get_pos(field);
        print_board(field);
        algorithm(field, queue);
        queue = queue? queue = false : queue = true;
        print_board(field);
        if (check(field)) {
            cout << "0";
            flag = false;
        }
        else {
            cout << "1" << endl;
        }
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
    playing(field);

}
