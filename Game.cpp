#include"Game.h"
#include<iostream>
using namespace std;
Wall w1;                                                //ǽ����

Food f1(w1);                                            //ʳ�����

Snake_first s1(w1, f1);                                 //�߶��󣨴������һ��

Snake_second s2(w1, f1);                                //�߶��󣨴�����Ҷ���

Snake_AI s3;                                            //�߶��󣨴���AI��

clock_t t_end_1,t_end_2;								//���ڱ�ʾ��¼ʱ���

Game::Game()
{
    x = 0, y = 0,selectmode=1;
    isDead = false;
    isDead_second = false;
}

void Game::star_mainmenu()                               //��ӡ������ѡ��
{
    green();
    gotoxy(hOut, 25, 10);
    cout << "1. ��ʼ��Ϸ ";
    gotoxy(hOut, 65, 10);
    cout << "2. ѡ���Ѷ� ";
    gotoxy(hOut, 25, 20);
    cout << "3. �߷ּ�¼ ";
    gotoxy(hOut, 65, 20);
    cout << "4. ѡ��ģʽ ";
    gotoxy(hOut, 25, 30);
    cout << "5. ѡ���ͼ ";
    gotoxy(hOut, 65, 30);
    cout << "6. �˳���Ϸ ";
}

void Game::star_selectmenu()                              //��ӡ�Ѷ�ѡ�����ѡ��
{
    green();
    gotoxy(hOut, 25, 10);
    cout << "1. �� ";
    gotoxy(hOut, 65, 10);
    cout << "2. ��ͨ ";
    gotoxy(hOut, 25, 20);
    cout << "3. ���� ";
    gotoxy(hOut, 65, 20);
    cout << "4. ���� ";
}

void Game::star_mapmenu()                                  //��ӡ��ͼѡ�����ѡ��
{
    green();
    gotoxy(hOut, 25, 10);
    cout << "1. ��ͼ1 ";
    gotoxy(hOut, 65, 10);
    cout << "2. ��ͼ2 ";
    gotoxy(hOut, 25, 20);
    cout << "3. ��ͼ3 ";
    gotoxy(hOut, 65, 20);
    cout << "4. ��ͼ4 ";
}

void Game::star_endmenu()                                   //��ӡ��Ϸ��������ѡ��
{
    green();
    gotoxy(hOut, 25, 15);
    cout << "1. �� ";
    gotoxy(hOut, 65, 15);
    cout << "2. �� ";

}

void Game::star_modemenu()                                  //��ӡģʽ����ѡ��
{
    green();
    gotoxy(hOut, 20, 15);
    cout << "1. ����ģʽ ";
    gotoxy(hOut, 60, 15);
    cout << "2. ˫��ģʽ ";

}
void Game::star_modemenu_ai()                               //��ӡģʽ(��һ�AI������ѡ��
{
    green();
    gotoxy(hOut, 20, 15);
    cout << "1. ���ģʽ ";
    gotoxy(hOut, 60, 15);
    cout << "2. AIģʽ ";
}


void Game::onChoose_mainmenu()                              //�����棬���´�ӡ��ѡ�����壨������ɫ��죩
{
    if (x == 25 && y == 10)
    {
        on_Select();
        cout << "1. ��ʼ��Ϸ ";
    }
    else if (x == 65 && y == 10)
    {
        on_Select();
        cout << "2. ѡ���Ѷ� ";
    }
    else if (x == 25 && y == 20)
    {
        on_Select();
        cout << "3. �߷ּ�¼ ";
    }
    else if (x == 65 && y == 20)
    {
        on_Select();
        cout << "4. ѡ��ģʽ ";
    }
    else if (x == 25 && y == 30)
    {
        on_Select();
        cout << "5. ѡ���ͼ ";
    }
    else if (x == 65 && y == 30)
    {
        on_Select();
        cout << "6. �˳���Ϸ ";
    }
}

void Game::onChoose_selectmenu()                           //�Ѷ�ѡ����棬���´�ӡ��ѡ�����壨������ɫ��죩
{
    if (x == 25 && y == 10)
    {
        on_Select();
        cout << "1. �� ";
    }
    else if (x == 25 && y == 20)
    {
        on_Select();
        cout << "3. ���� ";
    }
    else if (x == 65 && y == 10)
    {
        on_Select();
        cout << "2. ��ͨ ";
    }
    else if (x == 65 && y == 20)
    {
        on_Select();
        cout << "4. ���� ";
    }
}

