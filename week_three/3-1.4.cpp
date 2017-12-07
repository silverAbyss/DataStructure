#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int status;
typedef int ElemType;
typedef struct LNode{
    struct LNode* next;
    ElemType data;
}LNode,*Linklist;

#define    TRUE    1
#define    FALSE   0
#define    OK      1
#define    ERROR   0
#define    OVERFLOW    -2
void PrintList(Linklist L);
status MergeList(Linklist La, Linklist Lb, Linklist & Lc);
//输入（尾部插入）链表
status InputList(Linklist & L) {
   LNode * curPtr, * rearPtr;
   rearPtr = L;  //初始时头结点为尾节点,rearPtr指向尾巴节点
    while(1){  //每次循环都开辟一个新节点，并把新节点拼到尾节点后
        int e;
        scanf("%d",&e);
        if(e == -1) break;
        curPtr = (LNode*)malloc(sizeof(LNode));//生成新结点
        if(!curPtr) exit(OVERFLOW);
        curPtr->data = e;//输入元素值
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
    if(curPtr == NULL) {
        printf("NULL\n");
        return ;
    }
    while(curPtr != NULL) {
        if(L->next == curPtr)
            printf("%d",curPtr->data);
        else
            printf(" %d",curPtr->data);
        curPtr = curPtr->next;
    }
    printf("\n");
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
//取两链表的交集
status MergeList(Linklist La, Linklist Lb, Linklist & Lc) {
    LNode * la,*lb,*lc;
    lc = Lc;
    la = La->next;
    lb = Lb->next;

    while(la && lb) {
        if(la->data == lb->data) {

            lc->next = la;
            lc = la;
            la = la->next;
            lb = lb->next;
        }
        else if(la->data > lb->data) {
            lb = lb->next;
        }
        else{
            la = la->next;
        }
    }

    return OK;
}
int main()
{
    Linklist La,Lb,Lc;
    InitList(La);
    InitList(Lb);
    InitList(Lc);

    InputList(La);
    InputList(Lb);

    MergeList(La,Lb,Lc);
    PrintList(Lc);
    return 0;
}
