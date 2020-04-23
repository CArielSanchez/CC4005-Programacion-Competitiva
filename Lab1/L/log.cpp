#include <bits/stdc++.h>
using namespace std;
typedef float ull;

ull factorial(ull n)
{
    ull r = 0;
    for (ull i = 1; i <= n; i++)
    {
        r += log2(i);
    }
    return r;
}

ull exponencial(ull a, ull n)
{
    ull r = n * log2(a);
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
        B = a[z]*4;

        while (A != B){
            //cout<<"A: "<<A<<" B: "<<B<<"\n";

            mid = A + (B - A)/2;
            //cout<<"MID: "<<mid<<"\n";

            exp = exponencial(a[z], mid);
            //cout<<"EXP : "<<exp<<"\n";

            fact = factorial(mid);
            //cout<<"FACT: "<<fact<<"\n";
            

            if( fact >= exp )
            {
                B = mid; // Bajamos
            }
            else
            {
                A = mid + 1; // Subir
            }
        }

        fact = factorial(A);
        //cout<<"FACT FINAL: "<<fact<<"\n";
        exp = exponencial(a[z], A);
        //cout<<"EXP FINAL : "<<exp<<"\n";

        if( exp > fact ) // No hay un n entre A y B que cumpla la condicion
        {
            cout<<"ERROR\n";
            return 1;
        }
        else
        {
            a[z] = A; // A cumple
        }
    }

    //cout<<"\n";
    for (int i = 0; i < t; i++)
    {
        cout<<a[i]<<"\n";
    }
    
    return 0;
}