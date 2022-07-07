#include"Snake_second.h"																	//��Ҷ�
using namespace std;

Snake_second::Snake_second(Wall& wall, Food& food) :wall_(wall), food_(food)			//���캯��
{
	Head = NULL;
	score = 0;
	ability = 0;

}

void Snake_second::DestoryPoint()													   //�������нڵ�
{
	point* ptr = Head;
	while (Head != NULL)
	{
		ptr = ptr->next;
		delete Head;
		Head = ptr;
	}
}

void Snake_second::AddPoint(int x, int y)											  //���ӽڵ�
{
	if (ability)
		red();																		 //����Ϊ��ɫ
	else
		blue();
	point* newpoint = new point;
	newpoint->x = x;
	newpoint->y = y;
	newpoint->next = NULL;


	if (Head != NULL)
	{
		wall_.Setwall(Head->y, Head->x, (char*)"��");								  //��ӡ����ͷ
		gotoxy(hOut, Head->x * 2, Head->y);
		cout << "��";

	}
	newpoint->next = Head;
	Head = newpoint;
	wall_.Setwall(Head->y, Head->x, (char*)"��");
	gotoxy(hOut, Head->x * 2, Head->y);
	cout << "��";																     //��ӡ����ͷ
}

void Snake_second::InitSnake()													     //��ʼ���ڵ㣬�����촽����Ϊ��
{
	DestoryPoint();
	AddPoint(3, 38);
	AddPoint(4, 38);
	AddPoint(5, 38);
}

void Snake_second::DeletePoint()												     //ɾ���ڵ�
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
	wall_.Setwall(ptr1->y, ptr1->x, (char*)"  ");								    //�ָ���βΪ�հ�
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

	switch (key)																    //��Ӧ��������
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
		if (wall_.Getwall(y, x) == (char*)"��" || wall_.Getwall(y, x) == (char*)"��")           //���������ǽ�ڣ�������
			return false;
	}
	else if (ability == 1)
	{
		if ( wall_.Getwall(y, x) == (char*)"��"||x==0||x==39||y==0||y==39)					    //��ǽģʽ�����������߽磬������
			return false;
	}

	if (wall_.Getwall(y, x) == (char*)"��")														//����ʳ����ȼ�һ
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
		AddPoint(x, y);																			//�����������ͷ����һ����β����һ
		DeletePoint();
	}
	return true;
}

int Snake_second::Countlist()																	//����������
{
	int  size = 0;
	point* ptr = Head;
	while (ptr != NULL)
	{
		size++;																					//ÿ����һ���ڵ㣬���ȼ�һ
		ptr = ptr->next;
	}
	return size;
}

int Snake_second::Getscore()																	//��ȡ�÷�
{
	return score;
}

void Snake_second::Resetscore()																	//���õ÷�
{
	score = 0;
}

int Snake_second::Getability() { return ability; }												//�鿴�Ƿ���д�ǽ����

void Snake_second::Resetability() { ability = 0; }												//���ô�ǽ����