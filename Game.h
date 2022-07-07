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
	Game();											 //���캯��
	void star_mainmenu();                                    //��ʼ��������

	void star_selectmenu();                                  //��ʼ��ѡ���ѶȽ���

	void star_endmenu();                                     //��ʼ����������

	void star_modemenu();                                    //��ʼ��ģʽ����

	void star_modemenu_ai();                                 //��ʼ��ģʽ����һ�AI������

	void star_mapmenu();                                     //��ʼ����ͼѡ�����

	void onChoose_mainmenu();                    //ȷ����ѡ�е�λ�ã������棩	���ƶ���Ŀ��λ�ã�����ɫ��죬����ǰѡ��λ�ã�

	void onChoose_selectmenu();                 //ȷ����ѡ�е�λ�ã��Ѷ�ѡ����棩

	void onChoose_mapmenu();					//ȷ����ѡ�е�λ�ã���ͼѡ����棩

	void onChoose_endmenu();                    //ȷ����ѡ�е�λ��(��Ϸ�������棩

	void onChoose_modemenu();                   //ȷ����ѡ�е�λ�ã�ģʽѡ����棩

	void onChoose_modemenu_ai();               //ȷ����ѡ�е�λ�ã���һ�AI��

	void print_mainmenu();                      //��ӡ������

	void print_selectmenu();                    //��ӡ�Ѷ�ѡ�����

	void print_mapmenu();                      //��ӡ��ͼѡ�����

	void print_modemenu_ai();                   //��ӡģʽ����һ�AI������

	void print_modemenu();                      //��ӡģʽ����

	void print_scoremenu();                     //��ӡ�÷ֽ���

	void print_endmenu();                       //��ӡ����ģʽ��Ϸ��������

	void print_endmenu_2();                     //��ӡ˫��ģʽ��Ϸ��������

	void updatescore();										//���µ÷ּ�¼

private:
	int x, y;											//���λ�ã�x��y��

	bool isDead;										//�ж����һ�����Ƿ�����

	bool isDead_second;									//�ж���Ҷ������Ƿ�����

	int selectmode;										//ѡ��˫��ģʽ��1������ģʽ��2����˫��ģʽ��

};
#endif // !INITIAL_MENU_H
