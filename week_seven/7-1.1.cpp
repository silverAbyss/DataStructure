//头文件包含
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

//函数状态码定义
#define TRUE       1
#define FALSE      0
#define OK         1
#define ERROR      0
#define OVERFLOW   -1
#define INFEASIBLE -2
#define NULL  0

typedef int Status;

//二叉链表存储结构定义
typedef int TElemType;
typedef struct BiTNode{
    TElemType data;
    struct BiTNode  *lchild, *rchild;
} BiTNode, *BiTree;

//先序创建二叉树各结点
Status CreateBiTree(BiTree &T){
   TElemType e;
   scanf("%d",&e);
   if(e==0)T=NULL;
   else{
     T=(BiTree)malloc(sizeof(BiTNode));
     if(!T)exit(OVERFLOW);
     T->data=e;
     CreateBiTree(T->lchild);
     CreateBiTree(T->rchild);
   }
   return OK;
}

//下面是需要实现的函数的声明
int GetDepthOfBiTree ( BiTree T);
int LeafCount(BiTree T);
//下面是主函数
int main()
{
   BiTree T;
   int depth, numberOfLeaves;
   CreateBiTree(T);
   depth= GetDepthOfBiTree(T);
	 numberOfLeaves=LeafCount(T);
   printf("%d %d\n",depth,numberOfLeaves);
}

int GetDepthOfBiTree ( BiTree T) {
    if(T == NULL ) {
        return 0;
    }
    else {
        int lenl = GetDepthOfBiTree(T->lchild);
        int lenr = GetDepthOfBiTree(T->rchild);
        return lenl > lenr? lenl+1:lenr+1;
    }
}

int LeafCount(BiTree T) {
    if(T == NULL) return 0;
    else if(T->lchild == NULL && T->rchild == NULL) return 1;
    else {
        return LeafCount(T->lchild) + LeafCount(T->rchild);
    }
}
