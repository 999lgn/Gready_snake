#include"Snake_first.h"													//���һ
using namespace std;

Snake_first::Snake_first(Wall& wall, Food& food) :wall_(wall), food_(food)		//���캯��
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
	while (Head != NULL)											//������������
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
		green();													//����������ɫ
	point* newpoint = new point;									//�����µ�����
	newpoint->x = x;
	newpoint->y = y;
	newpoint ->next= NULL;


	if (Head != NULL)
	{
		wall_.Setwall(Head->y, Head->x, (char*)"��");				//��ӡ����ͷ��������ͷ�������
		gotoxy(hOut, Head->x*2, Head->y);
		cout << "��";

	}
	newpoint->next = Head;											//��������ͷ
	Head = newpoint;
	wall_.Setwall(Head->y, Head->x, (char*)"��");
	gotoxy(hOut, Head->x*2 ,Head->y);
	cout << "��";													//��ӡ����ͷ�����ȼ�һ
}

void Snake_first::InitSnake()
{
	DestoryPoint();												   //��ʼ�������������Ϊ��
	AddPoint(3, 1);
	AddPoint(4, 1);
	AddPoint(5, 1);
}

void Snake_first::DeletePoint()										//ɾ���������һ���ڵ㣬�����ȼ���һ
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
	wall_.Setwall(ptr1->y, ptr1->x, (char*)"  ");				   //����βλ�ûָ��հ�
	gotoxy(hOut, ptr1->x*2, ptr1->y);
	cout << "  ";
	delete ptr1;

	ptr1 = NULL;
	ptr2->next = NULL;
}

bool Snake_first::Move(char key)
{
	int x = Head->x;											//��ͷ������
	int y = Head->y;											//��ͷ������

	switch (key)												//��Ӧ��������
	{
	case UP:													//����
		y--;
		break;
	case DOWN:													//����
		y++;
		break;
	case LEFT:													//����
		x--;
		break;
	case RIGHT:													//����
		x++;
		break;
	default:
		break;
	}
	if (ability == 1)									                //��ǽ״̬��ֻ�����������Լ��߽������
	{
		if(wall_.Getwall(y, x) == (char*)"��"||y==0||y==39||x==0||x==39)
			return false;
	}
	else if (ability == 0 )												//�������ǽ������������
	{
		if(wall_.Getwall(y, x) == (char*)"��" || wall_.Getwall(y, x) == (char*)"��")
			return false;
	}

	if (wall_.Getwall(y, x) == (char*)"��")																		//����Ե�ʳ���򳤶ȼ�һ
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
	else																					//��������������������������һλ������һ���ڵ㣬ĩβɾ��һ���ڵ�
	{
		AddPoint(x, y);
		DeletePoint();																	
	}
	return true;
}

int Snake_first::Getsleeptime()
{ 
	int sleepTime = 0;																	//�ӳ�ʱ��
	int size = Countlist();																//������
	if (difficulty == 1)															    //�Ѷȵȼ�Ϊ��
	{
		sleepTime = 400 - 20 * (size - 3);												//�ӳ�ʱ�������������ӱ��
		return (sleepTime > 10 ? sleepTime : 10);
	}
	else if (difficulty == 2)														    //�Ѷȵȼ�Ϊ��ͨ
	{
		sleepTime = 300 - 15 * (size - 3);												//�ӳ�ʱ�������������ӱ��
		return (sleepTime > 10 ? sleepTime : 10);
	}
	else if (difficulty == 3)														     //�Ѷȵȼ�Ϊ����
	{																					//�ӳ�ʱ�������������ӱ��
		sleepTime = 200 - 10 * (size - 3);
		return (sleepTime > 5 ? sleepTime : 5);
	}
	else if(difficulty == 4)															//�Ѷȵȼ�Ϊ����
	{
		sleepTime = 100 - 5 * (size - 3);												//�ӳ�ʱ�������������ӱ��
		return (sleepTime > 5 ? sleepTime : 5);
	}
	
}

int Snake_first::Countlist()
{
	int  size = 0;
	point* ptr = Head;
	while (ptr != NULL)
	{
		size++;																			//ÿ����һ���ڵ㣬���ȼ�һ
		ptr = ptr->next;
	}
	return size;
}

int Snake_first::Getscore()
{													
	return score;
}

void Snake_first::Resetscore()															//���õ÷�
{
	score = 0;
}

int Snake_first::Getability() { return ability; }										//�鿴�Ƿ�߱���ǽ����

void Snake_first::Resetability() { ability = 0; }										//���ô�ǽ����

