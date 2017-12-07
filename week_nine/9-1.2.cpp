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
        //如果第guest1-1行第guest2-1列为1，则no problem
        if(Nexus[guest1-1][guest2-1] == 1)
            printf("No problem\n");
        //如果为0，则ok
        else if(Nexus[guest1-1][guest2-1] == 0)
            printf("OK\n");
        //如果为-1
        else if(Nexus[guest1-1][guest2-1] == -1){
            //且第guest1-1行与guest2-1行有同一列的均为1，则ok but...
            for(j = 0; j < _max; j++) {
                if(Nexus[guest1-1][j] == 1 && Nexus[guest2-2][j] == 1){
                    printf("OK but...\n");
                    break;
                }
            }
            //否则no way
            if(j == _max)
                printf("No way\n");
        }
    }
}

int main()
{
    //创建一个100x100的数组，行表示第一位客人，列表示该客人与其他人的关系
    int Nexus[MAX][MAX];
    int numOfPeople,arcs,numOfJudge;
    scanf("%d%d%d",&numOfPeople,&arcs,&numOfJudge);
    InitNexus(Nexus,numOfPeople);
    InputArcs(Nexus,arcs);
    //PrintNexus(Nexus,numOfPeople);
    JudgeSeat(Nexus,numOfPeople,numOfJudge);
    return 0;
}
