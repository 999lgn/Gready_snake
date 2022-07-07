#ifndef FOOD_H
#define FOOD_H
#include"Wall.h"
class Food
{
public:
	Food(Wall&);		//构造函数

	void Setfood();		//在地图中随机设置食物

	int Get_FoodX();	//获取食物横坐标

	int Get_FoodY();	//获取食物纵坐标

	int Get_attribute(); //获得食物属性

	Wall& wall; 

	clock_t t_start ;	//用于表示时间差

private:
	int FoodX;			//食物横坐标

	int FoodY;			//食物纵坐标

	int attribute;     //食物属性（高分或低分）
};
#endif // !FOOD_H

#pragma once
