//6-1 ѭ������������ɾ����15 �֣�
//����Ҫ��ʵ�ִ�ͷ����ѭ��������Ĵ����͵����������ɾ����
//L��һ����ͷ����ѭ������������ListCreate_CL���ڴ���һ��
//ѭ������������ListDelete_CL����ɾ��ȡֵ����minС��max������Ԫ�ء�
//�����ʽ�� ��һ������һ������n����ʾѭ����������Ԫ�ظ�������
//����һ�й�n���������м��ÿո����������������min��max��
//�����ʽ�� ���ɾ����ѭ������ĸ���Ԫ�أ�����Ԫ��֮���ÿո������
//���һ��Ԫ�غ���û�пո�
//����������
//6
//1 2 3 4 5 6
//2 5
//���������
//1 2 5 6

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
typedef int  ElemType; //�������Ա��е�Ԫ�ؾ�Ϊ����

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList; //ѭ�����������Ͷ����뵥��������ͬ��������β�ڵ�nextȡֵ

Status ListCreate_CL(LinkList &CL);

void ListDelete_CL(LinkList &CL, ElemType min, ElemType max);

void ListPrint_CL(LinkList &CL)
{   //���������,�ձ�ʱ���Empty List��
    LNode *p=CL->next;  //pָ���һ��Ԫ�ؽ��
    if(p==CL){
      printf("Empty List");
      return;
    }
    while(p!=CL)
    {
        if(p->next!=CL)
            printf("%d ",p->data);
        else
            printf("%d",p->data);
        p=p->next;
    }
}
int main()
{
    LinkList CL;
    ElemType min,max;
    if(ListCreate_CL(CL)!= OK)
    {
       printf("ѭ��������ʧ�ܣ�����\n");
       return -1;
    }
    scanf("%d%d",&min,&max);

    ListDelete_CL(CL,min,max);

    ListPrint_CL(CL);
    return 0;
}
//------------------��ҵ����---------------------------
Status ListCreate_CL(LinkList &CL) {
    //����ͷ���
    CL = (LNode*)malloc(sizeof(LNode));
    if(!CL)
        exit(OVERFLOW);
    //��CL����rearPtr��curPtr����nΪ�㣬curPtr��nextָ��CL
    LNode* curPtr;
    LNode* rearPtr;
    rearPtr = CL;
    curPtr = CL;
    int n;
    scanf("%d",&n);
    //���򣬴���n���½ڵ㣬��һ�ڵ��nextָ���½ڵ㣬
    //rearPtrָ���½ڵ�
    for(int i = 0; i < n; i++) {
        curPtr = (LNode*)malloc(sizeof(LNode));
        if(!curPtr)
            exit(OVERFLOW);
        scanf("%d",&curPtr->data);
        rearPtr->next = curPtr;
        rearPtr = curPtr;
    }
    curPtr->next = CL;

    return OK;
}

void ListDelete_CL(LinkList &CL, ElemType min, ElemType max) {
    //rearPtrָ��ͷ��㣬curPtrָ���һ���ڵ�
    LNode * curPtr;
    LNode* rearPtr;
    int _min = min,_max = max;
    rearPtr = CL;
    curPtr = CL->next;
    //��ǰ�ڵ�Ϊͷ���ʱ����
    while(curPtr != CL) {
        //�����ǰ�ڵ����ݴ�С����Ҫ��rearPtr��nextָ��curPtr����һ���ڵ�
        //�ͷ�curPtr��ָ�ڴ棬curPtrָ����һ���ڵ�
        if(curPtr->data > _min && curPtr->data < _max) {
            rearPtr->next = curPtr->next;
            free(curPtr);
            curPtr = rearPtr->next;
        }
        //������Ҫ��βָ���뵱ǰָ�������һ���ڵ�
        else {
            rearPtr = rearPtr->next;
            curPtr = curPtr->next;
        }
    }
}
