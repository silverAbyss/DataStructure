//6-1 ���ڴ溯��ʵ����6 �֣�

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
        return;//void���Ͳ��ܷ���ֵ
    }
    else
    {
        PrintN(n-1);
        printf("%d",n);
    }
}
//���뺯��n�ݼ���0����ֹ���˳�����ʱ����printf
