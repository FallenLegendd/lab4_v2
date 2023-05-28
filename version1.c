#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include "Coordinates.h"



using namespace std;



int dist_point(Coordinates* XY1, Coordinates* XY2) {
    return sqrt(pow((XY2->get_x() - XY1->get_x()), 2) + pow((XY2->get_y() - XY1->get_y()), 2));
}

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

vector <Object*> Create_Objects(int mapx, int mapy) {
    int count;
    cout << "Input count objects(1 - 100): ";
    cin >> count;
    vector <Object*> obj;
    Object* newobj;
    int i, i2;
    int id;
    int create_id;
    for (i = 0; i < count; ++i) {
        create_id = 0;

        while (create_id != 1) {
            create_id = 1;
            id = 99 + (rand() % 10000);
            for (i2 = 0; i2 < i; ++i2) {
                if (id == obj[i2]->get_id()) {
                    create_id = 0;
                    break;
                }
            }

        }

        cout << "id = " << id << endl;
        newobj = new Object(id, rand() % mapx, rand() % mapy);
        obj.push_back(newobj);
    }
    return obj;
}

void randomwalk_objs(vector <Object*>* objs, int mapx, int mapy) {
    int count;
    cout << "Input count iteration move(1 - 1000): ";
    cin >> count;
    int i, i2;
    for (i = 0; i < count; ++i) {
        for (i2 = 0; i2 < objs->size(); ++i2) {
            objs->at(i2)->randomwalk(mapx, mapy);
        }
    }
    Object* ptr, * ptr2;
    for (i2 = 0; i2 < objs->size(); ++i2) {
        ptr = objs->at(i2);

        cout << "id - " << ptr->get_id() << "\n";
        cout << "\tpath = " << ptr->get_path() << "\n";
        cout << "\tcount point = " << ptr->get_count_point() << "\n";
        cout << "\tpath to \n";
        for (i = 0; i < objs->size(); ++i) {
            if (i != i2) {
                ptr2 = objs->at(i);
                cout << "\t\t[id - " << ptr2->get_id() << "] = " << ptr->get_path_coord(ptr2->get_position()) << "\n";
            }
        }
    }
    cout << "End iteratrion move\n";
}

int main() {
    srand(time(NULL));
    int size_x = 1000, size_y = 1000;
    vector <Object*> objs;
    objs = Create_Objects(size_x, size_y);
    randomwalk_objs(&objs, size_x, size_y);

    cout << "End program\n";

}