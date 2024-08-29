#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{
    int var;
    int lt;
    int cost;
} sweet;

void merge(sweet a[], int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    sweet left[n1], right[n2];
    for (int i = 0; i < n1; i++)
    {
        left[i]=a[p+i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = a[p+n1+i];
    }
    int i=0, j = 0, k = p;
    while(i<n1&&j<n2){
        if(left[i].lt>=right[j].lt){
            a[k] = left[i];
            k++;
            i++;
        }
        else if(right[j].lt>left[i].lt){
            a[k] = right[j];
            j++;
            k++;
        }
        // else if(left[i].cost==right[j].cost){
        //     a[k] = left[i];
        //     k++;
        //     i++;
        //     a[k] = right[j];
        //     k++;
        //     j++;
        // }
    }
    if(i==n1){
        while(j<n2){
            a[k++]=right[j++];
        }
    }
    else{
        while(i<n1){
            a[k++]=left[i++];
        }
    }
}

void mergesort(sweet a[], int p, int r){
    if (r>p)
    {
        int q = (r+p)/2;
        mergesort(a,p,q);
        mergesort(a,q+1,r);
        merge(a,p,q,r);
    }
}

int main()
{
    int n;
    printf("Enter the number of sweet varieties: ");
    scanf("%d", &n);
    sweet s[n];
    printf("Enter all their latest times to deliver: ");
    for (int i = 0; i < n; i++)
    {
        s[i].var = i+1;
    }
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i].lt);
    }
    printf("Enter their costs: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i].cost);
    }
    mergesort(s,0,n);
    int ans[n];
    int time[s[0].lt-s[n-1].lt+1];
    for (int i = 0; i < s[0].lt - s[n-1].lt + 1; i++)
    {
        time[i]=0;
    }
    int i = s[0].lt - s[n-1].lt + 1;
    while(i>0){
        time[i];
    }
    return 0;
}