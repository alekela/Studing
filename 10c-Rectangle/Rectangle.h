#ifndef ABDUL
#define ABDUL


using namespace std;


class Rectangle{
    private:
        double rd_x, rd_y;
        double lu_x, lu_y;

    public:
        Rectangle(double that_lux, double that_luy, double that_rdx, double that_rdy);

        bool check_collision(Rectangle& other); 

        void set_lux(double that_lux);

        void set_luy(double that_luy);

        void set_rdx(double that_rdx);

        void set_rdy(double that_rdy);

        double get_lux() { return lu_x; }

        double get_luy() { return lu_y; }

        double get_rdx() { return rd_x; }

        double get_rdy() { return rd_y; }
};

#endif