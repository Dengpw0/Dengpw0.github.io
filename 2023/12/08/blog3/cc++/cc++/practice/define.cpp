#include <stdio.h>
#include <stdlib.h> //����� rand();    srand();

#define MAXnum 40 //�����������

int main()
{
    int window1, window2, window3;
    int a[2];
    int flag = 3;
    int cout = 0;
    for (int j = 0; ; j++)
    {
        srand(window1); // window3=rand();
        srand(window2);
        srand(window3);

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
            if (cout == 3) //���������ڳ���40��
            {
                flag = 0; //�Ž�����
                cout = 0;
            }
        }
        if (flag == 1)
        {
            printf("�Ž���\n");
        }
        else if (flag == 0)
        {
            printf("�Ž�����\n");
        }
    }
    system("pause");
    return 0;
}