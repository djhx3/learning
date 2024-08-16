#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const char nl = '\n';

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int count = 0;
    for (int i = 0; i < k-1; i++) {
        count+=2*a[i]-1;
    }
    cout << count << nl;
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
