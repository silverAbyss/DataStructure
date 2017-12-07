#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int status;
typedef int ElemType;
typedef struct LNode {
    struct LNode * next;
    ElemType data;
}LNode,*Linklist;

//状态码定义
#define    TRUE    1
#define    FALSE   0
#define    OK      1
#define    ERROR   0
#define    OVERFLOW    -2

status CreatList_L(Linklist & L) {
    LNode* temp, *rearPtr;
    temp = (LNode* )malloc (sizeof(LNode));
    if(!temp) exit(OVERFLOW);
    L = temp;
    rearPtr = L;
    int num;
    while(scanf("%d",&num)) {
        if(num < 0) break;
        temp = (LNode* )malloc (sizeof(LNode));
        if(!temp) exit(OVERFLOW);
        temp->data = num;
        rearPtr->next = temp;
        rearPtr = rearPtr->next;
    }
    rearPtr = NULL;
    return OK;
}

int main()
{
    //创建链表
    Linklist  L;
    int k;
    scanf("%d",&k);
    if(CreatList_L(L) != OK) {
        printf("链表创建失败！\n");
        return -1;
    }
    //创建两个指针，一个指针指向第K个元素，另一个指针指向头结点
    LNode* fristPtr, * secondPtr;
    fristPtr = L;
    secondPtr = L;
    int i;
    for(i = 0; i < k; i ++) {
        fristPtr = fristPtr->next;
    }
    //两个指针同时后移，当第一个指针为空时，取另一指针的元素
    while(fristPtr != NULL) {
        fristPtr = fristPtr->next;
        secondPtr = secondPtr->next;
        //printf("test here : fristPtr->data is %d,secondPtr->data is %d\n",fristPtr->data,secondPtr->data);
    }
    //检验链表是否为空，空输出NULL，非空输出第K个元素
    if(secondPtr == NULL)
        printf("NULL\n");
    else
        printf("%d\n",secondPtr->data);

    return 0;
}
