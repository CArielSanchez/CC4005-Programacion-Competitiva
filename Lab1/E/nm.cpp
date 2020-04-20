#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m, k = 0;

    cin>>n>>m>>k;

    long long A = 1;
    long long B = n * m;
    long long medio = 0;
    long long menoresAMi = 0;
    while(A < B) { // Buscando resultado
        medio = A + (B - A)/2;
        menoresAMi = 0;
        //cout<<"Medio: "<<medio<<"\n";

        for (long long i = 1; i <= n; i++)
        {
            //cout<<"Menores a mi: "<<min(m, medio/i)<<"\n";
            menoresAMi += min(m, medio/i); // En la i-esima fila, el peor caso es que toda la fila es menor al resultado, el mejor que solo mid/i sea menor (Si h*i > medio => h > medio/i)
        }
        //cout<<"Total Menores a mi: "<<menoresAMi<<"\n";
        
        if (menoresAMi < k)
        {
            A = medio + 1;
        }else if (menoresAMi > k)
        {
            B = medio;
        }else{
            break;
        }
    }

    if(A == B){ // Líimite derecho
        medio = A;
    }
    
    cout<<medio;

    return 0;
}
