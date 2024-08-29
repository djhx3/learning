#include<bits/stdc++.h>
#include<string>
using namespace std;

using ll=long long;
const char nl = '\n';

ll Log(ll a){
    a/=3;
    ll count=0;
    while(a){
        a/=3;
        count++;
    }
    return count;
}

void solve(){
    ll l, r;
    cin >> l >> r;
    // ll diff = r - l + 1;
    ll start = Log(l)+1;
    ll end = Log(r) + 1;
    // ll count = 0;
    // ll temp1 = 0;
    // ll temp = 0;
    // for (ll i = start; i < end; i++)
    // {
    //     temp = (ll) pow(3, i);
    //     temp1=max(l,temp/3);
    //     temp=min(temp,r);
    //     count+=(temp - temp1 + 1)*i;
    //     cout<<"PROCESS - "<< count <<nl;
    // }
    // count+=(r-temp+1)*end;
    // //count+=start-end+1;
    // cout<<"PROCESS - "<<count<<nl;
    // if(start==end) count = (diff + 1)*(start);
    // // vector<ll> a(diff);
    // // for (ll i = 0; i < diff; i++)
    // // {
    // //     a[i] = l + i;
    // // }
    // // sort(a.begin(), a.end());
    // // ll count = 0;
    // // for (ll i = 0; i < diff; i++)
    // // {
    // //     count+=((Log2(a[i])/Log2(3))+1);
    // //     if(i==diff-1) count+=((log2(a[i])/log2(3))+1);
    // // }
    // // // cout << count << nl;
    // // ll change = ((Log2(a[0]))/(Log2(3))+1);
    // // for (ll i = 0; i < diff; i++)
    // // {
    // //     ll change1 = ((Log2(a[i])/Log2(3))+1);
    // //     if(change<change1){
    // //         count--;
    // //         change = ((Log2(a[i])/Log2(3))+1);
    // //         // cout << a[i] << " - " << count << nl;
    // //     }

    // // }
    int count=0;
    int k = 0;
    if(start==end) count = (r - l + 2)*(start);
    else for (int i = start; i <= end; i++)
    {
        k = (ll) pow(3, i);
        if(i==start){
            count += (k - l + 1)*i;
        }
        else if(i==end){
            count += (r - (k/3) + 1)*i;
        }
        else{
            count += (k - (k/3))*i;
        }
    }
    cout << count << nl;
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