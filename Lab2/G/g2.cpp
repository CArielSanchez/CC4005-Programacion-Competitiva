#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    long long int fila0 [n];
    long long int fila1 [n];
    long long int Table[2][n]; 
    char * s1 = new char[n];
    cin>>s1;
    
    char* s2 = new char[n];
    cin>>s2;

    for (int i = 0; i < n; i++)
    {
        fila0[i] = s1[i] - '0';
    }
    
    for (int i = 0; i < n; i++)
    {
        fila1[i] = s2[i] - '0';
    }
    for(int i=0;i<n;i++){
        if(i==0){
            if(fila0[i]==fila1[i]){
            Table[0][i]=0;
            Table[1][i]=0;
            }
            if(fila0[i]!=fila1[i]){
            Table[0][i]=1;
            Table[1][i]=1;
            }
        }
        else{

            if(fila0[i]==fila1[i]){
                Table[0][i]=0;
                Table[1][i]=Table[1][i-1];
            }
            if(fila0[i]!=fila1[i]){
                if(Table[0][i-1]==0){
                   Table[0][i]=1;
                   Table[1][i]=Table[1][i-1]+1;
                }
                if(Table[0][i-1]==1){
                    if(fila0[i-1]==fila0[i]){
                        Table[0][i]=1;
                        Table[1][i]=Table[1][i-1]+1;
                    }
                    else{
                        Table[0][i]=2;
                        Table[1][i]=Table[1][i-1];
                    }
                }
                if(Table[0][i-1]==2){
                    if(fila0[i]==fila1[i]){
                        Table[0][i]=0;
                        Table[1][i]=Table[1][i-1];
                    }
                    else{
                        Table[0][i]=1;
                        Table[1][i]=Table[1][i-1]+1;
                    }
                }
            }
    }

    }
    cout<<Table[1][n-1];

    }