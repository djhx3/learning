//Name: Dhruva J Herrick
//Roll No: 23CS30017
//Assignment 3 Question 1

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct{
    float start;
    float end;
} cdc;

void merge(cdc a[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    cdc b[n1], c[n2];
    for (int i = 0; i < n1; i++)
    {
        b[i] = a[l+i];
    }
    for (int i = 0; i < n2; i++)
    {
        c[i] = a[l+n1+i];
    }
    int i = 0, j = 0, k = l;
    while(i<n1&&j<n2){
        if(b[i].start<=c[j].start){
            a[k] = b[i];
            i++;
            k++;
        }
        else{
            a[k] = c[j];
            j++;
            k++;
        }
    }
    if(j==n2){
        while(i<n1){
            a[k] = b[i];
            k++;
            i++;
        }
    }
    else{
        while(j<n2){
            a[k] = c[j];
            k++;
            j++;
        }
    }
}

//sorting according to start time
void mergesort(cdc a[], int l, int r){
    if(r>l){
        int m = (l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}

void merge1(cdc a[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    cdc b[n1], c[n2];
    for (int i = 0; i < n1; i++)
    {
        b[i] = a[l+i];
    }
    for (int i = 0; i < n2; i++)
    {
        c[i] = a[l+n1+i];
    }
    int i = 0, j = 0, k = l;
    while(i<n1&&j<n2){
        if(b[i].end<=c[j].end){
            a[k] = b[i];
            i++;
            k++;
        }
        else{
            a[k] = c[j];
            j++;
            k++;
        }
    }
    if(j==n2){
        while(i<n1){
            a[k] = b[i];
            k++;
            i++;
        }
    }
    else{
        while(j<n2){
            a[k] = c[j];
            k++;
            j++;
        }
    }
}

//sorting according to end time
void mergesort1(cdc a[], int l, int r){
    if(r>l){
        int m = (l+r)/2;
        mergesort1(a,l,m);
        mergesort1(a,m+1,r);
        merge1(a,l,m,r);
    }
}

//returns maximum of two integers
int max(int a, int b){
    return (a>=b)? a:b;
}

int numberofvol(cdc a[], int n){
    int q[n];
    for (int i = 0; i < n; i++)
    {
        q[i] = a[i].end;
    }
    int ans = 1;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if(q[i]>a[i].start) ans++;

    }
    printf("%d\n", ans);
    return ans;
    
}

int main(){
    int n;
    printf("Enter the number of students n: ");
    scanf("%d", &n);
    cdc arr[n];
    printf("Enter the start time array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i].start);
    }
    printf("Enter the end time array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i].end);
    }
    cdc copy[n];
    for (int i = 0; i < n; i++)
    {
        copy[i]=arr[i];
    }
    mergesort(arr, 0, n-1); //array sorted as per starting times
    mergesort1(copy,0,n-1);
    int num = 1, num1 = 0;
    int j = 0;
    int worker=0;
    for(int i = 0; i < n; i++) {
        if(j>=n) break;
        if (arr[i].start < copy[j].end) {       //---> here was the main mistake
            worker--;
            if(worker<0) {num1++; worker++;}     //shortage of students means that number of students should be increased 
            // if(arr[i].end<arr[j].end && i<n-1 && arr[i].end<arr[i+1].start){
            //     worker++;
            // }
            num = max(num1,num);
            continue;
        }
        num1--;
        i--;
        j++;
    }
    printf("\nMinimum number of volunteers needed is %d\n", num);
}

