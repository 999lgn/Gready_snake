#include"Tool.h"
using namespace std;

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

void blue_border()
{
    WORD blue_orange = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED |
        FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN;                            //����������ɫ��������ɫ���ȣ�
    SetConsoleTextAttribute(hOut, blue_orange);                                              //����������ʽ
}

void blue()                                                                                 
{
	WORD blue = FOREGROUND_BLUE | FOREGROUND_INTENSITY;                                     //����Ϊ��ɫ����
	SetConsoleTextAttribute(hOut, blue);
}

void white()
{
    WORD white = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;//����������ɫ��������ɫ���ף�
    SetConsoleTextAttribute(hOut, white);                                                   //����������ʽ
}

void green()
{
    WORD cyan = FOREGROUND_GREEN | FOREGROUND_INTENSITY;                                    //����������ɫ��������ɫ���ࣩ
    SetConsoleTextAttribute(hOut, cyan);                                                    //����������ʽ
}

void red()													                                //����Ϊ��ɫ����
{
    WORD red = FOREGROUND_RED | FOREGROUND_INTENSITY;
    SetConsoleTextAttribute(hOut, red);
}

void on_Select()
{
    WORD select = FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_RED;                 //����������ɫ��������ɫ���죩
    SetConsoleTextAttribute(hOut, select);                                                  //����������ʽ
}

void mode_color()
{
    WORD modecolor = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;              //����������ɫ��������ɫ���ȣ�
    SetConsoleTextAttribute(hOut, modecolor);                                               //����������ʽ
}

void gotoxy(HANDLE hOut, int x, int y)                  //���ù��λ��
{
    COORD pos;
    pos.Y = y;
    pos.X = x;
    SetConsoleCursorPosition(hOut, pos);
}

