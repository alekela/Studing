#include <iostream>
#include "Rectangle.h"


using namespace std;


Rectangle::Rectangle(double that_lux, double that_luy, double that_rdx, double that_rdy) : lu_x(that_lux), lu_y(that_luy), rd_x(that_rdx), rd_y(that_rdy)
{}

bool Rectangle::check_collision(Rectangle& other) {
    double point_x = other.get_lux();
    double point_y = other.get_luy();
    if (lu_x < point_x && rd_x > point_x && lu_y > point_y && rd_y < point_y) {
        return true;
    }
    point_x = other.get_lux();
    point_y = other.get_rdy();
    if (lu_x < point_x && rd_x > point_x && lu_y > point_y && rd_y < point_y) {
        return true;
    }

    point_x = other.get_rdx();
    point_y = other.get_rdy();
    if (lu_x < point_x && rd_x > point_x && lu_y > point_y && rd_y < point_y) {
        return true;
    }

    point_x = other.get_rdx();
    point_y = other.get_luy();
    if (lu_x < point_x && rd_x > point_x && lu_y > point_y && rd_y < point_y) {
        return true;
    }

    return false;
}
void Rectangle::set_lux(double that_lux) {
    lu_x = that_lux;
}

void Rectangle::set_luy(double that_luy) {
    lu_y = that_luy;
}

void Rectangle::set_rdx(double that_rdx) {
    rd_x = that_rdx;
}

void Rectangle::set_rdy(double that_rdy) {
    rd_y = that_rdy;
}
