#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

#define NPOINTSMAX 100000
#define PI 3.141592653

double step(double, double, double);
double vstep(double, double, double, double, double, double);

int main(int argc, char* argv[]){
    const double g = 9.81;
    double v0,dt,b2m;
    int angle, density;
    string filename;
    v0 = atof(argv[1]);
    dt = atof(argv[2]);
    density = atoi(argv[3]);
    b2m = atof(argv[4]);
    angle = atoi(argv[5]);
    cout << v0 << endl << dt << endl << density << endl << b2m << endl << angle << endl;
    if(argc > 6){
        filename = argv[6];
    }else{
        filename = "cannonballdata"+to_string(angle)+".dat";
    }
    double vxt,vx,vyt,vy,xt,x[NPOINTSMAX],yt,y[NPOINTSMAX];
    vxt = v0*cos(angle*PI/180.0);
    vyt = v0*sin(angle*PI/180.0);
    x[0] = y[0] = 0.0;
    int i=0;
    do{
        i++;
        vx = vxt;
        vy = vyt;
        xt = step(x[i-1],vx,dt);
        yt = step(y[i-1],vy,dt);
        vxt = vstep(vx,vy,dt,0.0,b2m,density*y[i-1]);
        vyt = vstep(vy,vx,dt,g,b2m,density*y[i-1]);
        x[i] = xt;
        y[i] = (yt>0.0)?yt:0.0;
    }while(i < NPOINTSMAX && y[i] > 0.0);
    
    ofstream fout(filename);
    for(int j=0;j<=i;j++){
        fout << left << setw(12) << x[j] << "\t";
        fout << y[j] << endl;
    }
}

double step(double x, double v, double dt){
    return x + (v*dt);
}
double vstep(double v1, double v2, double dt, double g, double b2m, double y){
    double v = pow((v1*v1) + (v2*v2),0.5);
    double y0 = 1000.0;
    return v1  - (exp(-y/y0)*b2m*v1*v*dt) - (g*dt);
}
