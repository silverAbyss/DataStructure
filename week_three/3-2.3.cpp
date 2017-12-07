#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int status;
typedef int ElemType;
typedef struct LNode {
    struct LNode * next;
    ElemType data;
}LNode,*Linklist;

//״̬�붨��
#define    TRUE    1
#define    FALSE   0
#define    OK      1
#define    ERROR   0
#define    OVERFLOW    -2

status CreatList_L(Linklist & L) {
    LNode* temp, *rearPtr;
    temp = (LNode* )malloc (sizeof(LNode));
    if(!temp) exit(OVERFLOW);
    L = temp;
    rearPtr = L;
    int num;
    while(scanf("%d",&num)) {
        if(num < 0) break;
        temp = (LNode* )malloc (sizeof(LNode));
        if(!temp) exit(OVERFLOW);
        temp->data = num;
        rearPtr->next = temp;
        rearPtr = rearPtr->next;
    }
    rearPtr = NULL;
    return OK;
}

int main()
{
    //��������
    Linklist  L;
    int k;
    scanf("%d",&k);
    if(CreatList_L(L) != OK) {
        printf("������ʧ�ܣ�\n");
        return -1;
    }
    //��������ָ�룬һ��ָ��ָ���K��Ԫ�أ���һ��ָ��ָ��ͷ���
    LNode* fristPtr, * secondPtr;
    fristPtr = L;
    secondPtr = L;
    int i;
    for(i = 0; i < k; i ++) {
        fristPtr = fristPtr->next;
    }
    //����ָ��ͬʱ���ƣ�����һ��ָ��Ϊ��ʱ��ȡ��һָ���Ԫ��
    while(fristPtr != NULL) {
        fristPtr = fristPtr->next;
        secondPtr = secondPtr->next;
        //printf("test here : fristPtr->data is %d,secondPtr->data is %d\n",fristPtr->data,secondPtr->data);
    }
    //���������Ƿ�Ϊ�գ������NULL���ǿ������K��Ԫ��
    if(secondPtr == NULL)
        printf("NULL\n");
    else
        printf("%d\n",secondPtr->data);

    return 0;
}
