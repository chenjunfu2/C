#include "ConsoleAPI.h"

//�ı���
extern inline void move_g(short x, short y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ x,y });//ͬ��������̨(Set����)��Console����̨����Cursor��꣩ ��Positionλ�ã�
}

//�õ���ǰ�������
extern inline bool get_show(void)//return true������ɼ�
{
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//STD_OUTPUT_HANDLE  STD_INPUT_HANDLE
	return cursor_info.bVisible;
}

//�������||��ʾ
extern inline void ShowCursor(bool Show)//Show=false�����겻�ɼ�
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, Show };//x,y  x�������������
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//STD_OUTPUT_HANDLE  STD_INPUT_HANDLE
}

//����Ƿ����ع��
extern inline void see_cursor_hide_show(bool Show)//false���� true��ʾ
{
	if (get_show() != Show)//�����Ϊ��������̨���¹��������ʾ����������Ϊ����ʾ
		ShowCursor(Show);
}