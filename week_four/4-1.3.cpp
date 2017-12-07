#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define    OK      1
#define    ERROR   0
#define    TRUE    1
#define    FALSE   0
#define    OVERFLOW -2

#define STACK_INIT_SIZE  100
#define STACKINCREMENT   10
typedef int status;
typedef char SElemType;
typedef struct {
    SElemType * top;
    SElemType * base;
    int stacksize;
}SqStack;

status StackInit(SqStack& S) {
    S.base = (SElemType* )malloc(STACK_INIT_SIZE* sizeof(SElemType));
    if(!S.base) exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}
status StackEmpty(SqStack S) {
    if(S.top == S.base)
        return TRUE;
    else
        return FALSE;
}
status Push(SqStack & S, SElemType e) {
    if(S.top - S.base == S.stacksize) {
        S.base = (SElemType* ) realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
        if(!S.base) exit(OVERFLOW);
        S.top = (S.base+S.stacksize);
        S.stacksize += STACKINCREMENT;
    }
    *S.top = e;
    S.top++;
    return OK;
}
status Pop(SqStack & S) {
    if(S.top == S.base) return ERROR;
    S.top--;
    //e = *(--S.top);
    return OK;
}
SElemType GetTop(SqStack S) {
    if(S.top == S.base) return ERROR;
    return *(S.top-1);
}
status StackExpressionTrans(SqStack & S) {
    char chr,c;
    int flag = 0;
    while((chr = getchar()) != '\n') {
        switch (chr) {
        case '+':
        case '-':
            while((c = GetTop(S)) != ERROR && (c = GetTop(S)) != '+' && (c = GetTop(S)) != '-') {
                if(c == '(' || c == ')'){
                    Pop(S);
                    continue;
                }
                        printf(" %c ",c);
                        Pop(S);
                }
            Push(S,chr);
            break;
        case '*':
        case '/':
            Push(S,chr);

            break;
        case '(':
            Push(S,chr);
            break;
        case ')':
            while((c = GetTop(S)) != '(' && (c = GetTop(S)) != ERROR) {
                printf("%c ",c);
                Pop(S);
            }
            Pop(S);
            break;
        default:
            printf("%c ",chr);
            break;
        }
    }
    while(GetTop(S) != ERROR) {
        printf("%c-",Pop(S));
    }
    return OK;
}

int main()
{
    SqStack S;
    StackInit(S);
    StackExpressionTrans(S);

    return 0;
}
