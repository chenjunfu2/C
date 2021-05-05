#pragma once

#ifndef _Menu
#define _Menu
#include <iostream>
#include <conio.h>
#define Cooder			"С��"
#define VersionNumber	"2.1"
#define CoodingDay		"2021/05/05"
#define CopyRightYear	"2021"
using namespace std;


//���˵�
inline int menu_page(void)
{
	cout << "------------Ŀ¼-----------\n";
	cout << " 1.��ʼ��Ϸ\t2.��Ϸ˵��\n";
	cout << " 3.����Ӧ��\t4.�˳�Ӧ��\n";
	cout << "---------------------------\n";
	cout << "\n�밴�¶�Ӧ����ѡ��\n";
	int input = _getch();
	while (input < '1' || input > '4')
		input = _getch();

	return input;
}

//��ʼ��Ϸ
inline int menu_game(void)
{
	cout << "------------��Ϸ-----------\n";
	cout << " 1.˳��ģʽ\t2.ѡ��ģʽ\n";
	cout << " 3.�����ϲ�\t4.�˳�Ӧ��\n";
	cout << "---------------------------\n";
	cout << "\n�밴�¶�Ӧ����ѡ��\n";
	int input = _getch();
	while (input < '1' || input > '4')
		input = _getch();

	return input;
}

//��Ϸ˵��
inline void menu_explain(void)
{
	cout << "��Ϸ˵����\n\n";
	cout << "1.��ʹ��:\n"\
			"  W (��) A (��) S (��) D (��) ��\n"\
			"  ��(��) ��(��) ��(��) ��(��) �ٿ�����\n";
	cout << "2.����Ϸʱ:\n"\
			"  ��Q�����˳���Ϸ��������һ����\n"\
			"  ��R��������һ����\n"\
			"  ��F����������һ����\n"\
			"  ��E�������浱ǰ�ؿ�\n"\
			"  ��Z����ת����һ�ؿ�\n"\
			"  ��X����ת����һ�ؿ�\n";
	cout << "3.�������ִ�Сд����Ҫע�������Ҫʹ��Ӣ�����뷨�����򰴼��ᱻ���뷨����ץ�ߵ����޷���ʱ����\n";
	cout << "4.��Ϸ��ͼ�ڵ�һ�δ�ʱ�����ɣ���Ҫ������Ϸ\n";
	cout << "5.��Ϸ��ͼ�ɱ༭������ɾ�������ϸ����ص�ͼע��������ݵ�ͼ�����Ͷ�Ӧ�޸�\n\n";
	cout << "��л���������֧�֣�����BUG���뼰ʱ����Ŷ~\n";
	cout << "\n�����������...\n";
	_getch();

	return;
}

//����Ӧ��
inline void menu_about(void)
{
	cout << "--------------����-------------\n";
	cout << " �� д �ߣ�" << Cooder << "\n";
	cout << " ��д���ڣ�" << CoodingDay << "\n";
	cout << " �� �� �ţ�" << VersionNumber << "\n";
	cout << " ��Ȩ���У�CopyRight (C) " << CopyRightYear << "\n";
	cout << "-------------------------------\n";
	cout << "\n�����������...\n";
	_getch();

	return;
}

inline void sypose(void)
{
	cout << "�밴���������. . .";
	_getch();
}

inline bool sure(const char* be)
{
	cout << "\nȷ��Ҫ" << be << "��(y/n)\n";

	int input;
	while ((input = tolower(getchar())) != 'y' && input != 'n')
	{
		if (input != '\n')
			while (getchar() != '\n')continue;
	}
	if (input != '\n')
		while (getchar() != '\n')continue;

	if (input == 'y')
		return true;
	else
		return false;
}


#endif