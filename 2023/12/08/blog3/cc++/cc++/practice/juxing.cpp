#include<iostream>
using namespace std;
int main()
{
    int i,j;
    int a,b;
    char c;
    bool f;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>f;
    for(i=0;i<a;i++)
    {
        if(f)
        {
            for(j=0;j<b;j++)
            {
             cout<<c;
            }
        }
        else
        {
            if(i==0||i==a-1)
            {
                for(j=0;j<b;j++)
                {
                    cout<<c;
                }
            }
            else
            {
                for(j=0;j<b;j++)
                {
                    if(j==0||j==b-1)
                    {
                        cout<<c;
                    }
                    else
                    {
                        cout<<" ";
                    }
                }
            }
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}