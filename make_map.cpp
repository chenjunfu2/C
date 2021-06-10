#include "make_map.h"

using namespace std;

extern inline bool open_map_m(fstream& fout_a)
{
	fout_a.open("game.ini", ios_base::out | ios_base::trunc);
	if (!fout_a.is_open())
	{
		fout_a.close();
		fout_a.clear();
		return false;
	}
	return true;
}

extern inline void close_map_fout(fstream& fout_a)
{
	fout_a.clear();
	fout_a.close();
}

extern inline bool description(fstream& fout_a)
{
	fout_a << "��ͼ������:" << "0:�յ� 1:ǽ�� 2:�� 3:���� 4:Ŀ�ĵ� 5:������Ŀ�ĵ� 6:����Ŀ�ĵ�" << endl;
	fout_a << "ע������:" << "���ϸ���ģ������޸ģ�����ᵼ�²���Ҫ���鷳��  "
		<< "1.�ؿ��Ų��ɶ��������밴��˳���1��ʼ������2��3��4...�Դ����ƣ���������һ���ؿ�  "
		<< "2.ÿһ�ؿ��Ķ�Ӧ��ͼ���ſ��Բ�һ����ֻ��ÿһ������ð�ź���������ֽڿ����޸�  "
		<< "3.ÿһ�ؿ���ͼ��С���Բ�һ��������ͼ��С�޸ĺ�����ĵ�ͼ�������ݴ�С���룬ÿһ������֮����ʹ�ÿո�ֿ���ÿһ������֮��ֻ��ʹ��һ�����з�  "
		<< "4.����ؿ���ÿһ���ؿ�ʹ���������з�����  "
		<< "5.�벻Ҫ����������Ŀ���  "
		<< "6.��ͼ������ֻ����һ��\"��\"(��ͼ������2)  "
		<< "7.����ٴ���Ҫģ�������߻�ɾ����ǰ�ļ����µĵ�ͼ�ļ����ٴ����д�Ӧ�á�" << endl << endl;

	if (!fout_a.good())
		return false;
	return true;
}

extern inline bool checkpoint(fstream& fout_a)
{
	for (int k = 0, l = 0; k < MAX_MAP; ++k, l = 0)
	{
		//3
		fout_a << "�ؿ�:" << k + 1 << endl;

		//4
		fout_a << "��Ӧ��ͼ����:";
		for (auto mp : map_f[k])
			fout_a << l++ << ":" << mp;

		//5
		fout_a << endl << "��ͼ��С:" << MAP_X << "*" << MAP_Y << endl;

		//6
		fout_a << "��ͼ���:" << endl;
		for (int i = 0; i < MAP_Y; ++i)
		{
			for (int j = 0; j < MAP_X; ++j)
			{
				fout_a << map[k][i][j] << " ";
			}
			fout_a << endl;
		}
		fout_a << endl;
	}
	if (!fout_a.good())
		return false;
	return true;
}



extern inline ERR make_map(void)
{
	fstream fout_a;
	ERR error;

	if (!open_map_m(fout_a))
	{
		no_good(error, open_failed, make_map_F);
		return error;
	}
	if (!description(fout_a))
	{
		no_good(error, description_WriteFalse, make_map_F);
		return error;
	}
	if (!checkpoint(fout_a))
	{
		no_good(error, checkpoint_WriteFalse, make_map_F);
		return error;
	}
	close_map_fout(fout_a);

	return error;
}