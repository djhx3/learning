//Name: Dhruva J Herrick
//Roll No: 23CS30017
//Assignment  Question 
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<math.h>

int dp[1000];
int web1[1000];
int web2[1000];

int max(int x, int y){
    return (x>y)? x:y;
}

int solve(int n, int i, int lastin){
    if(i==n-1&&lastin==0) return max(web1[i], web2[i]);
    if(i==n-1) return web1[i];
    if(dp[i]!=0) return dp[i];
    int down, notdown;
    if(lastin == 0) down = solve(n,i+1,1) + max(web1[i], web2[i]);
    else down = solve(n,i+1,1)+web1[i];
    notdown = solve(n,i+1,0);
    dp[i] = max(down, notdown);
    printf("%d - %d\n", i, dp[i]);
    return dp[i];
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &web1[i], &web2[i]);
    }
    int ans = solve(n,0,0);
    printf("%d\n", ans);
    return 0;
}