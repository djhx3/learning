#include<bits/stdc++.h>
#include<string>
using namespace std;

using ll=long long;
const char nl = '\n';
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    char m[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>m[i][j];
        }
    }
    if(m[0][0]=='*'){
        cout<<"0"<<nl;
        return;
    }
    int dp[n][n];
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==0&&j==0) continue;
            if(m[i][j]=='*') dp[i][j] = 0;
            else{
                if(i>0&&j>0){
                    dp[i][j] =(dp[i-1][j] + dp[i][j-1])%MOD;
                }
                else if(i>0){
                    dp[i][j] = dp[i-1][j];
                }
                else if(j>0){
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        
    }
    cout<<dp[n-1][n-1]<<nl;
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