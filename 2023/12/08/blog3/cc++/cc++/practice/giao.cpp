#include <iostream>
#include <vector>
using namespace std;

class dog
{
public:
    virtual void print();
    int num;
};

class giao : public dog
{
public:
    void print()
    {
        cout << "giao is dog" << endl;
    }
};

int main()
{
    system("pause");
    return 0;
}
