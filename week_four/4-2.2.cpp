#include<stdlib.h>
#include<stdio.h>
int counter = 1;//记录需要的铁轨数
int rails[100001];
void Insert(int *rails, int temp, int num)//二分查找
{
    int _begin = 0, _end = num, mid;
    while(_begin < _end)
    {
        mid = _begin + (_end - _begin)/2;
        if(rails[mid] > temp) _end = mid;
        else if(rails[mid] < temp) _begin = mid + 1;
    }
    rails[_end] = temp;
}
int main()
{
    int n,i,j,num;
    int temp;
    scanf("%d",&n);
    for(i = 0,j = 0; i < n; i++) {
        if(i == 0) {
            scanf("%d",&rails[j]);
            j++;
        }
        else {
            scanf("%d",&temp);
            if(temp > rails[j-1]) {
                rails[j] = temp;
                j++;
                counter++;
            }
            else if(temp < rails[j-1]) {
                Insert(rails,temp,j);
            }
        }
    }
    printf("%d\n",j);
    return 0;
}
