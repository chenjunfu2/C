#pragma once

#ifndef _ConsoleAPI
#define _ConsoleAPI

#include <Windows.h>

//�ı���
extern inline void move_g(short x, short y);
//�õ���ǰ�������
extern inline bool get_show(void);//return true������ɼ�
//�������||��ʾ
extern inline void ShowCursor(bool Show);//Show=false�����겻�ɼ�
//����Ƿ����ع��
extern inline void see_cursor_hide_show(bool Show);//false���� true��ʾ

#endif