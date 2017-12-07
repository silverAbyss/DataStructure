#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<malloc.h>
using namespace std;

typedef char ElemType;
typedef struct LNode{
    struct LNode * next;
    ElemType data;
}LNode, *Linklist;
typedef int status;
#define    TRUE        1
#define    FALSE       0
#define    OK          1
#define    ERROR       0
#define    OVERFLOW    -2
status  InitList(Linklist & L);
status  InputList(Linklist & L, int len);
void    PrintList(Linklist L);
status  ListEmpty(Linklist L);
status  GetElem_L(Linklist L,int i,ElemType & e);
int     LocatElem_L(Linklist L,ElemType e);
status  InsertList(Linklist & L,int i,ElemType e);
status  DeleteList(Linklist & L,int i,ElemType&  e);

int main()
{
    Linklist L;
    InitList(L);
    int n;
    scanf("%d",&n);
    printf("%d\n",L->next);
    InputList(L,n);

    PrintList(L);
    int length = n;
    printf("%d\n",length);

    if(ListEmpty(L)) printf("no\n");
    else printf("yes\n");

    ElemType e;
    GetElem_L(L,3,e);
    printf("%c\n",e);

    int posi;
    cout << LocatElem_L(L,'a') << endl;

    InsertList(L, 4, 'x');
    ++n;
    PrintList(L);

    DeleteList(L,3,e);
    --n;
    PrintList(L);
    free(L);
    return 0;
}
//��ʼ������
status InitList(Linklist & L) {
    LNode * temp;
    temp = (LNode* )malloc(sizeof(LNode));
    if(!temp) exit(OVERFLOW);
    L = temp;
    L->next = NULL;
    return OK;
}
//���루β�����룩����
status InputList(Linklist & L, int n) {
   LNode * curPtr, * rearPtr;
   rearPtr = L;  //��ʼʱͷ���Ϊβ�ڵ�,rearPtrָ��β�ͽڵ�
    for (int i = 1;i <= n;i ++){  //ÿ��ѭ��������һ���½ڵ㣬�����½ڵ�ƴ��β�ڵ��
        curPtr = (LNode*)malloc(sizeof(LNode));//�����½��
        if(!curPtr) exit(OVERFLOW);
        scanf(" %c",&curPtr->data);//����Ԫ��ֵ
        curPtr->next = NULL;  //���һ���ڵ��next����
        rearPtr->next = curPtr;
        rearPtr = curPtr;
    }
    return OK;
}
//�������
void PrintList(Linklist L) {
    LNode* curPtr;
    curPtr = L->next;
    while(curPtr != NULL) {
        if(L->next == curPtr)
            printf("%c",curPtr->data);
        else
            printf(" %c",curPtr->data);
        curPtr = curPtr->next;
    }
    printf("\n");
}
//�ж������Ƿ�Ϊ��
status ListEmpty(Linklist L) {
    if(L->next) return TRUE;
    else return FALSE;
}
//��ȡ����ĵ�i��Ԫ��
status GetElem_L(Linklist L,int i,ElemType & e) {
    LNode* p;
    p = L->next;
    int j = 1;
    while(p && j < i) {
        p = p->next;
        ++j;
    }
    if(!p || j > i) return ERROR;
    e = p->data;
    return OK;
}
//��ȡԪ��e��λ��
int LocatElem_L(Linklist L, ElemType e) {
    LNode* p;
    p = L->next;
    int j = 1;
    while(p && e != p->data) {
        p = p->next;
        j++;
    }
    if(p) return j;
    else return 0;
}
//��λ��i������Ԫ��e
status InsertList(Linklist &L, int i, ElemType e) {
    LNode * p;
    p = L->next;
    int j = 1;
    while(p && j < i-1) {
        p = p->next;
        ++j;
    }
    if(!p || j > i-1) return ERROR;
    LNode* temp;
    temp = (LNode* )malloc (sizeof(LNode));
    if(!temp) exit(OVERFLOW);
    temp->data = e;
    temp->next = p->next;
    p->next = temp;
    return OK;
}
//ɾ����i��Ԫ��
status DeleteList(Linklist & L,int i,ElemType & e) {
    LNode * p,*q;
    p = L->next;
    int j = 1;
    while(p && j < i-1) {
        p = p->next;
        ++j;
    }
    if(p && j > i-1) return ERROR;
    q = p->next->next;
    free(p->next);
    p->next = q;
    return OK;
}
