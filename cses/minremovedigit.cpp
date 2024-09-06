#include<bits/stdc++.h>
#include<string>
using namespace std;

using ll=long long;
const char nl = '\n';

int maxDig(int n){
    char c[10];
    int i =0;
    while(n){
        c[i] = n%10;
        i++;
        n/=10;
    }
    int max1 = -1;
    for (int j = 0; j < i; j++)
    {
        if(c[j]>max1) max1 = c[j];
    }
    return max1;
}
void solve(){
    int n;
    scanf("%d", &n);
    int count =0;
    while(n){
        n = n-maxDig(n);
        count++;
    }
    cout<<count<<nl;
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