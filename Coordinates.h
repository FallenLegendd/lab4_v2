#pragma once




class Coordinates {

    int x, y;
public:
    Coordinates(int x1, int y1) {
        x = x1;
        y = y1;
    }
    int get_x() {
        return x;
    }
    int get_y() {
        return y;
    }
    void set_x(int x1) {
        x = x1;
    }
    void set_y(int y1) {
        y = y1;
    }

};