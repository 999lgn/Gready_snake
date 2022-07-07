#include"Snake_second.h"																	//玩家二
using namespace std;

Snake_second::Snake_second(Wall& wall, Food& food) :wall_(wall), food_(food)			//构造函数
{
	Head = NULL;
	score = 0;
	ability = 0;

}

void Snake_second::DestoryPoint()													   //销毁所有节点
{
	point* ptr = Head;
	while (Head != NULL)
	{
		ptr = ptr->next;
		delete Head;
		Head = ptr;
	}
}

void Snake_second::AddPoint(int x, int y)											  //增加节点
{
	if (ability)
		red();																		 //设置为红色
	else
		blue();
	point* newpoint = new point;
	newpoint->x = x;
	newpoint->y = y;
	newpoint->next = NULL;


	if (Head != NULL)
	{
		wall_.Setwall(Head->y, Head->x, (char*)"●");								  //打印旧蛇头
		gotoxy(hOut, Head->x * 2, Head->y);
		cout << "●";

	}
	newpoint->next = Head;
	Head = newpoint;
	wall_.Setwall(Head->y, Head->x, (char*)"●");
	gotoxy(hOut, Head->x * 2, Head->y);
	cout << "●";																     //打印新蛇头
}

void Snake_second::InitSnake()													     //初始化节点，蛇身嘴唇长度为三
{
	DestoryPoint();
	AddPoint(3, 38);
	AddPoint(4, 38);
	AddPoint(5, 38);
}

void Snake_second::DeletePoint()												     //删除节点
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
	wall_.Setwall(ptr1->y, ptr1->x, (char*)"  ");								    //恢复蛇尾为空白
	gotoxy(hOut, ptr1->x * 2, ptr1->y);
	cout << "  ";
	delete ptr1;

	ptr1 = NULL;
	ptr2->next = NULL;
}

bool Snake_second::Move(char key)
{
	int x = Head->x;
	int y = Head->y;

	switch (key)																    //响应键盘输入
	{
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	default:
		break;
	}
	if (ability == 0)
	{
		if (wall_.Getwall(y, x) == (char*)"■" || wall_.Getwall(y, x) == (char*)"●")           //碰到蛇身或墙壁，蛇死亡
			return false;
	}
	else if (ability == 1)
	{
		if ( wall_.Getwall(y, x) == (char*)"●"||x==0||x==39||y==0||y==39)					    //穿墙模式，碰到蛇身或边界，蛇死亡
			return false;
	}

	if (wall_.Getwall(y, x) == (char*)"◆")														//碰到食物，长度加一
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
	else
	{
		AddPoint(x, y);																			//其他情况，蛇头处加一，蛇尾处减一
		DeletePoint();
	}
	return true;
}

int Snake_second::Countlist()																	//计算蛇身长度
{
	int  size = 0;
	point* ptr = Head;
	while (ptr != NULL)
	{
		size++;																					//每遍历一个节点，长度加一
		ptr = ptr->next;
	}
	return size;
}

int Snake_second::Getscore()																	//获取得分
{
	return score;
}

void Snake_second::Resetscore()																	//重置得分
{
	score = 0;
}

int Snake_second::Getability() { return ability; }												//查看是否具有穿墙能力

void Snake_second::Resetability() { ability = 0; }												//重置穿墙能力