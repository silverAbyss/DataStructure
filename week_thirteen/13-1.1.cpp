#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define     TRUE        1
#define     FALSE       0
#define     OK          1
#define     ERROR       0
#define     OVERFLOW    -2

int Radix = 5;

typedef long QElemType;
typedef int status;
typedef struct QNode {
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

status InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = (QNode*)malloc(sizeof(QNode));
    if(!Q.front) exit (OVERFLOW);
    Q.front->next = NULL;
    return OK;
}

status DestroyQueue(LinkQueue &Q) {
    QueuePtr p = Q.front,postp;
    while(p) {
        postp = p->next;
        free(p);
        p = postp;
    }
    Q.front = NULL;
    Q.rear = NULL;
    return OK;
}

status EnQueue(LinkQueue &Q, QElemType e) {
    QueuePtr p;
    p = (QNode*)malloc(sizeof(QNode));
    if(!p) exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

status DeQueue(LinkQueue &Q,QElemType &e) {
    if(Q.front == Q.rear) return ERROR;
    QueuePtr p = Q.front->next;
    e = p->data;
    if(Q.rear == p) Q.rear = Q.front;
    free(p);
    return OK;
}

status QueueEmpty(LinkQueue &Q) {
    if(Q.front == Q.rear) return TRUE;
    else return FALSE;
}

status GetHead(LinkQueue Q, QElemType &e){
    if (Q.rear == Q.front)
        return ERROR;
    e = Q.front->data;
    return OK;
}

void Distribute(long *R, LinkQueue B[],int j) {
    //���ؼ��ֵĵ�j���������з��䣬����˹���ʱ������һ��Ϊ��
    for(int i = 1; i <= R[0]; i++) {
        int k = R[i];
        for(int t = 0; t < j; t++)
            k /= 10;
        k = k % 10;//ȡ�ؼ��ĵ�jλ���ӵ�λ��ʼ��
        EnQueue(B[k],R[i]);
    }
}

void Collect(long *R, LinkQueue B[]) {
    //���ν����ǿ������еļ�¼�ռ������������̽���ʱ�����Ӿ����
    int i = 0, j;
    for( j = 0; j < Radix; j++)//����������ΪN
        while(!QueueEmpty(B[j]))
            DeQueue(B[j],R[i++]);//�����Ӽ�¼���������R[i]��
}

void RadixSort(long *R) {
    //��R[0..n-1]���л�������
    LinkQueue B[Radix];
    for(int i = 0; i < Radix; i++)
        InitQueue(B[i]);
    for(int i = 0; i < 10; i++) {
        printf("one \n");
        Distribute(R,B,i);
        printf("two \n");
        Collect(R,B);
    }
}

//ϣ������
void ShellInsert(long *L, int dk, int N) {
    for(int i = dk+1,j; i <= N; ++i) {
        if(L[i] < L[i-dk]){
            L[0] = L[i];
            for(j = i-dk; j > 0 && (L[0] < L[j]); j -= dk)
                L[j+dk] = L[j];
            L[j+dk] = L[0];
        }
    }
}
void ShellSort(long *L,int N) {
    int dlta[] = {7,5,3,1};
    int t = 4;
    for(int k = 0; k < t; ++k)
        ShellInsert(L,dlta[k],N);
}

int main()
{
    int N;
    scanf("%d",&N);
    long *R = (long*)malloc(sizeof(long)*(N+1));
    R[0] = (long)N;
    for(int i = 1; i <= N; i++){
        scanf("%ld",&R[i]);
    }
    //printf("test here \n");
    //RadixSort(R);
    ShellSort(R,N);
    for(int i = 1; i <= N; i++) {
        if(i == 1)
            printf("%ld",R[i]);
        else
            printf(" %ld",R[i]);
    }
    return 0;
}

