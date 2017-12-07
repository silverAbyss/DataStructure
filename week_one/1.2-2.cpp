
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
}LNode,*LinkList;

Status ListCreate_L(LinkList &L,int n)
{
    LNode *rearPtr,*curPtr;   //һ��βָ�룬һ��ָ���½ڵ��ָ��
    L=(LNode*)malloc(sizeof (LNode));
    if(!L)exit(OVERFLOW);
    L->next=NULL;               //�Ƚ���һ����ͷ���ĵ�����
    rearPtr=L;  //��ʼʱͷ���Ϊβ�ڵ�,rearPtrָ��β�ͽڵ�
    for (int i=1;i<=n;i++){  //ÿ��ѭ��������һ���½ڵ㣬�����½ڵ�ƴ��β�ڵ��
        curPtr=(LNode*)malloc(sizeof(LNode));//�����½��
        if(!curPtr)exit(OVERFLOW);
        scanf("%d",&curPtr->data);//����Ԫ��ֵ
        curPtr->next=NULL;  //���һ���ڵ��next����
        rearPtr->next=curPtr;
        rearPtr=curPtr;
    }
    return OK;
}
//��������Ҫʵ�ֵĺ���������
int ListLocate_L(LinkList L, ElemType x);

int main()
{
    LinkList L;
    int n;
    int x,k;
    scanf("%d",&n);  //����������Ԫ�ظ���
    if(ListCreate_L(L,n)!= OK) {
          printf("����ʧ�ܣ�����\n");
          return -1;
    }
   scanf("%d",&x); //���������Ԫ��
   k=ListLocate_L(L,x);
   printf("%d\n",k);
   return 0;
}

/* ����������д�� */
int ListLocate_L(LinkList L, ElemType x) {
    //����һ��ָ��ǰ�ڵ��ָ��
    LNode* curPtr = L->next;
    //����������counter,����������ǰ�ڵ�������ֵ=x������λ��
    int counter = 1;
    //����ǰָ��nextΪ�գ�ѭ������
    while(curPtr->next != NULL) {
        if(curPtr->data == x)
            return counter;
        //���򣬷���0
        else {
            curPtr = curPtr->next;
            counter++;
        }
    }
}
