#pragma once

#ifndef _Menu
#define _Menu
#include <iostream>
#include <conio.h>
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
	cout << "��Ϸ˵����\n";
	cout << "��ʹ�� w(��) a(��) s(��) d(��) �� ��(��) ��(��) ��(��) ��(��) �ٿ�����\n";
	cout << "����Ϸʱ��q�����˳���Ϸ��������һ���棬��r��������һ����\n";
	cout << "��Ϸ��ͼ�ڵ�һ�δ�ʱ�����ɣ���Ҫ������Ϸ\n";
	cout << "��Ϸ��ͼ�ɱ༭������ɾ�������ϸ����ص�ͼע��������ݵ�ͼ�����Ͷ�Ӧ�޸�\n";
	cout << "��л���������֧�֣�����BUG���뼰ʱ����Ŷ\n";
	cout << "\n�����������...\n";
	_getch();

	return;
}

//����Ӧ��
inline void menu_about(void)
{
	cout << "--------------����-------------\n";
	cout << " �� д �ߣ�С ��\n";
	cout << " ��д���ڣ�2020/8/28\n";
	cout << " ��Ȩ���У�CopyRight (C) 2020\n";
	cout << "-------------------------------\n";
	cout << "\n�����������...\n";
	_getch();

	return;
}


#endif