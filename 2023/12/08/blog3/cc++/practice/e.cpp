#include<iostream>
using namespace std;
int main()
{
    double e=0;
    double c=0;
    int n;
    cin>>n;
    int b=1;
    int d;
    while(n!=0)
    {
        while(d!=0&&b!=1)
        {
            d=b;
            b=b*(d-1);
            d--;
        }
        c=1/b;
        e=e+c;
        b++;
        n--;
    }
    printf("%.10lf",e);
    system("pause");
    return 0;
}