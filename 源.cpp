#include"Game.h"
                                                   
int main()                                              //������
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);          //��ȡ����̨�����Ϣ
    CursorInfo.bVisible = false;                        //���ؿ���̨���
    SetConsoleCursorInfo(handle, &CursorInfo);          //���ÿ���̨���״̬
    system("mode con cols=125 lines=45");               //��������̨��С
    
    Game start;                                         //��������
    start.print_mainmenu();                             //��ӡ������,��ʼ��Ϸ
    system("pause");
    return 0;

}






