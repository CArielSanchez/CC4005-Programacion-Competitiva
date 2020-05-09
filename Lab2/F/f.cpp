#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = pow(10, 9) + 7;
vector<vector<ll>> dp;

ll calcDP(ll i, ll j, ll n, ll m){
    if(dp[i][j] != -1){
        // cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<" Ya calculado\n";
        return dp[i][j];
    }else{
        if(i == 2*m){
            // cout<<i<<" = 2*"<<m<<" => return 1\n";
            dp[i][j] = 1;
            return 1;
        }
        ll x = 0;
        for (ll z = j; z <= n; z++)
        {
            // cout<<"Llamada a ("<<i+1<<","<<z<<")\n";
            ll l = calcDP(i+1, z, n, m) % mod;
            dp[i+1][z] = l % mod;
            x += l % mod;
        }
        dp[i][j] = x % mod;
        // cout<<"dp["<<i<<"]["<<j<<"] = "<<x<<"\n";
        return x % mod;
    }
}

int main(){
    ll n;
    ll m;
    cin>>n>>m;
    dp.assign(2*m+1, vector<ll>(2*n+1, -1));
    ll r = 0;
    for (ll i = 1; i <= n; i++)
    {
        r+= calcDP(1, i, n, m) % mod;
    }
    
    cout<<r % mod;
    return 0;
}