void Game::onChoose_mapmenu()                              //��ͼѡ����棬���´�ӡ��ѡ�����壨������ɫ��죩
{
    if (x == 25 && y == 10)
    {
        on_Select();
        cout << "1. ��ͼ1 ";
    }
    else if (x == 25 && y == 20)
    {
        on_Select();
        cout << "3. ��ͼ3 ";
    }
    else if (x == 65 && y == 10)
    {
        on_Select();
        cout << "2. ��ͼ2 ";
    }
    else if (x == 65 && y == 20)
    {
        on_Select();
        cout << "4. ��ͼ4 ";
    }
}

void Game::onChoose_endmenu()                             //��Ϸ�������棬���´�ӡ��ѡ�����壨������ɫ��죩
{
    if (x == 25 && y == 15)
    {
        on_Select();
        cout << "1. �� ";
    }
    else if (x == 65 && y == 15)
    {
        on_Select();
        cout << "2. �� ";
    }
}

void Game::onChoose_modemenu()                            //ģʽ���棬���´�ӡ��ѡ�����壨������ɫ��죩
{
    if (x == 20 && y == 15)
    {
        on_Select();
        cout << "1. ����ģʽ ";
    }
    else if (x == 60 && y == 15)
    {
        on_Select();
        cout << "2. ˫��ģʽ ";
    }
}

void Game::onChoose_modemenu_ai()                          //ģʽ���棨��һ�AI�������´�ӡ��ѡ�����壨������ɫ��죩
{
    if (x == 20 && y == 15)
    {
        on_Select();
        cout << "1. ���ģʽ";
    }
    else if (x == 60 && y == 15)
    {
        on_Select();
        cout << "2. AIģʽ";
    }
}

