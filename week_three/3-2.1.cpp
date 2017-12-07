//������ͷ�ļ�����
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int ElemType;
typedef int status;
typedef struct LNode{
    struct LNode * next;
    ElemType coef;
    ElemType expn;
}LNode,*Linklist;

//״̬�붨��
#define    TRUE    1
#define    FALSE   0
#define    OK      1
#define    ERROR   0
#define    OVERFLOW    -2

void PrintList(Linklist l);
//��ʼ������
status ListCreat_L(Linklist & L) {
    LNode * temp;
    temp = (LNode* )malloc(sizeof(LNode));
    if(!temp) exit(OVERFLOW);
    L = temp;
    L->next = NULL;
    return OK;
}
//���루β�����룩����
status InputList(Linklist & L) {
   int n;
   scanf("%d",&n);
   LNode * curPtr, * rearPtr;
   rearPtr = L;  //��ʼʱͷ���Ϊβ�ڵ�,rearPtrָ��β�ͽڵ�
    for(int i = 0; i < n; i++){  //ÿ��ѭ��������һ���½ڵ㣬�����½ڵ�ƴ��β�ڵ��
        curPtr = (LNode*)malloc(sizeof(LNode));//�����½��
        if(!curPtr) exit(OVERFLOW);
        scanf("%d %d",&curPtr->coef,&curPtr->expn);//����Ԫ��ֵ
        rearPtr->next = curPtr;
        rearPtr = curPtr;
    }
    rearPtr->next = NULL;  //���һ���ڵ��next����
    return OK;
}

void PrintList(Linklist lc) {
	LNode *hc;
	int flag = 0;
	hc = lc->next; //ָ��������ã����´����Ľڵ����Դ�ڵ����
	if(hc == NULL){ //��ʽ����
		printf("0 0");
	}
	while(hc != NULL){
		if(flag)
			printf(" ");
		else
			flag = 1;
		printf("%d %d",hc->coef,hc->expn);
		hc = hc->next;
	}
}

Linklist AddList(Linklist La,Linklist Lb) {
    Linklist Lc;
    if(ListCreat_L(Lc) != OK) {
        printf("������ʧ�ܣ�\n");
        return Lc;
    }
    //����ָ���������в��뵽Lc��
    LNode* la_Ptr,* lb_Ptr, *lc_Ptr, *temp;
    la_Ptr = La->next;
    lb_Ptr = Lb->next;
    lc_Ptr = Lc;
    while(la_Ptr && lb_Ptr) {
        //���la��ָ����la�Ȳ���
        if(la_Ptr->expn > lb_Ptr->expn) {
            lc_Ptr->next = la_Ptr;
            la_Ptr = la_Ptr->next;
        }
        //���lb��ָ����lb�Ȳ���
        else if(la_Ptr->expn < lb_Ptr->expn) {
            lc_Ptr->next = lb_Ptr;
            lb_Ptr = lb_Ptr->next;
        }
        //�����ȣ������½ڵ㣬ϵ������ڲ���
        else {
            temp = (LNode* )malloc(sizeof(LNode));
            if(!temp) exit(OVERFLOW);
            temp->coef = la_Ptr->coef + lb_Ptr->coef;
            temp->expn = la_Ptr->expn;
            lc_Ptr->next = temp;
            la_Ptr = la_Ptr->next;
            lb_Ptr = lb_Ptr->next;
        }
        lc_Ptr = lc_Ptr->next;
    }
    while(la_Ptr) {
        lc_Ptr->next = la_Ptr;
        lc_Ptr = lc_Ptr->next;
        la_Ptr = la_Ptr->next;
    }
    while(lb_Ptr) {
        lc_Ptr->next = lb_Ptr;
        lc_Ptr = lc_Ptr->next;
        lb_Ptr = lb_Ptr->next;
    }
    lc_Ptr->next = NULL;
    Lb = lc_Ptr;
    return Lb;
}

status MultiList(Linklist La, Linklist Lb, Linklist & Lc) {
    //La��ÿһ�����Lb��ÿһ��
    LNode* la, *lb, *lc, *temp, *ans, *cur;
    //la��lb�ֱ����La��Lb��lcָ������������һ���ڵ�
    la = La->next;
    lb = Lb->next;
    lc = Lc;
    //ÿ����˵Ľ������ans������
    ans = (LNode* )malloc(sizeof(LNode));
    if(!ans) exit(OVERFLOW);
    ans->next = NULL;

    //printf("--test here is OK---\n");
    while(la != NULL) {
        cur = ans;//cur��Ϊ����ans��ָ��
        while(lb != NULL ) {
            temp = (LNode* )malloc(sizeof(LNode));
            if(!temp) exit(OVERFLOW);
            temp->coef = la->coef * lb->coef;
            temp->expn = la->expn + lb->expn;
            cur->next = temp;
            cur = temp;
            lb = lb->next;
        }
        cur->next = NULL;
        AddList(ans,lc);
        cur = ans->next;
        while(cur) {
            temp = cur->next;
            free(cur);
            cur = temp;
        }
        lb = Lb->next;
        la = la->next;
    }
    //ÿ�������������ӣ���ÿ�ν����Lc���
    return OK;
}

int main()
{
    Linklist La,Lb,Lc;

    if(ListCreat_L(La) != OK) {
        printf("������ʧ�ܣ�\n");
        return -1;
    }
    if(ListCreat_L(Lb) != OK) {
        printf("������ʧ�ܣ�\n");
        return -1;
    }
    //�ֱ�������������ʽ��ϵ����ָ��
    InputList(La);
    InputList(Lb);

    //����ʽ���
    //MultiList(La,Lb,Lc);
    //�������ʽ
    //PrintList(Lc);
    printf("\n");

    //����ʽ���
    Lc = AddList(La,Lb);
    //�������ʽ
    PrintList(Lc);
    return 0;
}
