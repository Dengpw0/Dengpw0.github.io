#include<iostream>
using namespace std;
int main()
{
    long long a,b;
    cin>>a;
    b=0;
    while(a!=0) //只剩一位数，最后一次进循环，再除以10得0，结束翻转
    {
       b=b*10+a%10; //a%10得到末位，b*10末位向前进一位
       a/=10;   //去除个位
    }
    cout<<b<<endl;
    system("pause");
    return 0;
}