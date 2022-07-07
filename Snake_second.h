#ifndef SNAKE_SECOND_H										//玩家二
#define SNAKE_SECOND_H
#include"Food.h"
class Snake_second
{
public:
	Snake_second(Wall& wall, Food& food);					//构造函数
	enum													//枚举类型代表玩家二上下左右的方向
	{
		UP = 'i',
		DOWN = 'k',
		LEFT = 'j',
		RIGHT = 'l',
	};
	struct point											//结构体，储存节点
	{
		int x;
		int y;
		point* next;
	};

	void InitSnake();										//初始化蛇

	bool Move(char key);									//移动蛇

	void DestoryPoint();									//销毁所有节点

	void AddPoint(int, int);								//增加节点

	void DeletePoint();										//删除节点

	int Countlist();										//计算蛇身长度

	int Getscore();											//获取得分

	void Resetscore();										//重置得分

	int Getability();										//查看是否具有穿墙能力

	void Resetability();									//重置穿墙能力

	clock_t start;											//记录时间
private:
	int score ;											   //得分

	int ability;											//表示蛇是否具有穿墙能力

	point* Head;

	Wall& wall_;

	Food& food_;

};

#endif // !SNAKE_H

#pragma once
