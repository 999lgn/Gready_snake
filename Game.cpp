#include"Game.h"
#include<iostream>
using namespace std;
Wall w1;                                                //墙对象

Food f1(w1);                                            //食物对象

Snake_first s1(w1, f1);                                 //蛇对象（代表玩家一）

Snake_second s2(w1, f1);                                //蛇对象（代表玩家二）

Snake_AI s3;                                            //蛇对象（代表AI）

clock_t t_end_1,t_end_2;								//用于表示记录时间差

Game::Game()
{
    x = 0, y = 0,selectmode=1;
    isDead = false;
    isDead_second = false;
}

void Game::star_mainmenu()                               //打印主界面选项
{
    green();
    gotoxy(hOut, 25, 10);
    cout << "1. 开始游戏 ";
    gotoxy(hOut, 65, 10);
    cout << "2. 选择难度 ";
    gotoxy(hOut, 25, 20);
    cout << "3. 高分纪录 ";
    gotoxy(hOut, 65, 20);
    cout << "4. 选择模式 ";
    gotoxy(hOut, 25, 30);
    cout << "5. 选择地图 ";
    gotoxy(hOut, 65, 30);
    cout << "6. 退出游戏 ";
}

void Game::star_selectmenu()                              //打印难度选择界面选项
{
    green();
    gotoxy(hOut, 25, 10);
    cout << "1. 简单 ";
    gotoxy(hOut, 65, 10);
    cout << "2. 普通 ";
    gotoxy(hOut, 25, 20);
    cout << "3. 困难 ";
    gotoxy(hOut, 65, 20);
    cout << "4. 地狱 ";
}

void Game::star_mapmenu()                                  //打印地图选择界面选项
{
    green();
    gotoxy(hOut, 25, 10);
    cout << "1. 地图1 ";
    gotoxy(hOut, 65, 10);
    cout << "2. 地图2 ";
    gotoxy(hOut, 25, 20);
    cout << "3. 地图3 ";
    gotoxy(hOut, 65, 20);
    cout << "4. 地图4 ";
}

void Game::star_endmenu()                                   //打印游戏结束界面选项
{
    green();
    gotoxy(hOut, 25, 15);
    cout << "1. 是 ";
    gotoxy(hOut, 65, 15);
    cout << "2. 否 ";

}

void Game::star_modemenu()                                  //打印模式界面选项
{
    green();
    gotoxy(hOut, 20, 15);
    cout << "1. 单人模式 ";
    gotoxy(hOut, 60, 15);
    cout << "2. 双人模式 ";

}
void Game::star_modemenu_ai()                               //打印模式(玩家或AI）界面选项
{
    green();
    gotoxy(hOut, 20, 15);
    cout << "1. 玩家模式 ";
    gotoxy(hOut, 60, 15);
    cout << "2. AI模式 ";
}


void Game::onChoose_mainmenu()                              //主界面，重新打印被选择字体（即背景色变红）
{
    if (x == 25 && y == 10)
    {
        on_Select();
        cout << "1. 开始游戏 ";
    }
    else if (x == 65 && y == 10)
    {
        on_Select();
        cout << "2. 选择难度 ";
    }
    else if (x == 25 && y == 20)
    {
        on_Select();
        cout << "3. 高分纪录 ";
    }
    else if (x == 65 && y == 20)
    {
        on_Select();
        cout << "4. 选择模式 ";
    }
    else if (x == 25 && y == 30)
    {
        on_Select();
        cout << "5. 选择地图 ";
    }
    else if (x == 65 && y == 30)
    {
        on_Select();
        cout << "6. 退出游戏 ";
    }
}

void Game::onChoose_selectmenu()                           //难度选择界面，重新打印被选择字体（即背景色变红）
{
    if (x == 25 && y == 10)
    {
        on_Select();
        cout << "1. 简单 ";
    }
    else if (x == 25 && y == 20)
    {
        on_Select();
        cout << "3. 困难 ";
    }
    else if (x == 65 && y == 10)
    {
        on_Select();
        cout << "2. 普通 ";
    }
    else if (x == 65 && y == 20)
    {
        on_Select();
        cout << "4. 地狱 ";
    }
}

