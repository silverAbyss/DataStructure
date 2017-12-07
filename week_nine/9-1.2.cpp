#include<stdio.h>
#define MAX 100

//void PrintNexus(int Nexus[MAX][MAX],int _max) {
//    for(int i = 0; i < _max; i++) {
//        for(int j = 0; j < _max; j++)
//            printf("%d\t",Nexus[i][j]);
//        printf("\n");
//    }
//}
void InitNexus(int Nexus[MAX][MAX],int _max) {
    for(int i = 0; i < _max; i++) {
        for(int j = 0; j < _max; j++)
            Nexus[i][j] = 0;
    }
}
void InputArcs(int Nexus[MAX][MAX],int arcs) {
    for(int i = 0; i < arcs; i++) {
        int codntX,codntY,nexus;
        scanf("%d%d%d",&codntX,&codntY,&nexus);
        Nexus[codntX-1][codntY-1] = nexus;
        Nexus[codntY-1][codntX-1] = nexus;
    }
}
void JudgeSeat(int Nexus[MAX][MAX],int _max,int numOfJudge) {
    for(int i = 0; i < numOfJudge; i++) {
        int guest1,guest2,j;
        scanf("%d%d",&guest1,&guest2);
        //�����guest1-1�е�guest2-1��Ϊ1����no problem
        if(Nexus[guest1-1][guest2-1] == 1)
            printf("No problem\n");
        //���Ϊ0����ok
        else if(Nexus[guest1-1][guest2-1] == 0)
            printf("OK\n");
        //���Ϊ-1
        else if(Nexus[guest1-1][guest2-1] == -1){
            //�ҵ�guest1-1����guest2-1����ͬһ�еľ�Ϊ1����ok but...
            for(j = 0; j < _max; j++) {
                if(Nexus[guest1-1][j] == 1 && Nexus[guest2-2][j] == 1){
                    printf("OK but...\n");
                    break;
                }
            }
            //����no way
            if(j == _max)
                printf("No way\n");
        }
    }
}

int main()
{
    //����һ��100x100�����飬�б�ʾ��һλ���ˣ��б�ʾ�ÿ����������˵Ĺ�ϵ
    int Nexus[MAX][MAX];
    int numOfPeople,arcs,numOfJudge;
    scanf("%d%d%d",&numOfPeople,&arcs,&numOfJudge);
    InitNexus(Nexus,numOfPeople);
    InputArcs(Nexus,arcs);
    //PrintNexus(Nexus,numOfPeople);
    JudgeSeat(Nexus,numOfPeople,numOfJudge);
    return 0;
}
