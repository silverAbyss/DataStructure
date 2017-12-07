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

//函数声明
Status ListInsert_SortedSq(SqList &L, ElemType e);

//顺序表初始化函数
Status InitList_Sq(SqList &L)
{
    //开辟一段空间
    L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    //检测开辟是否成功
    if(!L.elem){
        exit(OVERFLOW);
    }
    //赋值
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;

    return OK;
}

//顺序表输出函数
void ListPrint_Sq(SqList L)
{
    ElemType *p = L.elem;//遍历元素用的指针


    for(int i = 0; i < L.length; ++i){
        if(i == L.length - 1){
            printf("%d", *(p+i));
        }
        else{
            printf("%d ", *(p+i));
        }
    }
}
int main()
{
    //声明一个顺序表
    SqList L;
    //初始化顺序表
    InitList_Sq(L);

    int number = 0;
    ElemType e;

     scanf("%d", &number);//插入数据的个数

    for(int i = 0; i < number; ++i)
    {
				scanf("%d", &e);//输入数据
        ListInsert_SortedSq(L, e);
    }

    ListPrint_Sq(L);

    return  0;
}


Status ListInsert_SortedSq(SqList &L, ElemType e) {
    //如果表容等于表长，扩容
   ElemType* temp;

    if(L.length == L.listsize){
        temp = (ElemType* )realloc(L.elem,(LIST_INIT_SIZE+LISTINCREMENT)*sizeof(ElemType));
        if(!temp) exit(OVERFLOW);
        L.elem = temp;
        L.listsize += LISTINCREMENT;
    }

   //找到大于e的第一个数字或数据遍历到末尾结束
    int i = 0;
   for(i = 0; *(L.elem+i) < e && i < L.length ; i++)
    ;
   //从i开始，所有元素后移一个单位
   for(int j = L.length; j >= i; j--) {
    *(L.elem+j) = *(L.elem+j-1);
   }

   //将元素e插入到位置i
   *(L.elem+i) = e;

   //表长加一
   L.length++;
   return OK;
}
