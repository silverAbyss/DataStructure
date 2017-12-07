#include<stdio.h>
#include<malloc.h>
int Search(int *p, int *q, int n) {
    while(--n){
        if(*p < *q) p++;
        else q++;
    }
    return (*p) < (*q) ? *p : *q;
}
int main()
{
    int n,i;
    int *p,*q;
    scanf("%d",&n);
    p = (int*)malloc(sizeof(int)*n);
    q = (int*)malloc(sizeof(int)*n);
    for(i = 0; i < n; i++)
        scanf("%d",p+i);
    for(i = 0; i < n; i++)
        scanf("%d",q+i);
    int ans = Search(p,q,n);
    printf("%d\n",ans);
    return 0;
}
