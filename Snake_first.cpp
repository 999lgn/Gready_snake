#include"Snake_first.h"													//玩家一
using namespace std;

Snake_first::Snake_first(Wall& wall, Food& food) :wall_(wall), food_(food)		//构造函数
{
	Head = NULL;
	//isRool = false;
	difficulty = 1;
	score = 0;
	ability = 0;
}

void Snake_first::DestoryPoint()
{
	point* ptr = Head;
	while (Head != NULL)											//销毁整个蛇身
	{
		ptr = ptr->next;
		delete Head;
		Head = ptr;
	}
}

void Snake_first::AddPoint(int x, int y)
{
	if (ability)
		red();
	else
		green();													//设置蛇身颜色
	point* newpoint = new point;									//增加新的蛇身
	newpoint->x = x;
	newpoint->y = y;
	newpoint ->next= NULL;


	if (Head != NULL)
	{
		wall_.Setwall(Head->y, Head->x, (char*)"●");				//打印旧蛇头，即旧蛇头变成蛇身
		gotoxy(hOut, Head->x*2, Head->y);
		cout << "●";

	}
	newpoint->next = Head;											//设置新蛇头
	Head = newpoint;
	wall_.Setwall(Head->y, Head->x, (char*)"●");
	gotoxy(hOut, Head->x*2 ,Head->y);
	cout << "●";													//打印新蛇头，长度加一
}

void Snake_first::InitSnake()
{
	DestoryPoint();												   //初始化蛇身，最初长度为三
	AddPoint(3, 1);
	AddPoint(4, 1);
	AddPoint(5, 1);
}

void Snake_first::DeletePoint()										//删除蛇身最后一个节点，即长度减少一
{
	if (Head == NULL || Head->next == NULL)
		return;
	point* ptr1 = Head->next;
	point* ptr2 = Head;
	while (ptr1->next != NULL)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	wall_.Setwall(ptr1->y, ptr1->x, (char*)"  ");				   //将蛇尾位置恢复空白
	gotoxy(hOut, ptr1->x*2, ptr1->y);
	cout << "  ";
	delete ptr1;

	ptr1 = NULL;
	ptr2->next = NULL;
}

bool Snake_first::Move(char key)
{
	int x = Head->x;											//蛇头横坐标
	int y = Head->y;											//蛇头纵坐标

	switch (key)												//响应键盘输入
	{
	case UP:													//向上
		y--;
		break;
	case DOWN:													//向下
		y++;
		break;
	case LEFT:													//向左
		x--;
		break;
	case RIGHT:													//向右
		x++;
		break;
	default:
		break;
	}
	if (ability == 1)									                //穿墙状态，只有碰到自身以及边界才死亡
	{
		if(wall_.Getwall(y, x) == (char*)"●"||y==0||y==39||x==0||x==39)
			return false;
	}
	else if (ability == 0 )												//如果碰到墙或蛇身则死亡
	{
		if(wall_.Getwall(y, x) == (char*)"■" || wall_.Getwall(y, x) == (char*)"●")
			return false;
	}

	if (wall_.Getwall(y, x) == (char*)"◆")																		//如果吃到食物则长度加一
	{
		AddPoint(x, y);
		if (food_.Get_attribute() == 2)
		{
			score += 200;
			ability = 1;
			start = clock();
		}
		if (food_.Get_attribute() == 1)
		{
			score += 300;
		}
		else if (food_.Get_attribute() == 0)
		{
			score += 100;
		}
		food_.Setfood();

	}
	else																					//如果不是以上两种情况，则在下一位置增加一个节点，末尾删除一个节点
	{
		AddPoint(x, y);
		DeletePoint();																	
	}
	return true;
}

int Snake_first::Getsleeptime()
{ 
	int sleepTime = 0;																	//延迟时间
	int size = Countlist();																//蛇身长度
	if (difficulty == 1)															    //难度等级为简单
	{
		sleepTime = 400 - 20 * (size - 3);												//延迟时间随蛇身长度增加变短
		return (sleepTime > 10 ? sleepTime : 10);
	}
	else if (difficulty == 2)														    //难度等级为普通
	{
		sleepTime = 300 - 15 * (size - 3);												//延迟时间随蛇身长度增加变短
		return (sleepTime > 10 ? sleepTime : 10);
	}
	else if (difficulty == 3)														     //难度等级为困难
	{																					//延迟时间随蛇身长度增加变短
		sleepTime = 200 - 10 * (size - 3);
		return (sleepTime > 5 ? sleepTime : 5);
	}
	else if(difficulty == 4)															//难度等级为地狱
	{
		sleepTime = 100 - 5 * (size - 3);												//延迟时间随蛇身长度增加变短
		return (sleepTime > 5 ? sleepTime : 5);
	}
	
}

int Snake_first::Countlist()
{
	int  size = 0;
	point* ptr = Head;
	while (ptr != NULL)
	{
		size++;																			//每遍历一个节点，长度加一
		ptr = ptr->next;
	}
	return size;
}

int Snake_first::Getscore()
{													
	return score;
}

void Snake_first::Resetscore()															//重置得分
{
	score = 0;
}

int Snake_first::Getability() { return ability; }										//查看是否具备穿墙能力

void Snake_first::Resetability() { ability = 0; }										//重置穿墙能力

