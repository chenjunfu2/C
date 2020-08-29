#pragma once

#ifndef MAKE_MAP
#define MAKE_MAP

#define MAX_MAP 4
#define MAP_X 15
#define MAP_Y 15

#include <fstream>
#include <iostream>
#include "error.h"
using namespace std;

//地图表现形式	0：空地"  "		1：墙壁■		2：人♀		3：箱子□		4：目的地☆○		5：箱子在目的地★●		6：人在目的地♀
//示范地图
int map[MAX_MAP][MAP_X][MAP_Y] = {
{
	{0,0,0,1,1,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,4,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,0,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,3,1,1,1,1,1,0,0,0,0,0},
	{1,1,1,1,0,0,3,0,4,1,0,0,0,0,0},
	{1,4,0,3,0,2,1,1,1,1,0,0,0,0,0},
	{1,1,1,1,1,3,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,0,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,4,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
},
{
	{0,0,0,0,0,1,1,1,1,1,1,0,0,0,0},
	{0,1,1,1,1,1,4,0,0,0,1,0,0,0,0},
	{0,1,0,0,1,4,4,1,1,0,1,0,0,0,0},
	{0,1,0,0,3,4,4,0,0,0,1,0,0,0,0},
	{0,1,0,0,1,0,4,1,0,1,1,0,0,0,0},
	{1,1,1,0,1,1,3,1,0,0,1,0,0,0,0},
	{1,0,3,0,0,0,0,3,3,0,1,0,0,0,0},
	{1,0,1,3,1,0,0,1,0,0,1,0,0,0,0},
	{1,2,0,0,1,1,1,1,1,1,1,0,0,0,0},
	{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
},
{
	{0,0,0,0,0,0,0,0,1,1,1,1,1,0,0},
	{0,0,0,0,0,0,0,0,1,0,0,0,1,0,0},
	{1,1,1,1,1,1,1,1,1,0,1,0,1,0,0},
	{1,0,3,0,3,0,3,0,3,0,0,0,1,0,0},
	{1,0,1,4,1,4,1,4,1,0,3,1,1,0,0},
	{1,4,4,4,4,4,4,4,0,2,0,1,0,0,0},
	{1,0,1,0,1,0,1,0,1,3,1,1,1,0,0},
	{1,0,3,0,3,0,3,0,3,0,0,0,1,0,0},
	{1,1,1,1,1,1,1,1,1,0,1,0,1,0,0},
	{0,0,0,0,0,0,0,0,1,0,0,0,1,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,1,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
},
{
	{0,0,0,0,0,0,1,1,1,1,1,1,1,0,0},
	{0,0,0,0,0,1,1,0,0,0,0,0,1,1,0},
	{0,0,0,0,1,1,0,0,3,1,1,0,0,1,0},
	{0,0,0,0,1,0,0,1,0,0,0,3,0,1,0},
	{0,0,0,0,1,0,1,0,0,1,0,1,0,1,0},
	{0,0,0,0,1,0,3,0,3,0,0,3,0,1,0},
	{1,1,1,1,1,1,1,0,1,3,1,0,0,1,0},
	{1,0,0,3,0,3,0,0,0,0,0,0,1,1,0},
	{1,0,4,4,2,3,5,5,4,1,1,1,1,0,0},
	{1,1,4,4,4,4,4,4,1,1,1,0,0,0,0},
	{0,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
}
};
//示范地图对应地图符号
char map_f[MAX_MAP][7][3] = { { "  ","■","♀","□","○","●","♀" },{ "  ","■","♂","□","☆","★","♂" },{ "  ","■","♀","□","○","●","♀" },{ "  ","■","♂","□","☆","★","♂" } };





static inline bool open_map(fstream& fout_b)
{
	fout_b.open("game.ini", ios_base::out | ios_base::trunc | ios_base::binary);
	if (!fout_b.is_open())
	{
		fout_b.close();
		fout_b.clear();
		return false;
	}
	return true;
}

static inline void close_map_fout(fstream& fout_b)
{
	fout_b.clear();
	fout_b.close();
}
	
static inline bool description(fstream& fout_b)
{
	fout_b << "地图表现型:" << "0:空地 1:墙壁 2:人 3:箱子 4:目的地 5:箱子在目的地 6:人在目的地" << endl;
	fout_b << "注意事项:" << "请严格按照模板进行修改，否则会导致不必要的麻烦！  "
			<<"1.关卡号不可断续，必须按照顺序从1开始，接着2、3、4...以此类推  "
			<<"2.每一关卡的对应地图符号可以不一样，只有每一个数字冒号后面的两个字符可以修改  "
			<<"3.每一关卡地图大小可以不一样，当地图大小修改后，下面的地图标记请根据大小对齐，每一列数字之间请使用空格分开，每一行数字之间只可使用一个换行符  "
			<<"4.多个关卡请每一个关卡使用两个换行符隔开  "
			<<"5.请不要增加无意义的空行  "
			<<"6.地图内有且只能有一个\"人\"(地图表现型2)  "
			<<"7.如果再次需要模板请移走或删除当前文件夹下的地图文件并再次运行此应用" << endl << endl;

	if (!fout_b.good())
		return false;
	return true;
}
	
static inline bool checkpoint(fstream& fout_b)
{
	for (int k = 0, l = 0; k < MAX_MAP; ++k, l = 0)
	{
		//3
		fout_b << "关卡:" << k + 1 << endl;

		//4
		fout_b << "对应地图符号:";
		for (auto mp : map_f[k])
			fout_b << l++ << ":" << mp;

		//5
		fout_b << endl << "地图大小:" << MAP_X << "*" << MAP_Y << endl;

		//6
		fout_b << "地图标记:" << endl;
		for (int i = 0; i < MAP_X; ++i)
		{
			for (int j = 0; j < MAP_Y; ++j)
			{
				fout_b << map[k][i][j] << " ";
			}
			fout_b << endl;
		}
		fout_b << endl;
	}
	if (!fout_b.good())
		return false;
	return true;
}
	


inline ERR make_map(void)
{
	fstream fout_b;
	ERR error;

	if (!open_map(fout_b))
	{
		no_good(error, open_failed);
		return error;
	}
	if (!description(fout_b))
	{
		no_good(error, description_WriteFalse);
		return error;
	}
	if (!checkpoint(fout_b))
	{
		no_good(error, checkpoint_WriteFalse);
		return error;
	}
	close_map_fout(fout_b);

	return error;
}


#endif