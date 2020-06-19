#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
enum color{UNVISITED, IN_STACK, VISITED };
vector<color> state;

void dfs_visit(int u){
    state[u]=VISITED;
    for (int v : graph[u]){
        if(state[v]==IN_STACK){
            dfs_visit(v);
        }
    } 
}

int main(){
    int conexo=0;
    int n,m;
    cin>>n>>m;
    state.resize(n+1);
    graph.resize(n+1);
    
    // Todos los nodos parten como no visitados
    for(int i=1;i<=n;i++){
        state[i]=UNVISITED;
    }

    // A cada nodo le appendeo lista de nodos vecinos (concetados por arco)
    for(int i=1;i<=m;i++){
        int u;
        int v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        state[u]=IN_STACK; // Por revisar
        state[v]=IN_STACK;
    }

    for(int i=1;i<=n;i++){
        if(state[i]==IN_STACK){
            conexo++;
            dfs_visit(i);
        }
        if(state[i]==UNVISITED){
            conexo++;
        }
    }
    if(conexo==1 && n == m){ // n==m ==== un sólo ciclo
        cout<<"FHTAGN!";
        return 0;
    }
    cout<<"NO";
    return 0;
}


