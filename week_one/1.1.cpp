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
typedef int Elemtype;  //�������Ա��е�Ԫ�ؾ�Ϊ����
typedef struct{
    Elemtype* elem;   //�洢�ռ����ַ
    int length;       //����Ԫ�صĸ���
    int listsize;     //��������С
}SqList;    //˳������Ͷ���
Status ListInsert_Sq(SqList &L, int pos, Elemtype e);
Status ListDelete_Sq(SqList &L, int pos, Elemtype &e);
int ListLocate_Sq(SqList L, Elemtype e);
void ListPrint_Sq(SqList L);

//�ṹ��ʼ�������ٲ���
Status InitList_Sq(SqList &L){
  //��ʼ��LΪһ���յ�����˳���
    L.elem=(Elemtype *)malloc(LIST_INIT_SIZE*sizeof(Elemtype));
    if(!L.elem)exit(OVERFLOW);
    L.listsize=LIST_INIT_SIZE;
    L.length=0;
    return OK;
}


int main() {
    SqList L;

    if(InitList_Sq(L)!= OK) {
        printf("InitList_Sq: ��ʼ��ʧ�ܣ�����\n");
        return -1;
    }

    for(int i = 1; i <= 10; ++ i)
        ListInsert_Sq(L, i, i);

    int operationNumber;  //��������
    scanf("%d", &operationNumber);

    while(operationNumber != 0) {
        int operationType;  //��������
        scanf("%d", & operationType);

        if(operationType == 1) {  //���Ӳ���
            int pos, elem;
            scanf("%d%d", &pos, &elem);
            ListInsert_Sq(L, pos, elem);
        } else if(operationType == 2) {  //ɾ������
             int pos; Elemtype elem;
             scanf("%d", &pos);
             ListDelete_Sq(L, pos, elem);
             printf("%d\n", elem);
        } else if(operationType == 3) {  //���Ҷ�λ����
            Elemtype elem;
            scanf("%d", &elem);
            int pos = ListLocate_Sq(L, elem);
            if(pos >= 1 && pos <= L.length)
                printf("%d\n", pos);
            else
                printf("NOT FIND!\n");
        } else if(operationType == 4) {  //�������
            ListPrint_Sq(L);
        }
       operationNumber--;
    }
    return 0;
}

/* ����������д�� */
//��������
Status ListInsert_Sq(SqList &L, int pos, Elemtype e) {
    if(pos < 1)
        return ERROR;
    if(pos >= L.listsize) {
        SqList temp;
        temp.elem = (Elemtype*)realloc(L.elem,(LIST_INIT_SIZE+LISTINCREMENT)*sizeof(Elemtype));
        if(InitList_Sq(temp)!= OK) {
            printf("InitList_Sq: ��ʼ��ʧ�ܣ�����\n");
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

//ɾ������
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

//��˳����ж�λ
int ListLocate_Sq(SqList L, Elemtype e) {
    int counter;
    for(counter = 0; counter < L.length; counter++) {
        if(L.elem[counter] == e)
           return counter+1;
    }
    if(L.length == counter+1)
        return 0;
}

//���˳���
void ListPrint_Sq(SqList L) {
    for(int counter = 0; counter < L.length; counter++) {
        if(counter == 0)
            printf("%d",L.elem[counter]);
        else
            printf(" %d",L.elem[counter]);
    }
}
