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
typedef int elementType;

typedef struct lnode

{ elementType data;

struct lnode *next;

}Lnode,* LinkList;

int LinklistCreate_L(LinkList &CL)//����һ����ͷ��������
{
    Lnode *curPtr, *rearPtr;
    int n;
    CL=(Lnode*)malloc(sizeof(Lnode));//����һ��ͷ���
    if(!CL) exit(OVERFLOW);
    CL->next = CL;//���ҳ�ʼ��Ϊcl
    rearPtr=CL;//��ǰβ���Ϊͷ���
    scanf("%d", &n);
    for(int i=0; i<n; i++)//ѭ��ָ������
    {
        curPtr = (Lnode*)malloc(sizeof(Lnode));//ÿ��ѭ��������һ���½�㣬��ֵ���½ڵ�
        if(!CL) exit(OVERFLOW);
        scanf("%d", &curPtr->data);
        rearPtr->next=curPtr;
        rearPtr=curPtr;//ƴ��
    }
    rearPtr->next=NULL;//β���Ϊ��
    return OK;
}

int LinklistInsert(LinkList &CL, int x)//��������һ���������Ұ�˳�����
{
    Lnode *curPtr, *prePtr, *inPtr;
    int flag=0;
    curPtr=CL->next;
    prePtr=CL;
    while(curPtr!=NULL)//��������
    {
        if(x<=curPtr->data)//������������Ӧ�������ڵ�λ�� ��Ž�����
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
    //���������,�ձ�ʱ���Empty List��
    Lnode *p=CL->next;  //pָ���һ��Ԫ�ؽ��
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
        printf("ѭ��������ʧ�ܣ�����\n");
        return -1;
    }
    scanf("%d",&x);
    LinklistInsert(CL, x);
    ListPrint_CL(CL);
    return 0;
}
