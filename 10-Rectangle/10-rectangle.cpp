#include <iostream>

using namespace std;



class Point{
    private:
        double x;
        double y;
    public:
        void set_x(double that_x) {
            x = that_x;
        }

        void set_y(double that_y) {
            y = that_y;
        }

        double get_x() {
            return x;
        }

        double get_y() {
            return y;
        }
};

class Rectangle{
    private:
        Point rd;
        Point lu;
        Point points[4];

    public:
        Rectangle(Point that_lu, Point that_rd) {
            rd = that_rd;
            lu = that_lu;

            Point ru, ld;
            ru.set_x(rd.get_x());
            ru.set_y(lu.get_y());

            ld.set_x(lu.get_x());
            ld.set_y(rd.get_y());
            points[0] = lu;
            points[1] = ru;
            points[2] = rd;
            points[3] = ld;

        }
        bool check_collision(Rectangle other) {
            for (int i = 0; i < 4; i++){
                Point lu2 = other.get_lupoint();
                Point rd2 = other.get_rdpoint();
                double x = points[i].get_x();
                double y = points[i].get_y();
                bool a = lu2.get_x() < x && rd2.get_x() > x;
                bool b = lu2.get_y() > y && rd2.get_y() < y;
                if (a && b) {
                    return true;
                }
            }
            return false;
        }
        void set_lupoint(Point that_lu) {
            lu = that_lu;
        }

        void set_rdpoint(Point that_rd) {
            rd = that_rd;
        }
        Point get_lupoint() {
            return lu;
        }

        Point get_rdpoint() {
            return rd;
        }
};



int main() {
    Point p1, p2, p3, p4;
    p1.set_x(1);
    p2.set_x(2);
    p3.set_x(3);
    p4.set_x(4);

    p1.set_y(4);
    p2.set_y(3);
    p3.set_y(2);
    p4.set_y(1);

    Rectangle rect1(p1, p2), rect2(p3, p4);

    cout << rect2.check_collision(rect1);

}
