    #include <stdio.h>
    #include <stdlib.h>

    #define MaxVertexNum 100    /* 最大顶点数设为100 */
    typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */
    typedef int WeightType;        /* 边的权值设为整型 */
    typedef char DataType;        /* 顶点存储的数据类型设为字符型 */

    int Visited[MaxVertexNum];
    /* 边的定义 */
    typedef struct ENode *PtrToENode;
    struct ENode {
        Vertex V1, V2;      /* 有向边<V1, V2> */
    };
    typedef PtrToENode Edge;

    /* 邻接点的定义 */
    typedef struct AdjVNode *PtrToAdjVNode;
    struct AdjVNode {
        Vertex AdjV;        /* 邻接点下标 */
        PtrToAdjVNode Next;    /* 指向下一个邻接点的指针 */
    };

    /* 顶点表头结点的定义 */
    typedef struct Vnode {
        PtrToAdjVNode FirstEdge;/* 边表头指针 */
    } AdjList[MaxVertexNum];    /* AdjList是邻接表类型 */

                                /* 图结点的定义 */
    typedef struct GNode *PtrToGNode;
    struct GNode {
        int Nv;     /* 顶点数 */
        int Ne;     /* 边数   */
        AdjList G;  /* 邻接表 */
    };
    typedef PtrToGNode LGraph; /* 以邻接表方式存储的图类型 */
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
    { /* 初始化一个有VertexNum个顶点但没有边的图 */
        Vertex V;
        LGraph Graph;

        Graph = (LGraph)malloc(sizeof(struct GNode)); /* 建立图 */
        Graph->Nv = VertexNum;
        Graph->Ne = 0;
        /* 初始化邻接表头指针 */
        /* 注意：这里默认顶点编号从0开始，到(Graph->Nv - 1) */
        for (V = 0; V<Graph->Nv; V++)
            Graph->G[V].FirstEdge = NULL;

        return Graph;
    }

    void InsertEdge(LGraph Graph, Edge E)
    {
        PtrToAdjVNode NewNode;

        /* 插入边 <V1, V2> */
        /* 为V2建立新的邻接点 */
        NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
        NewNode->AdjV = E->V2;
        /* 将V2插入V1的表头 */
        NewNode->Next = Graph->G[E->V1].FirstEdge;
        Graph->G[E->V1].FirstEdge = NewNode;

        /* 若是无向图，还要插入边 <V2, V1> */
        /* 为V1建立新的邻接点 */
        NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
        NewNode->AdjV = E->V1;
        /* 将V1插入V2的表头 */
        NewNode->Next = Graph->G[E->V2].FirstEdge;
        Graph->G[E->V2].FirstEdge = NewNode;
    }

    LGraph BuildGraph()
    {
        LGraph Graph;
        Edge E;
        Vertex V;
        int Nv, i;

        scanf("%d", &Nv);   /* 读入顶点个数 */
        Graph = CreateGraph(Nv); /* 初始化有Nv个顶点但没有边的图 */

        scanf("%d", &(Graph->Ne));   /* 读入边数 */
        if (Graph->Ne != 0) { /* 如果有边 */
            E = (Edge)malloc(sizeof(struct ENode)); /* 建立边结点 */
                                                    /* 读入边，格式为"起点 终点 权重"，插入邻接矩阵 */
            for (i = 0; i<Graph->Ne; i++) {
                scanf("%d %d", &E->V1, &E->V2);
                /* 注意：如果权重不是整型，Weight的读入格式要改 */
                InsertEdge(Graph, E);
            }
        }
        return Graph;
    }


    /* 邻接表存储的图 - DFS */

    void Visit(Vertex V)
    {
        printf("正在访问顶点%d\n", V+1);
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
            printf("队列空");
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
    /* 邻接表存储的图 - BFS */


    /* Visited[]为全局变量，已经初始化为false */
    void BFS(LGraph Graph, Vertex S, void(*Visit)(Vertex))
    {   /* 以S为出发点对邻接矩阵存储的图Graph进行BFS搜索 */
        Queue Q;
        Vertex V;
        PtrToAdjVNode W;

        Q = CreateQueue(); /* 创建空队列, MaxSize为外部定义的常数 */

        /* 访问顶点S：此处可根据具体访问需要改写 */
        Visit(S);
        Visited[S] = true; /* 标记S已访问 */
        InsertQ(S, Q); /* S入队列 */

        while (!IsEmpty(Q)) {
            V = DeleteQ(Q);  /* 弹出V */
            for (W = Graph->G[V].FirstEdge; W; W = W->Next) /* 对V的每个邻接点W->AdjV */
                if (!Visited[W->AdjV])    /* 若W->AdjV未被访问 */
                    {
                    /* 访问顶点W */
                    Visit(W->AdjV);
                    Visited[W->AdjV] = true; /* 标记W已访问 */
                    InsertQ(W->AdjV, Q); /* W入队列 */
                }
        } /* while结束*/
    }

    int main() {
        LGraph Graph = CreateGraph(6);
        Graph->Ne = 8;
        Vertex a[8] = { 0,0,0,1,1,3,2,3 };
        Vertex b[8] = { 1,2,4,3,4,4,5,5 };

        /* 读入边，格式为"起点 终点 权重"，插入邻接矩阵 */
        for (int i = 0; i<Graph->Ne; i++) {
            Edge E = (Edge)malloc(sizeof(struct ENode)); /* 建立边结点 */
            E->V1 = a[i]; E->V2 = b[i];
            /* 注意：如果权重不是整型，Weight的读入格式要改 */
            InsertEdge(Graph, E);
        }


        for (int i = 0; i < MaxVertexNum; i++) {Visited[i] = false; }
        BFS(Graph, 0, Visit);
        system("pause");
    }
