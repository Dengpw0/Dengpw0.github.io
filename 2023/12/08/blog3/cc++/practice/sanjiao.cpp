#include<iostream>
using namespace std;
int main()
{
    char a;
    cin>>a;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<(5/2-i);j++)
        cout<<" ";
        for(int j=0;j<(5-2*(5/2-i));j++)
        cout<<a;
        cout<<endl;
    }
    system("pause");
    return 0;
}