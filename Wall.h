#ifndef WALL_H
#define WALL_H
#include"Tool.h"
#include<iostream>
class Wall
{
public:
	enum { row = 40, col = 40 };			//墙的长，宽

	void Initialwall();						//初始化墙

	void Printwall();				        //打印墙

	void Setwall(int x, int y, char* c);	//设置墙的某一点，生成食物

	char* Getwall(int x, int y);			//获取墙内某一点坐标

	int Getmap();							//返回所选择地图类型

	void Setmap(int x = 0);					//选择地图类型

	int map = 0;							//代表所选择地图，默认地图为0
private:
	char* wall[4][row][col];				//创建三维数组用于储存每一个墙，每一个位置的元素


};
#endif // !WALL_H

#pragma once
