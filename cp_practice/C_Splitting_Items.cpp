#include<bits/stdc++.h>
#include<string>
using namespace std;

using ll=long long;
const char nl = '\n';

ll minel(vector<ll>::iterator a1, vector<ll>::iterator a2){
    auto min = min_element(a1,a2);
    ll ans = distance(a1, min);
    return ans;
}

void solve(){
    ll n, k;
    cin>>n>>k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(a.begin(), a.end(), greater<ll>());
    int ascore = 0, bscore=0;
    for (ll i = 0; i < n; i++)
    {
        if(i%2==0){
            ascore+=a[i];
        }
        else{
            ll m1 = min(a[i-1]-a[i], k);
            bscore+=a[i]+m1;
            k-=m1;
        }
    }
    // if(ascore - bscore <= k){
    //     cout<<"0"<<nl;
    //     return;
    // }
    // bscore+=k;
    cout<<ascore-bscore<<nl;
    a.clear();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}