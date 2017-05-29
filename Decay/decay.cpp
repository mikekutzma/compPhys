#include <iostream>
using namespace std;

#define NPOINTS 100
int main(int argc, char* argv[]){
    double N0,T,dt,tau;
    if(argc < 4){
        cout << "Initial number of nuclei: ";
        cin >> N0;
        cout << "Time constant: ";
        cin >> tau;
        cout << "Time step: ";
        cin >>  dt;
    } else{
        N0 = atof(argv[1]);
        tau = atof(argv[2]);
        dt = atof(argv[3]);
    }
    double N[NPOINTS];
    N[0] = N0;
    cout << 0 << "\t" << N0 << endl;
    for(int i=1;i<NPOINTS;i++){
        N[i] = N[i-1] * (1 - (dt/tau));
        cout << (i*dt) << "\t" << N[i] << endl;    
    }
}
    


