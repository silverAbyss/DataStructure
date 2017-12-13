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

void CreatSqList(SqList SL,int num) {
    for(int i = 0; i < num; i++) {
        cin >> SL[i].num >> SL[i].name >> SL[i].scorce;
    }
}

//归并排序
void Merge(SqList SL,int low,int mid,int high,SqList temp) {
    int p_left = low,p_right = mid+1,p_result = low;
    while(p_left <= mid && p_right <= high) {
        if(SL[p_left].num <= SL[p_right].num) {
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
    for (int i = 0; i < p_result; ++i) {
        SL[low+i] = temp[i];
    }
}

void MSort(SqList SL,int low,int high,SqList temp) {

    if(low == high)
        temp[low] = SL[low];
    else {
        int mid = (low+high)/2;
        MSort(SL,low,mid,temp);
        MSort(SL,mid+1,high,temp);
        Merge(SL,low,mid,high,temp);
    }
}

void Print(SqList SL,int num) {
    for (int i = 0; i < num; ++i) {
        cout << setfill('0') << setw(6) << SL[i].num << " " << SL[i].name << " " << SL[i].scorce << endl;
    }
}

int main() {
    int numOfRecords,SortMethod;
    cin >> numOfRecords >> SortMethod;

    SqList SL = new SNode[numOfRecords];
    SqList temp1 = new SNode[numOfRecords];

    CreatSqList(SL,numOfRecords);

    MSort(SL,0,numOfRecords-1,temp1);

    Print(SL,numOfRecords);
    return 0;
}
