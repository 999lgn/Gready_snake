#include"Game.h"
                                                   
int main()                                              //主函数
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);          //获取控制台光标信息
    CursorInfo.bVisible = false;                        //隐藏控制台光标
    SetConsoleCursorInfo(handle, &CursorInfo);          //设置控制台光标状态
    system("mode con cols=125 lines=45");               //调整控制台大小
    
    Game start;                                         //创建对象
    start.print_mainmenu();                             //打印主界面,开始游戏
    system("pause");
    return 0;

}






