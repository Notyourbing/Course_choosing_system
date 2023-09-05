#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string.h>

using namespace std;
char key[201][5], course[20][20], percourse[200][20][20];//key用于储存201个密码，每个密码四位；course储存20个课程；precourse储存每个学生选的课程
int choose;
int coursenumber;//跟踪已开放的课程数量
int clas[200] = { 0 };//每个学生的班级信息
int num[200] = { 0 };//学生选课的数量
int number[4][20] = { 0 };//每门课程的选课人数，最多四个班级

void second1(void);//教务二级菜单
void second2(int num);//学生二级菜单
void keysystem(void);//身份验证	
void changekey(int num);
void open(void);//开放课程
void reopen(void);//修改已经开放的课程
void check0(void);//查看选课情况
void check1(int num);//查看选课情况
void classes(int num);//学生选课

void first(void) {
	system("cls");
	cout << "一级菜单  首页" << '\n' << "欢迎使用本系统" << '\n' << "1、教务" << '\n' << "2、学生" << '\n' << "3、退出" << '\n' << "您选择：";
	cin >> choose;
	switch (choose)
	{
	case 1: keysystem(); break;
	case 2: keysystem(); break;
	case 3: system("cls"); break;
	}
}

void second1(void)
{
	system("cls");
	cout << "二级菜单  个人主页" << '\n' << "1、修改课程" << '\n' << "2、修改密码" << '\n' << "3、查看选课情况" << '\n' << "4、退出并返回一级菜单" << '\n' << "您选择：";
	int choose0; cin >> choose0; cin.get();
	switch (choose0)
	{
	case 1:if (course[0][0] == '\0') open(); else reopen(); break;
	case 2:changekey(0); break;
	case 3:check0(); break;
	case 4:first(); break;
	}
}

void second2(int num) {
	system("cls");
	cout << "二级菜单  个人主页" << '\n' << "1、修改选课" << '\n' << "2、修改密码" << '\n' << "3、查看我的选课情况" << '\n' << "4、退出并返回一级菜单" << '\n' << "您选择：";
	int choose1; cin >> choose1;
	switch (choose1) {
	case 1:classes(num); break;
	case 2:changekey(num); break;
	case 3:check1(num); break;
	case 4:first(); break;
	}
}

void keysystem(void)
{
	system("cls");
	cout << "身份验证系统" << '\n' << "请输入序号：";
	int account;
	cin >> account;
	cin.get();
	if ((choose == 1 && account == 0) || (choose == 2 && account > 0))
	{
		cout << "请输入四位密码：";
		char key0[5];
		cin.getline(key0, 5);
		int flag0 = 1;
		for (int i = 0; i < 5; i++)
		{
			if (key[account][i] != key0[i]) flag0 = 0;
		}
		if (flag0 == 1)
		{
			if (account == 0) second1();
			else second2(account);
		}
		else
		{
			cout << "密码错误！" << '\n' << "按回车键返回";
			cin.get();
			first();
		}
	}
	else
	{
		cout << "身份错误！" << '\n' << "按回车键返回";
		cin.get();
		first();
	}
}

void open(void)
{
	system("cls");
	cout << "三级菜单  开放课程" << '\n' << "请输入您要开放的课程(若输入完成，请按回车)" << '\n';
	int flag0 = 1; coursenumber = 0;
	do
	{
		cout << ++coursenumber << "、";
		cin.getline(course[coursenumber - 1], 20);
		if (course[coursenumber - 1][0] == '\0') flag0 = 0;
	} while (flag0 == 1);
	cout << '\n' << "输入完成" << '\n';
	for (int i = 0; i < coursenumber - 1; i++)
	{
		cout << i + 1 << "、" << course[i] << ' ';
	}
	cout << '\n' << "是否确认?  1、确认并返回  2、我要修改" << '\n' << "请输入：";
	int n; cin >> n;
	switch (n)
	{
	case 1:second1(); break;
	case 2:reopen(); break;
	}
}

