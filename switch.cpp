#include "switch.h"

using namespace std;

int game_switch(map_j& mpj, fstream& fin_a)
{
ctu_s:
	int game_switch = '4';
	switch (menu_page())
	{
	case '1':
	game_i:
		system("cls");
		see_cursor_hide_show(false);
		game_switch = menu_game();
		break;
	case '2':
		system("cls");
		see_cursor_hide_show(false);
		menu_explain();
		break;
	case '3':
		system("cls");
		see_cursor_hide_show(false);
		menu_about();
		break;
	case '4':
		system("cls");
		see_cursor_hide_show(false);
		//goto end;
		return 0;
		break;
	default:
		system("cls");
		cerr << "menu_page error!\n";
		sypose();
		//goto end;
		return -1;
		break;
	}


	switch (game_switch)
	{
	case '1'://����ģʽ
		system("cls");
		see_cursor_hide_show(false);
		{
			int mpn = 1;

			map_a mpa = read_mapCp(mpj, fin_a, mpn);
			while (!error(mpa.error))
			{
				system("cls");
				cout << "��" << mpa.checkpoint << "��";
				Sleep(1100);


				switch (game(mpa))
				{
				case ERROR:
					delete_map(mpa);
					goto br1;
					break;
				case LASTCHECK - 5:
					system("cls");
					delete_map(mpa);
					if (mpn > 1)
						mpa = read_mapCp(mpj, fin_a, --mpn);
					else
					{
						cout << "�Ѿ��ǵ�һ�أ�" << endl << endl;
						sypose();
						mpa = read_mapCp(mpj, fin_a, mpn);
					}
					break;
				case NEXTCHECK - 5:
					system("cls");
					delete_map(mpa);
					if (mpn < mpj.map_num)
						mpa = read_mapCp(mpj, fin_a, ++mpn);
					else
					{
						cout << "�Ѿ������һ�أ�" << endl << endl;
						sypose();
						mpa = read_mapCp(mpj, fin_a, mpn);
					}
					break;
				case SWITCH - 5:
					system("cls");
					delete_map(mpa);
					ShowCursor(true);//��ʾ���
					mpn = map_jump_menu(mpj);
					ShowCursor(false);//���ع��
					if (mpn == -1) goto game_i;
					mpa = read_mapCp(mpj, fin_a, mpn);
					break;
				case SAVE - 5:
					Make_MLD(mpa, false);
					delete_map(mpa);
					cout << endl << endl << "�оֱ���ɹ���" << endl;
					sypose();

					goto game_i;
					break;
				case QUIT - 5:
					delete_map(mpa);
					goto game_i;
					break;
				case END - 5:
					Make_MLD(mpa, true);
					delete_map(mpa);
					cout << endl << endl << "�طű���ɹ���" << endl;
					sypose();
					system("cls");

					if (mpn == mpj.map_num)
					{
						cout << "����ͨ�����һ�أ���Ϸ������" << endl;
						sypose();
						goto game_i;
					}
					else
						mpa = read_mapCp(mpj, fin_a, ++mpn);
					break;
				default:
					delete_map(mpa);
					goto br1;
					break;
				}
			}
		br1:
			cout << "��Ϸ������" << endl << endl << flush;//���в�ˢ�»�����
		}
		break;
		
	case '2'://�о�ģʽ
		system("cls");
		{
			bool p;
			string str;

			ShowCursor(true);//��ʾ���
			{
				cout << "�������ļ�����";
				getline(cin, str, '\n');
			}
			ShowCursor(false);//���ع��

			map_a mpa = Read_MLD(str.c_str(), p);
			if (p)
			{
				cout << "���ǲо��ļ���" << endl;
				delete_map(mpa);
				sypose();
				goto game_i;
			}

			switch (game(mpa) - 3)
			{
			case SAVE - 5 - 3:
				Make_MLD(mpa, false);
				delete_map(mpa);
				cout << endl << endl << "�оֱ���ɹ���" << endl;
				sypose();
				goto game_i;
				break;
			case QUIT - 5 - 3:
				delete_map(mpa);
				goto game_i;
				break;
			case END - 5 - 3:
				Make_MLD(mpa, true);
				delete_map(mpa);
				cout << endl << endl << "�طű���ɹ���" << endl;
				sypose();
				break;
			default:
				delete_map(mpa);
				goto br2;
				break;
			}
			goto game_i;
		br2:
			cout << "��Ϸ������" << endl << endl << flush;//���в�ˢ�»�����
		}
		break;
	case '3'://�ط�ģʽ
		system("cls");
		{
			bool p;
			int iptn;
			string str;

			ShowCursor(true);//��ʾ���
			{
				cout << "�������ļ�����";
				getline(cin, str, '\n');

				cout << "��������������";
				while (!(cin >> iptn))
				{
					cout << "����������" << endl;
					cin.clear();
				}
				while (getchar() != '\n') continue;
			}
			ShowCursor(false);//���ع��

			map_a mpa = Read_MLD(str.c_str(), p);
			if (!p)
			{
				ShowCursor(true);
				if (!sure("���Ųо��ļ�"))
					break;
				ShowCursor(false);
			}
			game_p(mpa, iptn, p);
			delete_map(mpa);

			sypose();
			system("cls");
			see_cursor_hide_show(false);
			goto game_i;
		}
		break;
	case '4'://�����ϲ�
		system("cls");
		see_cursor_hide_show(false);
		goto ctu_s;
		break;
	default:
		system("cls");
		cerr << "menu_game error!\n";
		sypose();
		//goto end;
		return -1;
		break;
	}

	return 0;
}