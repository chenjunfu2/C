#pragma once

#ifndef _menu
#define _menu

#include <iostream>
#include <string>
#include <conio.h>

#define Cooder			"С��"
#define VersionNumber	"3.4"
//#define CoodingDay		"2021/05/05"
#define CopyRightYear	"2021"

//���˵�
extern inline int menu_page(void);
//��ʼ��Ϸ
extern inline int menu_game(void);
//��Ϸ˵��
extern inline void menu_explain(void);
//����Ӧ��
extern inline void menu_about(void);



//�ȴ��û���һ������
extern inline void sypose(void);
//���û�ȷ���Ƿ���ĳ��
extern inline bool sure(const char* be);

#endif