void reopen(void)
{
	system("cls");
	cout << "三级菜单  修改课程" << '\n' << "当前课程：";
	for (int i = 0; i < coursenumber - 1; i++)
	{
		cout << i + 1 << "、" << course[i] << ' ';
	}
	int num;
	cout << '\n' << "选择您要进行的操作： 1、删除课程  2、修改名称  3、添加课程" << '\n' << "请输入：";
	int n; cin >> n; switch (n)
	{
	case 1:
		cout << '\n' << "输入您要删除的课程编号：";
		cin >> num;
		for (int i = num - 1; i < coursenumber - 1; i++)
		{
			strcpy(course[i], course[i + 1]);
		}//从删除的课程开始，从后向前覆盖删除的课程
		coursenumber--;
		break;
	case 2:
		cout << '\n' << "输入您要修改的课程编号：";
		cin >> num;
		cout << "修改为：";
		char ch[20];
		cin >> ch;
		strcpy(course[num - 1], ch);
		break;
	case 3:cout << "输入您要添加的课程名：";
		cin >> course[coursenumber - 1];
		coursenumber++;
		break;
	}
	cout << endl;
	for (int i = 0; i < coursenumber - 1; i++)
	{
		cout << i + 1 << "、" << course[i] << ' ';
	}
	cout << '\n' << "是否确认?  1、确认并返回  2、我要修改" << '\n' << "请输入：";
	cin >> n;
	switch (n)
	{
	case 1:second1(); break;
	case 2:reopen(); break;
	}
}

void changekey(int account0)
{
	system("cls");
	cout << "三级菜单  修改密码" << '\n' << "您当前的密码：" << key[account0] << '\n' << "输入新密码：";
	char ch[20];
	cin >> ch;
	strcpy(key[account0], ch);
	switch (account0)
	{
	case 0:second1(); break;
	default:second2(account0); break;//默认学生菜单
	}
}

