#include <bits/stdc++.h>
using namespace std;

int main(){
    double rp,dp;
    int n;
    cin>>rp>>dp>>n;
    double x[n];
    double y[n];
    double r[n];

    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i]>>r[i];
    }

    double total = 0;
    double distancia;

    for(int i=0;i<n;i++){
        distancia = sqrt(x[i]*x[i] + y[i]*y[i]);

        if(distancia >= r[i] + (rp-dp) && distancia + r[i] <= rp){ // Fuera circulo interno, dentro de la pizza
            total++;
        }
    }

    cout<<total;
    return 0;
}