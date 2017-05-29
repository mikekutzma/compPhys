#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define NPOINTS 100

double decaycalc(double, double, double, double);

int main(int argc, char* argv[]){
//Declare and initialize
    double NA0,NB0,T,dt,tau;
    if(argc < 5){
        cout << "Initial number of A nuclei: ";
        cin >> NA0;
        cout << "Initial number of B nuclei: ";
        cin >> NB0;
        cout << "Time constant: ";
        cin >> tau;
        cout << "Time step: ";
        cin >>  dt;
    } else{
        NA0 = atof(argv[1]);
        NB0 = atof(argv[2]);
        tau = atof(argv[3]);
        dt = atof(argv[4]);
    }
    double NA[NPOINTS];
    double NB[NPOINTS];
    NA[0] = NA0;
    NB[0] = NB0;
//Calculate
    double atemp;
    double btemp;
    for(int i=1;i<NPOINTS;i++){
        atemp = decaycalc(NA[i-1],NB[i-1],tau,dt);
        btemp = decaycalc(NB[i-1],NA[i-1],tau,dt);
        NA[i] = atemp;
        NB[i] = btemp;
    }
//Write to file
    ofstream fout("dualdecaydata.dat");
    for(int i=0;i<NPOINTS;i++){
        fout << fixed << setprecision(4) << (i*dt) << "\t\t";
        fout << fixed << setprecision(4) << NA[i] << "\t\t";
        fout << fixed << setprecision(4) << NB[i] << endl;
    }
}
    
double decaycalc(double N1, double N2, double tau, double dt){
    return N1 + ((dt/tau)*(N2-N1));
}

