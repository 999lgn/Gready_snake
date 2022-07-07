#include"Tool.h"
using namespace std;

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

void blue_border()
{
    WORD blue_orange = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED |
        FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN;                            //设置字体颜色、背景颜色（橙）
    SetConsoleTextAttribute(hOut, blue_orange);                                              //设置字体样式
}

void blue()                                                                                 
{
	WORD blue = FOREGROUND_BLUE | FOREGROUND_INTENSITY;                                     //设置为蓝色字体
	SetConsoleTextAttribute(hOut, blue);
}

void white()
{
    WORD white = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;//设置字体颜色、背景颜色（白）
    SetConsoleTextAttribute(hOut, white);                                                   //设置字体样式
}

void green()
{
    WORD cyan = FOREGROUND_GREEN | FOREGROUND_INTENSITY;                                    //设置字体颜色、背景颜色（青）
    SetConsoleTextAttribute(hOut, cyan);                                                    //设置字体样式
}

void red()													                                //设置为红色字体
{
    WORD red = FOREGROUND_RED | FOREGROUND_INTENSITY;
    SetConsoleTextAttribute(hOut, red);
}

void on_Select()
{
    WORD select = FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_RED;                 //设置字体颜色、背景颜色（红）
    SetConsoleTextAttribute(hOut, select);                                                  //设置字体样式
}

void mode_color()
{
    WORD modecolor = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;              //设置字体颜色、背景颜色（橙）
    SetConsoleTextAttribute(hOut, modecolor);                                               //设置字体样式
}

void gotoxy(HANDLE hOut, int x, int y)                  //设置光标位置
{
    COORD pos;
    pos.Y = y;
    pos.X = x;
    SetConsoleCursorPosition(hOut, pos);
}

