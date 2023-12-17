#include <windows.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM); //回调函数      windows调用，不是自己代码调用
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow) //从右往左
{
    static TCHAR szAppName[] = TEXT("Mywindows");
    HWND hwnd; //把柄，句柄，windows找到窗口的途径
    MSG msg;   //windows的核心机制，消息结构

    //实现第一个Windows窗口应用程序
    //**第一步、设计窗口类
    WNDCLASS wc;
    wc.style = CS_HREDRAW | CS_VREDRAW; //窗口类的风格
    wc.lpfnWndProc = WindowProc;        //窗口处理函数

    wc.cbClsExtra = 0;                                      //窗口类的扩展空间大小    初始化0
    wc.cbWndExtra = 0;                                      //窗口额外空间内存大小    初始化0
    wc.hInstance = hInstance;                               //当前应用程序实例句柄
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);             //左上角图标,没有就NULL,这里加载一个系统图标
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);               //加载鼠标光标
    wc.hbrBackground = WHITE_BRUSH;//(HBRUSH)GetStockObject(WHITE_BRUSH); //加载画刷
    wc.lpszMenuName = NULL;                                 //菜单名
    wc.lpszClassName = szAppName;                           //窗口类型名
    //**第二步，注册窗口类
    if (!RegisterClass(&wc))
    {
        MessageBox(NULL, TEXT("error"), szAppName, MB_OK);
        return 0;
    }
    //**第三步，创建窗口
    hwnd = CreateWindow(
        szAppName,                                                             //窗口类型名
        TEXT("邓小帅"),                                               //窗口的标题
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
    ShowWindow(hwnd, nCmdShow);
    //**第五步，更新窗口
    UpdateWindow(hwnd);
    //**第六步，消息循环
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    system("pause");
    return msg.wParam;
}

//*窗口处理函数
//WPARAM unsigned int
//LPARAM long

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rect;
    switch (uMsg)
    {
    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        GetClientRect(hwnd, &rect);
        DrawText(hdc, TEXT("giao哥！"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        EndPaint(hwnd, &ps);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}