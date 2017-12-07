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
typedef int Elemtype;  //假设线性表中的元素均为整型
typedef struct{
    Elemtype* elem;   //存储空间基地址
    int length;       //表中元素的个数
    int listsize;     //表容量大小
}SqList;    //顺序表类型定义
Status ListInsert_Sq(SqList &L, int pos, Elemtype e);
Status ListDelete_Sq(SqList &L, int pos, Elemtype &e);
int ListLocate_Sq(SqList L, Elemtype e);
void ListPrint_Sq(SqList L);

//结构初始化与销毁操作
Status InitList_Sq(SqList &L){
  //初始化L为一个空的有序顺序表
    L.elem=(Elemtype *)malloc(LIST_INIT_SIZE*sizeof(Elemtype));
    if(!L.elem)exit(OVERFLOW);
    L.listsize=LIST_INIT_SIZE;
    L.length=0;
    return OK;
}


int main() {
    SqList L;

    if(InitList_Sq(L)!= OK) {
        printf("InitList_Sq: 初始化失败！！！\n");
        return -1;
    }

    for(int i = 1; i <= 10; ++ i)
        ListInsert_Sq(L, i, i);

    int operationNumber;  //操作次数
    scanf("%d", &operationNumber);

    while(operationNumber != 0) {
        int operationType;  //操作种类
        scanf("%d", & operationType);

        if(operationType == 1) {  //增加操作
            int pos, elem;
            scanf("%d%d", &pos, &elem);
            ListInsert_Sq(L, pos, elem);
        } else if(operationType == 2) {  //删除操作
             int pos; Elemtype elem;
             scanf("%d", &pos);
             ListDelete_Sq(L, pos, elem);
             printf("%d\n", elem);
        } else if(operationType == 3) {  //查找定位操作
            Elemtype elem;
            scanf("%d", &elem);
            int pos = ListLocate_Sq(L, elem);
            if(pos >= 1 && pos <= L.length)
                printf("%d\n", pos);
            else
                printf("NOT FIND!\n");
        } else if(operationType == 4) {  //输出操作
            ListPrint_Sq(L);
        }
       operationNumber--;
    }
    return 0;
}

/* 请在这里填写答案 */
//插入数据
Status ListInsert_Sq(SqList &L, int pos, Elemtype e) {
    if(pos < 1)
        return ERROR;
    if(pos >= L.listsize) {
        SqList temp;
        temp.elem = (Elemtype*)realloc(L.elem,(LIST_INIT_SIZE+LISTINCREMENT)*sizeof(Elemtype));
        if(InitList_Sq(temp)!= OK) {
            printf("InitList_Sq: 初始化失败！！！\n");
            return -1;
        }
        L.elem = temp.elem;
    }

    L.listsize += LISTINCREMENT;
    int counter;
    for(counter = L.length-1; counter >= pos-1; counter--) {
        L.elem[counter+1] = L.elem[counter];
    }
    L.elem[pos-1] = e;
    L.length++;
}

//删除数据
Status ListDelete_Sq(SqList &L, int pos, Elemtype &e) {
    if(pos < 1 || pos > L.length)
        return ERROR;
    e = L.elem[pos-1];
    int counter;
    for(counter = pos-1; counter < L.length-1; counter ++) {
        L.elem[counter] = L.elem[counter+1];
    }
    L.length--;
}

//在顺序表中定位
int ListLocate_Sq(SqList L, Elemtype e) {
    int counter;
    for(counter = 0; counter < L.length; counter++) {
        if(L.elem[counter] == e)
           return counter+1;
    }
    if(L.length == counter+1)
        return 0;
}

//输出顺序表
void ListPrint_Sq(SqList L) {
    for(int counter = 0; counter < L.length; counter++) {
        if(counter == 0)
            printf("%d",L.elem[counter]);
        else
            printf(" %d",L.elem[counter]);
    }
}
