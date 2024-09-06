#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

const long long MOD = 1e9 +7;
const int maxx = 1e6;

int n, x;
int a[100];
long long dp[maxx+1] = {0};

int main(){
    scanf("%d %d", &n, &x);    
    int map[n][x+1];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if(j+a[i]<=x)dp[j+a[i]] = (dp[j+a[i]]+dp[j])%MOD;       //traversing all dp for every single a[i] coin
        }
    }
    
    printf("%lld\n", dp[x]%MOD);    
}