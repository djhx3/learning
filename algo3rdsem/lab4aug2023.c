//Name: Dhruva J Herrick
//Roll No: 23CS30017
//Assignment  Question 
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<math.h>

#define maxln 1000

typedef struct machine{
    int points;
    int skip;
} mac;

mac m[maxln];
int dp[maxln];

int max(int x, int y){
    return (x>y)? x : y;
}

int maxpt(int n, mac m[], int i){
    if(i==n-1) return m[i].points;
    if(i>=n) return 0;
    if(dp[i]!=0) return dp[i];
    int play, notplay;
    play = maxpt(n,m,i+m[i].skip+1)+m[i].points;
    notplay = maxpt(n,m,i+1);
    dp[i] = max(play,notplay);
    return max(play,notplay);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &m[i].points, &m[i].skip);
    }
    maxpt(n,m,0);
    printf("%d\n", dp[0]);
    return 0;
}