void Game::onChoose_mapmenu()                              //地图选择界面，重新打印被选择字体（即背景色变红）
{
    if (x == 25 && y == 10)
    {
        on_Select();
        cout << "1. 地图1 ";
    }
    else if (x == 25 && y == 20)
    {
        on_Select();
        cout << "3. 地图3 ";
    }
    else if (x == 65 && y == 10)
    {
        on_Select();
        cout << "2. 地图2 ";
    }
    else if (x == 65 && y == 20)
    {
        on_Select();
        cout << "4. 地图4 ";
    }
}

void Game::onChoose_endmenu()                             //游戏结束界面，重新打印被选择字体（即背景色变红）
{
    if (x == 25 && y == 15)
    {
        on_Select();
        cout << "1. 是 ";
    }
    else if (x == 65 && y == 15)
    {
        on_Select();
        cout << "2. 否 ";
    }
}

void Game::onChoose_modemenu()                            //模式界面，重新打印被选择字体（即背景色变红）
{
    if (x == 20 && y == 15)
    {
        on_Select();
        cout << "1. 单人模式 ";
    }
    else if (x == 60 && y == 15)
    {
        on_Select();
        cout << "2. 双人模式 ";
    }
}

void Game::onChoose_modemenu_ai()                          //模式界面（玩家或AI），重新打印被选择字体（即背景色变红）
{
    if (x == 20 && y == 15)
    {
        on_Select();
        cout << "1. 玩家模式";
    }
    else if (x == 60 && y == 15)
    {
        on_Select();
        cout << "2. AI模式";
    }
}

