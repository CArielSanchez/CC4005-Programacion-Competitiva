#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> ii;
typedef vector<ii> vii;
typedef vector<vector<ii> > wgraph;

typedef vector<long long> vi;

void Dijsktra(long long s, wgraph &M, vi &dist, vi &p) {
	dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));

	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		long long d = front.first, u = front.second;
		if (d > dist[u]) continue;
		
		//cout << u+1 << endl;

		for (long long j = 0; j < M[u].size(); j++) {
			ii v = M[u][j];
			if (dist[u] + v.first < dist[v.second]) {
				dist[v.second] = dist[u] + v.first;
				pq.push(ii(dist[v.second], v.second));

				p[v.second] = u;
			}
		}
	}
}

int main(){
    //// INPUT
    long long n,m;
    cin>>n>>m;

    wgraph grafo(n, vector<ii>());

    long long v, u, w;
    for (long long i = 0; i < m; i++)
    {   
        cin>>v>>u>>w;
        grafo[v-1].push_back(ii(w, u-1));
        grafo[u-1].push_back(ii(w, v-1));
    }
    //// DIJSKTRA
    vi distancia;
    distancia.assign(n, 1e14);
    vi padre;
    padre.assign(n, 1e14);
    Dijsktra(0, grafo, distancia, padre);

    /// HAY CAMINO ?
    if(distancia[n-1] == 1e14){
        cout<<-1;return 0;
    }
    //cout<<"distancia: "<< distancia[n-1]<< endl;

    // SACRIFICAR COMPUTO POR MEMORIA (BUSQUEDA LINEAL)
    // long long p = 0;
    // while(p != n-1){
    //     cout<<p+1<<" ";
    //     for (long long i = 0; i < n; i++){ // Busco a mi hijo
    //         if(padre[i] == p){ // Si yo soy el padre de este niño
    //             p = i; // El es mi heredero
    //             break;
    //         }
    //     }
    //     p = padre[p];
    // }
    // cout<<p+1;


    /// CAMINO INVERSO
    vector<long long> road(0, 0);
    road.push_back(n-1 + 1);
    long long father = padre[n-1];
    road.push_back(father + 1);
    while(father != 0){
        father = padre[father];
        //cout<<father;
        road.push_back(father + 1);
        if(father == 0) break;
    }

    /// CAMINO CORRECTO
    for (long long i = road.size() - 1; i >= 0; i--){cout<<road[i]<<" ";}
    return 0;
}


