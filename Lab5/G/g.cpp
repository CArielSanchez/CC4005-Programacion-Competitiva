#include <bits/stdc++.h>
using namespace std;
#define MAX_NODES 100000

vector<int> vecinos[MAX_NODES]; // Para cada nodo tengo la lista de sus vecinos
int visitados[MAX_NODES]; // Lista de visitados
priority_queue<int, vector<int>, greater<int>> menores; // Garantiza que el menor está al inicio


int main(){
    int n, m, from, to;
    cin>>n>>m; // Nodos, Arcos
    for (int i = 0; i < m; i++)
    {
		cin>>from>>to;
		vecinos[from].push_back(to);
		vecinos[to].push_back(from);
    }
    for (int i = 0; i < MAX_NODES; i++) // Reset visitados
    {
        visitados[i] = -1;
    }
    

    visitados[1] = 1;
    menores.push(1); // El primero lo tengo listo

    int actual;
    while(!menores.empty()){
        actual = menores.top();menores.pop();
        cout<<actual<<" ";
        for (int i = 0; i < vecinos[actual].size(); i++)
        {
            int x = vecinos[actual][i];
            if(visitados[x] != 1){
                visitados[x] = 1;
                menores.push(x);
            }
        }
        
    }
    return 0;
}