void Game::print_mainmenu()                                //打印主界面
{
    green();
    system("cls");
    cout << "操作说明：w,a,s,d 控制光标选择；Enter 确定；空格加速；控制蛇（玩家一：w，a，s，d ；玩家二：i，j，k，l）" << endl;//操作说明

    gotoxy(hOut, 45, 4);
    cout << "贪吃蛇大作战";
    blue_border();
    gotoxy(hOut, 10, 5);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";        //打印上边框
    gotoxy(hOut, 10, 35);
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";        //打印下边框
    for (int i = 10, j = 6; j < 35; j++)                                                                //打印左边框
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    for (int i = 90, j = 6; j < 35; j++)                                                                //打印右边框
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }

    on_Select();                                                    //打印各个选项
    gotoxy(hOut, 25, 10);
    cout << "1. 开始游戏 ";
    green();
    gotoxy(hOut, 65, 10);
    cout << "2. 选择难度 ";
    gotoxy(hOut, 25, 20);
    cout << "3. 高分纪录 ";
    gotoxy(hOut, 65, 20);
    cout << "4. 选择模式 ";
    gotoxy(hOut, 25, 30);
    cout << "5. 选择地图 ";
    gotoxy(hOut, 65, 30);
    cout << "6. 退出游戏 ";

    x = 25, y = 10;                                                  //初始化坐标
    char sel;
    sel = _getch();
    while (sel != '\r')                                              //如果监测到键盘输入Enter键，代表选择该选项，跳出循环
    {
        star_mainmenu();
        switch (sel)                                                 //wsad控制光标进行自由选择
        {
        case 'w':
            y = y - 10;
            break;
        case 's':
            y = y + 10;
            break;
        case 'a':
            x = x - 40;
            break;
        case 'd':
            x = x + 40;
            break;
        }
        //防止超出范围
        if (x >= 65)
        {
            x = 65;
        }
        if (y >= 30)
        {
            y = 30;
        }
        if (x <= 25)
        {
            x = 25;
        }
        if (y <= 10)
        {
            y = 10;
        }
        gotoxy(hOut, x, y);                                         //到达光标位置
        onChoose_mainmenu();                                        //重新打印被选择选项，标红
        sel = _getch();
    }
    if (x == 25 && y == 10)                                         //开始游戏
    {
        if (selectmode == 1)                                        //单人模式
        {
            white();
            system("cls");                                          //先清屏
            srand((unsigned int)time(0));
            char prekey = NULL;                                    //保存前一键盘输入

            w1.Initialwall();                                      //初始化墙模块
            w1.Printwall();                                        //打印墙
            s1.InitSnake();                                        //初始化蛇

            white();
            gotoxy(hOut, 0, Wall::row + 1);                        //在左下角显示当前得分以及难度等级
            cout << "得分：" << s1.Getscore() << endl;
            cout << "难度：";
            if (s1.difficulty == 1)
            {
                cout << "简单" << endl;
            }
            else if (s1.difficulty == 2)
            {
                cout << "普通" << endl;
            }
            else if (s1.difficulty == 3)
            {
                cout << "困难" << endl;
            }
            else if (s1.difficulty == 4)
            {
                cout << "地狱" << endl;
            }
            f1.Setfood();                                          //设置食物
            while (!isDead)                                       //如果蛇没有死亡，一直循环
            {

                char key1 = _getch();                                                                //接收键盘输入
                if (prekey == NULL && key1 == s1.LEFT) { continue; }                                 //最开始方向向左
                do
                {
                    if (key1 == s1.UP || key1 == s1.DOWN || key1 == s1.LEFT || key1 == s1.RIGHT)
                    {
                        if ((key1 == s1.LEFT && prekey == s1.RIGHT) ||                              //如果键盘输入与当前方向相反，则无效，保持当前方向，不更新键盘输入
                            (key1 == s1.RIGHT && prekey == s1.LEFT) ||
                            (key1 == s1.UP && prekey == s1.DOWN) ||
                            (key1 == s1.DOWN && prekey == s1.UP)
                            )
                        {
                            key1 = prekey;
                        }
                        else                                                                         //否则更新键盘输入
                        {
                            prekey = key1;
                        }
                        if (s1.Move(key1) == true)                                                  //如果蛇移动成功
                        {
                            gotoxy(hOut, 0, Wall::row + 1);
                            white();
                            cout << "得分:" << s1.Getscore();                                       //更新得分
                            if (GetAsyncKeyState(VK_SPACE))                                        //监测是否按下空格
                                Sleep(25);                                                         //按下则加速
                            else
                                Sleep(s1.Getsleeptime());                                          //否则进行正常延迟
                        }
                        else
                        {
                            isDead = true;
                            updatescore();                                                         //如果死亡，更新高分纪录；
                            print_endmenu();                                                       //打印游戏结束界面
                            if (isDead)
                                break;
                        }

                    }
                    else
                    {
                        key1 = prekey;                                                            //如果按下其他键，蛇保持当前方向
                    }
                    t_end_1 = clock();
                    if ((f1.Get_attribute() == 1|| f1.Get_attribute() == 2) && (t_end_1 - f1.t_start > 3000))
                    {
                        w1.Setwall(f1.Get_FoodY(), f1.Get_FoodX(), (char*)"  ");
                        gotoxy(hOut, f1.Get_FoodX() * 2, f1.Get_FoodY());
                        std::cout << "  ";
                        f1.Setfood();
                    }
                    t_end_2 = clock();
                    if (s1.Getability() == 1 && (t_end_2 - s1.start > 5000))
                        s1.Resetability();
                } while (!_kbhit());                                                             //如果没有监测到键盘输入，则保持当前方向

            }
            return;
        }

        else if (selectmode == 2)                                                                //双人模式
        {
            white();
            system("cls");
            srand((unsigned int)time(0));
            char prekey = NULL;                                                                  //保存当前键盘输入
            char prekey_second = NULL;                                                           //保存前一键盘输入

            w1.Initialwall();
            w1.Printwall();                                                                      //打印墙
            f1.Setfood();                                                                        //设置食物
            s1.InitSnake();                                                                      //初始化玩家一
            s2.InitSnake();                                                                      //初始化玩家二

            white();
            gotoxy(hOut, 0, Wall::row);
            cout << "玩家一得分：" << s1.Getscore();                                             //左下角打印两名玩家的得分
            gotoxy(hOut, 0, Wall::row + 1);
            cout << "玩家二得分：" << s2.Getscore();

            while ((!isDead) && (!isDead_second))
            {

                char key = _getch();
                char key1 = key;                                                                 //代表玩家一接收键盘输入
                char key2 = key;                                                                 //代表玩家二接收键盘输入
                if (prekey == NULL && key1 == s1.LEFT) { continue; }
                if (prekey_second == NULL && key2 == s2.LEFT) { continue; }
                do
                {

                    if (key1 == s1.UP || key1 == s1.DOWN || key1 == s1.LEFT || key1 == s1.RIGHT)
                    {
                        if ((key1 == s1.LEFT && prekey == s1.RIGHT) ||                           //如果当前输入与蛇的方向反向，输入无效
                            (key1 == s1.RIGHT && prekey == s1.LEFT) ||
                            (key1 == s1.UP && prekey == s1.DOWN) ||
                            (key1 == s1.DOWN && prekey == s1.UP)
                            )
                        {
                            key1 = prekey;                                                       //保持前一方向
                        }
                        else
                        {
                            prekey = key1;                                                       //否则更新方向
                        }
                        if (s1.Move(key1) == true)
                        {
                            gotoxy(hOut, 0, Wall::row);
                            white();
                            cout << "玩家一得分:" << s1.Getscore();                              //移动成功，更新玩家一得分
                            Sleep(75);
                        }
                        else
                        {
                            isDead = true;
                            print_endmenu_2();                                                   //如果玩家一死亡，游戏结束
                            if (isDead)
                                break;
                        }

                    }
                    else
                    {
                        key1 = prekey;                                                            //其他无效输入则让蛇保持当前方向不变
                    }

                    if (key2 == s2.UP || key2 == s2.DOWN || key2 == s2.LEFT || key2 == s2.RIGHT)
                    {
                        if ((key2 == s2.LEFT && prekey_second == s2.RIGHT) ||                     //如果当前输入与蛇的方向反向，输入无效
                            (key2 == s2.RIGHT && prekey_second == s2.LEFT) ||
                            (key2 == s2.UP && prekey_second == s2.DOWN) ||
                            (key2 == s2.DOWN && prekey_second == s2.UP)
                            )
                        {
                            key2 = prekey_second;                                                  //保持前一方向
                        }
                        else
                        {
                            prekey_second = key2;                                                  //否则更新方向
                        }
                        if (s2.Move(key2) == true)
                        {
                            gotoxy(hOut, 0, Wall::row + 1);
                            white();
                            cout << "玩家二得分:" << s2.Getscore();                                //移动成功，更新玩家二得分
                            Sleep(75);
                        }
                        else
                        {
                            isDead_second = true;
                            print_endmenu_2();                                                     //如果玩家二死亡，游戏结束
                            if (isDead_second)
                                break;
                        }

                    }
                    else
                    {
                        key2 = prekey_second;                                                      //其他无效按键则保持当前方向
                    }
                    t_end_1 = clock();
                    if ((f1.Get_attribute() == 1||f1.Get_attribute()==2) && (t_end_1 - f1.t_start > 3000))
                    {
                        w1.Setwall(f1.Get_FoodY(), f1.Get_FoodX(), (char*)"  ");
                        gotoxy(hOut, f1.Get_FoodX() * 2, f1.Get_FoodY());
                        std::cout << "  ";
                        f1.Setfood();
                    }
                    t_end_2 = clock();
                    if (s1.Getability() == 1 && (t_end_2 - s1.start > 5000))
                        s1.Resetability();
                    if (s2.Getability() == 1 && (t_end_2 - s2.start > 5000))
                        s2.Resetability();

                } while (!_kbhit());                                                                //如果当前没有键盘输入，蛇就保持当前方向前进
            }
            return;
        }
        else if (selectmode == 3)
        {
            white();
            system("cls");
            srand((unsigned int)time(0));
            s3.printInterface();					//打印界面
            while (s3.Snake.size() < static_cast<unsigned long long>(Snake_AI::WIDTH) * Snake_AI::HEIGHT) //未占满全屏
            {
                s3.snakeMove();						//移动一步
                s3.printSnake();					//打印新的蛇
                Sleep(20);							//控制移动速度
                if (GetAsyncKeyState(VK_ESCAPE))    //按下ESC返回
                    break;

            }
            while (!s3.Snake.empty())
                s3.Snake.pop_back();
            print_mainmenu();
            return;
        }
    }
    else if (x == 65 && y == 10)                                                                        //选择难度界面
    {
        print_selectmenu();
    }
    else if (x == 25 && y == 20)                                                                         //选择记录高分界面
    {
        print_scoremenu();
    }
    else if (x == 65 && y == 20)                                                                         //选择模式界面
    {
        print_modemenu();
    }
    else if (x == 25 && y == 30)                                                                         //选择地图界面
    {
        print_mapmenu();
    }
    else if (x == 65 && y == 30)
    {
        exit(-1);
    }
   

    
}

