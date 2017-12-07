    #include <stdio.h>
    #include <stdlib.h>

    #define MaxVertexNum 100    /* ��󶥵�����Ϊ100 */
    typedef int Vertex;         /* �ö����±��ʾ����,Ϊ���� */
    typedef int WeightType;        /* �ߵ�Ȩֵ��Ϊ���� */
    typedef char DataType;        /* ����洢������������Ϊ�ַ��� */

    int Visited[MaxVertexNum];
    /* �ߵĶ��� */
    typedef struct ENode *PtrToENode;
    struct ENode {
        Vertex V1, V2;      /* �����<V1, V2> */
    };
    typedef PtrToENode Edge;

    /* �ڽӵ�Ķ��� */
    typedef struct AdjVNode *PtrToAdjVNode;
    struct AdjVNode {
        Vertex AdjV;        /* �ڽӵ��±� */
        PtrToAdjVNode Next;    /* ָ����һ���ڽӵ��ָ�� */
    };

    /* �����ͷ���Ķ��� */
    typedef struct Vnode {
        PtrToAdjVNode FirstEdge;/* �߱�ͷָ�� */
    } AdjList[MaxVertexNum];    /* AdjList���ڽӱ����� */

                                /* ͼ���Ķ��� */
    typedef struct GNode *PtrToGNode;
    struct GNode {
        int Nv;     /* ������ */
        int Ne;     /* ����   */
        AdjList G;  /* �ڽӱ� */
    };
    typedef PtrToGNode LGraph; /* ���ڽӱ�ʽ�洢��ͼ���� */
    #define ERROR 0

    struct Node {
        int Data;
        struct Node *Next;
    };

    struct QNode {
        struct Node *rear;
        struct Node *front;
    };
    typedef struct QNode *Queue;




    LGraph CreateGraph(int VertexNum)
    { /* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
        Vertex V;
        LGraph Graph;

        Graph = (LGraph)malloc(sizeof(struct GNode)); /* ����ͼ */
        Graph->Nv = VertexNum;
        Graph->Ne = 0;
        /* ��ʼ���ڽӱ�ͷָ�� */
        /* ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) */
        for (V = 0; V<Graph->Nv; V++)
            Graph->G[V].FirstEdge = NULL;

        return Graph;
    }

    void InsertEdge(LGraph Graph, Edge E)
    {
        PtrToAdjVNode NewNode;

        /* ����� <V1, V2> */
        /* ΪV2�����µ��ڽӵ� */
        NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
        NewNode->AdjV = E->V2;
        /* ��V2����V1�ı�ͷ */
        NewNode->Next = Graph->G[E->V1].FirstEdge;
        Graph->G[E->V1].FirstEdge = NewNode;

        /* ��������ͼ����Ҫ����� <V2, V1> */
        /* ΪV1�����µ��ڽӵ� */
        NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
        NewNode->AdjV = E->V1;
        /* ��V1����V2�ı�ͷ */
        NewNode->Next = Graph->G[E->V2].FirstEdge;
        Graph->G[E->V2].FirstEdge = NewNode;
    }

    LGraph BuildGraph()
    {
        LGraph Graph;
        Edge E;
        Vertex V;
        int Nv, i;

        scanf("%d", &Nv);   /* ���붥����� */
        Graph = CreateGraph(Nv); /* ��ʼ����Nv�����㵫û�бߵ�ͼ */

        scanf("%d", &(Graph->Ne));   /* ������� */
        if (Graph->Ne != 0) { /* ����б� */
            E = (Edge)malloc(sizeof(struct ENode)); /* �����߽�� */
                                                    /* ����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ��� */
            for (i = 0; i<Graph->Ne; i++) {
                scanf("%d %d", &E->V1, &E->V2);
                /* ע�⣺���Ȩ�ز������ͣ�Weight�Ķ����ʽҪ�� */
                InsertEdge(Graph, E);
            }
        }
        return Graph;
    }


    /* �ڽӱ�洢��ͼ - DFS */

    void Visit(Vertex V)
    {
        printf("���ڷ��ʶ���%d\n", V+1);
    }


    int IsEmpty(Queue Q) {
        return(Q->front == NULL);
    };

    Queue CreateQueue() {
        Queue PtrQ;
        PtrQ = (Queue)malloc(sizeof(struct QNode));
        struct Node *rear;
        struct Node *front;
        rear = (Node*)malloc(sizeof(struct Node));
        rear = NULL;
        front = (Node*)malloc(sizeof(struct Node));
        front = NULL;
        PtrQ->front = front;
        PtrQ->rear = rear;
        return PtrQ;
    };

    int DeleteQ(Queue PtrQ) {
        struct Node *FrontCell;
        int FrontElem;

        if (IsEmpty(PtrQ)) {
            printf("���п�");
            return ERROR;
        }
        FrontCell = PtrQ->front;
        if (PtrQ->front == PtrQ->rear)
            PtrQ->front = PtrQ->rear = NULL;
        else {
            PtrQ->front = PtrQ->front->Next;
        }
        FrontElem = FrontCell->Data;
        free(FrontCell);
        return FrontElem;
    }

    void InsertQ(int item, Queue PtrQ) {
        struct Node *FrontCell;
        FrontCell = (Node*)malloc(sizeof(struct Node));
        FrontCell->Data = item;
        FrontCell->Next = NULL;

        if (IsEmpty(PtrQ)) {
            PtrQ->front = FrontCell;
            PtrQ->rear = FrontCell;
        }
        else {
            PtrQ->rear->Next = FrontCell;
            PtrQ->rear = FrontCell;
        }
    };
    /* �ڽӱ�洢��ͼ - BFS */


    /* Visited[]Ϊȫ�ֱ������Ѿ���ʼ��Ϊfalse */
    void BFS(LGraph Graph, Vertex S, void(*Visit)(Vertex))
    {   /* ��SΪ��������ڽӾ���洢��ͼGraph����BFS���� */
        Queue Q;
        Vertex V;
        PtrToAdjVNode W;

        Q = CreateQueue(); /* �����ն���, MaxSizeΪ�ⲿ����ĳ��� */

        /* ���ʶ���S���˴��ɸ��ݾ��������Ҫ��д */
        Visit(S);
        Visited[S] = true; /* ���S�ѷ��� */
        InsertQ(S, Q); /* S����� */

        while (!IsEmpty(Q)) {
            V = DeleteQ(Q);  /* ����V */
            for (W = Graph->G[V].FirstEdge; W; W = W->Next) /* ��V��ÿ���ڽӵ�W->AdjV */
                if (!Visited[W->AdjV])    /* ��W->AdjVδ������ */
                    {
                    /* ���ʶ���W */
                    Visit(W->AdjV);
                    Visited[W->AdjV] = true; /* ���W�ѷ��� */
                    InsertQ(W->AdjV, Q); /* W����� */
                }
        } /* while����*/
    }

    int main() {
        LGraph Graph = CreateGraph(6);
        Graph->Ne = 8;
        Vertex a[8] = { 0,0,0,1,1,3,2,3 };
        Vertex b[8] = { 1,2,4,3,4,4,5,5 };

        /* ����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ��� */
        for (int i = 0; i<Graph->Ne; i++) {
            Edge E = (Edge)malloc(sizeof(struct ENode)); /* �����߽�� */
            E->V1 = a[i]; E->V2 = b[i];
            /* ע�⣺���Ȩ�ز������ͣ�Weight�Ķ����ʽҪ�� */
            InsertEdge(Graph, E);
        }


        for (int i = 0; i < MaxVertexNum; i++) {Visited[i] = false; }
        BFS(Graph, 0, Visit);
        system("pause");
    }
