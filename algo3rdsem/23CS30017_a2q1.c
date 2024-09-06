/*
Name: Dhruva J Herrick
Roll No: 23CS30017
Assignment 2 Question 1
*/
#include <stdio.h>
#include <stdlib.h>

//defining the functions, code below main
int swap(int a[], int i, int j);
int partition1(int a[], int low, int high, int *e);
// int partition(int a[], int low, int high);
int quicksort(int a[], int p, int r);

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the numbers: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quicksort(a,0,n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    return 0;
}

int quicksort(int a[], int low, int high){
    int pivot;
    int eq = 0;
    if(high>low){
        pivot = partition1(a,low,high,&eq);
        quicksort(a, low, pivot-1-eq);
        quicksort(a, pivot+1, high);
    }
}

//normal partition function without optimization
// int partition(int a[], int low, int high){
//     int l,r, piv = a[low];
//     l = low;
//     r = high;
//     while(l<r){
//         while(a[l]<=piv) l++;    //move left while item<pivot
//         while(a[r]>piv) r--;       //move right while item>pivot
//         if(l<r) {
//             swap(a, l, r);
//         }
//     }
//     a[low]=a[r];       //r is the final pivot position
//     a[r] = piv;
//     return r;  //return the pivot position
// }

int partition1(int a[], int low, int high, int *e){
    int l, r, piv = a[low];
    l = low;
    r = high;
    int equal = low;
    while(l<r){
        while(a[l]<=piv) {   //move left while item<pivot
            if(a[l]==piv){
                equal++;
            }
            l++; 
        }                      //third partition created
        while(a[r]>piv) r--;       //move right while item>pivot
        if(l<r) {
            swap(a, l, r);
        }
    }
    a[low]=a[r];       //r is the final pivot position
    a[r] = piv;
    int counter = 0;//counter to keep track of the number of equal elements to the pivot
    int i = low;  
    while(i<high){
        if(a[i]==piv) {
            counter++;
            swap(a, i, r-equal+counter);
            equal--;
        }
        i++;
    }
    *e = counter;
    return r;  //return the pivot position
}

int swap(int a[], int i, int j){
    int temp = a[i]; 
    a[i]=a[j]; 
    a[j]= temp;
}