void Game::print_selectmenu()
{
    mode_color();
    system("cls");
    gotoxy(hOut, 42, 4);
    cout << "选择难度";
    gotoxy(hOut, 5, 5);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";         //打印上边框
    gotoxy(hOut, 5, 25);
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";        //打印下边框
    for (int i = 5, j = 6; j < 25; j++)                                                                 //打印左边框
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    for (int i = 85, j = 6; j < 25; j++)                                                                //打印右边框
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    green();
    gotoxy(hOut, 65, 10);                                                                               //打印不同模式
    cout << "2. 普通 ";
    gotoxy(hOut, 25, 20);
    cout << "3. 困难 ";
    gotoxy(hOut, 65, 20);
    cout << "4. 地狱 ";
    on_Select();
    gotoxy(hOut, 25, 10);
    cout << "1. 简单 ";
    //wsad控制光标对进行自由选择
    x = 25, y = 10;
    char sel;
    sel = _getch();
    while (sel != '\r')
    {
        star_selectmenu();
        switch (sel)
        {
        case 'w':
            y = y - 10;
            break;
        case 's':
            y = y + 10;
            break;
        case 'a':
            x = x - 40;
            break;
        case 'd':
            x = x + 40;
            break;
        }
        //防止超出范围
        if (x >= 65)
        {
            x = 65;
        }
        if (y >= 20)
        {
            y = 20;
        }
        if (x <= 25)
        {
            x = 25;
        }
        if (y <= 10)
        {
            y = 10;
        }
        gotoxy(hOut, x, y);
        onChoose_selectmenu();
        sel = _getch();
    }
    if (x == 25 && y == 10)
        s1.difficulty = 1;                      //简单
    else if (x == 65 && y == 10)
        s1.difficulty = 2;                      //普通
    else if (x == 25 && y == 20)
        s1.difficulty = 3;                      //困难
    else if (x == 65 && y == 20)
        s1.difficulty = 4;                      //地狱
    print_mainmenu();                             //返回主界面

}

