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
        ll n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        ll ind[n];
        for(int i=0; i<m; i++) cin>>ind[i];
        string c;
        cin>>c;
        sort(ind, ind+m);
        sort(c.begin(), c.end());
        ll count =m-1;
        for(int i=0; i<m-1; i++)
        {
            if(ind[i]==ind[i+1])
            {
                swap(c[i], c[count]);
                sort(c.begin()+i+1, c.end());
            }
        }
        for(int i=0; i<m; i++)
        {
            s[ind[i]-1]=c[i];
        }
        cout<<s<<nl;
    }
    return 0;
}
//idk why codeforces showing wrong answer for this code