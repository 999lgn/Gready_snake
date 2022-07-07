#include"Wall.h"

void Wall::Initialwall()										//初始化墙，“■”表示墙的边界
{
	for (int i = 0; i < row; ++i)								//地图一
	{
		for (int j = 0; j < col; ++j)
		{
			if (i == 0 || i == row - 1)
				wall[0][i][j] = (char*)"■";						//注意，方块横向占两个位置，纵向占一个位置
			else if (j == 0 || j == col - 1)
				wall[0][i][j] = (char*)"■";
			else
				wall[0][i][j] = (char*)"  ";						//其余位置用两个空格代替
		}
	}

	for (int i = 0; i < row; ++i)								//地图二
	{
		for (int j = 0; j < col; ++j)
		{
			if (i == 0 || i == row - 1)
				wall[1][i][j] = (char*)"■";						//注意，方块横向占两个位置，纵向占一个位置
			else if (j == 0 || j == col - 1)
				wall[1][i][j] = (char*)"■";
			else if ((i == 7 || i == 31) && (j >= 9) && (j <= 29))
				wall[1][i][j] = (char*)"■";
			else if ((j == 7 || j == 31)&& (i >= 9) && (i <= 29))
				wall[1][i][j] = (char*)"■";
			else
				wall[1][i][j] = (char*)"  ";						//其余位置用两个空格代替
		}
	}

	for (int i = 0; i < row; ++i)								 //地图三
	{
		for (int j = 0; j < col; ++j)
		{
			if (i == 0 || i == row - 1)
				wall[2][i][j] = (char*)"■";						//注意，方块横向占两个位置，纵向占一个位置
			else if((i==j)&& ((i >= 4 && i <= 17) || (i >= 21 && i <= 34)))
				wall[2][i][j] = (char*)"■";
			else if ((i+j==38) && ((i >= 4 && i <= 17) || (i >= 21 && i <= 34)))
				wall[2][i][j] = (char*)"■";
			else if((i==19)&&((j>=4&&j<=17)||(j>=21&&j<=34)))
				wall[2][i][j] = (char*)"■";
			else if ((j == 19) && ((i >= 4 && i <= 17) || (i >= 21 && i <= 34)))
				wall[2][i][j] = (char*)"■";
			else if (j == 0 || j == col - 1)
				wall[2][i][j] = (char*)"■";
			else
				wall[2][i][j] = (char*)"  ";						//其余位置用两个空格代替
		}
	}

	for (int i = 0; i < row; ++i)									//地图四
	{
		for (int j = 0; j < col; ++j)
		{
			if (i == 0 || i == row - 1)
				wall[3][i][j] = (char*)"■";						//注意，方块横向占两个位置，纵向占一个位置
			else if((i==4||i==35)&&j>=4&&j<=35)
				wall[3][i][j] = (char*)"■";
			else if(j==4&&i>=4&&i<=35)
				wall[3][i][j] = (char*)"■";
			else if(j==35&&i>=4&&i<=30)
				wall[3][i][j] = (char*)"■";
			else if(i==30&&j>=9&&j<=35)
				wall[3][i][j] = (char*)"■";
			else if(j==9&&i>=9&&i<=30)
				wall[3][i][j] = (char*)"■";
			else if(i==9&&j>=9&&j<=30)
				wall[3][i][j] = (char*)"■";
			else if(j==30&&i>=9&&i<=25)
				wall[3][i][j] = (char*)"■";
			else if(i==25&&j>=14&&j<=30)
				wall[3][i][j] = (char*)"■";
			else if(j==14&&i>14&&i<=25)
				wall[3][i][j] = (char*)"■";
			else if(i==14&&j>=14&&j<=25)
				wall[3][i][j] = (char*)"■";
			else if(j==25&&i>=14&&i<=20)
				wall[3][i][j] = (char*)"■";
			else if(i==20&&j>=19&&j<=25)
				wall[3][i][j] = (char*)"■";
			else if(j==19&&i>=17&&i<=20)
				wall[3][i][j] = (char*)"■";
			else if (j == 0 || j == col - 1)
				wall[3][i][j] = (char*)"■";
			else
				wall[3][i][j] = (char*)"  ";						//其余位置用两个空格代替
		}
	}


}

void Wall::Printwall()											//打印围墙
{																
	white();													//设置墙的颜色
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			std::cout << wall[map][i][j] ;
		}
		std::cout << std::endl;
	}
}

char* Wall::Getwall(int x, int y)								//获取墙内某一点的坐标
{

	return wall[map][x][y];
}

void Wall::Setwall(int x, int y, char* c)						//设置墙内某一点，生成食物
{
	wall[map][x][y] = c;
}

int Wall::Getmap() { return map; };								//返回所选择地图类型

void Wall::Setmap(int x) { map = x; };							//用户设置地图类型

