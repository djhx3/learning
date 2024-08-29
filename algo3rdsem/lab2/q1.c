#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//Quicksort with three partition - better optimised for duplicate elements

int swap(int a[], int i, int j){
    int temp = a[i];
    a[i]=a[j];
    a[j]=temp;
}

void printArray(int arr[], int size) {  
    int i;  
    for (i = 0; i < size; i++)  
        printf("%d ", arr[i]);  
    printf("\n");  
}  
  
int partition(int a[], int n, int l, int r, int *eq){
    int i=0, j=0, lind, rind, piv = a[l];
    (*eq)=0;
    lind = l;
    rind = r;
    while(rind>lind){
        while(a[lind]<=piv){
            if(a[lind] == piv) (*eq)++;
            lind++;
        }
        while(a[rind]>piv) rind--;
        if(lind<rind) swap(a, lind, rind);
    }
    a[l] = a[rind];
    a[rind] = piv;
    int t = 1;
    int count = 0;
    for(int i=l;i<r;i++)
    {
        if(count>=(*eq)) break;
        if(a[i]==piv && (*eq)>1){
            if(a[rind-t]!=piv && (rind-t)>=0){
                swap(a,i,rind-t);
                count++;
            }
            else {
            printf("a[i] %d\n", a[i]);
                while(a[rind-t]==piv && (rind-t)>=0) {
                    t++;
                    count++;
                }
                if(count>=*eq) break;
                swap(a,i,rind-t);
                count++;
            }
        }
    }
    return rind;
}

int quicksort(int a[], int l, int r){
    int pivot;
    int eq = 0;
    if(r>l){
        pivot = partition(a,r-l,l,r,&eq);
        quicksort(a,l,pivot-eq);
        // printf("pivot %d - %d \n", pivot, a[pivot]);
        // printArray(a,r-l+1);
        quicksort(a,pivot+1,r);
        // printf("hello\n");
        // printArray(a,r-l+1);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: ");
    for(int i =0; i<n; i++){
        scanf("%d", &a[i]);
    }    
    quicksort(a,0,n-1);
    printf("Sorted array: ");
    printArray(a,n);
    
    return 0;
}