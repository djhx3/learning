#include<bits/stdc++.h>
#include<string>
using namespace std;

using ll=long long;
const char nl = '\n';
const int maxx = 1e6;

// int solve2(int n, int x, int i, vector<int>& c, vector<int>& pg){
//     if(x==0) return 0;
//     if(i>=n) return 0;
//     if(dp[x]!=-1) return dp[x];
//     int take=0, nottake=0;
//     if(c[i]<=x){
//         take = solve2(n, x-c[i], i+1, c, pg)+pg[i];
//     }
//     nottake = solve2(n, x, i+1, c, pg);
//     dp[x] = max(take, nottake);
//     return dp[x];
// }

vector<int> dp;

void solve(){
    int n, x;
    cin>>n>>x;
    vector<int> c(n), pg(n);
    for (int i = 0; i < n; i++)
    {
        cin>>c[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>pg[i];
    }
    dp.assign(x+1, -1); // Reset dp vector for each test case
    // int ans = solve2(n,x,0,c,pg);
    dp[0]=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = x-c[i]; j >= 0; j--)
        {
            if(dp[j] != -1){
                dp[j+c[i]] = max(dp[j]+pg[i], dp[j+c[i]]);
            }
        }
        
    }
    for (int i = 1; i < x+1; i++)
    {
        dp[i] = max(dp[i], dp[i-1]);
    }
    
    int ans = dp[x];
    cout<<ans<<nl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}