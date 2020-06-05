#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = pow(10, 9) + 7;

ll gcd(ll a,ll b) {
    ll R;
    while ((a % b) > 0)  {
        cout<<"gcd("<<a<<","<<b<<")\n";
        R = (a % b);
        a = b;
        b = R;
    }
    return b;
}

int main(){
    ll n;
    ll x;
    cin>>n>>x;
    
    ll nums[n];
    ll sum = 0;

    for (ll i = 0; i < n; i++)
    {
        cin>>nums[i];
        sum += nums[i];
    }
    //cout<<"sum: "<<sum<<"\n";
    ll t = (ll) pow(x, sum) % mod;
    ll s = 0;

    for (ll i = 0; i < n; i++)
    {
        s += (ll) pow(x, sum - nums[i]) % mod;
    }
    
    cout<<s<<"\n";
    cout<<t<<"\n";

    ll r = gcd(t, s);
    cout<<r % mod;
    return 0;
}
