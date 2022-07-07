#ifndef GAME_H
#define GAME_H
#include"Snake_first.h"
#include"Snake_second.h"
#include"Snake_AI.h"
#include"Tool.h"
#include<fstream>
#include<istream>
#include<conio.h>
class Game {
public:
	Game();											 //构造函数
	void star_mainmenu();                                    //初始化主界面

	void star_selectmenu();                                  //初始化选择难度界面

	void star_endmenu();                                     //初始化结束界面

	void star_modemenu();                                    //初始化模式界面

	void star_modemenu_ai();                                 //初始化模式（玩家或AI）界面

	void star_mapmenu();                                     //初始化地图选择界面

	void onChoose_mainmenu();                    //确定所选中的位置（主界面）	（移动到目标位置，背景色变红，代表当前选择位置）

	void onChoose_selectmenu();                 //确定所选中的位置（难度选择界面）

	void onChoose_mapmenu();					//确定所选中的位置（地图选择界面）

	void onChoose_endmenu();                    //确定所选中的位置(游戏结束界面）

	void onChoose_modemenu();                   //确定所选中的位置（模式选择界面）

	void onChoose_modemenu_ai();               //确定所选中的位置（玩家或AI）

	void print_mainmenu();                      //打印主界面

	void print_selectmenu();                    //打印难度选择界面

	void print_mapmenu();                      //打印地图选择界面

	void print_modemenu_ai();                   //打印模式（玩家或AI）界面

	void print_modemenu();                      //打印模式界面

	void print_scoremenu();                     //打印得分界面

	void print_endmenu();                       //打印单人模式游戏结束界面

	void print_endmenu_2();                     //打印双人模式游戏结束界面

	void updatescore();										//更新得分纪录

private:
	int x, y;											//光标位置（x，y）

	bool isDead;										//判断玩家一的蛇是否死亡

	bool isDead_second;									//判断玩家二的蛇是否死亡

	int selectmode;										//选择单双人模式（1代表单人模式，2代表双人模式）

};
#endif // !INITIAL_MENU_H
