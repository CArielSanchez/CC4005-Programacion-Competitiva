#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases;
    cin>>cases;

    int n[cases][4];

    for (size_t i = 0; i < cases; i++)
    {
        cin>>n[i][0]>>n[i][1]>>n[i][2]>>n[i][3];
    }

    int r[cases];
    int a,b;
    int sec = 0;
    for (size_t i = 0; i < cases; i++)
    {
        if(n[i][0]==n[i][1]){
            r[i] = 0;
        }else{
            a=n[i][0]; //x
            b=n[i][1]; //y
            while(1){
                a+= n[i][2];
                b-= n[i][3];
                sec++;
                if(a == b){
                    r[i] = sec;
                    break;
                }
                if(a > b){
                    r[i] = -1;
                    break;
                }
            }
        }
        sec=0;
    }

    for (size_t i = 0; i < cases; i++)
    {
        cout<<r[i]<<"\n";
    }
    
    return 0;
}