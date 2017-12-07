#include<stdio.h>
#include<stdlib.h>

typedef int TElemType;
typedef struct HTNode{
    TElemType data;
    struct HTNode *lchild,*rchild;
}HTNode,*HTree;

#define TRUE    1
#define FALUSE  0
#define OK      1
#define ERROR   0
#define OVERFLOW  -2


int main()
{
    int eg[64],n;

    return 0;
}

/*
#include <string>
using namespace std;
#define MaxNum 64

struct TreeNode//���Ľ��
{
    int Weight=0;
    TreeNode *Left=nullptr;
    TreeNode *Right=nullptr;
};

struct HeapNode//��
{
    TreeNode Data[MaxNum];
    int Size=0;
};

HeapNode *CreateHeap(int N)//����һ���µ�С����
{
    HeapNode *H=new(HeapNode);
    H->Data[0].Weight=-1;
    return H;
}

TreeNode *DeleteMin(HeapNode *H)//�Ӷ���ɾ��һ�����
{
    int Parent=0,Child=0;
    TreeNode temp;
    TreeNode *MinItem=new(TreeNode);
    *MinItem=H->Data[1];

    temp=(H->Data[(H->Size)--]);

    for (Parent = 1; Parent*2 <= H->Size ; Parent=Child)//Ѱ��ɾ�����ǰ�������һ��������¶��еĲ���λ��
    {
        Child=Parent*2;
        if ((Child!=H->Size)&&((H->Data[Child].Weight)>(H->Data[Child+1].Weight)))
        {
            Child++;
        }
        if ((temp.Weight)<=(H->Data[Child].Weight))
        {
            break;
        }else
        {
            H->Data[Parent]=H->Data[Child];
        }

    }
    H->Data[Parent]=temp;
    return MinItem;

}

void Insert(HeapNode *H,TreeNode *item)//�����½�㵽����
{
    int i=0;
    i=++(H->Size);
    for (;H->Data[i/2].Weight>item->Weight; i/=2)
    {
        H->Data[i]=H->Data[i/2];

    }
    H->Data[i]=*item;

}

HeapNode *ReadData(int N,HeapNode *H,int A[])//��ȡ�����ڵ��Ȩֵ��������
{
    char s='\0';
    int value=0;
    for (int i=0; i<N; ++i)
    {
        cin>>s;
        cin>>value;
        A[i]=value;
        TreeNode *T=new(TreeNode);
        T->Weight=value;
        Insert(H, T);
    }
    return H;
}

TreeNode *Huffman(HeapNode *H)//����Huffman��
{
    TreeNode *T=nullptr;
    int num=H->Size;
    for (int i=0; i<num-1; ++i)
    {
        T=new(TreeNode);
        T->Left=DeleteMin(H);

        T->Right=DeleteMin(H);

        T->Weight=T->Left->Weight+T->Right->Weight;
        Insert(H, T);

    }
    T=DeleteMin(H);
    return T;
}

int WPL(TreeNode *T,int Depth)//����Huffman���ı��볤��
{
    if ((T->Left==nullptr)&&(T->Right==nullptr))
    {
        return Depth*(T->Weight);
    }else
    {
        return (WPL(T->Left,Depth+1)+WPL(T->Right,Depth+1));
    }
}
struct JNode
{
    int Flag=0;
    JNode *Left=nullptr;
    JNode *Right=nullptr;

};
bool Judge(string S,JNode *J)//�жϸôα����ܷ����ǰ׺�����Ҫ��
{
    int i=0;
    for (; i<S.length(); ++i)
    {
        if (S[i]=='0')
        {
            if (J->Left==nullptr)
            {
                JNode *J_1=new(JNode);
                J->Left=J_1;
            }else
            {
                if (J->Left->Flag==1)
                {
                    return false;
                }
            }
            J=J->Left;
        }else
        {
            if (J->Right==nullptr)
            {
                JNode *J_1=new(JNode);
                J->Right=J_1;
            }else
            {
                if (J->Right->Flag==1)
                {
                    return false;
                }
            }
            J=J->Right;
        }
    }
    J->Flag=1;
    if (J->Left==nullptr&&J->Right==nullptr)
    {
        return true;
    }else
    {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    int N=0,n=0;
    cin>>N;
    HeapNode *H=CreateHeap(N);
    int Value[MaxNum]={};
    H=ReadData(N,H,Value);

    TreeNode *T=Huffman(H);

    int CodeLen=WPL(T,0);

    cin>>n;
    string temp="\0";
    char c='\0';
    bool result=false;


    for (int i=0; i<n; ++i)
    {
        int count=0,flag=0;
        JNode *J=new(JNode);
        for (int k=0; k<N; ++k)
        {
            cin>>c>>temp;
            count+=temp.length()*Value[k];
            if (!flag)
            {
                result=Judge(temp,J);
                if (!result)
                {
                    flag=1;
                }
            }


        }
        delete J;
        if (result&&(count==CodeLen))//ǰ׺�����ұ��볤��֮����Huffman������ͬ
        {
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}
*/
