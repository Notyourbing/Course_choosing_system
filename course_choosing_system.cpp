#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string.h>

using namespace std;
char key[201][5], course[20][20], percourse[200][20][20];//key���ڴ���201�����룬ÿ��������λ��course����20���γ̣�precourse����ÿ��ѧ��ѡ�Ŀγ�
int choose;
int coursenumber;//�����ѿ��ŵĿγ�����
int clas[200] = { 0 };//ÿ��ѧ���İ༶��Ϣ
int num[200] = { 0 };//ѧ��ѡ�ε�����
int number[4][20] = { 0 };//ÿ�ſγ̵�ѡ������������ĸ��༶

void second1(void);//��������˵�
void second2(int num);//ѧ�������˵�
void keysystem(void);//�����֤	
void changekey(int num);
void open(void);//���ſγ�
void reopen(void);//�޸��Ѿ����ŵĿγ�
void check0(void);//�鿴ѡ�����
void check1(int num);//�鿴ѡ�����
void classes(int num);//ѧ��ѡ��

void first(void) {
	system("cls");
	cout << "һ���˵�  ��ҳ" << '\n' << "��ӭʹ�ñ�ϵͳ" << '\n' << "1������" << '\n' << "2��ѧ��" << '\n' << "3���˳�" << '\n' << "��ѡ��";
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
	cout << "�����˵�  ������ҳ" << '\n' << "1���޸Ŀγ�" << '\n' << "2���޸�����" << '\n' << "3���鿴ѡ�����" << '\n' << "4���˳�������һ���˵�" << '\n' << "��ѡ��";
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
	cout << "�����˵�  ������ҳ" << '\n' << "1���޸�ѡ��" << '\n' << "2���޸�����" << '\n' << "3���鿴�ҵ�ѡ�����" << '\n' << "4���˳�������һ���˵�" << '\n' << "��ѡ��";
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
	cout << "�����֤ϵͳ" << '\n' << "��������ţ�";
	int account;
	cin >> account;
	cin.get();
	if ((choose == 1 && account == 0) || (choose == 2 && account > 0))
	{
		cout << "��������λ���룺";
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
			cout << "�������" << '\n' << "���س�������";
			cin.get();
			first();
		}
	}
	else
	{
		cout << "��ݴ���" << '\n' << "���س�������";
		cin.get();
		first();
	}
}

void open(void)
{
	system("cls");
	cout << "�����˵�  ���ſγ�" << '\n' << "��������Ҫ���ŵĿγ�(��������ɣ��밴�س�)" << '\n';
	int flag0 = 1; coursenumber = 0;
	do
	{
		cout << ++coursenumber << "��";
		cin.getline(course[coursenumber - 1], 20);
		if (course[coursenumber - 1][0] == '\0') flag0 = 0;
	} while (flag0 == 1);
	cout << '\n' << "�������" << '\n';
	for (int i = 0; i < coursenumber - 1; i++)
	{
		cout << i + 1 << "��" << course[i] << ' ';
	}
	cout << '\n' << "�Ƿ�ȷ��?  1��ȷ�ϲ�����  2����Ҫ�޸�" << '\n' << "�����룺";
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
	cout << "�����˵�  �޸Ŀγ�" << '\n' << "��ǰ�γ̣�";
	for (int i = 0; i < coursenumber - 1; i++)
	{
		cout << i + 1 << "��" << course[i] << ' ';
	}
	int num;
	cout << '\n' << "ѡ����Ҫ���еĲ����� 1��ɾ���γ�  2���޸�����  3����ӿγ�" << '\n' << "�����룺";
	int n; cin >> n; switch (n)
	{
	case 1:
		cout << '\n' << "������Ҫɾ���Ŀγ̱�ţ�";
		cin >> num;
		for (int i = num - 1; i < coursenumber - 1; i++)
		{
			strcpy(course[i], course[i + 1]);
		}//��ɾ���Ŀγ̿�ʼ���Ӻ���ǰ����ɾ���Ŀγ�
		coursenumber--;
		break;
	case 2:
		cout << '\n' << "������Ҫ�޸ĵĿγ̱�ţ�";
		cin >> num;
		cout << "�޸�Ϊ��";
		char ch[20];
		cin >> ch;
		strcpy(course[num - 1], ch);
		break;
	case 3:cout << "������Ҫ��ӵĿγ�����";
		cin >> course[coursenumber - 1];
		coursenumber++;
		break;
	}
	cout << endl;
	for (int i = 0; i < coursenumber - 1; i++)
	{
		cout << i + 1 << "��" << course[i] << ' ';
	}
	cout << '\n' << "�Ƿ�ȷ��?  1��ȷ�ϲ�����  2����Ҫ�޸�" << '\n' << "�����룺";
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
	cout << "�����˵�  �޸�����" << '\n' << "����ǰ�����룺" << key[account0] << '\n' << "���������룺";
	char ch[20];
	cin >> ch;
	strcpy(key[account0], ch);
	switch (account0)
	{
	case 0:second1(); break;
	default:second2(account0); break;//Ĭ��ѧ���˵�
	}
}

