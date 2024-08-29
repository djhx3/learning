#include<bits/stdc++.h>
#include<string>
using namespace std;

using ll=long long;
const char nl = '\n';

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll j = 0; j < n; j++) {
        cin >> a[j];
    }
    while (q--) {
        ll i, x;
        cin >> i >> x;
        ll level = 1;
        ll count = 0;
        if(i==1){
            cout<<"YES"<<nl;
            continue;
        }
        else if(i<=x){
            cout<<"YES"<<nl;
            continue;
        }
        for (ll j = 0; j < i - 1; j++) {
            if (level <= a[j]) count++;
            if (count == x) {
                level++;
                count = 0;
            }
        }
        if (level <= a[i - 1]) cout << "YES" << nl;
        else cout << "NO" << nl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}