//�⺯��ͷ�ļ�����
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

//����״̬�붨��
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2

typedef int  Status;

//˳���Ĵ洢�ṹ����
#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10
typedef int ElemType;  //�������Ա��е�Ԫ�ؾ�Ϊ����
typedef struct{
    ElemType* elem;   //�洢�ռ����ַ
    int length;       //����Ԫ�صĸ���
    int listsize;     //��������С
}SqList;    //˳������Ͷ���

Status ListCreate_Sq(SqList &L);
void ListReverse_Sq(SqList &L);

int main() {
    SqList L;
    ElemType *p;

    if(ListCreate_Sq(L)!= OK) {
        printf("ListCreate_Sq: ����ʧ�ܣ�����\n");
        return -1;
    }

    ListReverse_Sq(L);

    if(L.length){
				for(p=L.elem;p<L.elem+L.length-1;++p){
				    printf("%d ",*p);
				}
				printf("%d",*p);
    }
    return 0;
}

Status ListCreate_Sq(SqList &L) {
    //������˳���
    L.elem = (ElemType*)malloc(LIST_INIT_SIZE* sizeof(ElemType));
    if(!L.elem) exit(OVERFLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    //����Ԫ��
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d",L.elem+i);
        L.length++;
    }
    return OK;
}

void ListReverse_Sq(SqList &L) {
    ElemType temp;
    for(int i = 0;i < L.length/2; i++) {
       temp = *(L.elem+i);
       *(L.elem+i) = *(L.elem+L.length-1-i);
       *(L.elem+L.length-1-i) = temp;
    }
}
