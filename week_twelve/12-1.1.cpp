#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void OutPut(int *L,int N) {
    for(int i = 1; i <= N; i++) {
        if(i == 1)
            printf("%d",L[i]);
        else
            printf(" %d",L[i]);
    }
    printf("\n");
}

//冒泡排序
void BubbleSort(int *L, int N) {
    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j++) {
            if(L[i] > L[j+1]) {
                int temp = L[i];
                L[i] = L[j+1];
                L[j+1] = temp;
            }
        }
    }
}

//c++自带快排
int comp(const void *p,const void *q) {
    return (*(int*)p - *(int*)q);
}
void Qsort(int *L,int N) {
    qsort(L+1,N,sizeof(int),comp);
}

//快速排序(选取枢轴，左右两边分别排序)
int Partition(int *L, int low, int high) {
    L[0] = L[low];
    while(low < high) {
        while(high > low && L[high] >= L[0]) --high;
        L[low] = L[high];
        while(low < high && L[low] <= L[0]) ++low;
        L[high] = L[low];
    }
    L[low] = L[0];
    return low;
}
void QuickSort(int *L, int low, int high) {
    if(low < high) {
        int pivotLoc = Partition(L,low,high);
        QuickSort(L,low,pivotLoc-1);
        QuickSort(L,pivotLoc+1,high);
    }
    else
        return ;
}

//希尔排序
void ShellInsert(int *L, int dk, int N) {
    for(int i = dk+1,j; i <= N; ++i) {
        if(L[i] < L[i-dk]){
            L[0] = L[i];
            for(j = i-dk; j > 0 && (L[0] < L[j]); j -= dk)
                L[j+dk] = L[j];
            L[j+dk] = L[0];
        }
    }
}
void ShellSort(int *L,int N) {
    int dlta[] = {7,5,3,1};
    int t = 4;
    for(int k = 0; k < t; ++k)
        ShellInsert(L,dlta[k],N);
}

int main()
{
    int N,temp,*L;
    scanf("%d",&N);
    L = (int*)malloc(sizeof(int)*(N+1));
    for(int i = 1; i <= N; i++) {
        scanf("%d",&L[i]);
    }
    ShellSort(L,N);
    //QuickSort(L,1,N);
    //Qsort(L,N);
    //BubbleSort(L,N);
    OutPut(L,N);
    return 0;
}
