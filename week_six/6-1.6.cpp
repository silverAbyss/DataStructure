#include<stdio.h>

int N;

int s[31]; // ��Ż��ֽ��
int top = -1; // ����ָ��
int count = 0; // ͳ������Ĵ���
int sum = 0; // ������ۼӺ�

void division (int i);

int main ()
{
    scanf ("%d", &N);

    division (1);

    return 0;
}

void division (int i) {
    if (sum == N) {
        count ++;
        printf("%d=", N);
        int k;
        for (k=0; k<top; k++) {
            printf("%d+", s[k]);
        }
        if (count%4 == 0 || s[top] == N) {
            printf("%d\n", s[top]);
        } else {
            printf("%d;", s[top]);
        }
        return;
    } // �������
    if (sum > N) {
        return;
    }
    for (int j=i; j<=N; j++) {
        s[++top] = j;
        sum += j;
        printf("-top:%d-------in\n",top);
        division (j);
        printf("=top:%d=========out\n",top);
        sum -= j;
        top --;
    } // �㷨����
}
