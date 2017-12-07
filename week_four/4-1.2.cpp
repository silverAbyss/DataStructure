#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<cstring>
#include <algorithm>

#define    OK       1
#define    ERROR    0
#define    TRUE     1
#define    FALSE    0
#define    OVERFLOW -2

#define STACK_INIT_SIZE 1000
#define STACKINCREMENT 10
typedef char SElemType;
typedef int status;

typedef struct {
    SElemType * base;
    SElemType * top;
    int stacksize;
}SqStack;

status InitStack(SqStack& S) {
    S.base = (SElemType* )malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!S.base) exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}
status GetTop(SqStack S,SElemType & e) {
    if(S.top == S.base) return ERROR;
    e = *(S.top-1);
    return OK;
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
status StackEmpty(SqStack S) {
    if(S.top == S.base)
        return TRUE;
    else
        return FALSE;
}
void Print(char ch) {
    if(ch == '(') printf("(-?\n");
    else if(ch == '[') printf("[-?\n");
    else if(ch == '{') printf("{-?\n");
    else if(ch == 'a') printf("/*-?\n");
}
status MatchStack(SqStack & S) {
    SElemType str[1001], e;
    char frist_error = 0;
    int i;
    while(1) {
        gets(str);
        if(str[0] == '.' && str[1] == 0) break;
        int length = strlen(str);
        for(i = 0; i < length; i++) {
            if(frist_error) break; //ÈôÒÑ²éÕÒµ½´íÎó£¬Í£Ö¹¼ìÑé
            if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
                    Push(S,str[i]);
            }
            else if(str[i] == '/' && str[i+1] == '*') {
                Push(S,'a');
                i++;
            }
            else if(str[i] == ')') {
                GetTop(S,e);
                if(!StackEmpty(S) && e == '(') Pop(S);
                else {
                    frist_error = 1;
                    printf("NO\n");
                    if(StackEmpty(S))
                        printf("?-)\n");
                    else
                        Print(e);
                }
            }
            else if(str[i] == ']') {
                GetTop(S,e);
                if(!StackEmpty(S) && e == '[') Pop(S);
                else {
                    frist_error = 1;
                    printf("NO\n");
                    if(StackEmpty(S))
                        printf("?-]\n");
                    else
                        Print(e);
                }
            }
            else if(str[i] == '}') {
                GetTop(S,e);
                if(!StackEmpty(S) && e == '{') Pop(S);
                else {
                    frist_error = 1;
                    printf("NO\n");
                    if(StackEmpty(S))
                        printf("?-}\n");
                    else
                        Print(e);
                }
            }
            else if(str[i] == '*' && str[i+1] == '/') {
                GetTop(S,e);
                if(!StackEmpty(S) && e == 'a') Pop(S);
                else {
                    frist_error = 1;
                    printf("NO\n");
                    if(StackEmpty(S))
                        printf("?-*/\n");
                    else
                        Print(e);
                }
            }
        }
    }
    if(StackEmpty(S) && frist_error == 0) {
        printf("YES\n");
    }
    else if(frist_error == 0) {
        GetTop(S,e);
        printf("N0\n");
        Print(e);
    }
    return OK;
}

int main()
{
    //ÊµÀý»¯Ò»¸öÕ»
    SqStack S;
    InitStack(S);
    //ÊäÈëcÓïÑÔÔ´³ÌÐò
    //Èç¹ûÓöµ½Æ¥Åä×ó·ûºÅ£¬Ñ¹Õ»
    //Óöµ½Æ¥ÅäÓÒ·ûºÅ£¬ÓëÕ»¶¥ÔªËØÆ¥Åä
    //ÈôÆ¥Åä£¬½«×ó·ûºÅµ¯³ö£¬¼ÌÐøÏÂÒ»´ÎÆ¥Åä
    //·ñÔò£¬ÊäÈë½áÊø£¬Êä³öNO
    MatchStack(S);

    return 0;
}
