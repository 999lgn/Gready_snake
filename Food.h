#ifndef FOOD_H
#define FOOD_H
#include"Wall.h"
class Food
{
public:
	Food(Wall&);		//���캯��

	void Setfood();		//�ڵ�ͼ���������ʳ��

	int Get_FoodX();	//��ȡʳ�������

	int Get_FoodY();	//��ȡʳ��������

	int Get_attribute(); //���ʳ������

	Wall& wall; 

	clock_t t_start ;	//���ڱ�ʾʱ���

private:
	int FoodX;			//ʳ�������

	int FoodY;			//ʳ��������

	int attribute;     //ʳ�����ԣ��߷ֻ�ͷ֣�
};
#endif // !FOOD_H

#pragma once