void classes(int account0)
{
	system("cls");
	if (clas[account0] == 0)
	{
		cout << "�����˵�  ѡ��" << '\n' << "�����������ڵİ༶��";
		cin >> clas[account0];
	}
	else
		cout << "�����˵�  ѡ��";
	if (num[account0] > 0)
	{
		cout << '\n' << "����ѡ�γ̣�";
		for (int i = 0; i < num[account0]; i++)
		{
			cout << i + 1 << "��" << percourse[account0][i] << ' ';
		}
	}
	cout << '\n' << "��ǰѡ�ΰ壺";
	memset(number, 0, sizeof(number));
	for (int i = 0; i < coursenumber - 1; i++)
	{
		for (int j = 0; j < 200; j++)
		{
			for (int k = 0; k < num[j + 1]; k++)
			{
				if ((strcmp(course[i], percourse[j + 1][k]) == 0) && clas[j + 1] != 0)
					number[clas[j + 1] - 1][i]++;//��Ӧ�༶��Ӧ�γ���+1
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
				cout << '\n' << "����������";
				for (int j = 0; j < coursenumber - 1; j++)
					cout << "�������ө�������";
				cout << "��������";
				break;
			case 12:
				cout << '\n' << "����������";
				for (int j = 0; j < coursenumber - 1; j++)
					cout << "�������੥������";
				cout << "��������";
				break;
			default:
				cout << '\n' << "�ĩ�������";
				for (int j = 0; j < coursenumber - 1; j++)
					cout << "�������ө�������";
				cout << "��������";
				break;
			}
		}
		else if (i == 1)
		{
			cout << '\n' << "��" << setw(9) << "��";
			for (int j = 0; j < coursenumber - 1; j++)
				cout << setw(6) << course[j] << " ��";//�ڵ�һ������γ�����
		}
		else if (i == 11)
		{
			cout << '\n' << "��" << setw(9) << "��������";//���һ����������
			for (int j = 0; j < coursenumber - 1; j++)
				cout << setw(5) << number[0][j] + number[1][j] + number[2][j] + number[3][j] << "  ��";
		}
		else
		{
			cout << '\n' << "��" << setw(4) << i / 2 << "�� ��";
			for (int j = 0; j < coursenumber - 1; j++)
				cout << setw(5) << number[i / 2 - 1][j] << "  ��";
		}
	}
	if (num[account0] == 0)
	{
		cout << '\n' << "����δѡ�Σ��Ƿ�ѡ�Σ� 1����  2���񣬷���" << '\n' << "��ѡ��";
	}
	else
	{
		cout << '\n' << "�Ƿ��޸�ѡ�Σ� 1����  2���񣬷���" << '\n' << "��ѡ��";
	}
	int n;
	cin >> n;
	switch (n)
	{
	case 1:
		if (num[account0] == 0)
		{
			cout << '\n' << "ѡ����Ҫ���еĲ����� 1����ӿγ�  2������" << '\n' << "�����룺";
		}
		else
		{
			cout << '\n' << "ѡ����Ҫ���еĲ����� 1����ӿγ�  2������  3��ɾ����ѡ�γ�" << '\n' << "�����룺";
		}
		int m, k;
		cin >> m;
		switch (m)
		{
		case 1:
			cout << '\n' << "��ǰ��ѡ�γ̣�";
			for (int i = 0; i < coursenumber - 1; i++)
			{
				int flag0 = 1;
				for (int j = 0; j < num[account0]; j++)
				{
					if (strcmp(percourse[account0][j], course[i]) == 0)//�ж�ѧ���Ƿ�ѡ�������ſ�
						flag0 = 0;
				}
				if (flag0)
					cout << i + 1 << "��" << course[i] << ' ';
			}
			cout << '\n' << "����������ӵĿγ���ţ�";
			cin >> k;
			strcpy(percourse[account0][num[account0]], course[k - 1]);
			num[account0]++;
			break;
		case 2:second2(account0);
			break;
		case 3:
			cout << '\n' << "����ѡ�γ̣�";
			for (int i = 0; i < num[account0]; i++)
			{
				cout << i + 1 << "��" << percourse[account0][i] << ' ';
			}
			cout << '\n' << "��������Ҫɾ���Ŀγ̱�ţ�";
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
		cout << "�����˵�  �鿴ѡ�����" << '\n' << "����δ���ſγ̣����ȿ��ſγ̣�";
		cin.get();
		second1();
	}
	else
	{
		cout << "�����˵�  �鿴ѡ�����" << '\n' << "��Ҫ��ѯ�Ķ��� 1���γ�  2��ѧ��  3��ѡ�ΰ�  4������" << '\n' << "��ѡ��";
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
			cout << '\n' << "�ѿ��ŵĿγ̣�" << '\n';
			for (int i = 0; i < coursenumber - 1; i++)
			{
				cout << i + 1 << "��" << course[i] << ' ';
			}
			cout << '\n' << "������Ҫ��ѯ�Ŀγ���ţ�";
			int m;
			cin >> m;
			memset(number, 0, sizeof(number));
			for (int i = 0; i < coursenumber - 1; i++)//�����γ�
			{
				for (int j = 0; j < 200; j++)//����ѧ��
				{
					for (int k = 0; k < num[j + 1]; k++)
					{
						if ((strcmp(course[i], percourse[j + 1][k]) == 0) && (clas[j + 1] != 0))
							number[clas[j + 1] - 1][i]++;
					}
				}
			}
			cout << '\n' << "ѡ�ÿε�ͬѧ���� " << number[0][m - 1] + number[1][m - 1] + number[2][m - 1] + number[3][m - 1] << " ��";
			cout << '\n' << "������ѯ�� 1����  2���񣬷���" << '\n' << "��ѡ��";
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
			cout << '\n' << "������Ҫ��ѯ��ѧ����ţ�";
			int account0;
			cin >> account0;
			cout << '\n' << "��ͬѧ��ѡ�γ��У�";
			for (int i = 0; i < num[account0]; i++)
			{
				cout << i + 1 << "��" << percourse[account0][i] << ' ';
			}
			cout << '\n' << "������ѯ�� 1����  2���񣬷���" << '\n' << "��ѡ��";
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
						cout << '\n' << "����������"; for (int j = 0; j < coursenumber - 1; j++)cout << "�������ө�������"; cout << "��������";
						break;
					case 12:
						cout << '\n' << "����������"; for (int j = 0; j < coursenumber - 1; j++)cout << "�������۩�������"; cout << "��������";
						break;
					default:
						cout << '\n' << "�ĩ�������"; for (int j = 0; j < coursenumber - 1; j++)cout << "�������੥������"; cout << "��������";
						break;
					}
				}
				else if (i == 1)
				{
					cout << '\n' << "��" << setw(9) << "��";
					for (int j = 0; j < coursenumber - 1; j++)
						cout << setw(6) << course[j] << " ��";
				}
				else if (i == 11)
				{
					cout << '\n' << "��" << setw(9) << "��������";
					for (int j = 0; j < coursenumber - 1; j++)
						cout << setw(5) << number[0][j] + number[1][j] + number[2][j] + number[3][j] << "  ��";
				}
				else
				{
					cout << '\n' << "��" << setw(4) << i / 2 << "�� ��";
					for (int j = 0; j < coursenumber - 1; j++)cout << setw(5) << number[i / 2 - 1][j] << "  ��";
				}
			}
			cout << '\n' << "������ѯ�� 1����  2���񣬷���" << '\n' << "��ѡ��";
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
		cout << "�����˵�  �ҵ�ѡ�����" << '\n' << "��δѡ�κογ�";
	else
	{
		cout << "�����˵�  �ҵ�ѡ�����" << '\n' << "��ѡ�γ̣�";
		for (int i = 0; i < num[account0]; i++)
		{
			cout << i + 1 << "��" << percourse[account0][i] << ' '; cout << endl;
		}
	}
	cout << '\n' << "���س�������";
	cin.get();
	second2(account0);
}

int main()
{
	cout << "ʹ����֪��" << '\n' << "������ţ�����Ϊ0��ѧ��Ϊ1-200��" << '\n' << "�������룺����Ϊ��λ����ʼ�����Ϊ0000��" << '\n' << "��ܰ��ʾ����¼���������޸�����" << '\n' << "(���س�����ʼʹ��)";
	for (int i = 0; i < 201; i++)
	{
		strcpy(key[i], "0000");
	}
	cin.get();
	first();
	cout << "��л����ʹ�ã�";
	return 0;
}