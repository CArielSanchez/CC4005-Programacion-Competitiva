#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
string s;

int calcDP(int i, int j){
    if(dp[i][j] != -1){
        return dp[i][j];
    }else{
        if(s[i] == s[j]){
            int x = calcDP(i+1, j-1);
            dp[i][j] = x;
            return x;
        }else{
            int x = min(1+calcDP(i+1, j),1+calcDP(i, j-1));
            dp[i][j] = x;
            return x;
        }
    }
}

int main(){
    int t;
    cin>>t;
    int n = t;
    int r[t];
    while (t)
    {   
        dp.assign(6100, vector<int>(6100,-1));
        for (int i = 0; i < 6099; i++)
        {
            dp[i][i] = 0;
            dp[i+1][i] = 0;
        }
        dp[6099][6099] = 0;


        cin>>s;
        r[t-1] = calcDP(0, s.length()-1);
        t--;
    }

    for (int i = n-1; i >= 0; i--)
    {
        cout<<r[i]<<"\n";
    }
    
    return 0;
}
