#include <bits/stdc++.h>
using namespace std;

typedef unsigned short int ush;

typedef pair<ush, ush> ii;
typedef vector<ii> vii;
typedef vector<vector<ii> > wgraph;
typedef vector<ush> vi;

void Dijsktra(int s, wgraph &M, vi &dist, vi &p) {
	dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));

	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		ush d = front.first, u = front.second;
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
    ush t;
    cin>>t;
    while(t){
        //// INPUT
        ush n,m;
        cin>>n>>m;
        wgraph grafo(n*m, vector<ii>());
        ush w;

        for (ush i = 0; i < n; i++)
        {
            for (ush j = 0; j < m; j++)
            {
                cin>>w;

                if(j < m - 1){
                    grafo[i*m +j + 1].push_back(ii(w, i*m + j));    // siguiente -> yo
                }

                if(j>0){
                    //cout<<"back para i, j ="<<i<<","<<j<<" nodo base: "<<i*m+j<<" nodo anterior: "<<i*m+j-1<<endl;
                    grafo[i*m +j - 1].push_back(ii(w, i*m + j));    // anterior -> yo 
                }
                if(i > 0){
                    //cout<<"up para i, j ="<<i<<","<<j<<" nodo base: "<<i*m+j<<" nodo superior: "<<m*(i-1)+j<<endl;
                    grafo[m*(i-1)+j].push_back(ii(w, m*i+j));    // arriba -> yo
                }
                if(i < n - 1){
                    grafo[m*(i+1)+j].push_back(ii(w, m*i+j));    // abajo -> yo
                }

                
            }
        }
        //// DIJSKTRA
        vi distancia;
        distancia.assign(n*m, INT_MAX/2);
        vi padre;
        padre.assign(n*m, INT_MAX/2);
        Dijsktra(0, grafo, distancia, padre);
        // for (int i = 0; i < n*m; i++)
        // {
        //     cout<<padre[i]<<" ";
        // }
        cout<<distancia[n*m-1]  << endl;;

        t--;
    }
    return 0;
}


