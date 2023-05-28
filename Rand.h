#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include "Coordinates.h"
#include "Object.h"


using namespace std;


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