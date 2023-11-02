#include "cutellipsoid.h"
#include <cmath>


CutEllipsoid::CutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a){
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    rx      = _rx;
    ry      = _ry;
    rz      = _rz;
    r       = _r;
    g       = _g;
    b       = _b;
    a       = _a;
}

CutEllipsoid::~CutEllipsoid(){}

void CutEllipsoid::draw(Sculptor &t){
    t.setColor(r, g, b, a);
    double dist;
    for (int i=0; i<rx; i++) {
        for (int j=0; j<ry; j++) {
            for (int k=0; k<rz; k++) {
                dist = pow(i-xcenter, 2)/pow(rx, 2) + pow(j-ycenter, 2)/pow(ry, 2) + pow(k-zcenter, 2)/pow(rz, 2);
                if (dist <= 1) {
                    t.cutVoxel(i, j, k);
                }
            }
        }
    }
}