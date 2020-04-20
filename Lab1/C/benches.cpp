#include <bits/stdc++.h>
using namespace std;

int main(){
    int respuesta[2]; // min y max
    
    int visitantes;
    int nbancas;
    
    cin>>nbancas;
    cin>>visitantes;
    int maximo= -1;
    int minimo=INT_MAX;
    int bancas[nbancas];
    
    for(int i=0;i<nbancas;i++){
      cin>>bancas[i];
      if(bancas[i]>maximo){
        maximo=bancas[i];
      }
      if(bancas[i]<minimo){
        minimo=bancas[i];
      }
    }
    // MAXIMO
    respuesta[1]= maximo + visitantes;
    
    // MINIMO
    int min = INT_MAX;
    int index = 0;
    int restantes = visitantes;
    while(restantes > 0){
        for (size_t i = 0; i < nbancas; i++)
            {
                if(bancas[i] <= min){
                    index = i;
                    min = bancas[i];
                }
            }
            bancas[index]++; // Puse persona
            restantes--;
            min= INT_MAX; // Reset
    }
    int max= -1;
    for (size_t i = 0; i < nbancas; i++)
            {
                if(bancas[i] >= max){
                    max = bancas[i];
                }
            }
    
    respuesta[0] = max;
    cout<<respuesta[0]<<" "<<respuesta[1];
    
    return 0;
}