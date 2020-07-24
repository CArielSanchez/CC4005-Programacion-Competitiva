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

    wgraph grafo(n+1, vector<ii>());

    long long v, u, w;
    for (long long i = 0; i < m; i++)
    {   
        cin>>v>>u>>w;
        grafo[v-1].push_back(ii(2*w, u-1));
        grafo[u-1].push_back(ii(2*w, v-1));
    }
    // N
    long long a;
    for (long long i = 0; i < n; i++)
    {
        cin>>a;
        grafo[n].push_back(ii(a, i));
        grafo[i].push_back(ii(a, n));
    }
    
    //// DIJSKTRA
    vi distancia;
    distancia.assign(n+1, 1e14);
    vi padre;
    padre.assign(n+1, 1e14);
    Dijsktra(n, grafo, distancia, padre); // Desde el nodo concierto

    for (long long i = 0; i < n; i++)
    {
        cout<<distancia[i]<<" ";
    }
    
    return 0;
}


