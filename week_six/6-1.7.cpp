
    #include<stdio.h>
    #include<string.h>
    int a[10];
    int book[10];
    int n;
    void dfs(int step)
    {
        int i,j,x,k;
        k=step;
        int next[11]={0,1,2,3,4,5,6,7,8,9,10};
        if(step==n)
        {
            for(i=0;i<step;i++)
            {
                printf("%d",a[i]);
            }
            printf("\n");
            return ;
        }
        for(i=1;i<=n;i++)
        {
            x=next[i];
            if(!book[x])
            {
                a[step]=x;
                book[x]=1;
                dfs(k+1);
                book[x]=0;
            }
        }
    }
    int main()
    {
        scanf("%d",&n);
        memset(book,0,sizeof(book));
        dfs(0);
        return 0;
    }
