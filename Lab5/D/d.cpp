#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vector<ii> > wgraph;

typedef vector<int> vi;

void Dijsktra(int s, wgraph &M, vi &dist, vi &p) {
	dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));

	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if (d > dist[u]) continue;
		
		//cout << u+1 << endl;

		for (int j = 0; j < M[u].size(); j++) {
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
    int n,d;
    cin>>n>>d;

    vector<int> wei(n, 0);

    for (int i = 1; i < n-1; i++)
    {
        cin>>wei[i];
    }
    
    
    vii coord(n, pair<int, int>());

    int x,y;
    for (int i = 0; i < n; i++)
    {   
        cin>>x>>y;
        coord[i] = ii(x, y);
    }

    // grafo
    wgraph grafo(n, vector<ii>());

    for (int i = 0; i < n; i++)
    {   
        for (int j = 0; j < n; j++)
        {
            if(i != j){
                int distancia = ( (abs(coord[i].first - coord[j].first)) + (abs(coord[i].second - coord[j].second)) );
                grafo[i].push_back(ii(d*distancia - wei[j], j));
                grafo[j].push_back(ii(d*distancia - wei[i], i));
            }
        }
    }

    //// DIJSKTRA
    vi distancia;
    distancia.assign(n, INT_MAX/2);
    vi padre;
    padre.assign(n, INT_MAX/2);
    Dijsktra(0, grafo, distancia, padre); // Desde el nodo concierto

    cout<<distancia[n-1]<<"\n";

    return 0;
}


