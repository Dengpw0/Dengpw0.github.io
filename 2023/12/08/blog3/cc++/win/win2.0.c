#include <windows.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM); //�ص�����      windows���ã������Լ��������
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow) //��������
{
    static TCHAR szAppName[] = TEXT("Mywindows");
    HWND hwnd; //�ѱ��������windows�ҵ����ڵ�;��
    MSG msg;   //windows�ĺ��Ļ��ƣ���Ϣ�ṹ

    //ʵ�ֵ�һ��Windows����Ӧ�ó���
    //**��һ������ƴ�����
    WNDCLASS wc;
    wc.style = CS_HREDRAW | CS_VREDRAW; //������ķ��
    wc.lpfnWndProc = WindowProc;        //���ڴ�����

    wc.cbClsExtra = 0;                                      //���������չ�ռ��С    ��ʼ��0
    wc.cbWndExtra = 0;                                      //���ڶ���ռ��ڴ��С    ��ʼ��0
    wc.hInstance = hInstance;                               //��ǰӦ�ó���ʵ�����
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);             //���Ͻ�ͼ��,û�о�NULL,�������һ��ϵͳͼ��
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);               //���������
    wc.hbrBackground = WHITE_BRUSH;//(HBRUSH)GetStockObject(WHITE_BRUSH); //���ػ�ˢ
    wc.lpszMenuName = NULL;                                 //�˵���
    wc.lpszClassName = szAppName;                           //����������
    //**�ڶ�����ע�ᴰ����
    if (!RegisterClass(&wc))
    {
        MessageBox(NULL, TEXT("error"), szAppName, MB_OK);
        return 0;
    }
    //**����������������
    hwnd = CreateWindow(
        szAppName,                                                             //����������
        TEXT("��С˧"),                                               //���ڵı���
        WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX, //���ڵķ��
        200,                                                                   //���ڵĺ�����
        200,                                                                   //���ڵ�������
        800,                                                                   //���ڵĿ��
        600,                                                                   //���ڵĸ߶�
        NULL,                                                                  //�����ھ��
        NULL,                                                                  //�˵����
        hInstance,                                                             //��ǰӦ�ó���ʵ�����
        NULL                                                                   //���Ӳ���
    );
    //**���Ĳ�����ʾ����
    ShowWindow(hwnd, nCmdShow);
    //**���岽�����´���
    UpdateWindow(hwnd);
    //**����������Ϣѭ��
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    system("pause");
    return msg.wParam;
}

//*���ڴ�����
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
        DrawText(hdc, TEXT("giao�磡"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        EndPaint(hwnd, &ps);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}