#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const char nl = '\n';

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        ll n, k;
        cin>>n>>k;
        cout<<k*(n-1)+1<<nl;
    }
    return 0;
}