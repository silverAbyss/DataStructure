#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void OutPut(int *L,int N) {
    for(int i = 1; i <= N; i++) {
        if(i == 1)
            printf("%d",L[i]);
        else
            printf(" %d",L[i]);
    }
    printf("\n");
}
//¸Ä½øÃ°ÅÝÅÅÐò
void BubbleSort(int *L, int N,int M) {
    for(int i = 1; i < M+1 && i < N; i++) {
        for(int j = i; j < N; j++) {
            if(L[i] < L[j+1]) {
                int temp = L[i];
                L[i] = L[j+1];
                L[j+1] = temp;
            }
        }
        //OutPut(L,N);
    }
}

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    int *L = (int *)malloc(sizeof(int)*(N+1));
    for(int i = 0; i < N; i++)
        scanf("%d",&L[i+1]);
    BubbleSort(L,N,M);
    for(int i = 1; i <= M&& i <= N; i++) {
        if(i == 1)
            printf("%d",L[i]);
        else
            printf(" %d",L[i]);
    }
    return 0;
}
