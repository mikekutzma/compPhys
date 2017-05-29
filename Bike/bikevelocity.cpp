#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define NPOINTSMAX 100000

double velcalc_nof(double, double, double, double);
double velcalc_airf(double, double, double, double, double, double, double);

int main(int argc, char* argv[]){
//Declare and initialize
    double v0,P,m,dt,C,rho,A,T;
    if(argc < 9){
        cout << "Need arguments." << endl;
        return 1;
    } else{
        v0 = atof(argv[1]);
        P = atof(argv[2]);
        m = atof(argv[3]);
        dt = atof(argv[4]);
        C = atof(argv[5]);
        rho = atof(argv[6]);
        A = atof(argv[7]);
        T = atof(argv[8]);
    }
    double v_nof[NPOINTSMAX];
    double v_airf[NPOINTSMAX];
    const int NPOINTS = (int)(T/dt); 
    v_nof[0] = v0;
    v_airf[0] = v0;
//Calculate
    for(int i=1;i<NPOINTS;i++){
        v_nof[i] = velcalc_nof(v_nof[i-1],P,m,dt);
        v_airf[i] = velcalc_airf(v_airf[i-1],P,m,dt,C,rho,A);
    }
//Write to file
    ofstream fout("bikevelocitydata.dat");
    for(int i=0;i<NPOINTS;i++){
        fout << fixed << setprecision(4) << (i*dt) << "\t\t";
        fout << fixed << setprecision(4) << v_nof[i] << "\t\t";
        fout << fixed << setprecision(4) << v_airf[i] << endl;
    }
}
    
double velcalc_nof(double v, double P, double m, double dt){
    return v + (P/(m*v))*dt;
}
double velcalc_airf(double v, double P, double m, double dt, double C, double rho, double A){
    return v + ((P/(m*v))*dt) - ((C*rho*A*v*v/m)*dt);
}

