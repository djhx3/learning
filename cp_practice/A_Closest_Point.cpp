#include<bits/stdc++.h>
#include<string>
using namespace std;

using ll=long long;
const char nl = '\n';

void solve(){
    int n;
    cin>>n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin>>x[i];
    }
    if(n==2&&(x[1]-x[0])>1){
        cout<<"YES"<<endl;
        return;
    }
    else cout<<"NO"<<endl;
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