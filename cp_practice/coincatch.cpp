#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int x, y;
        cin>>x>>y;
        // if(y>=0 || (y<0&&(abs(x)-abs(y))>=(abs(x)-1)))
        // {
        //     cout<<"YES\n";
        // }
        // else{
        //     cout<<"NO\n";
        // }
        // EASIER WAY BELOW
        cout<<(y>=-1?"YES\n":"NO\n");
    }
    
    return 0;
}