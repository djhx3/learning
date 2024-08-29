#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int conq(double x[], double y[], int l, int r, double hullptx[], double hullpty[]){
    int i, j, k, h1, h2;
    double hull1x[r-l+1], hull1y[r-l+1], hull2x[r-l+1], hull2y[r-l+1];
    if(r-l+1 == 1){
        hullptx[0] = x[l];
        hullpty[0] = y[l];
        return 1;
    }
    if(r-l+1 == 2){
        hullptx[0] = x[l];
        hullpty[0] = y[l];
        hullptx[1] = x[r];
        hullpty[1] = y[r];
        return 2;
    }
    for(i = l; i <= (l+r)/2; i++){
        hull1x[i-l] = x[i];
        hull1y[i-l] = y[i];
    }
    h1 = conq(hull1x, hull1y, 0, (l+r)/2-l, hullptx, hullpty);
    for(i = (l+r)/2+1; i <= r; i++){
        hull2x[i-(l+r)/2-1] = x[i];
        hull2y[i-(l+r)/2-1] = y[i];
    }
    h2 = conq(hull2x, hull2y, 0, r-(l+r)/2-1, hullptx, hullpty);
    for(i = 0; i < h1; i++){
        hullptx[i] = hull1x[i];
        hullpty[i] = hull1y[i];
    }
    for(i = 0; i < h2; i++){
        hullptx[h1+i] = hull2x[i];
        hullpty[h1+i] = hull2y[i];
    }
    hullptx[h1+h2] = hull1x[0];
    hullpty[h1+h2] = hull1y[0];
    hullptx[h1+h2+1] = hull1x[0];
    hullpty[h1+h2+1] = hull1y[0];
    i = 0;
    j = 0;
    for(k = 1; k < h1; k++){
        if(hullpty[k] < hullpty[i]){
            i = k;
        }
    }
    return i; 
}

int divide(double x[], double y[], int l, int r, double hullptx[], double hullpty[])
{
    if(n==1) return 1;
    divide(x,y,l,(l+r)/2,hullptx,hullpty);
    divide(x,y,(l+r)/2+1,r,hullptx,hullpty);
    return conq(x,y,l,r,hullptx,hullpty);
} 

int hulldivideandconquer(double x[], double y[], int n, double hullptx[], double hullpty[]){
    int i, j, k, l, m, h1, h2;
    double hull1x[n], hull1y[n], hull2x[n], hull2y[n];
    if(n == 1){
        hullptx[0] = x[0];
        hullpty[0] = y[0];
        return 1;
    }
    if(n == 2){
        hullptx[0] = x[0];
        hullpty[0] = y[0];
        hullptx[1] = x[1];
        hullpty[1] = y[1];
        return 2;
    }
    for(i = 0; i < n/2; i++){
        hull1x[i] = x[i];
        hull1y[i] = y[i];
    }
    h1 = hulldivideandconquer(hull1x, hull1y, n/2, hullptx, hullpty);
    for(i = n/2; i < n; i++){
        hull2x[i-n/2] = x[i];
        hull2y[i-n/2] = y[i];
    }
    h2 = hulldivideandconquer(hull2x, hull2y, n-n/2, hullptx, hullpty);
    for(i = 0; i < h1; i++){
        hullptx[i] = hull1x[i];
        hullpty[i] = hull1y[i];
    }
    for(i = 0; i < h2; i++){
        hullptx[h1+i] = hull2x[i];
        hullpty[h1+i] = hull2y[i];
    }
    hullptx[h1+h2] = hull1x[0];
    hullpty[h1+h2] = hull1y[0];
    hullptx[h1+h2+1] = hull1x[0];
    hullpty[h1+h2+1] = hull1y[0];
    i = 0;
    j = 0;
    for(k = 1; k < h1; k++){
        if(hullpty[k] < hullpty[i]){
            i = k;
        }
    }
    for(k = 1; k < h2; k++){
        if(hullpty[k] > hullpty[j]){
            j = k;
        }
    }
    l = i;
    m = j;
    while(1){
        while((hullpty[(l+1)%h1] - hullpty[l]) * (hullptx[(i+1)%h1] - hullptx[i]) < (hullpty[i] - hullpty[(i-1+h1)%h1]) * (hullptx[i] - hullptx[(i-1+h1)%h1])){
            i = (i-1+h1)%h1;
        }
        while((hullpty[(m+1)%h2] - hullpty[m]) * (hullptx[(j+1)%h2] - hullptx[j]) < (hullpty[j] - hullpty[(j-1+h2)%h2]) * (hullptx[j] - hullptx[(j-1+h2)%h2])){
            j = (j-1+h2)%h2;
        }
        if((hullpty[(l+1)%h1] - hullpty[l]) * (hullptx[(i+1)%h1] - hullptx[i]) >= (hullpty[i] - hullpty[(i-1+h1)%h1]) * (hullptx[i] - hullptx[(i-1+h1)%h1]) && (hullpty[(m+1)%h2] - hullpty[m]) * (hullptx[(j+1)%h2] - hullptx[j]) >= (hullpty[j] - hullpty[(j-1+h2)%h2]) * (hullptx[j] - hullptx[(j-1+h2)%h2])){
            break;
        }
    }
    return h1+h2;
}

int hullpt(double x[], double y[], int n, double hullx[], double hully[])
{
    int i, j, k = 0;
    for(i = 0; i < n; i++)
    {
        while(k >= 2 && (hully[k-1] - hully[k-2]) * (x[i] - hullx[k-1]) < (y[i] - hully[k-1]) * (hullx[k-1] - hullx[k-2]))
        {
            k--;
        }
        hullx[k] = x[i];
        hully[k] = y[i];
        k++;
    }
    j = k;
    for(i = n-2; i >= 0; i--)
    {
        while(k > j && (hully[k-1] - hully[k-2]) * (x[i] - hullx[k-1]) < (y[i] - hully[k-1]) * (hullx[k-1] - hullx[k-2]))
        {
            k--;
        }
        hullx[k] = x[i];
        hully[k] = y[i];
        k++;
    }
    return k;
}

int main()
{
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    double x[n], y[n], hullx[n], hully[n];
    printf("Enter the x and y coordinates of the points: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &x[i], &y[i]);
    }
    int k = divide(x,y,0,n-1,hullx,hully);
    printf("The points on the convex hull are: ");
    for(int i = 0; i < k; i++)
    {
        printf("(%lf, %lf) ", hullx[i], hully[i]);
    }
    printf("\n");
    return 0;
}