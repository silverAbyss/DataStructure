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

//顺序表的存储结构定义
#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10
typedef int ElemType;  //假设线性表中的元素均为整型
typedef struct{
    ElemType* elem;   //存储空间基地址
    int length;       //表中元素的个数
    int listsize;     //表容量大小
}SqList;    //顺序表类型定义

Status ListCreate_Sq(SqList &L,int n);
void ListMoveLeft_Sq(SqList &L,int m);

int main() {
    SqList L;
    ElemType *p;
    int m,n;
    scanf("%d %d",&n,&m);

    if(ListCreate_Sq(L,n)!= OK) {
        //printf("ListCreate_Sq: 创建失败！！！\n");
        return -1;
    }

    ListMoveLeft_Sq(L,m);

    if(L.length){
				for(p=L.elem;p<L.elem+L.length-1;++p){
				    printf("%d ",*p);
				}
				printf("%d",*p);
    }
    return 0;
}

Status ListCreate_Sq(SqList &L,int n) {
    //创建空顺序表,表容量为表长的两倍
    L.elem = (ElemType*)malloc((n*2)* sizeof(ElemType));
    if(!L.elem) exit(OVERFLOW);
    L.length = 0;
    L.listsize = n*2;//表容量为表长的两倍
    //输入元素
    for(int i = 0; i < n; i++) {
        scanf("%d",L.elem+i);
        L.length++;
    }
    return OK;
}

void ListMoveLeft_Sq(SqList &L,int m) {
    //如果移动位置大于表的长度，m取表长的模变为等同情况下移动最小的数
    if(m >= L.length)
        m %= L.length;
    //将前m个元素赋给length后的m个内存里
    for(int i = 0;i < m; i++)
        *(L.elem+i+L.length) = *(L.elem+i);
    //然后从第m个位置开始，每个元素依次前移m个位置
    for(int i = 0; i < L.length; i++)
        *(L.elem+i) = *(L.elem+m+i);
}
