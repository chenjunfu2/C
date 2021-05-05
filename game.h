#pragma once

#ifndef _Game
#define _Game
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include "linked_list.h"
#include "error.h"
using namespace std;

#define REDO		0//����
#define MOVE		1//�ƶ�
#define REVOKE		2//����
#define NODO		3//�ػ�

#define REGAME		4//����
#define LASTCHECK	5//��һ��
#define NEXTCHECK	6//��һ��
#define QUIT		7//�˳�
#define END			8//����


//�������ṹ��
typedef struct peo {
	int x = 0;
	int y = 0;
	ERR error;
}PEO;

//��ȡ�������
template <typename T>
static inline PEO find_peo(const T map, int mx, int my)
{
	PEO peo;
	int pen = 0;
	for (int i = 0; i < my; ++i)
	{
		for (int j = 0; j < mx; ++j)
		{
			if (map[i][j] == 2 || map[i][j] == 6)
			{
				peo.x = j;
				peo.y = i;
				++pen;
			}
		}
	}

	if (pen == 0)
		no_good(peo.error, map_PeopleNull, find_peo_F);
	else if (pen > 1)
		no_good(peo.error, map_PeopleOverFlow, find_peo_F);
	//pen == 1
	return peo;
}

//�ƶ���
template <typename T>
static inline void move_p(const peo& pe, T map)
{
	if (map[pe.y][pe.x] == 6)
		map[pe.y][pe.x] = 4;
	else
		map[pe.y][pe.x] = 0;

	return;
}

//ȫ���ƶ����û�������
template <typename T>
static inline bool move_user(T map, int mx, int my, int x, int y, peo& pe, NODE& nodeR, NODE& nodeF)//move_a
{
	bool mov = false;
	if (nodeF.hpQueue != NULL)
		Del_AllQueue(nodeF);

	if (pe.x + x < 0 || pe.x + x >= mx || pe.y + y < 0 || pe.y + y >= my)//Խ���ж�
		return mov;
	{
		if (map[pe.y + y][pe.x + x] == 0)//��ǰ���ǿյ�
		{
			map[pe.y + y][pe.x + x] = 2;
			move_p(pe, map);
			mov = true;//�ƶ����
			Add_CpQueue(nodeR, x, y, 0);
		}
		else if (map[pe.y + y][pe.x + x] == 4)//��ǰ����Ŀ�ĵ�
		{
			map[pe.y + y][pe.x + x] = 6;
			move_p(pe, map);
			mov = true;//�ƶ����
			Add_CpQueue(nodeR, x, y, 1);
		}
	}
	if (mov == true)
	{
		pe.x += x;
		pe.y += y;
		return mov;
	}


	if (pe.x + (x * 2) < 0 || pe.x + (x * 2) >= mx || pe.y + (y * 2) < 0 || pe.y + (y * 2) >= my)//Խ���ж�
		return mov;
	{
		if (map[pe.y + y][pe.x + x] == 3)//��ǰ��������
		{
			if (map[pe.y + (y * 2)][pe.x + (x * 2)] == 0)//����ǰ���ǿյ�
			{
				map[pe.y + (y * 2)][pe.x + (x * 2)] = 3;
				map[pe.y + y][pe.x + x] = 2;
				move_p(pe, map);
				mov = true;//�ƶ����
				Add_CpQueue(nodeR, x, y, 2);
			}
			else if (map[pe.y + (y * 2)][pe.x + (x * 2)] == 4)//����ǰ����Ŀ�ĵ�
			{
				map[pe.y + (y * 2)][pe.x + (x * 2)] = 5;
				map[pe.y + y][pe.x + x] = 2;
				move_p(pe, map);
				mov = true;//�ƶ����
				Add_CpQueue(nodeR, x, y, 3);
			}
		}
		else if (map[pe.y + y][pe.x + x] == 5)//�˵�ǰ��������
		{
			if (map[pe.y + (y * 2)][pe.x + (x * 2)] == 0)//������Ŀ�ĵ�
			{
				map[pe.y + (y * 2)][pe.x + (x * 2)] = 3;
				map[pe.y + y][pe.x + x] = 6;
				move_p(pe, map);
				mov = true;//�ƶ����
				Add_CpQueue(nodeR, x, y, 4);
			}
			else if (map[pe.y + (y * 2)][pe.x + (x * 2)] == 4)//������Ŀ�ĵص�ǰ����Ŀ�ĵ�
			{
				map[pe.y + (y * 2)][pe.x + (x * 2)] = 5;
				map[pe.y + y][pe.x + x] = 6;
				move_p(pe, map);
				mov = true;//�ƶ����
				Add_CpQueue(nodeR, x, y, 5);
			}
		}
	}
	if (mov == true)
	{
		pe.x += x;
		pe.y += y;
		return mov;
	}
	
	return mov;
}

