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

#include "interpreter.h"

int main() {
    Sculptor *sculptor;
    Interpreter intepreter;
    vector<FiguraGeometrica*> fig;

    fig = intepreter.read("input.txt");

    sculptor = new Sculptor(intepreter.getdimx(), intepreter.getdimy(), intepreter.getdimz());
    for (size_t x=0; x<fig.size(); x++){
        fig[x] -> draw(*sculptor);
    }

    sculptor->writeOFF((char*)"teste.off");

    for (size_t x=0; x<fig.size(); x++){
        delete fig[x];
    }
    
    delete sculptor;

    return 0;
}
