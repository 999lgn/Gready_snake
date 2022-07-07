#ifndef WALL_H
#define WALL_H
#include"Tool.h"
#include<iostream>
class Wall
{
public:
	enum { row = 40, col = 40 };			//ǽ�ĳ�����

	void Initialwall();						//��ʼ��ǽ

	void Printwall();				        //��ӡǽ

	void Setwall(int x, int y, char* c);	//����ǽ��ĳһ�㣬����ʳ��

	char* Getwall(int x, int y);			//��ȡǽ��ĳһ������

	int Getmap();							//������ѡ���ͼ����

	void Setmap(int x = 0);					//ѡ���ͼ����

	int map = 0;							//������ѡ���ͼ��Ĭ�ϵ�ͼΪ0
private:
	char* wall[4][row][col];				//������ά�������ڴ���ÿһ��ǽ��ÿһ��λ�õ�Ԫ��


};
#endif // !WALL_H

#pragma once
