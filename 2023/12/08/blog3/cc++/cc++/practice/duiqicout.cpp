#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a;
    int i=0;
    while(scanf("%d",&a))
    {
        printf("%8d ",a);   //%nd,n是右对齐位数
        if(i==2)
        {
            printf("\n");//放在break上面，否则会直接break不进行printf
            break;
        }
        i++;
    }
    system("pause");
    return 0;
}