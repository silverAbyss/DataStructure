#include<stdio.h>

int main()
{
    //����ջ�����Ͳ���������length��ʾջ������Ԫ�ظ���
    int Ssize, oper, counter, length = 0,flag = 0;
    scanf("%d %d ",&oper, &Ssize);
    for(counter = 0; counter < oper; counter ++) {
        char chr;
        //s��ջ��length��һ,x��ջ��length��һ
        while((chr = getchar()) != '\n') {
            if(chr == 'S') {
                length++;
                if(length > Ssize)
                    flag = 1;
            }
            if(chr == 'X') {
                length--;
                if(length < 0)
                    flag = 1;
            }
        }
        if(length == 0 && flag == 0)
            printf("YES\n");
        else
            printf("NO\n");
        length = 0;
        flag = 0;
    }
    return 0;
}
