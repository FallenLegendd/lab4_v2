#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include "Coordinates.h"
#include "Object.h"



int dist_point(Coordinates* XY1, Coordinates* XY2) {
    return sqrt(pow((XY2->get_x() - XY1->get_x()), 2) + pow((XY2->get_y() - XY1->get_y()), 2));
}
