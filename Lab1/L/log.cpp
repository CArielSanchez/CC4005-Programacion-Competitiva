#include <bits/stdc++.h>
using namespace std;
typedef double ull;

// Compara si fact >= exp sin calcular fact completamente
bool factorial_comp(ull n, ull exp)
{
    ull r = 0;
    for (ull i = n; i >= 1; i--) // De mayores a menores
    {
        r += log(i) / n;
        
        if (r >= exp){
            return true;
        }
    }
    return r >= exp;
}

// log(n!) = SUM log(i->n)
// Dividimos por N, porque para el otro lado ya no tenemos N*log(a), sino log(a)
ull factorial(ull n)
{
    ull r = 0;
    for (ull i = 1; i <= n; i++)
    {
        r += log(i) / n;
        //cout<<r<<"\n";
    }
    return r;
}

// Aproxx stirling
ull factorial2(ull n)
{
    ull r = 0;
    r += n*log(n) - n + 0.5*log(n*2*M_PI);
    return r;
}

// N*log(a), pero el N pasa dividiendo al factorial
ull exponencial(ull a, ull n)
{
    ull r = log(a);
    return r;
}

int main(){
    unsigned int A ;
    unsigned int B ;
    unsigned int mid;
    ull fact;
    ull exp;

    int t;
    cin>>t;
    ull a[t];

    for (int i = 0; i < t; i++)
    {
        cin>>a[i];
    }
    
    for(int z = 0; z < t; z++) 
    {
        A = 1;
        B = 2718274 + 1;

        while (A != B){
            mid = A + (B - A)/2;
            // exp = exponencial(a[z], mid); // Exp es sólo calcular log(a) => + rápido que fact
            exp = log(a[z]);
            // fact = factorial(mid);
            // cout<<"A: "<<A<<" B: "<<B<<"\n";
            // cout<<"MID: "<<mid<<"\n";
            // cout<<"EXP : "<<exp<<"\n";
            // cout<<"FACT: "<<fact<<"\n";

            if( factorial_comp(mid, exp) )
            {
                B = mid; // Bajamos
            }
            else
            {
                A = mid + 1; // Subir
            }
        }

        // fact = factorial(A);
        // exp = exponencial(a[z], A);
        // // cout<<"EXP FINAL : "<<exp<<"\n";
        // // cout<<"FACT FINAL: "<<fact<<"\n";
        
        // if( exp > fact ) // No hay un n entre A y B que cumpla la condicion
        // {
        //     cout<<"ERROR\n";
        //     return 1;
        // }
        // else
        // {
            a[z] = A; // A cumple
        // }
    }

    //cout<<"\n";
    for (int i = 0; i < t; i++)
    {
        cout<<a[i]<<"\n";
    }
    
    return 0;
}