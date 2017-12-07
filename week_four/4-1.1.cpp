#include<stdio.h>

int main()
{
    //输入栈容量和操作数，用length表示栈内现有元素个数
    int Ssize, oper, counter, length = 0,flag = 0;
    scanf("%d %d ",&oper, &Ssize);
    for(counter = 0; counter < oper; counter ++) {
        char chr;
        //s入栈，length加一,x出栈，length减一
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
