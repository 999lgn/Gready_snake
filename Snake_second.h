#ifndef SNAKE_SECOND_H										//��Ҷ�
#define SNAKE_SECOND_H
#include"Food.h"
class Snake_second
{
public:
	Snake_second(Wall& wall, Food& food);					//���캯��
	enum													//ö�����ʹ�����Ҷ��������ҵķ���
	{
		UP = 'i',
		DOWN = 'k',
		LEFT = 'j',
		RIGHT = 'l',
	};
	struct point											//�ṹ�壬����ڵ�
	{
		int x;
		int y;
		point* next;
	};

	void InitSnake();										//��ʼ����

	bool Move(char key);									//�ƶ���

	void DestoryPoint();									//�������нڵ�

	void AddPoint(int, int);								//���ӽڵ�

	void DeletePoint();										//ɾ���ڵ�

	int Countlist();										//����������

	int Getscore();											//��ȡ�÷�

	void Resetscore();										//���õ÷�

	int Getability();										//�鿴�Ƿ���д�ǽ����

	void Resetability();									//���ô�ǽ����

	clock_t start;											//��¼ʱ��
private:
	int score ;											   //�÷�

	int ability;											//��ʾ���Ƿ���д�ǽ����

	point* Head;

	Wall& wall_;

	Food& food_;

};

#endif // !SNAKE_H

#pragma once
