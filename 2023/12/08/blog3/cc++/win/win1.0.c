#include <windows.h>
#include <stdio.h>

//栈：先进后出

//c语言默认函数调用的越低 _cdecl
//Windows API显示的写上函数的调用越低
//越低了函数的入栈方式，以及栈的清理方式
//#defineWINAPI __stdcall
//_cdecl 从右往左

//句柄：包含函数的所有信息，控制着他们的权限
//HINSTANCE:应用程序实例句柄类型    结构体指针类型
//DECLARE_HANDLE(HINSTANCE);    //宏
//#define DECLARE_HANDLE(n)  typedef struct n##__{int i;}*n
//  ##宏定义连接符
//  hInstance：当前应用程序实例句柄
//  hPreInstance    前一个应用程序实例句柄  32位及以后，这个参数都没有用了，都是NULL。

//LPSTR：   CHAR* 定义成了LPSTR
//typedef CHAR *PCHAR, *LPCH, *PCH, *NPSTR, *LPSTR, *PSTR;

//lpCmdLine：命令行参数
//nCmdShow：  窗口的显示方式    最大化 最小化 隐藏 正常显示
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow) //从右往左
{
    //****弹框
    //弹出一个窗口
    //**第一个参数
    //HWND：窗口句柄类型
    //**第二个参数
    //消息框显示的文本
    //LPCTSTR:<=>LPCWSTR<=>PCTSTR       const wchar_t*
    //**第三个参数
    //消息提示框的标题
    //**第四个参数
    //图标和按键的组合
    //UNIT: unsigned int UNIT   //无符号整数

    //MB_: MessageBox
    MessageBox(NULL, "NULL", "NULL", MB_ICONHAND | MB_ABORTRETRYIGNORE);
    // MessageBox(NULL,L"NULL",L"NULL",MB_OK);       //为什么不能想视频一样加L

    //MB_ICONHAND | MB_ABORTRETRYIGNORE 16 | 2  0001 0000|0000 0010

    return 0;
}

// int a = 0, b = 1;
// char str[10];
// // printf("%d,%d", a = a + b);
// //sprintf(str, "%d,%d", a = a + b, a = a + b); //从右往左入栈，a=1入栈，a+1=2入栈，a不可能同时有两种状态，
// //system("pause");