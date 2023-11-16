#include "putvoxel.h"
#include "putbox.h"
#include "putsphere.h"
#include "putellipsoid.h"
#include "cutvoxel.h"
#include "cutbox.h"
#include "cutsphere.h"
#include "cutellipsoid.h"
#include "interpreter.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

Interpreter::Interpreter(){}

vector<FiguraGeometrica*> Interpreter:: read(string filename){

    vector<FiguraGeometrica*> figuras;
    std::ifstream file;
    string stng,var;
    std::stringstream ss;

    file.open(filename.c_str());

    if(!file.is_open()){
        exit(0);
    }

    while(getline(file,stng)){

        ss.clear();
        ss.str(stng);
        ss >> var;
        std::cout << var << " ";

        if(var.compare("dim")==0){
            ss >> dimx >> dimy >> dimz;
        }
        else if(var.compare("putvoxel")==0){
            int x_,y_,z_;
            ss >> x_ >> y_ >> z_ >> r >> g >> b >> a;
            figuras.push_back(new PutVoxel(x_, y_, z_, r, g, b, a));
        }
        else if(var.compare("cutvoxel")==0){
            int x_, y_, z_;
            ss >> x_ >> y_ >> z_;
            figuras.push_back(new CutVoxel(x_, y_, z_, r, g, b, a));
        }
        else if(var.compare("putbox")==0){
            int x0; int x1; int y0; int y1; int z0; int z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            figuras.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
        }
        else if(var.compare("cutbox")==0){
            int x0; int x1; int y0; int y1; int z0; int z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            figuras.push_back(new CutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
        }
        else if(var.compare("putsphere")==0){
            int x0; int y0; int z0; int raio;
            ss >> x0 >> y0 >> z0 >> raio >> r >> g >> b >> a;
            figuras.push_back(new PutSphere(x0, y0, z0, raio, r, g, b, a));
        }
        else if(var.compare("cutsphere")==0){
            int x0; int y0; int z0; int raio;
            ss >> x0 >> y0 >> z0 >> raio;
            figuras.push_back(new CutSphere(x0, y0, z0, raio, r, g, b, a));
        }
        else if(var.compare("putellipsoid")==0){
            int x0, y0, z0, rx, ry, rz;
            ss >> x0 >> y0 >> z0 >> rx >> ry >> rz >> r >> g >> b >> a;
            figuras.push_back(new PutEllipsoid(x0, y0, z0, rx, ry, rz, r, g, b, a));
        }
        else if(var.compare("cutellipsoid")==0){
            int _x0, _y0, _z0, _rx, _ry, _rz;
            ss >> _x0 >> _y0 >> _z0 >> _rx >> _ry >> _rz;
            figuras.push_back(new CutEllipsoid(_x0, _y0, _z0, _rx, _ry, _rz, r, g, b, a));
        }
    }

    file.close();
    return(figuras);
}

int Interpreter::getdimx(){
    return dimx;
}

int Interpreter::getdimy(){
    return dimy;
}

int Interpreter::getdimz(){
    return dimz;
}