#include <stdio.h>

typedef enum {false, true} bool;
#define MaxVertexNum 10  /* ��󶥵�����Ϊ10 */
#define INFINITY 65535   /* ����Ϊ˫�ֽ��޷������������ֵ65535*/
typedef int Vertex;      /* �ö����±��ʾ����,Ϊ���� */
typedef int WeightType;  /* �ߵ�Ȩֵ��Ϊ���� */

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;  /* ������ */
    int Ne;  /* ����   */
    WeightType G[MaxVertexNum][MaxVertexNum]; /* �ڽӾ��� */
};
typedef PtrToGNode MGraph; /* ���ڽӾ���洢��ͼ���� */
bool Visited[MaxVertexNum]; /* ����ķ��ʱ�� */

MGraph CreateGraph(); /* ����ͼ���ҽ�Visited��ʼ��Ϊfalse������ʵ�֣�ϸ�ڲ��� */

void Visit( Vertex V )
{
    printf(" %d", V);
}

void DFS( MGraph Graph, Vertex V, void (*Visit)(Vertex) );

int main()
{
    MGraph G;
    Vertex V;

    G = CreateGraph();
    scanf("%d", &V);
    printf("DFS from %d:", V);
    DFS(G, V, Visit);

    return 0;
}

void DFS(MGraph Graph, Vertex V, void(*Visit)(Vertex))
{   /* ��VΪ��������ڽӱ�洢��ͼGraph����DFS���� */
    Vertex W;

    Visit(V); /* ���ʵ�V������ */
    Visited[V] = true; /* ���V�ѷ��� */

    for (W = 0; W<Graph->Nv;W++ ) /* ��V��ÿ���ڽӵ�W */
        if ((!Visited[W])&&(Graph->G[V][W]==1))    /* ��δ������ */
            DFS(Graph, W, Visit);    /* ��ݹ����֮ */
}
//http://blog.csdn.net/lafengxiaoyu/article/details/53493080
