#include<bits/stdc++.h>
#include<string>
using namespace std;

using ll=long long;
const char nl = '\n';

void solve(){
    int a[2], b[2];
    cin>>a[0]>>a[1]>>b[0]>>b[1];
    int ans=0;
    for (int i = 0; i < 2; i++)
    {
        
        for (int j = 0; j < 2; j++)
        {
            int win=0, loss=0;
            if(a[i]>b[j]) win++;
            else if(b[j]>a[i]) loss++;
            if(a[1-i]>b[1-j]) win++;
            else if(a[1-i]<b[1-j]) loss++;
            if(win>loss) ans++;
        }
        
    }
    cout<<ans<<nl;
    
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