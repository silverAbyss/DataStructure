//库函数头文件包含
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

//函数状态码定义
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2

typedef int  Status;
typedef int elementType;

typedef struct lnode

{ elementType data;

struct lnode *next;

}Lnode,* LinkList;

int LinklistCreate_L(LinkList &CL)//创建一个有头结点的链表
{
    Lnode *curPtr, *rearPtr;
    int n;
    CL=(Lnode*)malloc(sizeof(Lnode));//创建一个头结点
    if(!CL) exit(OVERFLOW);
    CL->next = CL;//并且初始化为cl
    rearPtr=CL;//当前尾结点为头结点
    scanf("%d", &n);
    for(int i=0; i<n; i++)//循环指定次数
    {
        curPtr = (Lnode*)malloc(sizeof(Lnode));//每次循环都开辟一个新结点，赋值给新节点
        if(!CL) exit(OVERFLOW);
        scanf("%d", &curPtr->data);
        rearPtr->next=curPtr;
        rearPtr=curPtr;//拼接
    }
    rearPtr->next=NULL;//尾结点为空
    return OK;
}

int LinklistInsert(LinkList &CL, int x)//用来插入一个数，并且按顺序插入
{
    Lnode *curPtr, *prePtr, *inPtr;
    int flag=0;
    curPtr=CL->next;
    prePtr=CL;
    while(curPtr!=NULL)//遍历链表
    {
        if(x<=curPtr->data)//如果所插入的数应该在所在的位置 则放进链表
        {
            inPtr = (Lnode*)malloc(sizeof(Lnode));
            inPtr->data = x;
            prePtr->next=inPtr;
            inPtr->next=curPtr;
            flag=1;
        }
        else
        {
            curPtr=curPtr->next;
            prePtr=prePtr->next;
        }
        if(flag==1)
            break;
    }
       if(flag == 0)
    {
        inPtr = (Lnode*)malloc(sizeof(Lnode));
        inPtr->data = x;
        prePtr->next = inPtr;
        inPtr->next = NULL;
    }

}
void ListPrint_CL(LinkList &CL)
{
    //输出单链表,空表时输出Empty List。
    Lnode *p=CL->next;  //p指向第一个元素结点
    if(p==CL)
    {
        printf("Empty List");
        return;
    }
    while(p!=NULL)
    {
        printf(" %d",p->data);
        p=p->next;
    }
}
int main()
{
    LinkList CL;
    elementType x;
    if(LinklistCreate_L(CL)!= OK)
    {
        printf("循环链表创建失败！！！\n");
        return -1;
    }
    scanf("%d",&x);
    LinklistInsert(CL, x);
    ListPrint_CL(CL);
    return 0;
}
