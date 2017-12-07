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

Status ListCreate_Sq(SqList &L,int n);
void ListMoveLeft_Sq(SqList &L,int m);

int main() {
    SqList L;
    ElemType *p;
    int m,n;
    scanf("%d %d",&n,&m);

    if(ListCreate_Sq(L,n)!= OK) {
        //printf("ListCreate_Sq: ����ʧ�ܣ�����\n");
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
    //������˳���,������Ϊ��������
    L.elem = (ElemType*)malloc((n*2)* sizeof(ElemType));
    if(!L.elem) exit(OVERFLOW);
    L.length = 0;
    L.listsize = n*2;//������Ϊ��������
    //����Ԫ��
    for(int i = 0; i < n; i++) {
        scanf("%d",L.elem+i);
        L.length++;
    }
    return OK;
}

void ListMoveLeft_Sq(SqList &L,int m) {
    //����ƶ�λ�ô��ڱ�ĳ��ȣ�mȡ����ģ��Ϊ��ͬ������ƶ���С����
    if(m >= L.length)
        m %= L.length;
    //��ǰm��Ԫ�ظ���length���m���ڴ���
    for(int i = 0;i < m; i++)
        *(L.elem+i+L.length) = *(L.elem+i);
    //Ȼ��ӵ�m��λ�ÿ�ʼ��ÿ��Ԫ������ǰ��m��λ��
    for(int i = 0; i < L.length; i++)
        *(L.elem+i) = *(L.elem+m+i);
}
