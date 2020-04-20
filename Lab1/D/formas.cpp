#include<bits/stdc++.h>
using namespace std;
     
     
int main(void)
{
    int n;
    int total = 0;
    int resp=0;

    cin>>n;
    int a[n];
    for(int i=0; i < n ;i++){
        cin >> a[i];
        total += a[i];
    }
    
    
    
    if (total % 3 == 0)
    {
        int valor_g = total/3;
        int formas = 0;
        int sum = 0;
    

        for(int i=0;i<n-1;i++)
        {
            sum += a[i];
        if ( sum  == valor_g * 2) // Encontré el segundo conjunto: el que me da dos veces la suma dividida en 3, entonces esta la puedo permutar con las formas que ya encontré
            {
                resp += formas; // Entonces sumo la cantidad de formas que llevo porque el conjunto que encontré lo puedo permutar con todos los que llevo
                
        }
        
        if (sum == valor_g) // Encontré el primer conjunto: el que me da la primera suma
            formas++;
        }

            
            
    }
    cout<<resp;
}