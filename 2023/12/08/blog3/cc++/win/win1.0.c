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
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow) //��������
{
    //****����
    //����һ������
    //**��һ������
    //HWND�����ھ������
    //**�ڶ�������
    //��Ϣ����ʾ���ı�
    //LPCTSTR:<=>LPCWSTR<=>PCTSTR       const wchar_t*
    //**����������
    //��Ϣ��ʾ��ı���
    //**���ĸ�����
    //ͼ��Ͱ��������
    //UNIT: unsigned int UNIT   //�޷�������

    //MB_: MessageBox
    MessageBox(NULL, "NULL", "NULL", MB_ICONHAND | MB_ABORTRETRYIGNORE);
    // MessageBox(NULL,L"NULL",L"NULL",MB_OK);       //Ϊʲô��������Ƶһ����L

    //MB_ICONHAND | MB_ABORTRETRYIGNORE 16 | 2  0001 0000|0000 0010

    return 0;
}

// int a = 0, b = 1;
// char str[10];
// // printf("%d,%d", a = a + b);
// //sprintf(str, "%d,%d", a = a + b, a = a + b); //����������ջ��a=1��ջ��a+1=2��ջ��a������ͬʱ������״̬��
// //system("pause");