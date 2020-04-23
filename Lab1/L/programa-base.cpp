#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull factorial(ull n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

bool factorial2(ull n, ull res_exponencial)
{
    if( n == 1 || n == 0){
        return 1 >= res_exponencial;
    }

    ull i = 1;
    ull f = 1; 
    while (f <= res_exponencial && i < n)
    {
        f *= (f+1);
        i++;
    }
    cout<<
    return f >= res_exponencial;
}

ull exponencial(ull a, ull n)
{
    ull i = n;
    ull result = 1;
    while (n > 0)
    {
        //cout<<"RESULT: "<<result<<"\n";
        result *= a;
        n--;
    }
    if (result == 0)
    {
        result = ULLONG_MAX; // RESULT ES MAYOR A ESTE VALOR
    }
    return result;
    //return pow(a, n);
}

int main(){
    ull A = 1;
    ull B = 100;
    ull mid;
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
        
        while (A != B){
            cout<<"A: "<<A<<" B: "<<B<<"\n";

            mid = A + (B - A)/2;
            cout<<"MID: "<<mid<<"\n";

            exp = exponencial(a[z], mid);
            cout<<"EXP : "<<exp<<"\n";

            //fact = factorial(mid);
            //cout<<"FACT: "<<fact<<"\n";
            

            if( factorial2(mid, exp) )
            {
                B = mid; // Bajamos
            }
            else
            {
                A = mid + 1; // Subir
            }
        }

        fact = factorial(A);
        cout<<"FACT FINAL: "<<fact<<"\n";
        exp = exponencial(a[z], A);
        cout<<"EXP FINAL : "<<exp<<"\n";

        if( exp > fact ) // No hay un n entre A y B que cumpla la condicion
        {
            cout<<"ERROR\n";
            return 1;
        }
        else
        {
            a[z] = A; // A cumple
        }
        A = 1;
        B = 100;
    }

    cout<<"\n";
    for (int i = 0; i < t; i++)
    {
        cout<<a[i]<<"\n";
    }
    
    return 0;
}