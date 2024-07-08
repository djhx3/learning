#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll solve(){
    int n;
    cin>>n;
    ll a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    ll premax=0, diff=0, sum=0, count=0;
    for (int i = 0; i < n; i++)
    {
        premax=max(premax, a[i]);
        diff=premax-a[i];
        sum+=diff;
        count=max(count, diff); //count is the max difference between any two elements which is the number of times indices will be selected
    }
    return count+sum;
    
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        // int n;
        // int count=0;
        // cin>>n;
        // for (int i = 1; i < n; i++)
        // {
        //     if(a[i]<a[i-1])
        //     {
        //         maxdiff=max(maxdiff, a[i-1]-a[i]);
        //     }
        // }
        // for(int j=0; j<maxdiff; j++)
        // {
        //     for(int i=1; i<n; i++)
        //     {
        //         if(a[i]<a[i-1])
        //         {
        //             a[i]++;
        //             count++;
        //         }
        //     }
        //     if(count==0) break;
        //     else count++;
        // }
        //More optimised below
        
        cout<<solve()<<endl;
        
    }

    
    return 0;
}