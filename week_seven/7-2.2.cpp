#include<stdio.h>
#include<stdlib.h>
#include<cstring>

typedef char TElemType;
typedef struct FamilyNode{
    TElemType name[11];
    struct FamilyNode *FristChild, *Sibing, *Parent;
}FamilyNode,*FamilyT;
typedef int status;
//״̬�붨��
#define TRUE    1
#define FALUSE  0
#define OK      1
#define ERROR   0
#define OVERFLOW    -2

status Creat_T(FT) {
    FamilyNode * Node;
    Node = (*FamilyNode) malloc(sizeof(FamilyNode));
    if(!Node) return ERROR;
    Node->FristChild = NULL;
    Node->Sibing = NULL;
    return OK;
}

int main()
{
    FamilyT FT;
    Creat_T(FT);//�������������ڵ�
    FamilyNode* p;//��ʱ�ڵ�
    int numOfMember, numOfJudge, front_space = 0, temp_space = 0;
    char temp_name[30];//��¼�ո�+���ֵ�����ȫ������

    scanf("%d %d",&numOfMember,&numOfJudge);
    for(int i = 0; i < numOfMember; i++) {
        gets(temp_name);
        int j = 0;
        while(temp_name[j] == ' ') {
            temp_space++;
            j += 2;
        }

        if(front_space == temp_space) {
            p = (*FamilyNode) malloc(sizeof(FamilyNode));
            if(!p) return ERROR;

        }
    }
    return 0;
}
