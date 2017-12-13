
//
// Created by 17519 on 2017/12/7.
//
#include <cstdio>
#include <sstream>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define  N 1001

typedef struct node
{
    string name ;
    bool isDir;
    vector<node*> next ;
    node(string _name="")
    {
        name = _name ;
        isDir = true ;
        next.clear() ;
    }
}Fnode;

int n ;

Fnode* createTree(Fnode* root  , string s)
{
    if(s == "")
        return NULL ;
    int pos = s.find_first_of('\\');
    if(pos == string::npos)
    {
        int len = root->next.size() ;
        bool flag = false ;
        for(int i = 0 ; i < len ; i++)
        {
            if( root->next[i]->name == s)
            {
                flag = true ;
                break ;
            }
        }
        if(flag == false)
        {
            Fnode* fn = new node(s);
            fn->isDir = false ;
            root->next.push_back(fn);
        }
    }else{
        int lens = s.size() ;
        string s1 = s.substr(0,pos) ;
        string s2 = s.substr(pos+1,lens-pos) ;
        bool flag = false ;
        int len = root->next.size() ;
        for(int i = 0 ; i < len ; i++)
        {
            if( root->next[i]->name == s1)
            {
                flag = true ;
                createTree(root->next[i],s2) ;
                break ;
            }
        }
        if(flag == false)
        {
            Fnode* fn = new node(s1) ;
            fn->isDir = true ;
            createTree(fn,s2) ;
            root->next.push_back(fn) ;
        }
    }
}

bool cmp(Fnode* f1 , Fnode* f2)
{
    if(f1->isDir == f2->isDir)
        return f1->name < f2->name;
    if(f1->isDir)
        return true ;
    return false ;
}

void pf(Fnode* root , int ceng)
{
    for(int i= 0 ;i < ceng*2 ;i++)
        printf(" ");
    cout << root->name << endl ;
    int len = root->next.size();
    if(len > 1)
        sort(root->next.begin(),root->next.end() , cmp);
    for(int i= 0 ; i< len ; i++)
    {
        pf(root->next[i] , ceng+1);
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    int i ;
    string s ;
    Fnode *root = new node("root") ;
    for(i = 0 ; i < n ; i++)
    {
        cin >> s ;
        createTree(root , s);
    }
    pf(root,0);
    return 0 ;
}
