#include "sculptor.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cmath>



Sculptor::Sculptor(int _nx, int _ny, int _nz) {
    nx = _nx;
    ny = _ny;
    nz = _nz;
    v = new Voxel**[nx];

    for (int i = 0; i < nx; i++) {
        v[i] = new Voxel*[ny];
        for (int j = 0; j < ny; j++) {
            v[i][j] = new Voxel[nz];
        }
    }
}


Sculptor::~Sculptor() {
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            delete[] v[i][j];
        }
        delete[] v[i];
    }
    delete[] v;
}


void Sculptor::putVoxel(int x, int y, int z) {
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    v[x][y][z].show = true;
}


void Sculptor::cutVoxel(int x, int y, int z) {
    v[x][y][z].show = false;
}


void Sculptor::setColor(float _r, float _g, float _b, float _a){

    r = _r;
    g = _g;
    b = _b;
    a = _a;

}


void Sculptor::writeOFF(const char *filename){
    int total_voxels = 0;
    std::ofstream fout;
    fout.open(filename, std::ios_base::out);
    fout << std::fixed << std::setprecision(1);

    if (!fout.is_open()) {
        std::cout << "Erro ao abrir o arquivo" << std::endl;
        exit(1);
    }

    fout << "OFF" << std::endl;


    for (int i=0; i<nx; i++) {
        for (int j=0; j<ny; j++) {
            for (int k=0; k<nz; k++) {
                if (v[i][j][k].show) {
                    total_voxels++;
                }
            }
        }
    }

    fout << total_voxels*8 << " " << total_voxels*6 << " 0\n" << std::endl;

    for (int i=0; i<nx; i++) {
        for (int j=0; j<ny; j++) {
            for (int k=0; k<nz; k++) {
                if (v[i][j][k].show) {
                    fout << i-0.5 << " " << j+0.5 << " " << k-0.5 << std::endl;
                    fout << i-0.5 << " " << j-0.5 << " " << k-0.5 << std::endl;
                    fout << i+0.5 << " " << j-0.5 << " " << k-0.5 << std::endl;
                    fout << i+0.5 << " " << j+0.5 << " " << k-0.5 << std::endl;
                    fout << i-0.5 << " " << j+0.5 << " " << k+0.5 << std::endl;
                    fout << i-0.5 << " " << j-0.5 << " " << k+0.5 << std::endl;
                    fout << i+0.5 << " " << j-0.5 << " " << k+0.5 << std::endl;
                    fout << i+0.5 << " " << j+0.5 << " " << k+0.5 << std::endl;   
                }
            }
        }
    }

    int count = 0;
    
    for (int i=0; i<nx; i++) {
        for (int j=0; j<ny; j++) {
            for (int k=0; k<nz; k++) {
                if (v[i][j][k].show) {
                    fout << "4 " << count << " " << count+3 << " " << count+2 << " " << count+1 << " ";
                    fout << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    fout << "4 " << count+4 << " " << count+5 << " " << count+6 << " " << count+7 << " ";
                    fout << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    fout << "4 " << count << " " << count+1 << " " << count+5 << " " << count+4 << " ";
                    fout << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    fout << "4 " << count << " " << count+4 << " " << count+7 << " " << count+3 << " ";
                    fout << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    fout << "4 " << count+3 << " " << count+7 << " " << count+6 << " " << count+2 << " ";
                    fout << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    fout << "4 " << count+1 << " " << count+2 << " " << count+6 << " " << count+5 << " ";
                    fout << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    count += 8;
                }
            }
        }
    }



}