void classes(int account0)
{
	system("cls");
	if (clas[account0] == 0)
	{
		cout << "三级菜单  选课" << '\n' << "请输入您所在的班级：";
		cin >> clas[account0];
	}
	else
		cout << "三级菜单  选课";
	if (num[account0] > 0)
	{
		cout << '\n' << "您已选课程：";
		for (int i = 0; i < num[account0]; i++)
		{
			cout << i + 1 << "、" << percourse[account0][i] << ' ';
		}
	}
	cout << '\n' << "当前选课板：";
	memset(number, 0, sizeof(number));
	for (int i = 0; i < coursenumber - 1; i++)
	{
		for (int j = 0; j < 200; j++)
		{
			for (int k = 0; k < num[j + 1]; k++)
			{
				if ((strcmp(course[i], percourse[j + 1][k]) == 0) && clas[j + 1] != 0)
					number[clas[j + 1] - 1][i]++;//对应班级对应课程数+1
			}
		}
	}
	for (int i = 0; i < 13; i++)
	{
		if (i % 2 == 0)
		{
			switch (i)
			{
			case 0:
				cout << '\n' << "┍━━━━";
				for (int j = 0; j < coursenumber - 1; j++)
					cout << "━━━┯━━━━";
				cout << "━━━┓";
				break;
			case 12:
				cout << '\n' << "┕━━━━";
				for (int j = 0; j < coursenumber - 1; j++)
					cout << "━━━┼━━━━";
				cout << "━━━┛";
				break;
			default:
				cout << '\n' << "┠━━━━";
				for (int j = 0; j < coursenumber - 1; j++)
					cout << "━━━┯━━━━";
				cout << "━━━┨";
				break;
			}
		}
		else if (i == 1)
		{
			cout << '\n' << "┃" << setw(9) << "┃";
			for (int j = 0; j < coursenumber - 1; j++)
				cout << setw(6) << course[j] << " ┃";//在第一行输入课程名称
		}
		else if (i == 11)
		{
			cout << '\n' << "┃" << setw(9) << "总人数┃";//最后一行是总人数
			for (int j = 0; j < coursenumber - 1; j++)
				cout << setw(5) << number[0][j] + number[1][j] + number[2][j] + number[3][j] << "  ┃";
		}
		else
		{
			cout << '\n' << "┃" << setw(4) << i / 2 << "班 ┃";
			for (int j = 0; j < coursenumber - 1; j++)
				cout << setw(5) << number[i / 2 - 1][j] << "  ┃";
		}
	}
	if (num[account0] == 0)
	{
		cout << '\n' << "您尚未选课，是否选课？ 1、是  2、否，返回" << '\n' << "您选择：";
	}
	else
	{
		cout << '\n' << "是否修改选课？ 1、是  2、否，返回" << '\n' << "您选择：";
	}
	int n;
	cin >> n;
	switch (n)
	{
	case 1:
		if (num[account0] == 0)
		{
			cout << '\n' << "选择您要进行的操作： 1、添加课程  2、返回" << '\n' << "请输入：";
		}
		else
		{
			cout << '\n' << "选择您要进行的操作： 1、添加课程  2、返回  3、删除已选课程" << '\n' << "请输入：";
		}
		int m, k;
		cin >> m;
		switch (m)
		{
		case 1:
			cout << '\n' << "当前可选课程：";
			for (int i = 0; i < coursenumber - 1; i++)
			{
				int flag0 = 1;
				for (int j = 0; j < num[account0]; j++)
				{
					if (strcmp(percourse[account0][j], course[i]) == 0)//判断学生是否选择了这门课
						flag0 = 0;
				}
				if (flag0)
					cout << i + 1 << "、" << course[i] << ' ';
			}
			cout << '\n' << "输入您想添加的课程序号：";
			cin >> k;
			strcpy(percourse[account0][num[account0]], course[k - 1]);
			num[account0]++;
			break;
		case 2:second2(account0);
			break;
		case 3:
			cout << '\n' << "您已选课程：";
			for (int i = 0; i < num[account0]; i++)
			{
				cout << i + 1 << "、" << percourse[account0][i] << ' ';
			}
			cout << '\n' << "输入您想要删除的课程编号：";
			cin >> k;
			for (int i = k - 1; i < num[account0] - 1; i++)
			{
				strcpy(percourse[account0][i], percourse[account0][i + 1]);
			}
			num[account0]--;
			break;
		}
		classes(account0);
		break;
	case 2:second2(account0);
		break;
	}
}

