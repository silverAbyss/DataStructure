#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a[1000],b[1000],n,temp;
    int i,j = 0,k = 0;//分别作为输入数据的计数器、队列a队列b的计数器
    scanf("%d",&n);
    for(i = 0; i < n; i++) {
        scanf("%d",&temp);
        if(1 == temp%2) {
            a[j] = temp;
            j++;
        }
        else {
            b[k] = temp;
            k++;
        }
    }
    int length_a = j, length_b = k;
    j = 0; k = 0;
    while(j < length_a && k < length_b) {
        if(j == 0) {
            printf("%d %d",a[j],a[j+1]);
            j += 2;
        }
        else {
            printf(" %d %d",a[j],a[j+1]);
            j += 2;
        }
        printf(" %d",b[k]);
        k++;
    }
    while(j < length_a) {
        if(j == 0) {
            printf("%d",a[j]);
            j++;
        }
        else {
            printf(" %d",a[j]);
            j++;
        }
    }
    while(k < length_b) {
        if(j == 0) {
            printf("%d",b[k]);
            k++;
            j++;
        }
        else {
            printf(" %d",b[k]);
            k++;
        }
    }
    return 0;
}