void Game::print_mapmenu()
{
    mode_color();
    system("cls");
    gotoxy(hOut, 42, 4);
    cout << "选择地图";
    gotoxy(hOut, 5, 5);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";         //打印上边框
    gotoxy(hOut, 5, 25);
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";        //打印下边框
    for (int i = 5, j = 6; j < 25; j++)                                                                 //打印左边框
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    for (int i = 85, j = 6; j < 25; j++)                                                                //打印右边框
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    green();
    gotoxy(hOut, 65, 10);                                                                               //打印不同地图
    cout << "2. 地图2 ";
    gotoxy(hOut, 25, 20);
    cout << "3. 地图3 ";
    gotoxy(hOut, 65, 20);
    cout << "4. 地图4 ";
    on_Select();
    gotoxy(hOut, 25, 10);
    cout << "1. 地图1 ";
    //wsad控制光标对进行自由选择
    x = 25, y = 10;
    char sel;
    sel = _getch();
    while (sel != '\r')
    {
        star_mapmenu();
        switch (sel)
        {
        case 'w':
            y = y - 10;
            break;
        case 's':
            y = y + 10;
            break;
        case 'a':
            x = x - 40;
            break;
        case 'd':
            x = x + 40;
            break;
        }
        //防止超出范围
        if (x >= 65)
        {
            x = 65;
        }
        if (y >= 20)
        {
            y = 20;
        }
        if (x <= 25)
        {
            x = 25;
        }
        if (y <= 10)
        {
            y = 10;
        }
        gotoxy(hOut, x, y);
        onChoose_mapmenu();
        sel = _getch();
    }
    if (x == 25 && y == 10)
        w1.map = 0;                      
    else if (x == 65 && y == 10)
        w1.map = 1;
    else if (x == 25 && y == 20)
        w1.map = 2;
    else if (x == 65 && y == 20)
        w1.map = 3;
    print_mainmenu();                             //返回主界面

}

