#include<stdio.h>
#include<stdlib.h>
#define MAX 101
#define INFINITY 65535

bool is_mark[MAX];//����Ƿ�ϲ�
int pathmatrirx[MAX][MAX];//����·����
int Dist[MAX];//��ǰ��ͨ���������ص����̾���

int main()
{
    int numofvertex;
    scanf("%d",&numofvertex);
    for(int i = 0; i < numofvertex; i++) {
        for(int j = 0; j < numofvertex; j++)
            pathmatrirx[i][j] = INFINITY;//��ʼ��·��Ϊ�
    }

    int arcs = numofvertex*(numofvertex-1)/2;
    //����߼���·�޽��ɱ�
    for(int i = 0; i < arcs; i++) {
        int vil1,vil2,cost,state;
        scanf("%d%d%d%d",&vil1,&vil2,&cost,&state);
        //����õ�·���޺ã��򲻼Ƴɱ�
        if(state == 1) {
            pathmatrirx[vil1-1][vil2-1] = pathmatrirx[vil2-1][vil1-1] = 0;
        }
        //���򣬼�¼�޽��ɱ�
        else {
            pathmatrirx[vil1-1][vil2-1] = pathmatrirx[vil2-1][vil1-1] = cost;
        }
    }

    //��ʼ��Dist��
    for(int i = 0; i < numofvertex; i++) {
        Dist[i] = pathmatrirx[0][i];
    }

    //��ǵ�һ���㣬�ҵ�һ���㵽����ľ������Ϊ0
    is_mark[0] = 0;
    Dist[0] = 0;
    int sum = 0;
    for(int i = 0; i < numofvertex; i++) {
        int minpath = INFINITY;
        int order = -1;
        for(int j = 1; j < numofvertex; j++) {
            if(minpath > Dist[j] && !is_mark[j]) {
                minpath = Dist[j];//ѡȡĿǰ����ͨ����С��·��
                order = j;//��¼��Ŀǰ��ͨ������ĵ������
            }
        }
        //�ϲ��õ㣨��Ǹõ㣩
        is_mark[order] = true;

        //ÿ�ϲ�һ���㣬�޸������㵽Ŀǰ��ͨ������С·��
        if(order != -1) {
            //��С·�����
            sum += minpath;
            for(int j = 1; j < numofvertex; j++) {
                if(Dist[j] > pathmatrirx[order][j] && !is_mark[j]) {
                    //����е���뵱ǰ��ͨ���ľ���С��ԭ���룬�޸�Dist��
                    Dist[j] = pathmatrirx[order][j];
                }
            }
        }
    }
    printf("%d\n",sum);
    return 0;
}
