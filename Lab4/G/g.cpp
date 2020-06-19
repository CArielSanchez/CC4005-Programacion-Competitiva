#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> p(n+1, 0);
    for(int i = 1; i <= n; i++){
        cin>>p[i];
    }

    vector<int> VISITED(n+1, -1);
    vector<int> response;

    for(int i = 1; i <= n; i++){
        int actual = i;

        while(true){
            if(VISITED[actual] == 1){
                response.push_back(actual);
                break;
            }

            VISITED[actual] = 1; // Visito a p[i]
            actual = p[actual];       // Veo el siguiente
        }
        fill(VISITED.begin(), VISITED.end(), -1);
    }

    // Out
    for(int i = 0; i< n-1; i++){
        cout<<response[i]<<" ";
    }
    cout<<response[n-1];
    return 0;
}