void Game::print_mainmenu()                                //��ӡ������
{
    green();
    system("cls");
    cout << "����˵����w,a,s,d ���ƹ��ѡ��Enter ȷ�����ո���٣������ߣ����һ��w��a��s��d ����Ҷ���i��j��k��l��" << endl;//����˵��

    gotoxy(hOut, 45, 4);
    cout << "̰���ߴ���ս";
    blue_border();
    gotoxy(hOut, 10, 5);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";        //��ӡ�ϱ߿�
    gotoxy(hOut, 10, 35);
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";        //��ӡ�±߿�
    for (int i = 10, j = 6; j < 35; j++)                                                                //��ӡ��߿�
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    for (int i = 90, j = 6; j < 35; j++)                                                                //��ӡ�ұ߿�
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }

    on_Select();                                                    //��ӡ����ѡ��
    gotoxy(hOut, 25, 10);
    cout << "1. ��ʼ��Ϸ ";
    green();
    gotoxy(hOut, 65, 10);
    cout << "2. ѡ���Ѷ� ";
    gotoxy(hOut, 25, 20);
    cout << "3. �߷ּ�¼ ";
    gotoxy(hOut, 65, 20);
    cout << "4. ѡ��ģʽ ";
    gotoxy(hOut, 25, 30);
    cout << "5. ѡ���ͼ ";
    gotoxy(hOut, 65, 30);
    cout << "6. �˳���Ϸ ";

    x = 25, y = 10;                                                  //��ʼ������
    char sel;
    sel = _getch();
    while (sel != '\r')                                              //�����⵽��������Enter��������ѡ���ѡ�����ѭ��
    {
        star_mainmenu();
        switch (sel)                                                 //wsad���ƹ���������ѡ��
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
        //��ֹ������Χ
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
        gotoxy(hOut, x, y);                                         //������λ��
        onChoose_mainmenu();                                        //���´�ӡ��ѡ��ѡ����
        sel = _getch();
    }
    if (x == 25 && y == 10)                                         //��ʼ��Ϸ
    {
        if (selectmode == 1)                                        //����ģʽ
        {
            white();
            system("cls");                                          //������
            srand((unsigned int)time(0));
            char prekey = NULL;                                    //����ǰһ��������

            w1.Initialwall();                                      //��ʼ��ǽģ��
            w1.Printwall();                                        //��ӡǽ
            s1.InitSnake();                                        //��ʼ����

            white();
            gotoxy(hOut, 0, Wall::row + 1);                        //�����½���ʾ��ǰ�÷��Լ��Ѷȵȼ�
            cout << "�÷֣�" << s1.Getscore() << endl;
            cout << "�Ѷȣ�";
            if (s1.difficulty == 1)
            {
                cout << "��" << endl;
            }
            else if (s1.difficulty == 2)
            {
                cout << "��ͨ" << endl;
            }
            else if (s1.difficulty == 3)
            {
                cout << "����" << endl;
            }
            else if (s1.difficulty == 4)
            {
                cout << "����" << endl;
            }
            f1.Setfood();                                          //����ʳ��
            while (!isDead)                                       //�����û��������һֱѭ��
            {

                char key1 = _getch();                                                                //���ռ�������
                if (prekey == NULL && key1 == s1.LEFT) { continue; }                                 //�ʼ��������
                do
                {
                    if (key1 == s1.UP || key1 == s1.DOWN || key1 == s1.LEFT || key1 == s1.RIGHT)
                    {
                        if ((key1 == s1.LEFT && prekey == s1.RIGHT) ||                              //������������뵱ǰ�����෴������Ч�����ֵ�ǰ���򣬲����¼�������
                            (key1 == s1.RIGHT && prekey == s1.LEFT) ||
                            (key1 == s1.UP && prekey == s1.DOWN) ||
                            (key1 == s1.DOWN && prekey == s1.UP)
                            )
                        {
                            key1 = prekey;
                        }
                        else                                                                         //������¼�������
                        {
                            prekey = key1;
                        }
                        if (s1.Move(key1) == true)                                                  //������ƶ��ɹ�
                        {
                            gotoxy(hOut, 0, Wall::row + 1);
                            white();
                            cout << "�÷�:" << s1.Getscore();                                       //���µ÷�
                            if (GetAsyncKeyState(VK_SPACE))                                        //����Ƿ��¿ո�
                                Sleep(25);                                                         //���������
                            else
                                Sleep(s1.Getsleeptime());                                          //������������ӳ�
                        }
                        else
                        {
                            isDead = true;
                            updatescore();                                                         //������������¸߷ּ�¼��
                            print_endmenu();                                                       //��ӡ��Ϸ��������
                            if (isDead)
                                break;
                        }

                    }
                    else
                    {
                        key1 = prekey;                                                            //����������������߱��ֵ�ǰ����
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
                } while (!_kbhit());                                                             //���û�м�⵽�������룬�򱣳ֵ�ǰ����

            }
            return;
        }

        else if (selectmode == 2)                                                                //˫��ģʽ
        {
            white();
            system("cls");
            srand((unsigned int)time(0));
            char prekey = NULL;                                                                  //���浱ǰ��������
            char prekey_second = NULL;                                                           //����ǰһ��������

            w1.Initialwall();
            w1.Printwall();                                                                      //��ӡǽ
            f1.Setfood();                                                                        //����ʳ��
            s1.InitSnake();                                                                      //��ʼ�����һ
            s2.InitSnake();                                                                      //��ʼ����Ҷ�

            white();
            gotoxy(hOut, 0, Wall::row);
            cout << "���һ�÷֣�" << s1.Getscore();                                             //���½Ǵ�ӡ������ҵĵ÷�
            gotoxy(hOut, 0, Wall::row + 1);
            cout << "��Ҷ��÷֣�" << s2.Getscore();

            while ((!isDead) && (!isDead_second))
            {

                char key = _getch();
                char key1 = key;                                                                 //�������һ���ռ�������
                char key2 = key;                                                                 //������Ҷ����ռ�������
                if (prekey == NULL && key1 == s1.LEFT) { continue; }
                if (prekey_second == NULL && key2 == s2.LEFT) { continue; }
                do
                {

                    if (key1 == s1.UP || key1 == s1.DOWN || key1 == s1.LEFT || key1 == s1.RIGHT)
                    {
                        if ((key1 == s1.LEFT && prekey == s1.RIGHT) ||                           //�����ǰ�������ߵķ�����������Ч
                            (key1 == s1.RIGHT && prekey == s1.LEFT) ||
                            (key1 == s1.UP && prekey == s1.DOWN) ||
                            (key1 == s1.DOWN && prekey == s1.UP)
                            )
                        {
                            key1 = prekey;                                                       //����ǰһ����
                        }
                        else
                        {
                            prekey = key1;                                                       //������·���
                        }
                        if (s1.Move(key1) == true)
                        {
                            gotoxy(hOut, 0, Wall::row);
                            white();
                            cout << "���һ�÷�:" << s1.Getscore();                              //�ƶ��ɹ����������һ�÷�
                            Sleep(75);
                        }
                        else
                        {
                            isDead = true;
                            print_endmenu_2();                                                   //������һ��������Ϸ����
                            if (isDead)
                                break;
                        }

                    }
                    else
                    {
                        key1 = prekey;                                                            //������Ч���������߱��ֵ�ǰ���򲻱�
                    }

                    if (key2 == s2.UP || key2 == s2.DOWN || key2 == s2.LEFT || key2 == s2.RIGHT)
                    {
                        if ((key2 == s2.LEFT && prekey_second == s2.RIGHT) ||                     //�����ǰ�������ߵķ�����������Ч
                            (key2 == s2.RIGHT && prekey_second == s2.LEFT) ||
                            (key2 == s2.UP && prekey_second == s2.DOWN) ||
                            (key2 == s2.DOWN && prekey_second == s2.UP)
                            )
                        {
                            key2 = prekey_second;                                                  //����ǰһ����
                        }
                        else
                        {
                            prekey_second = key2;                                                  //������·���
                        }
                        if (s2.Move(key2) == true)
                        {
                            gotoxy(hOut, 0, Wall::row + 1);
                            white();
                            cout << "��Ҷ��÷�:" << s2.Getscore();                                //�ƶ��ɹ���������Ҷ��÷�
                            Sleep(75);
                        }
                        else
                        {
                            isDead_second = true;
                            print_endmenu_2();                                                     //�����Ҷ���������Ϸ����
                            if (isDead_second)
                                break;
                        }

                    }
                    else
                    {
                        key2 = prekey_second;                                                      //������Ч�����򱣳ֵ�ǰ����
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

                } while (!_kbhit());                                                                //�����ǰû�м������룬�߾ͱ��ֵ�ǰ����ǰ��
            }
            return;
        }
        else if (selectmode == 3)
        {
            white();
            system("cls");
            srand((unsigned int)time(0));
            s3.printInterface();					//��ӡ����
            while (s3.Snake.size() < static_cast<unsigned long long>(Snake_AI::WIDTH) * Snake_AI::HEIGHT) //δռ��ȫ��
            {
                s3.snakeMove();						//�ƶ�һ��
                s3.printSnake();					//��ӡ�µ���
                Sleep(20);							//�����ƶ��ٶ�
                if (GetAsyncKeyState(VK_ESCAPE))    //����ESC����
                    break;

            }
            while (!s3.Snake.empty())
                s3.Snake.pop_back();
            print_mainmenu();
            return;
        }
    }
    else if (x == 65 && y == 10)                                                                        //ѡ���ѶȽ���
    {
        print_selectmenu();
    }
    else if (x == 25 && y == 20)                                                                         //ѡ���¼�߷ֽ���
    {
        print_scoremenu();
    }
    else if (x == 65 && y == 20)                                                                         //ѡ��ģʽ����
    {
        print_modemenu();
    }
    else if (x == 25 && y == 30)                                                                         //ѡ���ͼ����
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
    cout << "ѡ���Ѷ�";
    gotoxy(hOut, 5, 5);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";         //��ӡ�ϱ߿�
    gotoxy(hOut, 5, 25);
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";        //��ӡ�±߿�
    for (int i = 5, j = 6; j < 25; j++)                                                                 //��ӡ��߿�
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    for (int i = 85, j = 6; j < 25; j++)                                                                //��ӡ�ұ߿�
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    green();
    gotoxy(hOut, 65, 10);                                                                               //��ӡ��ͬģʽ
    cout << "2. ��ͨ ";
    gotoxy(hOut, 25, 20);
    cout << "3. ���� ";
    gotoxy(hOut, 65, 20);
    cout << "4. ���� ";
    on_Select();
    gotoxy(hOut, 25, 10);
    cout << "1. �� ";
    //wsad���ƹ��Խ�������ѡ��
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
        //��ֹ������Χ
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
        s1.difficulty = 1;                      //��
    else if (x == 65 && y == 10)
        s1.difficulty = 2;                      //��ͨ
    else if (x == 25 && y == 20)
        s1.difficulty = 3;                      //����
    else if (x == 65 && y == 20)
        s1.difficulty = 4;                      //����
    print_mainmenu();                             //����������

}

void Game::print_mapmenu()
{
    mode_color();
    system("cls");
    gotoxy(hOut, 42, 4);
    cout << "ѡ���ͼ";
    gotoxy(hOut, 5, 5);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";         //��ӡ�ϱ߿�
    gotoxy(hOut, 5, 25);
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";        //��ӡ�±߿�
    for (int i = 5, j = 6; j < 25; j++)                                                                 //��ӡ��߿�
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    for (int i = 85, j = 6; j < 25; j++)                                                                //��ӡ�ұ߿�
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    green();
    gotoxy(hOut, 65, 10);                                                                               //��ӡ��ͬ��ͼ
    cout << "2. ��ͼ2 ";
    gotoxy(hOut, 25, 20);
    cout << "3. ��ͼ3 ";
    gotoxy(hOut, 65, 20);
    cout << "4. ��ͼ4 ";
    on_Select();
    gotoxy(hOut, 25, 10);
    cout << "1. ��ͼ1 ";
    //wsad���ƹ��Խ�������ѡ��
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
        //��ֹ������Χ
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
    print_mainmenu();                             //����������

}

void Game::print_endmenu()
{
    mode_color();
    system("cls");
    gotoxy(hOut, 33, 4);
    cout << "������Ϸ�÷֣�" << s1.Getscore() << "  " << "�Ƿ��ٴν�����Ϸ";
    s1.Resetscore();                                           //�÷�����
    gotoxy(hOut, 5, 5);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";//��ӡ�ϱ߿�
    gotoxy(hOut, 5, 25);
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";//��ӡ�±߿�
    for (int i = 5, j = 6; j < 25; j++)   //��ӡ��߿�
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    for (int i = 85, j = 6; j < 25; j++) //��ӡ�ұ߿�
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    green();
    gotoxy(hOut, 65, 15);
    cout << "2. �� ";
    gotoxy(hOut, 25, 15);
    on_Select();
    cout << "1. �� ";
    //wsad���ƹ��Խ�������ѡ��
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
        //��ֹ������Χ
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
        isDead = false;             //������Ϸ������û�
        print_mainmenu();          //����������

    }
    else if (x == 65 && y == 15)     //�����¿�ʼ��Ϸ����Ϸ����
    {
        exit(-1);
    }
}

