/*
Name: Dhruva J Herrick
Roll No: 23CS30017
Assignment 2 Question 1
*/
#include <stdio.h>
#include <stdlib.h>

int minim;

//function to return minimum value
int min(int a, int b){
    return a < b ? a : b;
}
//checking if the required condition is true
int min2(int bus[], int n, int k, int l, int r){
    for (int i = 0; i < k; i++)
    {
        if(bus[i]<=(l+r)/2) return 1;
        else return 0;
    }
}

int mintime(int bus[], int n, int k, int l, int r){
    // minim = min(minim, r);
    if(r-l<=2) return r;
    if(min2(bus, n, k, l, r)) mintime(bus, n/2, k, l, (l+r)/2);     //binary search by checkng if second minimum is less than half the time in which case itll be in the first half
    else mintime(bus, n-n/2, k, ((l+r)/2)+1,r);
}
//function to return minimum value of an array
int minar(int bus[], int k){
    int minId = 0;
    for (int i = 1; i < k; i++)
    {
        if(bus[i]<bus[minId]) minId = i;
    }
    return minId;
}

int main(){
    int n, k;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    printf("Enter the number of buses: ");
    scanf("%d",&k);
    int bus[k];
    printf("Enter the array bus[]: ");
    for (int i = 0; i < k; i++)
    {
        scanf("%d",&bus[i]);
    }
    int minId = minar(bus,k);
    for (int i = 0; i < k; i++)
    {
        printf("%d ", bus[i]);
    }
    int ans = mintime(bus, n, k, 0, (bus[minId]*n));
    printf("Minimum time is %d\n", ans);
}