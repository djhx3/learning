#include<bits/stdc++.h>
#include<string>
using namespace std;

using ll=long long;
const char nl = '\n';

void solve(){
    int l = 1, r = 999;
    int temp=0;
    while(1){
        int a = (2*l+r)/3;
        int b = (l+2*r)/3;
        cout<<"? "<<a<<' '<<b<<endl;
        cin>>temp;
        if(temp==a*b){
            l=b;          
        }
        else if(temp == (a+1)*(b+1)){
            r=a;
        }
        else{
            l=a;
            r=b;
        }
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