void Game::print_endmenu_2()          //˫��ģʽ��������
{
    mode_color();
    system("cls");
    gotoxy(hOut, 43, 4);
    if (s1.Getscore() > s2.Getscore())
        cout << "���һ��ʤ";
    else if (s1.Getscore() < s2.Getscore())
        cout << "��Ҷ���ʤ";
    else if (s1.Getscore() == s2.Getscore())
        cout << "ƽ��";
    s1.Resetscore();                         //�÷�����
    s2.Resetscore();
    gotoxy(hOut, 38, 10);
    cout << "�Ƿ��ٴν�����Ϸ";
    gotoxy(hOut, 5, 5);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";//��ӡ�ϱ߿�
    gotoxy(hOut, 5, 25);
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";//��ӡ�±߿�
    for (int i = 5, j = 6; j < 25; j++) //��ӡ��߿�
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    for (int i = 85, j = 6; j < 25; j++) //��ӡ�ұ߿�
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    green();
    gotoxy(hOut, 65, 15);
    cout << "2. �� ";
    gotoxy(hOut, 25, 15);
    on_Select();
    cout << "1. �� ";
    //wsad���ƹ��Խ�������ѡ��
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
        //��ֹ������Χ
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
        isDead = false;                     // ���������Ϸ�����һ����Ҷ��û�
        isDead_second = false;
        print_mainmenu();                   //����������

    }
    else if (x == 65 && y == 15)
    {
        exit(-1);                            //�����¿�ʼ��Ϸ��������Ϸ
    }
}

