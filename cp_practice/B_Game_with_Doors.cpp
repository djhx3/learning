#include<bits/stdc++.h>
#include<string>
using namespace std;

using ll=long long;
const char nl = '\n';

void solve(){
    ll l, r, L, R;
    cin>>l>>r>>L>>R;
    if((l<L&&r<R&&r<L)||(L<l&&R<r&&R<l)){
        cout<<"1"<<nl;
    }
    else if((l<L&&r>R)){
        cout<<R-L+2<<nl;
    }
    else if(L<l&&R>r){
        cout<<r-l+2<<nl;
    }
    else if((l<L&&r<R)){
        cout<<r-L+2<<nl;
    }
    else if((L<l&&R<r)){
        cout<<R-l+2<<nl;
    }
    else if(L==l&&r==R){
        cout<<r-l<<nl;
    }
    else if(l==L&&r>R){
        cout<<R-L+1<<nl;
    }
    else if(l==L&&r<R){
        cout<<r-L+1<<nl;
    }
    else if(l<L&&r==R){
        cout<<r-L+1<<nl;
    }
    else if(l>L&&r==R){
        cout<<R-l+1<<nl;
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