//ȫ���ƶ���������
template <typename T>
static inline bool move_f(T map, int mx, int my, peo& pe, NODE& nodeR, NODE& nodeF)
{
	int list_x, list_y, list_n;
	if (See_CpQueue(nodeF, list_x, list_y, list_n).no_good)
		return false;
	Move_CpQueue_To_CpQueue(nodeR, nodeF);

	switch (list_n)
	{
	case 0:
		map[pe.y + list_y][pe.x + list_x] = 2;
		move_p(pe, map);
		break;
	case 1:
		map[pe.y + list_y][pe.x + list_x] = 6;
		move_p(pe, map);
		break;
	case 2:
		map[pe.y + (list_y * 2)][pe.x + (list_x * 2)] = 3;
		map[pe.y + list_y][pe.x + list_x] = 2;
		move_p(pe, map);
		break;
	case 3:
		map[pe.y + (list_y * 2)][pe.x + (list_x * 2)] = 5;
		map[pe.y + list_y][pe.x + list_x] = 2;
		move_p(pe, map);
		break;
	case 4:
		map[pe.y + (list_y * 2)][pe.x + (list_x * 2)] = 3;
		map[pe.y + list_y][pe.x + list_x] = 6;
		move_p(pe, map);
		break;
	case 5:
		map[pe.y + (list_y * 2)][pe.x + (list_x * 2)] = 5;
		map[pe.y + list_y][pe.x + list_x] = 6;
		move_p(pe, map);
		break;
	default:
		return false;
		break;
	}

	pe.x += list_x;
	pe.y += list_y;
	return true;
}

//ǰ�����ҷ�ת
static inline void reverse_num(int& list_x, int& list_y)
{
	list_x = -list_x;
	list_y = -list_y;
}

//�����ƶ���
template <typename T>
static inline void reverse_move_p(const peo& pe, T map, int list_x, int list_y)
{
	if (map[pe.y + list_y][pe.x + list_x] == 4)
		map[pe.y + list_y][pe.x + list_x] = 6;
	else
		map[pe.y + list_y][pe.x + list_x] = 2;
}

//����ȫ���ƶ���������
template <typename T>
static inline bool move_r(T map, int mx, int my, peo& pe, NODE& nodeR, NODE& nodeF)//reserve_move_a
{
	int list_x, list_y, list_n;
	if (See_CpQueue(nodeR, list_x, list_y, list_n).no_good)
		return false;
	Move_CpQueue_To_CpQueue(nodeF, nodeR);


	reverse_num(list_x, list_y);

	switch (list_n)
	{
	case 0:
	case 1:
		if (map[pe.y + list_y][pe.x + list_x] == 0)
		{
			move_p(pe, map);
			map[pe.y + list_y][pe.x + list_x] = 2;
		}
		else if (map[pe.y + list_y][pe.x + list_x] == 4)
		{
			move_p(pe, map);
			map[pe.y + list_y][pe.x + list_x] = 6;
		}
		break;
	case 2:
		reverse_move_p(pe, map, list_x, list_y);
		map[pe.y - list_y][pe.x - list_x] = 0;
		map[pe.y][pe.x] = 3;
		break;
	case 3:
		reverse_move_p(pe, map, list_x, list_y);
		map[pe.y - list_y][pe.x - list_x] = 4;
		map[pe.y][pe.x] = 3;
		break;
	case 4:
		reverse_move_p(pe, map, list_x, list_y);
		map[pe.y - list_y][pe.x - list_x] = 0;
		map[pe.y][pe.x] = 5;
		break;
	case 5:
		reverse_move_p(pe, map, list_x, list_y);
		map[pe.y - list_y][pe.x - list_x] = 4;
		map[pe.y][pe.x] = 5;
		break;
	default:
		return false;
		break;
	}

	pe.x += list_x;
	pe.y += list_y;
	return true;





	/*

	if (list_n == 1 || list_n == 2)//��ǰ�治������
	{
		if (map[pe.y + list_y][pe.x + list_x] == 0)//��ǰ���ǿյ�
		{
			move_p(pe, map);
			map[pe.y + list_y][pe.x + list_x] = 2;
		}
		else if (map[pe.y + list_y][pe.x + list_x] == 4)//��ǰ����Ŀ�ĵ�
		{
			move_p(pe, map);
			map[pe.y + list_y][pe.x + list_x] = 6;
		}
	}
	else if (list_n == 3 || list_n == 4)//��ǰ��������
	{
		if (list_n == 3)//����ǰ���ǿյ�
		{
			reverse_move_p(pe, map, list_x, list_y);
			map[pe.y - list_y][pe.x - list_x] = 0;
			map[pe.y][pe.x] = 3;
		}
		else if (list_n == 4)//����ǰ����Ŀ�ĵ�
		{
			reverse_move_p(pe, map, list_x, list_y);
			map[pe.y - list_y][pe.x - list_x] = 4;
			map[pe.y][pe.x] = 3;
		}
	}
	else if (list_n == 5 || list_n == 6)//�˵�ǰ��������
	{
		if (list_n == 5)//������Ŀ�ĵ�
		{
			reverse_move_p(pe, map, list_x, list_y);
			map[pe.y - list_y][pe.x - list_x] = 0;
			map[pe.y][pe.x] = 5;
		}
		else if (list_n == 6)//������Ŀ�ĵص�ǰ����Ŀ�ĵ�
		{
			reverse_move_p(pe, map, list_x, list_y);
			map[pe.y - list_y][pe.x - list_x] = 4;
			map[pe.y][pe.x] = 5;
		}
	}

	*/
}




