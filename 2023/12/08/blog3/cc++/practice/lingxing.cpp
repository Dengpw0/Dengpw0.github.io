#include <iostream>
using namespace std;
int main()
{
    char a;
    cin>>a;
    int i, j, k;
    for (i = 0; i < 5; i++) //正方形里填充空格和星号    //外层控制行数
    {
        //内层控制列数
        for (j = 0; j < abs(5 / 2 - i); j++) //每一行的左边空格数
        {
            cout<<" ";
        }
        for (j = 0; j < 5 - 2 * abs(5 / 2 - i); j++)    //每一行的*号，需要总列数减去空格的列数
        {
            cout<<a;
        }
        cout<<endl;   //每次换行
    }
    system("pause");
    return 0;
}