void check0(void)
{
	system("cls");
	if (coursenumber == 1)
	{
		cout << "三级菜单  查看选课情况" << '\n' << "您尚未开放课程！请先开放课程！";
		cin.get();
		second1();
	}
	else
	{
		cout << "三级菜单  查看选课情况" << '\n' << "您要查询的对象： 1、课程  2、学生  3、选课板  4、返回" << '\n' << "您选择：";
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
			cout << '\n' << "已开放的课程：" << '\n';
			for (int i = 0; i < coursenumber - 1; i++)
			{
				cout << i + 1 << "、" << course[i] << ' ';
			}
			cout << '\n' << "输入您要查询的课程序号：";
			int m;
			cin >> m;
			memset(number, 0, sizeof(number));
			for (int i = 0; i < coursenumber - 1; i++)//遍历课程
			{
				for (int j = 0; j < 200; j++)//遍历学生
				{
					for (int k = 0; k < num[j + 1]; k++)
					{
						if ((strcmp(course[i], percourse[j + 1][k]) == 0) && (clas[j + 1] != 0))
							number[clas[j + 1] - 1][i]++;
					}
				}
			}
			cout << '\n' << "选该课的同学共有 " << number[0][m - 1] + number[1][m - 1] + number[2][m - 1] + number[3][m - 1] << " 人";
			cout << '\n' << "继续查询？ 1、是  2、否，返回" << '\n' << "您选择：";
			int p;
			cin >> p;
			switch (p)
			{
			case 1:check0();
				break;
			case 2:second1();
				break;
			}
			break;
		case 2:
			cout << '\n' << "输入您要查询的学生序号：";
			int account0;
			cin >> account0;
			cout << '\n' << "该同学已选课程有：";
			for (int i = 0; i < num[account0]; i++)
			{
				cout << i + 1 << "、" << percourse[account0][i] << ' ';
			}
			cout << '\n' << "继续查询？ 1、是  2、否，返回" << '\n' << "您选择：";
			int q;
			cin >> q;
			switch (q)
			{
			case 1:check0(); break;
			case 2:second1(); break;
			}
			break;
		case 3:
			memset(number, 0, sizeof(number));
			for (int i = 0; i < coursenumber - 1; i++)
			{
				for (int j = 0; j < 200; j++)
				{
					for (int k = 0; k < num[j + 1]; k++)
					{
						if ((strcmp(course[i], percourse[j + 1][k]) == 0) && clas[j + 1] != 0)
							number[clas[j + 1] - 1][i]++;
					}
				}
			}
			for (int i = 0; i < 13; i++)
			{
				if (i % 2 == 0)
				{
					switch (i)
					{
					case 0:
						cout << '\n' << "┍━━━━"; for (int j = 0; j < coursenumber - 1; j++)cout << "━━━┯━━━━"; cout << "━━━┓";
						break;
					case 12:
						cout << '\n' << "┕━━━━"; for (int j = 0; j < coursenumber - 1; j++)cout << "━━━┷━━━━"; cout << "━━━┛";
						break;
					default:
						cout << '\n' << "┠━━━━"; for (int j = 0; j < coursenumber - 1; j++)cout << "━━━┼━━━━"; cout << "━━━┨";
						break;
					}
				}
				else if (i == 1)
				{
					cout << '\n' << "┃" << setw(9) << "┃";
					for (int j = 0; j < coursenumber - 1; j++)
						cout << setw(6) << course[j] << " ┃";
				}
				else if (i == 11)
				{
					cout << '\n' << "┃" << setw(9) << "总人数┃";
					for (int j = 0; j < coursenumber - 1; j++)
						cout << setw(5) << number[0][j] + number[1][j] + number[2][j] + number[3][j] << "  ┃";
				}
				else
				{
					cout << '\n' << "┃" << setw(4) << i / 2 << "班 ┃";
					for (int j = 0; j < coursenumber - 1; j++)cout << setw(5) << number[i / 2 - 1][j] << "  ┃";
				}
			}
			cout << '\n' << "继续查询？ 1、是  2、否，返回" << '\n' << "您选择：";
			int x;
			cin >> x;
			switch (x)
			{
			case 1:check0();
				break;
			case 2:second1();
				break;
			}
		case 4:second1();
			break;
		}
	}

}

void check1(int account0)
{
	system("cls");
	cin.get();
	if (num[account0] == 0)
		cout << "三级菜单  我的选课情况" << '\n' << "您未选任何课程";
	else
	{
		cout << "三级菜单  我的选课情况" << '\n' << "已选课程：";
		for (int i = 0; i < num[account0]; i++)
		{
			cout << i + 1 << "、" << percourse[account0][i] << ' '; cout << endl;
		}
	}
	cout << '\n' << "按回车键返回";
	cin.get();
	second2(account0);
}

int main()
{
	cout << "使用须知：" << '\n' << "关于序号：教务为0，学生为1-200。" << '\n' << "关于密码：密码为四位，初始密码均为0000。" << '\n' << "温馨提示：登录后请立即修改密码" << '\n' << "(按回车键开始使用)";
	for (int i = 0; i < 201; i++)
	{
		strcpy(key[i], "0000");
	}
	cin.get();
	first();
	cout << "感谢您的使用！";
	return 0;
}