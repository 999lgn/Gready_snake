#include"Food.h"
Food::Food(Wall& w1) :wall(w1) { FoodX = 0, FoodY = 0, attribute = 0; }

void Food::Setfood()  //设置食物
{
	while (true)
	{
		
		FoodX = rand() % (Wall::row - 2) + 1;		//随机生成x坐标
		FoodY = rand() % (Wall::col - 2) + 1;		//随机生成y坐标
		if (wall.Getwall(FoodY, FoodX) == "  ")		//打印食物块
		{
			wall.Setwall(FoodY, FoodX, (char*)"◆");
			gotoxy(hOut, FoodX*2, FoodY);
			int x = rand() % 5 + 1;					//产生高分食物，道具的概率各为五分之一
			if (x == 1)
			{
				attribute = 1;
				blue();
				std::cout << "◆";
				t_start = clock();
			}
			else if (x == 2&&wall.map!=0)
			{
				attribute = 2;
				red();
				std::cout << "◆";
				t_start = clock();
			}
			else 
			{
				attribute = 0;
				white();
				std::cout << "◆";
			}
			break;
		}
	}
}

int Food::Get_FoodX() { return FoodX; }			//获取食物横坐标

int Food::Get_FoodY() { return FoodY; }			//获取食物纵坐标

int Food::Get_attribute() { return attribute; }//获得食物属性