void Game::print_endmenu()
{
    mode_color();
    system("cls");
    gotoxy(hOut, 33, 4);
    cout << "本次游戏得分：" << s1.Getscore() << "  " << "是否再次进行游戏";
    s1.Resetscore();                                           //得分清零
    gotoxy(hOut, 5, 5);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";//打印上边框
    gotoxy(hOut, 5, 25);
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";//打印下边框
    for (int i = 5, j = 6; j < 25; j++)   //打印左边框
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    for (int i = 85, j = 6; j < 25; j++) //打印右边框
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    green();
    gotoxy(hOut, 65, 15);
    cout << "2. 否 ";
    gotoxy(hOut, 25, 15);
    on_Select();
    cout << "1. 是 ";
    //wsad控制光标对进行自由选择
    x = 25, y = 15;
    char sel;
    sel = _getch();
    while (sel != '\r')
    {
        star_endmenu();
        switch (sel)
        {
        case 'a':
            x = x - 40;
            break;
        case 'd':
            x = x + 40;
            break;
        }
        //防止超出范围
        if (x >= 65)
        {
            x = 65;
        }
        if (x <= 25)
        {
            x = 25;
        }
        gotoxy(hOut, x, y);
        onChoose_endmenu();
        sel = _getch();
    }
    if (x == 25 && y == 15)
    {
        isDead = false;             //重新游戏，玩家置活
        print_mainmenu();          //返回主界面

    }
    else if (x == 65 && y == 15)     //不重新开始游戏，游戏结束
    {
        exit(-1);
    }
}

void Game::print_endmenu_2()          //双人模式结束界面
{
    mode_color();
    system("cls");
    gotoxy(hOut, 43, 4);
    if (s1.Getscore() > s2.Getscore())
        cout << "玩家一获胜";
    else if (s1.Getscore() < s2.Getscore())
        cout << "玩家二获胜";
    else if (s1.Getscore() == s2.Getscore())
        cout << "平局";
    s1.Resetscore();                         //得分清零
    s2.Resetscore();
    gotoxy(hOut, 38, 10);
    cout << "是否再次进行游戏";
    gotoxy(hOut, 5, 5);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";//打印上边框
    gotoxy(hOut, 5, 25);
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";//打印下边框
    for (int i = 5, j = 6; j < 25; j++) //打印左边框
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    for (int i = 85, j = 6; j < 25; j++) //打印右边框
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    green();
    gotoxy(hOut, 65, 15);
    cout << "2. 否 ";
    gotoxy(hOut, 25, 15);
    on_Select();
    cout << "1. 是 ";
    //wsad控制光标对进行自由选择
    x = 25, y = 15;
    char sel;
    sel = _getch();
    while (sel != '\r')
    {
        star_endmenu();
        switch (sel)
        {
        case 'a':
            x = x - 40;
            break;
        case 'd':
            x = x + 40;
            break;
        }
        //防止超出范围
        if (x >= 65)
        {
            x = 65;
        }
        if (x <= 25)
        {
            x = 25;
        }
        gotoxy(hOut, x, y);
        onChoose_endmenu();
        sel = _getch();
    }
    if (x == 25 && y == 15)
    {
        isDead = false;                     // 如果重新游戏，玩家一，玩家二置活
        isDead_second = false;
        print_mainmenu();                   //返回主界面

    }
    else if (x == 65 && y == 15)
    {
        exit(-1);                            //不重新开始游戏，结束游戏
    }
}

void Game::print_scoremenu()
{
    mode_color();
    system("cls");
    gotoxy(hOut, 42, 4);
    cout << "历史高分";
    gotoxy(hOut, 5, 5);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";//打印上边框
    gotoxy(hOut, 5, 25);
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";//打印下边框
    for (int i = 5, j = 6; j < 25; j++) //打印左边框
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    for (int i = 85, j = 6; j < 25; j++) //打印右边框
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    fstream outin("score.dat", ios::in | ios::out | ios::binary);//获取得分纪录
    outin.seekg(0);
    int score[3];                       //创建数组保存得分前三名
    for (int i = 0; i < 3; ++i)
        outin.read(reinterpret_cast<char*>(&score[i]), sizeof(int));
    outin.close();
    gotoxy(hOut, 40, 10);               //打印前三名得分
    cout << "第一名：" << score[0];
    gotoxy(hOut, 40, 15);
    cout << "第二名：" << score[1];
    gotoxy(hOut, 40, 20);
    cout << "第三名：" << score[2];
    char sel;
    sel = _getch();
    while (sel != 27)                   //按下ESC键，返回主界面
    {
        sel = _getch();
    }
    print_mainmenu();
}

