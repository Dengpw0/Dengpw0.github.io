#include <stdio.h>
#include <stdlib.h>

int main()
{
    int window1, window2, window3;
    int a[2];
    int flag = 3;
    int cout = 0;
    int MAXnum = 40; //�����������
    a[0] = window1;
    a[1] = window2;
    a[2] = window3;
    for (int i = 0; i < 3; i++)
    {
        if (a[i] < MAXnum) //ֻҪ��һ��������������40
        {
            flag = 1; //�Ž���
        }
        if (a[i] > MAXnum)
        {
            cout++; //��������40�˵Ĵ���
        }
        if (cout == 3) //���������ڳ���40��     //һ��ʼ if (cout = 3)  ֱ�ӽ�cout��ֵ�ˣ�����ֱ�ӽ����if���
        {
            flag = 0; //�Ž�����
            cout = 0;
        }
    }
    if (flag == 1)
    {
        printf("�Ž���");
    }
    else if (flag == 0)
    {
        printf("�Ž�����");
    }
    system("pause");
    return 0;
}