#include"Food.h"
Food::Food(Wall& w1) :wall(w1) { FoodX = 0, FoodY = 0, attribute = 0; }

void Food::Setfood()  //����ʳ��
{
	while (true)
	{
		
		FoodX = rand() % (Wall::row - 2) + 1;		//�������x����
		FoodY = rand() % (Wall::col - 2) + 1;		//�������y����
		if (wall.Getwall(FoodY, FoodX) == "  ")		//��ӡʳ���
		{
			wall.Setwall(FoodY, FoodX, (char*)"��");
			gotoxy(hOut, FoodX*2, FoodY);
			int x = rand() % 5 + 1;					//�����߷�ʳ����ߵĸ��ʸ�Ϊ���֮һ
			if (x == 1)
			{
				attribute = 1;
				blue();
				std::cout << "��";
				t_start = clock();
			}
			else if (x == 2&&wall.map!=0)
			{
				attribute = 2;
				red();
				std::cout << "��";
				t_start = clock();
			}
			else 
			{
				attribute = 0;
				white();
				std::cout << "��";
			}
			break;
		}
	}
}

int Food::Get_FoodX() { return FoodX; }			//��ȡʳ�������

int Food::Get_FoodY() { return FoodY; }			//��ȡʳ��������

int Food::Get_attribute() { return attribute; }//���ʳ������