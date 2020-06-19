#include <bits/stdc++.h>
using namespace std;
//typedef long long int;

int N_primos = 10000001;

int primos[10000001];
int F[10000001]; // F[i] = # elementos en X, done i divide a X_j
int S[10000001]; // Suma acumulada de F

// Update primos[]
void criba(){
    primos[0] = 0;
    primos[1] = 0;
    for(int i=2; i< N_primos; i++){
        primos[i] = -1; // -1 === primo
    }
    for(int i=2; i< N_primos; i++){
        for(int j=2; i*j < N_primos; j++){
            primos[i*j] = i; // Pongo primo más grande que lo divide
        }
    }
}

// Factorizacion prima de numero X
vector<int> fact_prima(int X){
    vector<int> fact;

    while(primos[X] != -1){
        fact.push_back(primos[X]);
        X = X / primos[X];
    }
    fact.push_back(X);
    return fact;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    criba();

    // Input
    int n;
    cin>>n;
    int x[n];
    for(int i = 0; i<n; i++){
        cin>>x[i];
    }

    int m;
    cin>>m;
    int li[m];
    int ri[m];
    for(int i = 0; i<m; i++){
        cin>>li[i]>>ri[i];
    }

    // Calc fact. prima de cada x.
    vector<vector<int>> fp_x;
    for(int i = 0; i<n; i++){
        vector<int> prr = fact_prima(x[i]);
        fp_x.push_back(prr);
    }

    // Precomputar F[i]
    for(int i = 0; i< 10000001; i++){
        if(primos[i] != -1){ // Si no es primo, no cuenta para [l, r]
            F[i] = 0;
        }else{               // Es primo
            F[i] = 0;
            for(int j = 0; j< n; j++){ // Itero sobre todos los X

                for(int k = 0; k < fp_x[j].size(); k++){  // Recorro su fact prima

                    if(fp_x[j][k] == i){ // Si aparesco en la factorización prima de X_k, sumo y salgo
                        F[i]++;
                        break;
                    }
                }
            }
        }
    }

    // Calcular S === F acumulado
    S[0] = F[0];
    for(int i = 1; i< 10000001; i++){
        S[i] = S[i-1] + F[i];
    }

    for(int i = 0; i<m; i++){
        cout<<S[ri[i]] - S[li[i]-1]<<"\n";
    }

    return 0;
}
