#include <stdio.h>
#include <stdlib.h>

int main()
{
    int window1, window2, window3;
    int a[2];
    int flag = 3;
    int cout = 0;
    int MAXnum = 40; //窗口最大人数
    a[0] = window1;
    a[1] = window2;
    a[2] = window3;
    for (int i = 0; i < 3; i++)
    {
        if (a[i] < MAXnum) //只要有一个窗口人数少于40
        {
            flag = 1; //门禁打开
        }
        if (a[i] > MAXnum)
        {
            cout++; //计数超过40人的窗口
        }
        if (cout == 3) //有三个窗口超过40人     //一开始 if (cout = 3)  直接将cout赋值了，导致直接进这个if语句
        {
            flag = 0; //门禁锁上
            cout = 0;
        }
    }
    if (flag == 1)
    {
        printf("门禁打开");
    }
    else if (flag == 0)
    {
        printf("门禁锁上");
    }
    system("pause");
    return 0;
}