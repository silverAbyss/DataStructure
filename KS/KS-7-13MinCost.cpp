#include<cstdio>

#include<cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 101
#define INFINITY 65535

bool is_mark[MAX];//标记是否合并
int pathmatrirx[MAX][MAX];//所有路径长
int Dist[MAX];//当前连通量与其他地点的最短距离

int main()
{
    int numofvertex;
    vector<int > a;

    scanf("%d",&numofvertex);

    for(int i = 0; i < numofvertex; i++) {
        for(int j = 0; j < numofvertex; j++)
            pathmatrirx[i][j] = INFINITY;//初始化路径为最长
    }

    int arcs = numofvertex*(numofvertex-1)/2;
    //输入边即道路修建成本
    for(int i = 0; i < arcs; i++) {
        int vil1,vil2,cost,state;
        scanf("%d%d%d%d",&vil1,&vil2,&cost,&state);
        //如果该道路已修好，则不计成本
        if(state == 1) {
            pathmatrirx[vil1-1][vil2-1] = pathmatrirx[vil2-1][vil1-1] = 0;
        }
            //否则，记录修建成本
        else {
            pathmatrirx[vil1-1][vil2-1] = pathmatrirx[vil2-1][vil1-1] = cost;
        }
    }

    //初始化Dist表
    for(int i = 0; i < numofvertex; i++) {
        Dist[i] = pathmatrirx[0][i];
    }

    //标记第一个点，且第一个点到自身的距离更改为0
    is_mark[0] = true;
    Dist[0] = 0;
    int sum = 0;
    for(int i = 0; i < numofvertex; i++) {
        int minpath = INFINITY;
        int order = -1;
        for(int j = 1; j < numofvertex; j++) {
            if(minpath > Dist[j] && !is_mark[j]) {
                minpath = Dist[j];//选取目前离连通量最小的路径
                order = j;//记录离目前连通量最近的点的坐标
            }
        }
        //合并该点（标记该点）
        is_mark[order] = true;

        //每合并一个点，修改其他点到目前连通量的最小路径
        if(order != -1) {
            //最小路径求和
            sum += minpath;
            for(int j = 1; j < numofvertex; j++) {
                if(Dist[j] > pathmatrirx[order][j] && !is_mark[j]) {
                    //如果有点距离当前连通量的距离小于原距离，修改Dist表
                    Dist[j] = pathmatrirx[order][j];
                }
            }
        }
    }
    printf("%d\n",sum);
    return 0;
}
