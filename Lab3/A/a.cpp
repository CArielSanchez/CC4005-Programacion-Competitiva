#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;

// ll gcd(ll a,ll b) {
//     ll R;
//     while ((a % b) > 0)  {
//         //cout<<"gcd("<<a<<","<<b<<")\n";
//         R = (a % b);
//         a = b;
//         b = R;
//     }
//     return b;
// }

ll fastPow(ll x, ll n){
    //cout<<"fastpow("<<x<<","<<n<<")\n";
    if (n == 0) return 1LL;
    ll mid = fastPow(x, n / 2) % mod;
    //cout<<"mid: "<<mid<<"\n";
    ll val = (mid * mid) ;
    if (n % 2 == 1) val = (val * x);
    return val;
}

ll findMax(ll array[], ll n){
    ll max = 0;
    for (ll i = 0; i < n; i++)
    {
        if(array[i] > max){
            max = array[i];
        }
    }
    return max;
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
    ll t = fastPow(x, sum);
    //cout<<t<<"\n";
    
    // for (ll i = 0; i < n; i++)
    // {
    //     s += (ll) fastPow(x, sum - nums[i]) % mod;
    // }
    ll max = findMax(nums, n);
    ll fact = fastPow(x, sum-max);
    ll fact2 = 0;
    for (ll i = 0; i < n; i++)
    {
        fact2 += fastPow(x, max-nums[i]);
        fact2 = fact2 % mod;
    }

    ll s = (fact * fact2);
    
    
    //cout<<s<<"\n";
    //cout<<t<<"\n";

    ll r = __gcd(t, s);
    cout<<r % mod;
    return 0;
}
