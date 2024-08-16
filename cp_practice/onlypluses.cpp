#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const char nl = '\n';

void solve(){
    array<int, 3> a;
    cin >> a[0] >> a[1] >> a[2];
    for (int i = 0; i < 5; i++)
    {
        *min_element(a.begin(), a.end()) += 1;
    }
    
    cout << a[0]*a[1]*a[2] << nl;
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
