#pragma once

#ifndef _ERROR
#define _ERROR
#include <stdio.h>

//ERROR_NUM_ALL		0 ~ 10
#define GOOD_ERR				0
#define delete_failed			1
#define new_failed				2
#define open_failed				3
#define fst_eof					4
#define map_PeopleNull			5
#define map_PeopleOverFlow		6

//read_map		11 ~ 20
#define line_JumpFalse			11
#define map_JumpFalse			12
#define list_ReadFalse			13
#define checkpoint_ReadFalse	14
#define checkpoint_ERROR		15
#define sizeX_ReadFalse			16
#define sizeY_ReadFalse			17
#define mapX_NewFalse			18
#define mapY_NewFalse			19
#define map_ReadFalse			20

//linked_list	21 ~ -30
#define cpQueue_Null			21
#define hpQueue_Null			22
#define cpQueue_Have			23
#define hpQueue_Have			24

//make_map		31 ~ 40
#define description_WriteFalse	31
#define checkpoint_WriteFalse	32

//game			41 ~ 50
#define map_Default				41

//save_map+list	51 ~ 60
#define lctime_Small			51

//FUNTION		101 ~ 150	(0x0065 ~ 0x007B)
#define init_map_F				0x0065
#define init_peo_F				0x0066
#define find_peo_F				0x0067

#define Add_CpQueue_F			0x0068
#define Del_CpQueue_F			0x0069
#define Del_AllQueue_F			0x006A
#define Find_CpQueue_F			0x006B
#define See_All_F				0x006C
#define Add_All_F				0x006D
#define Move_CpQ_To_CpQ_F		0x006E
								
#define make_map_F				0x006F
								
#define open_map_F				0x0070
#define delete_map_F			0x0071
#define jump_map_F				0x0072
#define jump_line_F				0x0073
#define next_map_F				0x0074
#define read_checkpoint_F		0x0075
#define read_symbol_F			0x0076
#define read_size_F				0x0077
#define new_map_F				0x0078
#define read_map_F				0x0079
#define read_map_all_F			0x007A
#define read_mapCp_F			0x007B
								
#define Get_Time_F				0x007C

const char* reason[60] =
{
	//0
	"û�д�������ì�ܣ�",

	//1 ~ 10
	"�ڴ��ͷ�ʧ��",
	"�ڴ����ʧ��",
	"�ļ���ʧ��",
	"���������ļ�β",
	"��ͼ�в�������",
	"��ͼ����������",
	"",
	"",
	"",
	"",

	//11 ~ 20
	"������ʧ��",
	"��ͼ��תʧ��",
	"�ؿ��Ŷ�ȡʧ��",
	"�ؿ��ų�����Χ",
	"��ͼ���Ŷ�ȡ����",
	"��ͼX��С��ȡ����",
	"��ͼY��С��ȡ����",
	"��ͼX�ڴ�������",
	"��ͼY�ڴ�������",
	"��ͼ��ȡ����",
	
	//21 ~ 30
	"����βָ��Ϊ��",
	"����ͷָ��Ϊ��",
	"����βָ�뺬������",
	"����ͷָ�뺬������",
	"",
	"",
	"",
	"",
	"",
	"",

	//31 ~ 40
	"��ͼ˵��д�����",
	"�ؿ�д�����",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",

	//41 ~ 50
	"��ͼ��Ǵ���"
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",

	//51 ~ 60
	"ʱ���ַ����ֶι�С��",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
};

typedef struct err {
	bool no_good = false;
	int err_num = GOOD_ERR;
	unsigned err_HEX = 0x0000;
}ERR;


//����
inline void no_good(ERR& error, int error_num, unsigned err_HEX)
{
	error.no_good = true;
	error.err_num = error_num;
	error.err_HEX = err_HEX;
}
//��������
inline void are_good(ERR& error)
{
	error.no_good = false;
	error.err_num = GOOD_ERR;
	error.err_HEX = 0x0000;
}

//������
inline bool error(ERR error)
{
	if (error.no_good == false)
		return false;
	if (error.err_num == GOOD_ERR)
		return false;

	fprintf(stderr, "\nERROR:\n");
	fprintf(stderr, "code=0x%04X reason=%s\n\n", error.err_HEX, reason[error.err_num]);

	return error.no_good;
}


#endif