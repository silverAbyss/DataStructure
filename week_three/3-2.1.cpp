//函数库头文件包含
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

//状态码定义
#define    TRUE    1
#define    FALSE   0
#define    OK      1
#define    ERROR   0
#define    OVERFLOW    -2

void PrintList(Linklist l);
//初始化链表
status ListCreat_L(Linklist & L) {
    LNode * temp;
    temp = (LNode* )malloc(sizeof(LNode));
    if(!temp) exit(OVERFLOW);
    L = temp;
    L->next = NULL;
    return OK;
}
//输入（尾部插入）链表
status InputList(Linklist & L) {
   int n;
   scanf("%d",&n);
   LNode * curPtr, * rearPtr;
   rearPtr = L;  //初始时头结点为尾节点,rearPtr指向尾巴节点
    for(int i = 0; i < n; i++){  //每次循环都开辟一个新节点，并把新节点拼到尾节点后
        curPtr = (LNode*)malloc(sizeof(LNode));//生成新结点
        if(!curPtr) exit(OVERFLOW);
        scanf("%d %d",&curPtr->coef,&curPtr->expn);//输入元素值
        rearPtr->next = curPtr;
        rearPtr = curPtr;
    }
    rearPtr->next = NULL;  //最后一个节点的next赋空
    return OK;
}

void PrintList(Linklist lc) {
	LNode *hc;
	int flag = 0;
	hc = lc->next; //指针操作常用，用新创立的节点代替源节点操作
	if(hc == NULL){ //格式控制
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
        printf("链表创建失败！\n");
        return Lc;
    }
    //按照指数降序排列插入到Lc中
    LNode* la_Ptr,* lb_Ptr, *lc_Ptr, *temp;
    la_Ptr = La->next;
    lb_Ptr = Lb->next;
    lc_Ptr = Lc;
    while(la_Ptr && lb_Ptr) {
        //如果la的指数大，la先插入
        if(la_Ptr->expn > lb_Ptr->expn) {
            lc_Ptr->next = la_Ptr;
            la_Ptr = la_Ptr->next;
        }
        //如果lb的指数大，lb先插入
        else if(la_Ptr->expn < lb_Ptr->expn) {
            lc_Ptr->next = lb_Ptr;
            lb_Ptr = lb_Ptr->next;
        }
        //如果相等，开辟新节点，系数相加在插入
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
    //La的每一项乘以Lb的每一项
    LNode* la, *lb, *lc, *temp, *ans, *cur;
    //la与lb分别遍历La、Lb，lc指向新链表的最后一个节点
    la = La->next;
    lb = Lb->next;
    lc = Lc;
    //每次相乘的结果存在ans链表内
    ans = (LNode* )malloc(sizeof(LNode));
    if(!ans) exit(OVERFLOW);
    ans->next = NULL;

    //printf("--test here is OK---\n");
    while(la != NULL) {
        cur = ans;//cur作为遍历ans的指针
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
    //每次相乘运算结果相加，即每次结果与Lc相加
    return OK;
}

int main()
{
    Linklist La,Lb,Lc;

    if(ListCreat_L(La) != OK) {
        printf("链表创建失败！\n");
        return -1;
    }
    if(ListCreat_L(Lb) != OK) {
        printf("链表创建失败！\n");
        return -1;
    }
    //分别输入两个多项式的系数和指数
    InputList(La);
    InputList(Lb);

    //多项式相乘
    //MultiList(La,Lb,Lc);
    //输出多项式
    //PrintList(Lc);
    printf("\n");

    //多项式相加
    Lc = AddList(La,Lb);
    //输出多项式
    PrintList(Lc);
    return 0;
}
