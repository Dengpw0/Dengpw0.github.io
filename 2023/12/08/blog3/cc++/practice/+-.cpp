#include<iostream>
using namespace std;
int main()
{
    int a,b;
    char c;
    cin>>a>>b>>c;
    switch(c)
    {
        case '+':
            cout<<a+b<<endl;
            break;
        case '-':
            cout<<a-b<<endl;
            break;
        case '*':
            cout<<a*b<<endl;
            break;
        case '/':
            if(b==0)
            {
                cout<<"Divided by zero!"<<endl;
                break;
            }
            else
            {
                cout<<a/b<<endl;
                break;
            }
        default:                                //case以外
            cout<<"Invalid operator!"<<endl;
            break;
    }
    system("pause");
    return 0;
}