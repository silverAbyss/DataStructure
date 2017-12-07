#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree BuildTree(); /* 由裁判实现，细节不表 */
bool IsBST ( BinTree T );

int main()
{
    BinTree T;

    T = BuildTree();
    if ( IsBST(T) ) printf("Yes\n");
    else printf("No\n");

    return 0;
}
ElementType maxValue(BinTree T) {
    int maxnum = T->Data;
    BinTree p = T->Left;
    while(p) {
        if(maxnum < p->Data)
            maxnum = p->Data;
        p = p->Left;
    }
    return maxnum;
}
ElementType minValue(BinTree T) {
    int minnum = T->Data;
    BinTree p = T->Right;
    while(p) {
        if(minnum > p->Data)
            minnum = p->Data;
        p = p->Right;
    }
    return minnum;
}
bool IsBST ( BinTree T ) {
    if(!T) return true;
    if(T->Left != NULL && maxValue(T->Left) > T->Data)
        return false;
    if(T->Right != NULL && minValue(T->Right) < T->Data)
        return false;
    return (IsBST(T->Left) && IsBST(T->Right));
}
