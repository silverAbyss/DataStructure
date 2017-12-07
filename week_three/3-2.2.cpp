#include<stdio.h>

int main()
{
	int a[1001],b[1001],i,j;
	for(i=0;i<1001;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
		if(b[i]==0)
		break;
	}
	i ++;
	for(j = 0; j < i; j++) {
        if(a[j] == 0 || b[j] == 0) {
            if(j == 0)
                printf("0 0\n");
            else
                printf(" 0 0");
        }
        else {

            if(j == 0)
                printf("%d %d",a[j]*b[j],b[j]-1);
            else
                printf(" %d %d",a[j]*b[j],b[j]-1);
            if(j == i-2) {
                printf("\n");
                break;
            }
        }
	}

//	for(j=0;j<=i;j++)
//	{
//		if(a[j]==0||b[j]==0)
//		{
//			printf("0 0\n");
//		}
//		else
//		{
//			printf("%d %d",a[j]*b[j],b[j]-1);
//			if(j==i-1)
//			{
//				printf("\n");
//				break;
//			}
//			else
//			printf(" ");
//		}
//	}
    return 0;
}
