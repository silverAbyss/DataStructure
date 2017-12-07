    #include <cstdio>
    #include <cstdlib>
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <map>
    #include <stack>
    #include <iterator>
    #include <algorithm>

    using namespace std;

    #define N 12

    typedef struct node{
        char data;
        struct node* left;
        struct node* right;
        node(char _data = '-')
        {
            data = _data;
            left = NULL;
            right = NULL;
        }
    }Bnode;

    struct data{
        char c;
        int left;
        int right;
    };
    data vd[N];

    int fa[N];

    int find(int x)
    {
        if (x == fa[x])
            return x;
        return fa[x] = find(fa[x]);
    }
    void merg(int x, int y)
    {
        fa[find(y)] = find(x);
    }

    Bnode* createTree(Bnode* root, int num)
    {
        root = new node(vd[num].c);
        int left = vd[num].left;
        int right = vd[num].right;
        if (left != -1)
        {
            root->left = createTree(root->left, left);
        }
        if (right != -1)
        {
            root->right = createTree(root->right, right);
        }
        return root;
    }

    struct mydata{
        char c;
        char le;
        char ri;
    };

    bool isomorphism(Bnode* root1, Bnode* root2)
    {
        if (root1 == NULL && root2 == NULL)
            return true;
        if (root1 != NULL && root2 == NULL)
            return false;
        if (root1 == NULL && root2 != NULL)
            return false;
        if (root1->data != root2->data)
            return false;

        // 左子树 都为空
        if (root1->left == NULL  && root2->left == NULL)
            return isomorphism(root1->right, root2->right);

        if (root1->left != NULL && root2->left == NULL) // 需要交换子树判断
        {
            bool b1 = isomorphism(root1->left, root2->right);
            bool b2 = isomorphism(root1->right, root2->left);
            return b1&&b2;
        }
        else if (root1->left == NULL && root2->left != NULL)//同上
        {
            bool b1 = isomorphism(root1->left, root2->right);
            bool b2 = isomorphism(root1->right, root2->left);
            return b1&&b2;
        }
        else{

            if (root1->left->data == root2->left->data){ //判断左，右子树  而不是 左右子树的子树
                bool b1 = isomorphism(root1->left, root2->left);
                bool b2 = isomorphism(root1->right, root2->right);
                return b1&&b2;
            }
            else{
                bool b1 = isomorphism(root1->left, root2->right); // 当前树交换 再判断
                bool b2 = isomorphism(root1->right, root2->left);
                return b1&&b2;
            }
        }

        return false;
    }


    int main()
    {
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
        int i, n1, n2;
        char c1, cLeft, cRight;
        while (scanf("%d\n", &n1) != EOF)
        {
            //使用并查集
            for (i = 0; i < n1; i++)
                fa[i] = i;
            for (i = 0; i < n1; i++)
            {
                scanf("%c %c %c\n", &c1, &cLeft, &cRight);
                vd[i].c = c1;
                if (cLeft == '-')
                {
                    vd[i].left = -1;
                }
                else{
                    vd[i].left = cLeft - '0';
                    merg(i, vd[i].left);
                }
                if (cRight == '-')
                {
                    vd[i].right = -1;
                }
                else{
                    vd[i].right = cRight - '0';
                    merg(i, vd[i].right);
                }
            }
            Bnode* root1 = NULL;
            if (n1 > 0){
                int rootNum1 = find(0);
                root1 = createTree(root1, rootNum1);//构造树1
            }

            scanf("%d\n", &n2);
            for (i = 0; i < n2; i++)
                fa[i] = i;
            for (i = 0; i < n2; i++)
            {
                scanf("%c %c %c\n", &c1, &cLeft, &cRight);
                vd[i].c = c1;
                if (cLeft == '-')
                {
                    vd[i].left = -1;
                }
                else{
                    vd[i].left = cLeft - '0';
                    merg(i, vd[i].left);
                }
                if (cRight == '-')
                {
                    vd[i].right = -1;
                }
                else{
                    vd[i].right = cRight - '0';
                    merg(i, vd[i].right);
                }
            }
            Bnode* root2 = NULL;
            if (n2 > 0){
                int rootNum2 = find(0);
                root2 = createTree(root2, rootNum2);//构造树2
            }

            if (n1 != n2)
            {
                printf("No\n");
                continue;
            }

            bool flag = isomorphism(root1, root2);
            if (flag)
                printf("Yes\n");
            else
                printf("No\n");

        }
        return 0;
    }


