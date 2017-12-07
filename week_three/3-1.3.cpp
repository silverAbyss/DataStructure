#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int status;
typedef int ElemType;
typedef struct LNode{
    struct LNode* next;
    ElemType data;
}LNode,*Linklist;

#define    TRUE    1
#define    FALSE   0
#define    OK      1
#define    ERROR   0
#define    OVERFLOW    -2
void PrintList(Linklist L);
//���루β�����룩����
status InputList(Linklist & L) {
   LNode * curPtr, * rearPtr;
   rearPtr = L;  //��ʼʱͷ���Ϊβ�ڵ�,rearPtrָ��β�ͽڵ�
    while(1){  //ÿ��ѭ��������һ���½ڵ㣬�����½ڵ�ƴ��β�ڵ��
        int e;
        scanf("%d",&e);
        if(e == -1) break;
        curPtr = (LNode*)malloc(sizeof(LNode));//�����½��
        if(!curPtr) exit(OVERFLOW);
        curPtr->data = e;//����Ԫ��ֵ
        curPtr->next = NULL;  //���һ���ڵ��next����
        rearPtr->next = curPtr;
        rearPtr = curPtr;
    }
    return OK;
}
//�������
void PrintList(Linklist L) {
    LNode* curPtr;
    curPtr = L->next;
    if(curPtr == NULL) {
        printf("NULL\n");
        return ;
    }
    while(curPtr != NULL) {
        if(L->next == curPtr)
            printf("%d",curPtr->data);
        else
            printf(" %d",curPtr->data);
        curPtr = curPtr->next;
    }
    printf("\n");
}
//��ʼ������
status InitList(Linklist & L) {
    LNode * temp;
    temp = (LNode* )malloc(sizeof(LNode));
    if(!temp) exit(OVERFLOW);
    L = temp;
    L->next = NULL;
    return OK;
}
//�ǽ���ϲ�
status MergeList(Linklist la,Linklist lb,Linklist &lc) {
    LNode* la_ptr,*lb_ptr,*lc_ptr;
    la_ptr = la->next;
    lb_ptr = lb->next;
    lc_ptr = lc;
    while(la_ptr && lb_ptr) {
        if(la_ptr->data <= lb_ptr->data){
            lc_ptr->next = la_ptr;
            la_ptr = la_ptr->next;
        }
        else {
            lc_ptr->next = lb_ptr;
            lb_ptr = lb_ptr->next;
        }
        lc_ptr = lc_ptr->next;
    }
    lc_ptr->next = la_ptr ? la_ptr : lb_ptr;
    return OK;
}
int main()
{
    Linklist La,Lb,Lc;
    InitList(La);
    InitList(Lb);
    InitList(Lc);

    InputList(La);
    InputList(Lb);

    MergeList(La,Lb,Lc);
    PrintList(La);
    return 0;
}
