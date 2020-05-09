#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vll2;
vector<vll2> dp;
ll k1, k2;
ll mod = pow(10, 8);

ll calcDP(ll i, ll j, ll footmen){
    // cout<<"A\n";
    // cout<<dp[i][j][footmen];
    if(i < 0 || j < 0){ // Puse más de los que necesitaba poner. Caso no existe
        // cout<<"i: "<<i<<" j: "<<j<<"return 0\n";
        return 0;
    
    }else if(i == 0 && j ==0){ // Puse justo todos los horsemen y footmen
        // cout<<"i: "<<i<<" j: "<<j<<"return 1\n";
        return 1;
    }

    if(dp[i][j][footmen] != -1){
        // cout<<"Valor ya calculado\n";
        return dp[i][j][footmen] % mod;
    }
    // cout<<"B\n";
    
    // cout<<"C\n";
    if(footmen == 1){
        // cout<<"footmen\n";
        if(i == 0 && j > 0){ // No puedo poner más footmen
            // cout<<"No puedo poner más footmen i: "<<i<<" j: "<<j<<"return 0\n";
            return 0;
        }
        ll x = 0;
        for (ll k = 1; k <= k1; k++)
        {
            // cout<<"Llamada recursiva i: "<<i-k<<" j: "<<j<<" footmen: "<<0<<"\n";
            ll t = calcDP(i-k, j, 0) % mod;
            // cout<<"dp["<<i-k<<"]["<<j<<"]["<<0<<"] = "<<x<<"\n";
            if(i-k > 0)
                dp[i-k][j][0] = t % mod;
            x += t % mod;
        }
        // cout<<"dp["<<i<<"]["<<j<<"]["<<1<<"] = "<<x<<"\n";
        dp[i][j][1] = x % mod;
        return x % mod;
        
    }else{
        // cout<<"horsemen\n";
        if(j == 0 && i > 0){ // No puedo poner más horsemen
            // cout<<"No puedo poner más horsemen i: "<<i<<" j: "<<j<<"return 0\n";
            return 0;
        }
        ll x = 0;
        for (ll k = 1; k <= k2; k++)
        {
            // cout<<"Llamada recursiva i: "<<i<<" j: "<<j-k<<" footmen: "<<1<<"\n";
            ll t = calcDP(i, j-k, 1) % mod;
            // cout<<"dp["<<i<<"]["<<j-k<<"]["<<0<<"] = "<<x<<"\n";
            if(j-k > 0)
                dp[i][j-k][1] = t % mod;
            x += t % mod;
        }
        // cout<<"dp["<<i<<"]["<<j<<"]["<<0<<"] = "<<x<<"\n";
        dp[i][j][0] = x % mod;
        return x % mod;
    }
}

int main(){
    ll n1, n2;
    cin>>n1>>n2>>k1>>k2;
    dp.assign(n1+1, vll2(n2+1, vll(2, -1)));
    // cout<<"assign completed\n";
    ll f = calcDP(n1, n2, 1);
    //cout<<f;
    ll h = calcDP(n1, n2, 0);
    //cout<<h;
    cout<<((f+h)%mod);
    return 0;
}
