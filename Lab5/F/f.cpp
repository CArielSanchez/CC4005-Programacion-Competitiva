#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vector<ii> > wgraph;
typedef vector<ll> vi;

void Dijsktra(ll s, wgraph &M, vi &dist, vi &p) {
	dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));

	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		ll d = front.first, u = front.second;
		if (d > dist[u]) continue;
		
		//cout << u+1 << endl;

		for (ll j = 0; j < M[u].size(); j++) {
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
    ll t;
    cin>>t;
    ll ans[t];
    ll i = 0;
    ll topleft = 0;

    while(i < t){
        //// INPUT
        ll n,m;
        cin>>n>>m;
        wgraph grafo(n*m, vector<ii>());
        ll w;

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin>>w;
                if(i==0 && j ==0){
                    topleft = w;
                }

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
        distancia.assign(n*m, INT_MAX);
        vi padre;
        padre.assign(n*m, INT_MAX);
        Dijsktra(0, grafo, distancia, padre);
        // for (int i = 0; i < n*m; i++)
        // {
        //     cout<<padre[i]<<" ";
        // }
        //cout<<distancia[n*m-1]  << endl;
        ans[i] = distancia[n*m-1] + topleft;
        i++;
        //t--;
    }
    for (ll j = 0; j < t; j++)
    {
        cout<<ans[j]<< endl;
    }
    

    return 0;
}


