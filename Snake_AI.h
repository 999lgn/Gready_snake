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
	const static int ROWUNIT = 1;													//����̨��λ�д�С
	const static int COLUMNUNIT = 2;												//����̨��λ�д�С
	const static int HEIGHT = 38;													//��Ϸ�����
	const static int WIDTH = 78;													//��Ϸ�����
	const static int INF = 10000;													//�������
	const static int SNAKEBODY = 20000;											    //��������ĳ���
	const static int WALL = 30000;													//����ǽ�ĳ���


	typedef struct node {
		int x;
		int y;
	}SnakeNode;																//һ��λ�ã����Ա�ʾʳ��������

	SnakeNode Food;															//ʳ��

	SnakeNode NextStep;														//��һ����λ��

	SnakeNode theTail;														//��βλ��

	int NextDirection;														//��һ���ķ���

	list<SnakeNode> Snake;													//��¼�ߵ�����

	list<SnakeNode> VirtualSnake;											//��¼�����ߵ�����

	int SnakeDirection;														//�ߵĵ�ǰ����

	int Direction[4][2] = { { 0, ROWUNIT },{ 0, -ROWUNIT },
							{ COLUMNUNIT, 0 },{ -COLUMNUNIT, 0 } };			//��¼�����

	int bfsDistance[WIDTH + 2 * COLUMNUNIT][HEIGHT + 2 * ROWUNIT];			//��¼bfsʱ�����·,��ÿ����ͷ����ʳ����ʵ����

	int bfsJudgeVirtualTail[WIDTH + 2 * COLUMNUNIT][HEIGHT + 2 * ROWUNIT];	//��¼������β���λ�þ���

	int bfsJudgeRealTail[WIDTH + 2 * COLUMNUNIT][HEIGHT + 2 * ROWUNIT];		//��¼��λ�õ���β����								

	int dfsDistance[WIDTH + 2 * COLUMNUNIT][HEIGHT + 2 * ROWUNIT];			//��¼�ݹ���õľ���

	int Mark[WIDTH + 2 * COLUMNUNIT][HEIGHT + 2 * ROWUNIT];					//��ǲ��ɵ����λ��

	int currentDepth, deepest;												//��ǰ��ȣ�������


	void setFood();									//����ʳ��

	void printSnake();								//��ӡ����

	bool isOpposite(int a, int b);					//�ж��ƶ������Ƿ��뵱ǰ�����෴

	void printInterface();							//��ӡ��Ϸ����

	void getFoodDistance();							//��ȡʳ�����λ�þ��룬ʹ��BFS

	bool isReachable();								//�ж���ͷ�Ƿ��ܴﵽʳ��

	bool isVirtualTailReachable_Regular();			//������ѡ�����·��ȥ��ʳ��

	bool isVirtualTailReachable_Random();			//����������������·��ȥ��ʳ��	

	void eatFoodMove();								//����������ƶ�һ��

	bool eatFood();									//ѡ��һ�ֲ��Գ�ʳ��

	bool isSafe(SnakeNode NewHead);					//�ж��߳���ʳ���Ƿ�ȫ�����ҵ�β�ͣ�

	void followTailMove();							//����ȥ��ʳ���ȥ׷��β����

	int FoodDistance(SnakeNode adj);				//������������ʳ��������پ���

	bool followTail();								//׷��β����

	void DFS(int x, int y);							//�ݹ����ĳһλ�����

	int getDepth(SnakeNode temp);					//DFS��ȡ�������������·��

	void snakeWander();								//������в��Զ������У�DFS���·����

	void snakeMove();							    //ѡ��һ�ֲ����ƶ�

};
#endif // !SNAKE_AI

#pragma once
