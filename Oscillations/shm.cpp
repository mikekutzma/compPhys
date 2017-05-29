#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

#define NPOINTSMAX 100000
#define PI 3.141592653

double step(double, double, double);
double wstep(double, double, double, double,double, double, double, double);

int main(int argc, char* argv[]){
    double w0,theta0,l,dt,q,fd,wd;
    int N;
    string filename;
    w0 = atof(argv[1]);
    theta0 = atof(argv[2]);
    l = 9.81;
    dt = atof(argv[3]);
    N = atoi(argv[4]);
    filename = argv[5];
    q = 0.5;
    fd = atof(argv[6]);
    wd = 2.0/3.0;
    double thetat,wt,theta[NPOINTSMAX],w[NPOINTSMAX],t;
    theta[0] = theta0;
    w[0] = w0;
    for(int i=1;i<N;i++){
        w[i] = wstep(w[i-1],theta[i-1],l,dt,q,fd,wd,i*dt);
        theta[i] = step(theta[i-1],w[i],dt);
    }
    ofstream fout(filename);
    for(int i=0;i<N;i++){
        fout << left << setw(12) << i*dt << "\t";
        fout << left << setw(12) << theta[i] << "\t";
        fout << left << setw(12) << w[i] << endl;
    }
}

double step(double theta, double w,double dt){
    double a = theta + (w*dt);
    if(a > PI){
        a = a - (2*PI);
    }else if(a<-PI){
        a = a + (2*PI);
    }
    return a;
}

double wstep(double w,double theta,double l, double dt,double q, double fd, double wd, double t){
    const double g = 9.81;
    return w - (g*sin(theta)*dt/l) - (q*w*dt) - (fd*sin(wd*t)*dt);
}