void Game::print_scoremenu()
{
    mode_color();
    system("cls");
    gotoxy(hOut, 42, 4);
    cout << "��ʷ�߷�";
    gotoxy(hOut, 5, 5);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";//��ӡ�ϱ߿�
    gotoxy(hOut, 5, 25);
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";//��ӡ�±߿�
    for (int i = 5, j = 6; j < 25; j++) //��ӡ��߿�
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    for (int i = 85, j = 6; j < 25; j++) //��ӡ�ұ߿�
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    fstream outin("score.dat", ios::in | ios::out | ios::binary);//��ȡ�÷ּ�¼
    outin.seekg(0);
    int score[3];                       //�������鱣��÷�ǰ����
    for (int i = 0; i < 3; ++i)
        outin.read(reinterpret_cast<char*>(&score[i]), sizeof(int));
    outin.close();
    gotoxy(hOut, 40, 10);               //��ӡǰ�����÷�
    cout << "��һ����" << score[0];
    gotoxy(hOut, 40, 15);
    cout << "�ڶ�����" << score[1];
    gotoxy(hOut, 40, 20);
    cout << "��������" << score[2];
    char sel;
    sel = _getch();
    while (sel != 27)                   //����ESC��������������
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
    cout << "ѡ��ģʽ";
    gotoxy(hOut, 5, 5);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";//��ӡ�ϱ߿�
    gotoxy(hOut, 5, 25);
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";//��ӡ�±߿�
    for (int i = 5, j = 6; j < 25; j++) //��ӡ��߿�
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    for (int i = 85, j = 6; j < 25; j++) //��ӡ�ұ߿�
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    green();
    gotoxy(hOut, 60, 15);
    cout << "2. ˫��ģʽ ";
    gotoxy(hOut, 20, 15);
    on_Select();
    cout << "1. ����ģʽ ";
    //wsad���ƹ��Խ�������ѡ��
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
        //��ֹ������Χ
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
        selectmode = 1;                     //����ģʽ
        print_modemenu_ai();                //����������
    }
    else if (x == 60 && y == 15)
    {
        selectmode = 2;                     //˫��ģʽ
        print_mainmenu();                   //����������
    }

}

void Game::print_modemenu_ai()
{
    mode_color();
    system("cls");
    gotoxy(hOut, 39, 4);
    cout << "ѡ����һ�AI";
    gotoxy(hOut, 5, 5);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";//��ӡ�ϱ߿�
    gotoxy(hOut, 5, 25);
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";//��ӡ�±߿�
    for (int i = 5, j = 6; j < 25; j++) //��ӡ��߿�
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    for (int i = 85, j = 6; j < 25; j++) //��ӡ�ұ߿�
    {
        gotoxy(hOut, i, j);
        cout << "*";
    }
    green();
    gotoxy(hOut, 60, 15);
    cout << "2. AIģʽ ";
    gotoxy(hOut, 20, 15);
    on_Select();
    cout << "1. ���ģʽ ";
    //wsad���ƹ��Խ�������ѡ��
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
        //��ֹ������Χ
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
        selectmode = 1;                     //���ģʽ
        print_mainmenu();                   //����������
    }
    else if (x == 60 && y == 15)
    {
        selectmode = 3;                     //AIģʽ
        print_mainmenu();                   //����������
    }

}

void Game::updatescore()
{
    fstream outin("score.dat", ios::in | ios::out | ios::binary);     //��ȡ�÷ּ�¼
    outin.seekg(0);
    int score[3];                                                    //�������鱣��ǰ����
    for (int i = 0; i < 3; ++i)
        outin.read(reinterpret_cast<char*>(&score[i]), sizeof(int));
    if (s1.Getscore() < score[2])                                   //������ε÷ֵ��ڵ�������ֱ�ӹر��ļ�
        outin.close();
    else if (s1.Getscore() > score[2] && s1.Getscore() < score[1])  //������ε÷ָ��ڵ����������ڵڶ��������µ������ɼ�
    {
        score[2] = s1.Getscore();
        outin.seekp(0);
        for (int i = 0; i < 3; ++i)
            outin.write(reinterpret_cast<const char*>(&score[i]), sizeof(int));
        outin.close();
    }
    else if (s1.Getscore() >= score[1] && s1.Getscore() < score[0]) //������ε÷ָ��ڵڶ��������ڵ�һ�������µڶ��������ɼ�
    {
        int tem = score[1];
        score[1] = s1.Getscore();
        score[2] = tem;
        outin.seekp(0);
        for (int i = 0; i < 3; ++i)
            outin.write(reinterpret_cast<const char*>(&score[i]), sizeof(int));
        outin.close();
    }
    else if (s1.Getscore() >= score[0])                             //������ε÷ָ��ڵ�һ�������µ�һ�����������ɼ�
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
