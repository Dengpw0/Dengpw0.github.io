#include <iostream>
using namespace std;

int a, b;
char c;
void calc()
{
    switch (c)
    {
    case '+':
        cout << a + b << endl;
        break;
    case '-':
        cout << a - b << endl;
        break;
    case '*':
        cout << a * b << endl;
        break;
    case '/':
        cout << a / b << endl;
        break;
    case '%':
        cout << a % b << endl;
        break;
    }
}
int main()
{
    cin >> a >> c >> b;
    calc();
    system("pause");
    return 0;
}