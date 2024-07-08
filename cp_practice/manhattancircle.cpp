#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const char nl = '\n';

void solve(){
    ll n, m;
    cin>>n>>m;
    char a[n][m];
    for (int i = 0; i < n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }
    int maxhash=0, maxhashrow=0, maxhashcol=0;
    for (int i = 0; i < n; i++)
    {
        int count=0;
        for(int j=0; j<m; j++)
        {            
            if(a[i][j]=='#') count++;
            if(count>=maxhash) maxhashrow=i;
            maxhash=max(maxhash, count);
        }
    }
    for (int i = 0; i < m; i++)
    {
        int count=0;
        for(int j=0; j<n; j++)
        {            
            if(a[j][i]=='#') count++;
            if(count>=maxhash) maxhashcol=i;
            maxhash=max(maxhash, count);
        }
    }
    cout<<maxhashrow+1<<" "<<maxhashcol+1<<nl;
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