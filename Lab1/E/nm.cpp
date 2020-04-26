#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, m, k = 0;

    cin>>n>>m>>k;

    ll A = 1;
    ll B = n * m;
    ll medio;
    ll menoresAMi;
    ll anterior = 0;
    while(A < B) { // Buscando resultado
        medio = A + (B - A)/2;
        menoresAMi = 0;
        //cout<<"A: "<<A<<" B: "<<B<<" Medio: "<<medio<<"\n";

        for (ll i = 1; i <= n; i++)
        {
            //cout<<"Menores/iguales a mi: "<<min(m, medio/i)<<"\n";
            menoresAMi += min(m, medio/i); // En la i-esima fila, el peor caso es que toda la fila es menor al resultado, el mejor que solo mid/i sea menor (Si h*i > medio => h > medio/i)
        }
        //cout<<"Total Menores/iguales a mi: "<<menoresAMi<<"\n";
        
        if (menoresAMi < k)
        {
            A = medio + 1;
        }
        else // Buscamos con uno más chico
        {
            B = medio;
            anterior = medio;
        }
    }

    if(A < k && anterior > k){ // cuando busco para abajo pero me paso por harto por que hay por ej {1 {2} {2} 4}
        A = anterior;
    }
    
    cout<<A;

    return 0;
}