//�ı���
inline void move_g(short x, short y)
{
	//HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//�ҵ�����̨����
	//COORD coord = { x,y };//���Ľṹ����������
	//SetConsoleCursorPosition(handle, coord);//ͬ��������̨(Set����)��Console����̨����Cursor��꣩ ��Positionλ�ã�
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ x,y });//ͬ��������̨(Set����)��Console����̨����Cursor��꣩ ��Positionλ�ã�
}

//�õ���ǰ�������
inline bool get_show(void)//return true������ɼ�
{
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//STD_OUTPUT_HANDLE  STD_INPUT_HANDLE
	return cursor_info.bVisible;
}

//�������||��ʾ
//inline void HideCursor(DWORD x, bool y)//y=0�����겻�ɼ�
inline void ShowCursor(bool Show)//Show=false�����겻�ɼ�
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, Show };//x,y  x�������������
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//STD_OUTPUT_HANDLE  STD_INPUT_HANDLE
}




//�����˸�������
template <typename T, typename D>
static inline ERR init_peo(const T map, int mx, int my, const D map_f, const peo& pe)//, const NODE& nodeR, const NODE& nodeF
{
	ERR error;
	//COORD OldCur = get_g();
	//int list_xR, list_yR, list_nR;
	//int list_xF, list_yF, list_nF;

	//if ((Find_CpQueue(nodeR, list_xR, list_yR, list_nR).no_good)&&(Find_CpQueue(nodeF, list_xF, list_yF, list_nF).no_good))
		//return error;


	//����
	for (int i = pe.y - 2, j = pe.x; i < pe.y + 3; ++i)
	{
		if (i < 0 || i >= my) continue;
		if (map[i][j] >= 0 && map[i][j] <= 6)
		{
			move_g(j * 2, i);
			cout << map_f[map[i][j]];
			//cout << map[i][j];
		}
		else
		{
			system("cls");
			no_good(error, map_Default, init_peo_F);
			return error;
		}
	}

	//�ử
	for (int i = pe.y, j = pe.x - 2; j < pe.x + 3; ++j)
	{
		if (j < 0 || j >= mx) continue;
		if (map[i][j] >= 0 && map[i][j] <= 6)
		{
			move_g(j * 2, i);
			cout << map_f[map[i][j]];
			//cout << map[i][j];
		}
		else
		{
			system("cls");
			no_good(error, map_Default, init_peo_F);
			return error;
		}
	}

	//move_g(OldCur.X, OldCur.Y);
	move_g(0, my);
	return error;
}


//���Ƶ�ͼ
template <typename T , typename D>
static inline ERR init_map(const T map, int mx, int my, const D map_f)
{
	ERR error;

	move_g(0, 0);//����
	for (int i = 0; i < my; ++i)
	{
		for (int j = 0; j < mx; ++j)
		{
			if (map[i][j] >= 0 && map[i][j] <= 6)
			cout << map_f[map[i][j]];
			//cout << map[i][j];
			else
			{
				system("cls");
				no_good(error, map_Default, init_map_F);
				return error;
			}
		}
		cout << endl;
	}
	return error;
}

