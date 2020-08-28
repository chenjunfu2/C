#pragma once

#ifndef _ERROR
#define _ERROR
#include <iostream>
using namespace std;

//ERROR_NUM_ALL
#define GOOD_ERR				0
#define delete_failed			-120
#define new_failed				-119
#define open_failed				-118
#define fst_eof					-117
#define map_PeopleNull			-116

//read_map
#define line_JumpFalse			-10
#define map_JumpFalse			-9
#define list_ReadFalse			-8
#define checkpoint_ReadFalse	-7
#define checkpoint_ERROR		-6
#define sizeX_ReadFalse			-5
#define sizeY_ReadFalse			-4
#define mapX_NewFalse			-3
#define mapY_NewFalse			-2
#define map_ReadFalse			-1


//linked_list
#define cpQueue_Null			-20

//make_map
#define description_WriteFalse	-19
#define checkpoint_WriteFalse	-18

//game
#define map_Default				-17



typedef struct err {
	bool no_good = false;
	int err_num = 0;
}ERR;


//����
static inline void no_good(ERR& error, int error_num)
{
	error.no_good = true;
	error.err_num = error_num;
}
//��������
static inline void are_good(ERR& error)
{
	error.no_good = false;
	error.err_num = GOOD_ERR;
}


bool error(ERR error)
{

	if (error.no_good == false && error.err_num == GOOD_ERR)
	{
		//cerr << "û�д��������ì��";
		return error.no_good;
	}

	cerr << "error:";

	switch (error.err_num)
	{
	case GOOD_ERR:
		break;
	case delete_failed:
		cerr << "�ڴ��ͷ�ʧ�ܣ�" << endl << endl;
		break;
	case new_failed:
		cerr << "�ڴ����ʧ�ܣ�" << endl << endl;
		break;
	case open_failed:
		cerr << "�ļ���ʧ�ܣ�" << endl << endl;
		break;
	case fst_eof:
		cerr << "���������ļ�β��" << endl << endl;
		break;
	case line_JumpFalse:
		cerr << "������ʧ�ܣ�" << endl << endl;
		break;
	case map_JumpFalse:
		cerr << "��ͼ��תʧ�ܣ�" << endl << endl;
		break;
	case checkpoint_ReadFalse:
		cerr << "�ؿ��Ŷ�ȡʧ�ܣ�" << endl << endl;
		break;
	case checkpoint_ERROR:
		cerr << "�ؿ��ų�����Χ��" << endl << endl;
		break;
	case list_ReadFalse:
		cerr << "��ͼ���Ŷ�ȡ����" << endl << endl;
		break;
	case sizeX_ReadFalse:
		cerr << "��ͼX��С��ȡ����" << endl << endl;
		break;
	case sizeY_ReadFalse:
		cerr << "��ͼX��С��ȡ����" << endl << endl;
		break;
	case mapX_NewFalse:
		cerr << "��ͼX�ڴ�������" << endl << endl;
		break;
	case mapY_NewFalse:
		cerr << "��ͼY�ڴ�������" << endl << endl;
		break;
	case map_ReadFalse:
		cerr << "��ͼ��ȡ����" << endl << endl;
		break;
	case map_PeopleNull:
		cerr << "��ͼ�в������ˣ�" << endl << endl;
		break;
	case cpQueue_Null:
		cerr << "����βָ��Ϊ�գ�" << endl << endl;
		break;
	case description_WriteFalse:
		cerr << "��ͼ˵��д�����" << endl << endl;
		break;
	case checkpoint_WriteFalse:
		cerr << "�ؿ�д�����" << endl << endl;
		break;
	case map_Default:
		cerr << "��ͼ��Ǵ���" << endl << endl;
		break;
	default:
		cerr << "δ֪����";
		break;
	}

	return error.no_good;
}


#endif