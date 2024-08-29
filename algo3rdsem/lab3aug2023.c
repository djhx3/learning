#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

#define MAXLEN 100000

typedef struct{
    int start;
    int end;
    int dur;
} prog;

int max(int a, int b){
    return (a>b)? a : b;
}

int min(int a, int b){
    return (a<b)? a : b;
}

int main()
{
    prog p[MAXLEN];
    int n;
    printf("Enter the number of the programs: ");
    scanf("%d", &n);
    printf("Enter the elements in order start, end, duration : ");
    int mintime = INT_MAX;
    int maxtime = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &p[i].start, &p[i].end, &p[i].dur);
        maxtime = max(maxtime, p[i].end);
        mintime = min(mintime, p[i].start);
    }
    int itraversed[MAXLEN];
    for (int i = mintime; i < maxtime+1; i++)
    {
        itraversed[i] = 0;
    }
    
    int ans = 0;
    int count[MAXLEN];
    int notdone = 1;
    while(notdone){
        notdone = 0;
        for (int i = mintime; i < maxtime+2; i++)
        {
            count[i]=0;
        }
        for (int i = 0; i < n; i++)
        {
            if(p[i].dur>0){
                notdone = 1;
                count[p[i].start]++;
                count[p[i].end+1]--;
            }
        }
        if(!notdone) break;
        for (int i = mintime+1; i < maxtime+1; i++)
        {
            count[i]+=count[i-1];
        }
        int maxct = -1, maxcttime = -1;
        for (int i = mintime; i < maxtime+1; i++)
        {
            if(count[i]>maxct && itraversed[i]==0){
                maxct = count[i];
                maxcttime = i;
            }
        }
        itraversed[maxcttime] = 1;
        ans++;
        for (int i = 0; i < n; i++)
        {
            if(p[i].dur>0){
                if(p[i].start<=maxcttime&&p[i].end>=maxcttime){
                    p[i].dur--;
                }
            }
        }
    }
    printf("\nRequired minimum time %d\n", ans);
    //cumulative sum might be better to calculate total number of count because of less iterations needed 
    return 0;
}