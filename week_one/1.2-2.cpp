
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
typedef int  ElemType; //假设线性表中的元素均为整型

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

Status ListCreate_L(LinkList &L,int n)
{
    LNode *rearPtr,*curPtr;   //一个尾指针，一个指向新节点的指针
    L=(LNode*)malloc(sizeof (LNode));
    if(!L)exit(OVERFLOW);
    L->next=NULL;               //先建立一个带头结点的单链表
    rearPtr=L;  //初始时头结点为尾节点,rearPtr指向尾巴节点
    for (int i=1;i<=n;i++){  //每次循环都开辟一个新节点，并把新节点拼到尾节点后
        curPtr=(LNode*)malloc(sizeof(LNode));//生成新结点
        if(!curPtr)exit(OVERFLOW);
        scanf("%d",&curPtr->data);//输入元素值
        curPtr->next=NULL;  //最后一个节点的next赋空
        rearPtr->next=curPtr;
        rearPtr=curPtr;
    }
    return OK;
}
//下面是需要实现的函数的声明
int ListLocate_L(LinkList L, ElemType x);

int main()
{
    LinkList L;
    int n;
    int x,k;
    scanf("%d",&n);  //输入链表中元素个数
    if(ListCreate_L(L,n)!= OK) {
          printf("表创建失败！！！\n");
          return -1;
    }
   scanf("%d",&x); //输入待查找元素
   k=ListLocate_L(L,x);
   printf("%d\n",k);
   return 0;
}

/* 请在这里填写答案 */
int ListLocate_L(LinkList L, ElemType x) {
    //创建一个指向当前节点的指针
    LNode* curPtr = L->next;
    //创建计数器counter,遍历，若当前节点数据域值=x，返回位置
    int counter = 1;
    //若当前指针next为空，循环结束
    while(curPtr->next != NULL) {
        if(curPtr->data == x)
            return counter;
        //否则，返回0
        else {
            curPtr = curPtr->next;
            counter++;
        }
    }
}
