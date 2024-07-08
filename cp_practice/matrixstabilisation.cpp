#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const char nl = '\n';

int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

int inmatrix(int i, int j, int n, int m)
{
    return (i>=0 && i<n && j>=0 && j<m);
}

void solve()
{
    ll n, m;
    cin>>n>>m;
    ll a[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ll temp=0;
            for(int k=0; k<4; k++)
            {
                int x=i+dx[k];
                int y=j+dy[k];
                if(inmatrix(x, y, n, m))
                {
                    temp=max(temp,a[x][y]);
                }
            }
            a[i][j]=min(temp, a[i][j]);
        }
        
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<nl;
    }        
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