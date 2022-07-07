#ifndef SNAKE_AI
#define SNAKE_AI
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <queue>
#include <iterator>
#include <stack>
#include"Tool.h"
using namespace std;

class Snake_AI
{
public:
	const static int ROWUNIT = 1;													//控制台单位行大小
	const static int COLUMNUNIT = 2;												//控制台单位列大小
	const static int HEIGHT = 38;													//游戏区域高
	const static int WIDTH = 78;													//游戏区域宽
	const static int INF = 10000;													//无穷大常量
	const static int SNAKEBODY = 20000;											    //表征蛇身的常量
	const static int WALL = 30000;													//表征墙的常量


	typedef struct node {
		int x;
		int y;
	}SnakeNode;																//一个位置，可以表示食物，蛇身结点等

	SnakeNode Food;															//食物

	SnakeNode NextStep;														//下一步的位置

	SnakeNode theTail;														//蛇尾位置

	int NextDirection;														//下一步的方向

	list<SnakeNode> Snake;													//记录蛇的链表

	list<SnakeNode> VirtualSnake;											//记录虚拟蛇的链表

	int SnakeDirection;														//蛇的当前方向

	int Direction[4][2] = { { 0, ROWUNIT },{ 0, -ROWUNIT },
							{ COLUMNUNIT, 0 },{ -COLUMNUNIT, 0 } };			//记录方向表

	int bfsDistance[WIDTH + 2 * COLUMNUNIT][HEIGHT + 2 * ROWUNIT];			//记录bfs时的最短路,即每次蛇头与与食物真实距离

	int bfsJudgeVirtualTail[WIDTH + 2 * COLUMNUNIT][HEIGHT + 2 * ROWUNIT];	//记录虚拟蛇尾与各位置距离

	int bfsJudgeRealTail[WIDTH + 2 * COLUMNUNIT][HEIGHT + 2 * ROWUNIT];		//记录各位置到蛇尾距离								

	int dfsDistance[WIDTH + 2 * COLUMNUNIT][HEIGHT + 2 * ROWUNIT];			//记录递归求得的距离

	int Mark[WIDTH + 2 * COLUMNUNIT][HEIGHT + 2 * ROWUNIT];					//标记不可到达的位置

	int currentDepth, deepest;												//当前深度，最大深度


	void setFood();									//产生食物

	void printSnake();								//打印蛇身

	bool isOpposite(int a, int b);					//判断移动方向是否与当前方向相反

	void printInterface();							//打印游戏界面

	void getFoodDistance();							//获取食物与各位置距离，使用BFS

	bool isReachable();								//判断蛇头是否能达到食物

	bool isVirtualTailReachable_Regular();			//沿蛇身选择最短路径去吃食物

	bool isVirtualTailReachable_Random();			//方向随机但是是最短路径去吃食物	

	void eatFoodMove();								//沿最近方向移动一步

	bool eatFood();									//选择一种策略吃食物

	bool isSafe(SnakeNode NewHead);					//判断蛇吃完食物是否安全（能找到尾巴）

	void followTailMove();							//不能去吃食物就去追着尾巴跑

	int FoodDistance(SnakeNode adj);				//不考虑蛇身，求到食物的曼哈顿距离

	bool followTail();								//追着尾巴走

	void DFS(int x, int y);							//递归求解某一位置深度

	int getDepth(SnakeNode temp);					//DFS获取各个方向的最深路径

	void snakeWander();								//如果所有策略都不可行，DFS最长的路径走

	void snakeMove();							    //选择一种策略移动

};
#endif // !SNAKE_AI

#pragma once
