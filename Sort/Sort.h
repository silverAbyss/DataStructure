//
// Created by 17519 on 2017/12/18.
//

#ifndef DATASTRUCTURE_SORT_H
#define DATASTRUCTURE_SORT_H


void ShellInsert(int *L, int dk, int N) {
    for(int i = dk+1,j; i <= N; ++i) {
        if(L[i] < L[i-dk]){
            L[0] = L[i];
            for(j = i-dk; j > 0 && (L[0] < L[j]); j -= dk)
                L[j+dk] = L[j];
            L[j+dk] = L[0];
        }
    }
}
void ShellSort(int *L,int N) {
    int dlta[] = {7,5,3,1};
    int t = 4;
    for(int k = 0; k < t; ++k)
        ShellInsert(L,dlta[k],N);
}

void Merge(int* SL,int low,int mid,int high,int* temp) {
    int p_left = low,p_right = mid+1,p_result = 0;

    while(p_left <= mid && p_right <= high) {
        if(SL[p_left] <= SL[p_right]) {
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

void MSort(int* SL,int low,int high,int* temp) {

    if(low == high)
        temp[low] = SL[low];
    else {
        int mid = (low+high)/2;
        MSort(SL,low,mid,temp);
        MSort(SL,mid+1,high,temp);
        Merge(SL,low,mid,high,temp);
    }
}

#endif //DATASTRUCTURE_SORT_H
