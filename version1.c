#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include "Coordinates.h"
#include "Object.h"
#include "Rand.h"


using namespace std;








int main() {
    srand(time(NULL));
    int size_x = 1000, size_y = 1000;
    vector <Object*> objs;
    objs = Create_Objects(size_x, size_y);
    randomwalk_objs(&objs, size_x, size_y);

    cout << "End program\n";

}