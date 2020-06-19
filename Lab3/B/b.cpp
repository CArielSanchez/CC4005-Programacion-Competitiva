#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N_primos = 10000001;

ll primos[10000001];
ll F[10000001]; // F[i] = # elementos en X, done i divide a X_j
ll S[10000001]; // Suma acumulada de F

// Update primos[]
void criba(){
    primos[0] = 0;
    primos[1] = 0;
    for(ll i=2; i< N_primos; i++){
        primos[i] = -1; // -1 === primo
    }
    for(ll i=2; i< N_primos; i++){
        for(ll j=2; i*j < N_primos; j++){
            primos[i*j] = i; // Pongo primo más grande que lo divide
        }
    }
}

// Factorizacion prima de numero X
vector<ll> fact_prima(ll X){
    vector<ll> fact;

    while(primos[X] != -1){
        fact.push_back(primos[X]);
        X = X / primos[X];
    }
    fact.push_back(X);
    return fact;
}


int main(){
    criba();

    // Input
    ll n;
    cin>>n;
    ll x[n];
    for(ll i = 0; i<n; i++){
        cin>>x[i];
    }

    ll m;
    cin>>m;
    ll li[m];
    ll ri[m];
    for(ll i = 0; i<m; i++){
        cin>>li[i]>>ri[i];
    }

    // Calc fact. prima de cada x.
    vector<vector<ll>> fp_x;
    for(ll i = 0; i<n; i++){
        vector<ll> prr = fact_prima(x[i]);
        fp_x.push_back(prr);
    }

    // Precomputar F[i]
    for(ll i = 0; i< 10000001; i++){
        if(primos[i] != -1){ // Si no es primo, no cuenta para [l, r]
            F[i] = 0;
        }else{               // Es primo
            F[i] = 0;
            for(ll j = 0; j< n; j++){ // Itero sobre todos los X

                for(ll k = 0; k < fp_x[j].size(); k++){  // Recorro su fact prima

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
    for(ll i = 1; i< 10000001; i++){
        S[i] = S[i-1] + F[i];
    }

    for(ll i = 0; i<m; i++){
        cout<<S[ri[i]] - S[li[i]-1]<<"\n";
    }

    return 0;
}
