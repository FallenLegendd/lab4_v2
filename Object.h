#pragma once


#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <ctime>



class Object {
private:
    int id;
    int path = 0;
    Coordinates* posxy;
    vector<Coordinates*> coordinates;
    int speed = 26;
public:
    Object(int id, int x, int y) {
        this->id = id;
        posxy = new Coordinates(x, y);
        coordinates.push_back(posxy);

    }
    Coordinates* get_position() {
        return posxy;
    }
    int get_id() {
        return id;
    }
    int get_path() {
        return path;
    }
    int get_count_point() {
        return coordinates.size();
    }
    void randomwalk(int mapx, int mapy) {
        int nap = rand() % 8;//направление
        int x = 0, y = 0;
        //Coordinates *newposxy = new Coordinates(posxy->get_x(), posxy->get_y());
        if (nap == 0) {
            if (posxy->get_x() + speed <= mapx)
                x = posxy->get_x() + speed;
        }
        else if (nap == 1) {
            if (posxy->get_x() - speed >= 0)
                x = posxy->get_x() - speed;
        }
        else if (nap == 2) {
            if (posxy->get_y() + speed <= mapy)
                y = posxy->get_y() + speed;
        }
        else if (nap == 3) {
            if (posxy->get_y() - speed >= 0)
                y = posxy->get_y() - speed;
        }
        if (x != 0 || y != 0) {
            Coordinates* newposxy = new Coordinates(x, y);
            coordinates.push_back(newposxy);
            path += dist_point(newposxy, posxy);
            posxy = newposxy;
        }

    }
    int get_path_coord(Coordinates* point) {
        return dist_point(posxy, point);
    }


};