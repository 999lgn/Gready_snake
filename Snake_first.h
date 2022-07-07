#ifndef SNAKE_H						//���һ
#define SNAKE_H
#include"Food.h"
class Snake_first
{
public:
	Snake_first(Wall& wall, Food& food);	//���캯��
	enum                            //����ö�����ͣ��ֱ�����������ҷ���
	{
		UP = 'w',
		DOWN='s',
		LEFT='a',
		RIGHT='d',
	};
	struct point					//����ṹ�壬�����ڵ㴢��λ��,�Լ�ָ����һλ�õ�ָ�룻�ڵ��������
	{
		int x;
		int y;
		point* next;
	};
	void InitSnake();				//��ʼ����

	bool Move(char key);			//�ߵ��ƶ�

	void DestoryPoint();			//���ٽڵ�

	void AddPoint(int , int);		//���ӽڵ�

	void DeletePoint();				//ɾ���ڵ�

	int Getsleeptime();				//����ӳ�ʱ��

	int Countlist();				//����������

	void Resetscore();			   //���õ÷�

	int Getscore();					//��ȡ�÷�

	int Getability();				//�鿴�Ƿ���д�ǽ����

	void Resetability();			//���ô�ǽ����

	clock_t start;					//��¼ʱ��

	int difficulty;					//��¼�Ѷȵȼ�
private:
	point* Head;					//������ͷ

	Wall& wall_;

	Food& food_;		

	int score;						//��¼�÷�

	int ability;					//��ʾ���Ƿ���д�ǽ����

};

#endif // !SNAKE_FIRST_H

#pragma once