//��ȡ�������룬��������Ϸ
template <typename T>
static inline int get_keyb(T map, int mx, int my, peo& pe, NODE& nodeR, NODE& nodeF)
{
	//int ch, mov;
	int mov = NODO;

	start1:
	//{
		//ch = tolower(_getch());
		//if (ch != 'w' && ch != 'a' && ch != 's' && ch != 'd' && ch != 'q' && ch != 'r')
			//ch = _getch();
	//}
	
	switch (_getch())
	{
	case 72://up
	case 'w':
	case 'W':
		if ((mov = move_user(map, mx, my, 0, -1, pe, nodeR, nodeF)) == false)goto start1;
		break;
	case 75://left
	case 'a':
	case 'A':
		if ((mov = move_user(map, mx, my, -1, 0, pe, nodeR, nodeF)) == false)goto start1;
		break;
	case 77://right
	case 'd':
	case 'D':
		if ((mov = move_user(map, mx, my, +1, 0, pe, nodeR, nodeF)) == false)goto start1;
		break;
	case 80://down
	case 's':
	case 'S':
		if ((mov = move_user(map, mx, my, 0, +1, pe, nodeR, nodeF)) == false)goto start1;
		break;
	case 'r'://revoke
	case 'R':
		mov = REVOKE;
		if (!move_r(map, mx, my, pe, nodeR, nodeF))
			goto start1;
		break;
	case 'f'://redo
	case 'F':
		mov = REDO;
		if (!move_f(map, mx, my, pe, nodeR, nodeF))
			goto start1;
		break;
	case 'e'://regame
	case 'E':
		ShowCursor(true);
		if (sure("����"))
		{
			mov = REGAME;
			Del_AllQueue(nodeR);
			Del_AllQueue(nodeF);
		}
		else
			mov = NODO;
		ShowCursor(false);
		break;
	case 'z'://last checkpoint
	case 'Z':
		ShowCursor(true);
		if (sure("��һ��"))
		{
			mov = LASTCHECK;
			Del_AllQueue(nodeR);
			Del_AllQueue(nodeF);
		}
		else
			mov = NODO;
		ShowCursor(false);
		break;
	case 'x'://next checkpoint
	case 'X':
		ShowCursor(true);
		if (sure("��һ��"))
		{
			mov = NEXTCHECK;
			Del_AllQueue(nodeR);
			Del_AllQueue(nodeF);
		}
		else
			mov = NODO;
		ShowCursor(false);
		break;
	case 'q'://quit
	case 'Q':
		ShowCursor(true);
		if (sure("�˳�"))
		{
			mov = QUIT;
			Del_AllQueue(nodeR);
			Del_AllQueue(nodeF);
		}
		else
			mov = NODO;
		ShowCursor(false);
		break;
	default:
		goto start1;
		break;
	}

	return mov;
}

//�Ƿ�Ӯ
template <typename T>
static inline bool win_g(const T map,int mx,int my)
{
	for (int i = 0; i < my; ++i)
	{
		for (int j = 0; j < mx; ++j)
		{
			if (map[i][j] == 3)
			{
				return false;
			}
		}
	}
	return true;
}


//����Ƿ����ع��
inline void see_cursor_hide_show(bool Show)//false���� true��ʾ
{
	if (get_show() != Show)//�����Ϊ��������̨���¹��������ʾ����������Ϊ����ʾ
		ShowCursor(Show);
}


//������Ϸ
template <typename T, typename D>
inline int game(T map, int mx, int my, D map_f)
{
	peo pe = find_peo(map, mx, my);
	if (error(pe.error))
		return false;
	int num = 0, keyb = 0;
	NODE nodeR, nodeF;

	if (error(init_map(map, mx, my, map_f)))//����ȫ��ͼ
		return 0;
	cout << "��" << num << "��" << "  ";
	
	while (true)
	{
		if (win_g(map, mx, my))//win game�ж�
		{
			cout << endl << "You Win!";
			Del_AllQueue(nodeR);
			Del_AllQueue(nodeF);
			break;
		}

	con1:
		switch (keyb = get_keyb(map, mx, my, pe, nodeR, nodeF))//�õ��������벢������Ϸ
		{
		case REDO:
		case MOVE:
			++num;//������ƶ���������������
			break;
		case REVOKE:
			--num;//������������ݼ�
			break;
		case NODO:
			system("cls");
			init_map(map, mx, my, map_f);//������������ػ�ȫ����ͼ
			cout << "��" << num << "��" << "  ";
			goto con1;
			break;
		default:
			return keyb - 4;//4567->0123
			break;
		}

		see_cursor_hide_show(false);

		if (error(init_peo(map, mx, my, map_f, pe)))//���Ƹ��º�ĵ�ͼ
		{
			Del_AllQueue(nodeR);
			Del_AllQueue(nodeF);
			return 0;
		}
		cout << "��" << num << "��" << "  ";
	}

	return END - 4;//8->4
}


#endif