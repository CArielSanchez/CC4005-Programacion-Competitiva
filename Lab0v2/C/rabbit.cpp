#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases;
    cin>>cases;

    double n[cases][4];

    for (size_t i = 0; i < cases; i++)
    {
        cin>>n[i][0]>>n[i][1]>>n[i][2]>>n[i][3];
    }

    int r[cases];
    double sec = 0.0;
    for (size_t i = 0; i < cases; i++)
    {
        sec = (n[i][1] - n[i][0]) / (n[i][2] + n[i][3]);

        if((sec - (int) sec) == 0){

            r[i] = sec;
        }else{
            r[i] = -1;
        }
        sec = 0;
    }

    for (size_t i = 0; i < cases; i++)
    {
        cout<<r[i]<<"\n";
    }
    
    return 0;
}