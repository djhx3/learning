//Name: Dhruva J Herrick
//Roll No: 23CS30017
//Assignment  Question 
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<math.h>

void solve(long long n){
    long long sum = 7;
    long long a[(int)(1e6+1)];
    long long MOD = 1e9 + 7;
    a[0] = 1;
    a[1] = 1;
    a[2] = 2;
    a[3] = 4;
    a[4] = 8;
    a[5] = 16;
    a[6] = 32;
    if(n<7) {
        printf("%lld", a[n]);
        return;
    }
    while(sum<=n){
        for (int i = 1; i <= 6 && sum-i>0; i++)
        {
            a[sum] = (a[sum]+a[sum-i])%MOD;
        }
        sum++;
    }
    long long ans = a[n]%MOD;
    printf("%lld", ans);
}

int main()
{
    long long n;
    scanf("%lld", &n);
    solve(n);
    return 0;
}