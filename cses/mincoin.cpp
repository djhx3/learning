#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int fun(int n, int x, int a[], int dp[]){       //DID NOT WORK!
    
    if(dp[x]!=-1) return dp[x];
    int p, min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if(x>=a[i]) p = fun(n,x-a[i],a,dp);
        if(p<min) min = p;
    }
    dp[x] = min+1;
    return min+1;
}

int fun2(int n, int x, int a[], int dp[]){      //WORKS
    
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp = INT_MAX;
            if(a[j]<=i&&dp[i-a[j]]!=INT_MAX) temp = dp[i-a[j]]+1;
            if(temp<dp[i]) dp[i] = temp;
        }
        
    }
    if(dp[x] == INT_MAX) return -1;
    return dp[x];
}

int main(){
    int n, x;
    scanf("%d %d", &n, &x);
    int a[n], dp[x+1];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        dp[i]=INT_MAX;
    }
    printf("%d\n", fun2(n,x,a,dp));    
}