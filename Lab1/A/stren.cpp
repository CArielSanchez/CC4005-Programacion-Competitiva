#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t; // Numero casos
    
    int strg[t];
    int intelect[t];
    int exp[t];
    
    for(int i=0; i<t;i++){
    
    cin>>strg[i];
    cin>>intelect[i];
    cin>>exp[i];
      
    }
    
    int resp[t];
    double strr = 0;
    double intt = 0;
    double expp = 0;
    
    
    
    for(int i=0; i<t; i++){
      strr = (double) strg[i];
      intt = (double) intelect[i];
      expp = (double) exp[i];
       
      // Caso A: str <= int
      if(strr <= intt){
        int used = (intt - (strr + expp) ); // strr + 1 = expp
        //
        if(used >= 0){
          resp[i] = 0; // No hay puntos suficientes para que strr > intt
        }else{
          resp[i] = ((int) floor((expp + strr -intt + 1)/2 ) ); 
        }
        
      // Caso B: str > int
      }else{
        int diff = ((strr + expp) - intt + 1) / 2 ; // Cuanto es la distancia
        int total = expp + 1;
        resp[i] = min(diff, total);
      }
    }
    
    for(int i=0; i<t; i++){
      cout<<resp[i]<<"\n";
    }
    
    return 0;
}
