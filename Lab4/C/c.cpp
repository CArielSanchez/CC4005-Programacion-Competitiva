#include <bits/stdc++.h>
using namespace std;
ifstream my_file;


int main(){
    my_file.open("input.txt");
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    // Input
    int N, M, K;
    my_file>>N>>M>>K;

    int x[K];
    int y[K];

    for (int i = 0; i< K; i++){
        my_file>>x[i]>>y[i];
        x[i]--;
        y[i]--;
    }


    // BFS
    vector<vector<vector<int>>> bfs(2, vector<vector<int>>(N, vector<int>(M, -1)));

    // Caso 0
    bfs[0][x[0]][y[0]] = 0; // Marcar el foco como distancia 0

    queue<pair<int, int> >cola;
    cola.push(pair<int,int>(x[0], y[0]));

    while(!cola.empty()){
        pair<int, int> nodo = cola.front();cola.pop(); // Saca un nodo de la cola
        int x1 = nodo.first, y1 = nodo.second;

        // Arriba
        if(y1 +1 < M && bfs[0][x1][y1+1] == -1){ // Está dentro del tablero y no lo he revisado
            bfs[0][x1][y1+1] = bfs[0][x1][y1] + 1;
            cola.push(pair<int,int>(x1, y1 + 1));
        }
        // Abajo
        if(y1 -1 >= 0 && bfs[0][x1][y1-1] == -1){ // Está dentro del tablero y no lo he revisado
            bfs[0][x1][y1-1] = bfs[0][x1][y1] + 1;
            cola.push(pair<int,int>(x1, y1 - 1));
        }
        // Derecha
        if(x1 + 1 < N && bfs[0][x1+1][y1] == -1){ // Está dentro del tablero y no lo he revisado
            bfs[0][x1+1][y1] = bfs[0][x1][y1] + 1;
            cola.push(pair<int,int>(x1+1, y1));
        }
        // Izquierda
        if(x1 - 1 >= 0 && bfs[0][x1-1][y1] == -1){ // Está dentro del tablero y no lo he revisado
            bfs[0][x1-1][y1] = bfs[0][x1][y1] + 1; // Pongo la distancia hasta yo, +1
            cola.push(pair<int,int>(x1-1, y1));    // Agregar a la cola
        }
    }

    // Resto
    for (int i = 1; i< K; i++){
        bfs[1][x[i]][y[i]] = 0; // Marcar el foco como distancia 0

        queue<pair<int, int> >cola;
        cola.push(pair<int,int>(x[i], y[i]));

        while(!cola.empty()){
            pair<int, int> nodo = cola.front();cola.pop(); // Saca un nodo de la cola
            int x1 = nodo.first, y1 = nodo.second;

            // Arriba
            if(y1 +1 < M && bfs[1][x1][y1+1] == -1){ // Está dentro del tablero y no lo he revisado
                bfs[1][x1][y1+1] = bfs[1][x1][y1] + 1;
                cola.push(pair<int,int>(x1, y1 + 1));
            }
            // Abajo
            if(y1 -1 >= 0 && bfs[1][x1][y1-1] == -1){ // Está dentro del tablero y no lo he revisado
                bfs[1][x1][y1-1] = bfs[1][x1][y1] + 1;
                cola.push(pair<int,int>(x1, y1 - 1));
            }
            // Derecha
            if(x1 + 1 < N && bfs[1][x1+1][y1] == -1){ // Está dentro del tablero y no lo he revisado
                bfs[1][x1+1][y1] = bfs[1][x1][y1] + 1;
                cola.push(pair<int,int>(x1+1, y1));
            }
            // Izquierda
            if(x1 - 1 >= 0 && bfs[1][x1-1][y1] == -1){ // Está dentro del tablero y no lo he revisado
                bfs[1][x1-1][y1] = bfs[1][x1][y1] + 1; // Pongo la distancia hasta yo, +1
                cola.push(pair<int,int>(x1-1, y1));    // Agregar a la cola
            }
        }

        // Tomar los mínimos de las BFS y guardar en bfs[0]
        for(int n = 0; n<N;n++){
            for(int m = 0;m<M;m++){
                if(bfs[1][n][m] < bfs[0][n][m]){
                    bfs[0][n][m] = bfs[1][n][m];
                }
                bfs[1][n][m] = -1; // Reset Matriz
            }
        }
    }

    // Buscar el máximo de los mínimo
    int max = INT_MIN;
    int xx;
    int yy;

    for(int n = 0; n<N;n++){
        for(int m = 0;m<M;m++){
            if(bfs[0][n][m] > max){
                max = bfs[0][n][m];
                xx = n;
                yy = m;
            }
        }
    }

    ofstream my_file_o;
    my_file_o.open("output.txt");
    my_file_o<<xx+1<<" "<<yy+1;
    return 0;
}
