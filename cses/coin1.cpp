#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

const long long MOD = 1e9 +7;
const int maxx = 1e6;


// int fun2(int n, int x, int a[], long long dp[]){      
//     for (int i = 0; i <= x; i++)
//     {
//         if(dp[i]!=0){
//             for (int j = 0; j < n; j++)
//             {
//                 if(i+a[j]<=x) dp[i+a[j]] = (dp[i+a[j]]+dp[i])%MOD;
//             }
//         }
//     }
//     return dp[x]%MOD;
// }


    int n, x;
    int a[100];
    long long dp[maxx+1];

int main(){
    scanf("%d %d", &n, &x);
    for (int i = 0; i < x+1; i++)
    {
        dp[i]=0;
    }
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    dp[0] = 1;
    for (int i = 0; i <= x; i++)
    {
        if(dp[i]!=0){
            for (int j = 0; j < n; j++)
            {
                if(a[j]+i<=x) dp[i+a[j]] = (dp[i+a[j]]+dp[i])%MOD;      //traversing all coins for every single dp
            }
            
        }
    }
    
    printf("%lld\n", dp[x]%MOD);    
}