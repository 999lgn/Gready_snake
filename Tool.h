#ifndef TOOL_H
#define TOOL_H
#include<Windows.h>
extern HANDLE hOut;										//��ȡ��׼������

void blue_border();                                     //���ֳȵ�

void blue();											//��ɫ����

void white();											//��ɫ����

void green();											//��ɫ����

void red();												//��ɫ����

void on_Select();                                       //��ѡ��ʱ����ʽ

void mode_color();                                      //ģʽ������ɫ

void gotoxy(HANDLE hOut, int x, int y);                  //���ù��λ��

#endif // !TOOL_H

