#include <bits/stdc++.h>
using namespace std;

char matrix[500][500];
bool visitados[500][500];
int n, m, k;

void marcar(int fila, int col){
    //cout<<"fila y col:"<<fila<<" "<<col<<"\n";

    if(fila < 0 || fila >= n){return;}
    if(col < 0 || col >= m){return;}
    if(visitados[fila][col] == true){return;}
    if(matrix[fila][col] != '.'){return;}
    // Ahora estoy parado en un punto
    // Visito a todos mis nodos adyacentes
    visitados[fila][col] = true;
    marcar(fila, col+1);
    marcar(fila, col-1);
    marcar(fila+1, col);
    marcar(fila-1,col);
    // Luego de sus retornos, vuelvo a YO
    if(k > 0){  // Si me faltan nodos que eliminar
        k--;    // Me elimino YO
        matrix[fila][col] = 'X'; 
    }
    return;
}

int main(){
    cin>>n>>m>>k;
    string a[n];

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = a[i].at(j);
        }
        
    }

    bool flag = false;
    // Encontrar un punto
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(matrix[i][j] == '.'){
                //cout<<"encontre punto";
                flag = true;
                marcar(i,j);
                break;
            }
        }
        if(flag){
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<matrix[i][j];
        }
        cout<<"\n";
    }


    return 0;
}


