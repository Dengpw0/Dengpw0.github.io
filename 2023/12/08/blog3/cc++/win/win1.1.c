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

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow) //从右往左
{
    wchar_t *szAppClassName[] = "DKGuiFoundation";
    //实现第一个Windows窗口应用程序
    //**第一步、设计窗口类
    WNDCLASS wc;
    wc.style = CS_HREDRAW | CS_VREDRAW; //窗口类的风格
    wc.lpfnWndProc = WindowProc;        //窗口处理函数

    wc.cbClsExtra = 0;                                   //窗口类的扩展空间大小    初始化0
    wc.cbWndExtra = 0;                                   //窗口额外空间内存大小    初始化0
    wc.hInstance = hInstance;                            //当前应用程序实例句柄
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);          //左上角图标,没有就NULL,这里加载一个系统图标
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);            //加载鼠标光标
    wc.hbrBackground = CreateSolidBrush(RGB(255, 0, 0)); //加载画刷
    wc.lpszMenuName = NULL;                              //菜单名
    wc.lpszClassName = szAppClassName;                   //窗口类型名
    //**第二步，注册窗口类
    if (FALSE == RegisterClass(&wc))
    {
        MessageBox(NULL, "ERROR", "Tip", MB_OK);
        return 0;
    }
    //**第三步，创建窗口
    HWND hWnd = CreateWindow(   
        szAppClassNmae,                                                        //窗口类型名
        "my first window",                                                     //窗口的标题
        WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX, //窗口的风格
        200,                                                                   //窗口的横坐标
        200,                                                                   //窗口的纵坐标
        800,                                                                   //窗口的宽度
        600,                                                                   //窗口的高度
        NULL,                                                                  //父窗口句柄
        NULL,                                                                  //菜单句柄
        hInstance,                                                             //当前应用程序实例句柄
        NULL                                                                   //附加参数
    );
    //**第四步，显示窗口
    ShowWindow(hWnd, SW_SHOW);
    //**第五步，更新窗口
    //**第六步，消息循环
    return 0;
}

//*窗口处理函数
//WPARAM unsigned int
//LPARAM long

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
