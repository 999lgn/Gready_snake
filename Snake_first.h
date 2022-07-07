#ifndef SNAKE_H						//玩家一
#define SNAKE_H
#include"Food.h"
class Snake_first
{
public:
	Snake_first(Wall& wall, Food& food);	//构造函数
	enum                            //定义枚举类型，分别代表上下左右方向
	{
		UP = 'w',
		DOWN='s',
		LEFT='a',
		RIGHT='d',
	};
	struct point					//定义结构体，用来节点储存位置,以及指向下一位置的指针；节点代表蛇身
	{
		int x;
		int y;
		point* next;
	};
	void InitSnake();				//初始化蛇

	bool Move(char key);			//蛇的移动

	void DestoryPoint();			//销毁节点

	void AddPoint(int , int);		//增加节点

	void DeletePoint();				//删除节点

	int Getsleeptime();				//获得延迟时间

	int Countlist();				//计算蛇身长度

	void Resetscore();			   //重置得分

	int Getscore();					//获取得分

	int Getability();				//查看是否具有穿墙能力

	void Resetability();			//重置穿墙能力

	clock_t start;					//记录时间

	int difficulty;					//记录难度等级
private:
	point* Head;					//代表蛇头

	Wall& wall_;

	Food& food_;		

	int score;						//记录得分

	int ability;					//表示蛇是否具有穿墙能力

};

#endif // !SNAKE_FIRST_H

#pragma once
