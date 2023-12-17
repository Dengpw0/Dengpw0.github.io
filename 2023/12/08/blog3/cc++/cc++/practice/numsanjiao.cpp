#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int k=1;
        for(int j=1;j<=i;j++)
        {
            
            if(k<10)
            {
                cout<<"0";
                cout<<k;
            }
            else
            {
                cout<<k;
            }
            k++;
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}