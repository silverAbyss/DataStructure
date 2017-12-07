#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void Input(int *L,int N,int &sum) {
    for(int i = 1; i <= N; i++){
        scanf("%d",&L[i]);
        sum += L[i];
    }

}

//Ï£¶ûÅÅÐò
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

void OutPut(int *L,int N,int sum) {
    int frist = 0,j = N/2;
    for(int i = 1; i <= j; i++)
        frist += L[i];

    printf("Outgoing #: %d\n",N-j);
    printf("Introverted #: %d\n",j);
    printf("Diff = %d\n",sum-2*frist);
}

int main()
{
    int N,sum = 0;
    scanf("%d",&N);
    int *L = (int*)malloc(sizeof(int)*(N+1));
    Input(L,N,sum);
    ShellSort(L,N);

    OutPut(L,N,sum);
    return 0;
}
