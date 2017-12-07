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
//初始化链表
status InitList(Linklist & L) {
    LNode * temp;
    temp = (LNode* )malloc(sizeof(LNode));
    if(!temp) exit(OVERFLOW);
    L = temp;
    L->next = NULL;
    return OK;
}
//输入（尾部插入）链表
status InputList(Linklist & L, int n) {
   LNode * curPtr, * rearPtr;
   rearPtr = L;  //初始时头结点为尾节点,rearPtr指向尾巴节点
    for (int i = 1;i <= n;i ++){  //每次循环都开辟一个新节点，并把新节点拼到尾节点后
        curPtr = (LNode*)malloc(sizeof(LNode));//生成新结点
        if(!curPtr) exit(OVERFLOW);
        scanf(" %c",&curPtr->data);//输入元素值
        curPtr->next = NULL;  //最后一个节点的next赋空
        rearPtr->next = curPtr;
        rearPtr = curPtr;
    }
    return OK;
}
//输出链表
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
//判断链表是否为空
status ListEmpty(Linklist L) {
    if(L->next) return TRUE;
    else return FALSE;
}
//获取链表的第i个元素
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
//获取元素e的位置
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
//在位置i处插入元素e
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
//删除第i个元素
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
