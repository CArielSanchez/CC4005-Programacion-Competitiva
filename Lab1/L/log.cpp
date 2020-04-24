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
    unsigned int A = 1;
    unsigned int B = 2718274 + 1;;
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
    
    vector<double> C(B, 0);
    int highCalc = 1;
    int now ;

    for(int z = 0; z < t; z++) 
    {
        A = 1;
        B = 2718274 + 1;

        while (A != B){
            mid = A + (B - A)/2;
            exp = log(a[z]);

            if(C[mid] == 0){ // Si la suma de log(i) NO está calculada hasta ese punto
                fact = C[highCalc]; // Rescato valor calculado, pero caso vale 0
                now = highCalc + 1; // Muevo puntero
                for (int i = now; i <= mid; i++) // Calculo hasta donde necesito
                {
                    C[i] = log(i) + C[i-1];
                }
                highCalc = mid; // Ahora calcule hasta highCalc

                fact = C[mid] / (double) mid; // SUM log(i->N) / N
                          
            }else{ // Si ya está calculada, la saco simplemente
                fact = C[mid] / (double) mid;
            }
            // cout<<"A: "<<A<<" B: "<<B<<"\n";
            // cout<<"MID: "<<mid<<"\n";
            // cout<<"EXP : "<<exp<<"\n";
            // cout<<"FACT: "<<fact<<"\n";

            if( fact >= exp )
            {
                B = mid; // Bajamos
            }
            else
            {
                A = mid + 1; // Subir
            }
        }
        a[z] = A; // Siempre se cumple ahora que n max es 2718274 + 1 (respuesta de 1.000.000)
    }

    for (int i = 0; i < t; i++)
    {
        cout<< std::setprecision(33) <<a[i]<<"\n";
    }
    
    return 0;
}