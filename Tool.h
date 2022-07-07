#ifndef TOOL_H
#define TOOL_H
#include<Windows.h>
extern HANDLE hOut;										//获取标准输出句柄

void blue_border();                                     //蓝字橙底

void blue();											//蓝色字体

void white();											//白色字体

void green();											//青色字体

void red();												//红色字体

void on_Select();                                       //被选中时的样式

void mode_color();                                      //模式界面颜色

void gotoxy(HANDLE hOut, int x, int y);                  //设置光标位置

#endif // !TOOL_H

