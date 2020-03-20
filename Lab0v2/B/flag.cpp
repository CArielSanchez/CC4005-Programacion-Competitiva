#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m; // fila, columna
    bool result = true;

    cin>>n>>m;

    int r[n][m];
    string a[n];

    for(int i=0; i<n;i++){
        cin>>a[i];

        for(int j=0;j<m;j++){
            r[i][j] = (int) a[i].at(j) - '0';

        }
    }

    int anterior = -1;
    int color = -1;
    
    for(int i=0; i<n;i++){
        if(i != 0 && anterior == r[i][0]){ // Next different from before
            result = false;
            break;
        }

        color = r[i][0];

        for(int j=1;j<m;j++){ // ROW SAME COLOR
            if(color != r[i][j]){
                result = false;
                break;
            }
        }
        anterior = color;
        if(!result){
            break;
        }
    }

    result? cout<<"YES" : cout<<"NO";
    return 0;
}