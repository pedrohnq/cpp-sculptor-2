#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <vector>

#include "sculptor.h"
#include "figura_geometrica.h"

#include "putvoxel.h"
#include "cutvoxel.h"

#include "cutsphere.h"
#include "putsphere.h"

#include "putellipsoid.h"
#include "cutellipsoid.h"

#include "putbox.h"
#include "cutbox.h"

int main() {
    Sculptor *s = new Sculptor(100, 100, 100);

    std::vector <FiguraGeometrica*> figs;

    // PutVoxel
    figs.push_back(new PutVoxel(1, 1, 1, 1, 0, 0, 1));
    figs.push_back(new PutVoxel(2, 2, 2, 0, 1, 0, 1));

    // CutVoxel
    figs.push_back(new CutVoxel(2, 2, 2, 0, 1, 0, 1));


    // PutSphere
    figs.push_back(new PutSphere(10, 20, 1, 10, 1, 0, 0, 1));

    // CutSphere
    figs.push_back(new CutSphere(10, 20, 15, 5, 1, 0, 0, 1));

    // PutEllipsoid
    figs.push_back(new PutEllipsoid(10, 20, 30, 5, 10, 15, 1, 0, 0, 1));

    // CutEllipsoid
    figs.push_back(new CutEllipsoid(10, 20, 30, 10, 30, 20, 1, 0, 0, 1));

    // PutBox
    figs.push_back(new PutBox(10, 20, 30, 40, 50, 60, 0, 0, 1, 1));
    
    // CutBox
    figs.push_back(new CutBox(12, 21, 32, 41, 52, 61, 0, 0, 1, 1));



    // draw
    for (int i = 0; i < int(figs.size()); i++) {
        figs[i]->draw(*s);
    }

    s->writeOFF((const char*)"teste.off");

}