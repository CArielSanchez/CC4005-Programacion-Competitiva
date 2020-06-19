#include <bits/stdc++.h>
using namespace std;
//typedef long long int;

int N_primos = 1000001;

int primos[1000001];
int S[1000001]; // Suma acumulada de primod

// Update primos[]
void criba(){
    primos[0] = 0;
    primos[1] = 0;
    for(int i=2; i< N_primos; i++){
        primos[i] = 1; // 1 === primo
    }
    for(int i=2; i< N_primos; i++){
        for(int j=2; i*j < N_primos; j++){
            primos[i*j] = 0; // Pongo primo más grande que lo divide
        }
    }
}


bool k_primos_o_mas(int a, int b, int k, int L){
    int aux = a;
    //cout<<"L: "<<L<<"\n";
    while( aux + L -1 <= b){
        //cout<<"["<<aux<<","<<aux+L-1<<"]\n";
        if(S[aux+L-1] - S[aux - 1] < k){ // Si hay menos primos
            return false;
        }
        aux++;
    }
    return true;
}

int main(){
    criba();
    // Calcular S === primos acumulado
    S[0] = primos[0];
    for(int i = 1; i< 1000001; i++){
        S[i] = S[i-1] + primos[i];
    }

    int a;
    int b;
    int k;
    cin>>a>>b>>k;

    // Busqueda binaria sobre L
    int A = 1;
    int B = b - a + 1;
    int mid;
    while (A < B){
        mid = A + (B - A)/2;
        if(k_primos_o_mas(a, b, k, mid)){
            B = mid;
        }else{
            A = mid + 1;
        }
    }

    if(!k_primos_o_mas(a, b, k, A)){
        cout<<-1;
    }else{
        cout<<A;
    }

    return 0;
}
