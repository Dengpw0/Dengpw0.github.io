#include <windows.h>
#include <stdio.h>

//ջ���Ƚ����

//c����Ĭ�Ϻ������õ�Խ�� _cdecl
//Windows API��ʾ��д�Ϻ����ĵ���Խ��
//Խ���˺�������ջ��ʽ���Լ�ջ������ʽ
//#defineWINAPI __stdcall
//_cdecl ��������

//���������������������Ϣ�����������ǵ�Ȩ��
//HINSTANCE:Ӧ�ó���ʵ���������    �ṹ��ָ������
//DECLARE_HANDLE(HINSTANCE);    //��
//#define DECLARE_HANDLE(n)  typedef struct n##__{int i;}*n
//  ##�궨�����ӷ�
//  hInstance����ǰӦ�ó���ʵ�����
//  hPreInstance    ǰһ��Ӧ�ó���ʵ�����  32λ���Ժ����������û�����ˣ�����NULL��

//LPSTR��   CHAR* �������LPSTR
//typedef CHAR *PCHAR, *LPCH, *PCH, *NPSTR, *LPSTR, *PSTR;

//lpCmdLine�������в���
//nCmdShow��  ���ڵ���ʾ��ʽ    ��� ��С�� ���� ������ʾ

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow) //��������
{
    wchar_t *szAppClassName[] = "DKGuiFoundation";
    //ʵ�ֵ�һ��Windows����Ӧ�ó���
    //**��һ������ƴ�����
    WNDCLASS wc;
    wc.style = CS_HREDRAW | CS_VREDRAW; //������ķ��
    wc.lpfnWndProc = WindowProc;        //���ڴ�����

    wc.cbClsExtra = 0;                                   //���������չ�ռ��С    ��ʼ��0
    wc.cbWndExtra = 0;                                   //���ڶ���ռ��ڴ��С    ��ʼ��0
    wc.hInstance = hInstance;                            //��ǰӦ�ó���ʵ�����
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);          //���Ͻ�ͼ��,û�о�NULL,�������һ��ϵͳͼ��
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);            //���������
    wc.hbrBackground = CreateSolidBrush(RGB(255, 0, 0)); //���ػ�ˢ
    wc.lpszMenuName = NULL;                              //�˵���
    wc.lpszClassName = szAppClassName;                   //����������
    //**�ڶ�����ע�ᴰ����
    if (FALSE == RegisterClass(&wc))
    {
        MessageBox(NULL, "ERROR", "Tip", MB_OK);
        return 0;
    }
    //**����������������
    HWND hWnd = CreateWindow(   
        szAppClassNmae,                                                        //����������
        "my first window",                                                     //���ڵı���
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
    ShowWindow(hWnd, SW_SHOW);
    //**���岽�����´���
    //**����������Ϣѭ��
    return 0;
}

//*���ڴ�����
//WPARAM unsigned int
//LPARAM long

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
