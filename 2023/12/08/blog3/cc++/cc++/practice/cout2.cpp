#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    int i=0;
    while(cin>>a)
    {
        if(i==1)
        {
            b=a;
        }
        if(i==2)
        {
            break;
        }
        i++;
    }
    cout<<b<<endl;
    system("pause");
    return 0;
}