void Game::print_modemenu()
{
    mode_color();
    system("cls");
    gotoxy(hOut, 41, 4);
    cout << "选择模式";
    gotoxy(hOut, 5, 5);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";//打印上边框
    gotoxy(hOut, 5, 25);
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";//打印下边框
    for (int i = 5, j = 6; j < 25; j++) //打印左边框
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    for (int i = 85, j = 6; j < 25; j++) //打印右边框
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    green();
    gotoxy(hOut, 60, 15);
    cout << "2. 双人模式 ";
    gotoxy(hOut, 20, 15);
    on_Select();
    cout << "1. 单人模式 ";
    //wsad控制光标对进行自由选择
    x = 20, y = 15;
    char sel;
    sel = _getch();
    while (sel != '\r')
    {
        star_modemenu();
        switch (sel)
        {
        case 'a':
            x = x - 40;
            break;
        case 'd':
            x = x + 40;
            break;
        }
        //防止超出范围
        if (x >= 60)
        {
            x = 60;
        }
        if (x <= 20)
        {
            x = 20;
        }
        gotoxy(hOut, x, y);
        onChoose_modemenu();
        sel = _getch();
    }
    if (x == 20 && y == 15)
    {
        selectmode = 1;                     //单人模式
        print_modemenu_ai();                //返回主界面
    }
    else if (x == 60 && y == 15)
    {
        selectmode = 2;                     //双人模式
        print_mainmenu();                   //返回主界面
    }

}

void Game::print_modemenu_ai()
{
    mode_color();
    system("cls");
    gotoxy(hOut, 39, 4);
    cout << "选择玩家或AI";
    gotoxy(hOut, 5, 5);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";//打印上边框
    gotoxy(hOut, 5, 25);
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";//打印下边框
    for (int i = 5, j = 6; j < 25; j++) //打印左边框
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    for (int i = 85, j = 6; j < 25; j++) //打印右边框
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    green();
    gotoxy(hOut, 60, 15);
    cout << "2. AI模式 ";
    gotoxy(hOut, 20, 15);
    on_Select();
    cout << "1. 玩家模式 ";
    //wsad控制光标对进行自由选择
    x = 20, y = 15;
    char sel;
    sel = _getch();
    while (sel != '\r')
    {
        star_modemenu_ai();
        switch (sel)
        {
        case 'a':
            x = x - 40;
            break;
        case 'd':
            x = x + 40;
            break;
        }
        //防止超出范围
        if (x >= 60)
        {
            x = 60;
        }
        if (x <= 20)
        {
            x = 20;
        }
        gotoxy(hOut, x, y);
        onChoose_modemenu_ai();
        sel = _getch();
    }
    if (x == 20 && y == 15)
    {
        selectmode = 1;                     //玩家模式
        print_mainmenu();                   //返回主界面
    }
    else if (x == 60 && y == 15)
    {
        selectmode = 3;                     //AI模式
        print_mainmenu();                   //返回主界面
    }

}

void Game::updatescore()
{
    fstream outin("score.dat", ios::in | ios::out | ios::binary);     //获取得分纪录
    outin.seekg(0);
    int score[3];                                                    //创建数组保存前三名
    for (int i = 0; i < 3; ++i)
        outin.read(reinterpret_cast<char*>(&score[i]), sizeof(int));
    if (s1.Getscore() < score[2])                                   //如果本次得分低于第三名，直接关闭文件
        outin.close();
    else if (s1.Getscore() > score[2] && s1.Getscore() < score[1])  //如果本次得分高于第三名，低于第二名，更新第三名成绩
    {
        score[2] = s1.Getscore();
        outin.seekp(0);
        for (int i = 0; i < 3; ++i)
            outin.write(reinterpret_cast<const char*>(&score[i]), sizeof(int));
        outin.close();
    }
    else if (s1.Getscore() >= score[1] && s1.Getscore() < score[0]) //如果本次得分高于第二名，低于第一名，更新第二，三名成绩
    {
        int tem = score[1];
        score[1] = s1.Getscore();
        score[2] = tem;
        outin.seekp(0);
        for (int i = 0; i < 3; ++i)
            outin.write(reinterpret_cast<const char*>(&score[i]), sizeof(int));
        outin.close();
    }
    else if (s1.Getscore() >= score[0])                             //如果本次得分高于第一名，更新第一，二，三名成绩
    {
        int tem0 = score[0];
        int tem1 = score[1];
        score[0] = s1.Getscore();
        score[1] = tem0;
        score[2] = tem1;
        outin.seekp(0);
        for (int i = 0; i < 3; ++i)
            outin.write(reinterpret_cast<const char*>(&score[i]), sizeof(int));
        outin.close();
    }
}
