//6-1 爆内存函数实例（6 分）

#include <stdio.h>
void PrintN(long n);
int main()
{
    PrintN(66000L);
    return 0;
}
void PrintN (long n)
{
    if(n == 0)
    {
        return;//void类型不能返回值
    }
    else
    {
        PrintN(n-1);
        printf("%d",n);
    }
}
//进入函数n递减到0，终止，退出函数时依次printf
