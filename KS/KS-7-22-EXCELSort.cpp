//
// Created by 17519 on 2017/12/12.
//
#include<cstdio>
#include<cstdlib>
#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

typedef int status;
typedef struct SNode{
    int num;
    string name;
    int scorce;
}SNode,*SqList;

bool cmp(SNode p,SNode q,int SortMethod = 1);
void CreatSqList(SqList SL,int num);
void Merge(SqList SL,int low,int mid,int high,SqList temp,int SortMethod = 1);
void MSort(SqList SL,int low,int high,SqList temp,int SortMethod = 1);
void Print(SqList SL,int num);
void ShellSort(SqList SL,int N,int SortMethod = 1);
void ShellInsert(SqList SL, int dk, int N,int SortMethod = 1);

int main() {

    int numOfRecords, SortMethod;
    cin >> numOfRecords >> SortMethod;

    SqList SL = new SNode[numOfRecords];
    SqList temp1 = new SNode[numOfRecords+1];

    CreatSqList(SL,numOfRecords);
    //希尔排序
    //SqList SL = new SNode[numOfRecords+1];
    //ShellSort(SL,numOfRecords,SortMethod);
    //归并排序

    MSort(SL,0,numOfRecords-1,temp1,SortMethod);

    Print(SL,numOfRecords);
    return 0;
}

void Print(SqList SL,int num) {
    for (int i = 0; i < num; i++) {
        cout << setfill('0') << setw(6) << SL[i].num << " " << SL[i].name << " " << SL[i].scorce << endl;
    }
}

void CreatSqList(SqList SL,int num) {
    for(int i = 0; i < num; i++) {
        cin >> SL[i].num >> SL[i].name >> SL[i].scorce;
    }
}

bool cmp(SNode p,SNode q,int SortMethod) {
    if(SortMethod == 1) {
        return p.num < q.num;
    }
    if(SortMethod == 2) {
        if(p.name == q.name)
            return p.num < q.num;
        return p.name < q.name;
    }
    if(SortMethod == 3) {

        if(p.scorce == q.scorce) {
            return p.num < q.num;
        }
        return p.scorce < q.scorce;
    }
}

//归并排序
void Merge(SqList SL,int low,int mid,int high,SqList temp,int SortMethod) {
    int p_left = low,p_right = mid+1,p_result = 0;

    while(p_left <= mid && p_right <= high) {
        //if(SL[p_left].num <= SL[p_right].num) {

        if(cmp(SL[p_left],SL[p_right],SortMethod)) {
            temp[p_result++] = SL[p_left++];
        }
        else {
            temp[p_result++] = SL[p_right++];
        }
    }

    while(p_left <= mid) {
        temp[p_result++] = SL[p_left++];
    }
    while(p_right <= high) {
        temp[p_result++] = SL[p_right++];
    }
    for (int i = 0; i < p_result; i++) {
        SL[low+i] = temp[i];
    }

}

void MSort(SqList SL,int low,int high,SqList temp,int SortMethod) {

    if(low == high)
        temp[low] = SL[low];
    else {
        int mid = (low+high)/2;
        MSort(SL,low,mid,temp, SortMethod);
        MSort(SL,mid+1,high,temp, SortMethod);
        Merge(SL,low,mid,high,temp, SortMethod);
    }
}

//希尔排序
void ShellInsert(SqList SL, int dk, int N,int SortMethod) {
    for(int i = dk+1,j; i <= N; ++i) {
        if(cmp(SL[i],SL[i-dk],SortMethod)) {
        //if(SL[i].num < SL[i-dk].num){
            SL[0] = SL[i];
            for(j = i-dk; j > 0 && cmp(SL[0],SL[j],SortMethod); j -= dk)
                SL[j+dk] = SL[j];
            SL[j+dk] = SL[0];
        }
    }
}
void ShellSort(SqList SL,int N,int SortMethod) {
    int dlta[] = {7,5,3,1};
    int t = 4;
    for(int k = 0; k < t; ++k)
        ShellInsert(SL,dlta[k],N,SortMethod);
}
