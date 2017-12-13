//
// Created by 17519 on 2017/12/7.
//
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define TRUE    1
#define FALSE   0
#define OK      1
#define ERROR   0
#define OVERFLOW    -2

typedef int status;
typedef struct DNode{
    bool isDir;
    string name;
    vector <DNode*> next;
    DNode(string nam = "",bool isdir = false) {
        name = nam;
        isDir = isdir;
        next.clear();
    }
}DNode,*DTree;

status InsertDNode(DTree root,string& s) {
    if(s == "") return ERROR;
    //目录或文件名中找第一个'\'
    int p = s.find_first_of('\\');
    //如果没有'\'
    if(p == string::npos) {
        bool is_found = false;
        int len = root->next.size();
        //遍历root中是否有name为s的节点
        for(int i = 0; i < len; i++) {
            //如果有，退出循环
            if(root->next[i]->name == s) {
                is_found = true;
                break;
            }
        }
        //如果没有，创建该节点放入容器（默认为文件）
        if(!is_found) {
            DNode* temp = new DNode(s,false);
            if(!temp) return ERROR;
            root->next.push_back(temp);
        }
    }
    //如果有'\'，取出'\'前、后的字符串分别为s1,s2
    else {
        int length = s.length();
        string s1 = s.substr(0,p);
        string s2 = s.substr(p+1,length);
        bool is_found = false;
        //遍历root中是否有name为s1的节点
        int lens = root->next.size();
        for(int i = 0; i < lens; i++) {
            //如果有，递归创建节点（InsertDNode s2)
            if(root->next[i]->name == s1) {
                is_found = true;
                root->next[i]->isDir = true;
                InsertDNode(root->next[i],s2);
                break;
            }
        }
        //如果没有，创建节点放入容器，递归创建节点s2
        if(!is_found) {
            DNode* temp = new DNode(s1,true);
            if(!temp) return ERROR;
            root->next.push_back(temp);
            InsertDNode(temp,s2);
        }
    }
    return OK;
}

bool cmp(DNode* f1 , DNode* f2)
{
    if(f1->isDir == f2->isDir)
        return f1->name < f2->name;
    if(f1->isDir)
        return true ;
    return false ;
}

status Print(DTree DT, int layers) {
    for(int i = 0; i < layers*2; i++) {
        cout<<" ";
    }
    cout<<DT->name<<endl;
    //printf("%s",DT->name);
    int lens = DT->next.size();
    if(lens > 1)
        sort(DT->next.begin(),DT->next.end(),cmp);
    for(int i = 0; i < lens; i++) {
        Print(DT->next[i],layers+1);
    }
}

int main() {
    int N;
    DTree DT = new DNode("root",true);
    scanf("%d",&N);
    for (int i = 0; i < N; ++i) {
        string s;
        cin>>s;
        InsertDNode(DT,s);
    }
    Print(DT,0);
    return 0;
}