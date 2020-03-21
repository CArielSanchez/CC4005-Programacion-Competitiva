#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;

    cin>>n>>s;

    int a[n];

    for (size_t i = 0; i < n; i++)
    {
        a[i] = (int) s.at(i) - '0';
    }

    int f[9];

    for (size_t i = 0; i < 9; i++)
    {
        cin>>f[i];
    }

    // Algorithm
    int result[n];
    bool aplique = false;
    bool stop = false;
  

    for (size_t i = 0; i < n; i++)
    {
        if(!stop){
            //cout<<"nonstop ";
            if(f[a[i]-1] > a[i] && !aplique){
                result[i] = f[a[i]-1];
                aplique = true;
                //cout<<"aplique true ahora\n";
            }
            else if(f[a[i]-1] > a[i] && aplique){
                result[i] = f[a[i]-1];
                //cout<<"aplique true, sigo\n";
            }else if (f[a[i]-1] < a[i] && aplique){
                result[i] = a[i];
                //cout<<"no me conviene, paro\n";
                stop = true;
            }else{
                result[i] = a[i];
                //cout<<"no me conviene, no aplioque. copio\n";
            }
        }else{
            //cout<<"stop\n";
            result[i] = a[i];
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        cout<<result[i];
    }
    return 0;
}