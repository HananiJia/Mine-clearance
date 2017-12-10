#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void welcome()//��ʼ�� ��ӭ����
{
	printf("                                 \n");
	printf("        ��ӭ����ɨ����Ϸ         \n");
	printf("      ���԰� * �汾�� 1.1.0      \n");
	printf("      �����ˣ�  Edision Niu      \n");
	printf("*******��Ϸ������BUG�뷴��*******\n");
	printf("                                 \n");
	printf("��Ϸ�Ѽ�����ϣ��밴���������......\n");
	getchar();
	system("cls");//����
}

void menu()//���˵�
{
	printf("********************************\n");
	printf("** 0.�˳���Ϸ **** 1.��ʼ��Ϸ **\n");
	printf("********************************\n");
}
void game()
{
	char Mineboard[ROWS][COLS] = { 0 };//��������׵�����
	char Showboard[ROWS][COLS] = { 0 };//����չʾ����ҵ�
	printf("��Ϸ��ʼ��\n");
	InitBoard(Mineboard, ROWS,COLS,'0');
	InitBoard(Showboard, ROWS, COLS, '*');
	SetMine(Mineboard, ROW, COL, EASY_COUNT);//���õ���
	ClearMine(Mineboard, Showboard, ROW, COL);//ɨ��
}

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)//�����ʼ��
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void PrintBoard(char board[ROWS][COLS], int row, int col)//��ӡ����
{
	int i = 0;
	int j = 0;
	printf("  1   2   3   4   5   6   7   8   9  \n");
	printf("-------------------------------------\n");
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			printf("| %c ", board[i][j]);
		}
		printf("| %d\n",i);
		printf("|---|---|---|---|---|---|---|---|---|\n");
	}
}

void SetMine(char board[ROWS][COLS], int row, int col,int count)//�����ף�ը����
{
	int x = 0;
	int y = 0;
	while(count>0)
	{
	flag1:
		x = (rand() % 9) + 1;
		y = (rand() % 9) + 1;
		if (board[x][y] != '0')//�жϵ�ǰ�����Ƿ��Ѿ����ù�����
			goto flag1;//������ù��˻ص�flag1�����²���
		board[x][y] = '1';
		count--;
	}
}

void ClearMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//ɨ��
{
	int x = 0;
	int y = 0;
	int tmp = 0;//����tmp��ʵ�ֿ��ֵ�һ�β�??ը��
	while((Get(show))>10)//��ʣ��δ֪�������10ִ��ѭ������ɨ��
	{
		system("cls"); 
		printf("\n");
		PrintBoard(show, ROW, COL);
	flag:
		printf("��������Ҫ���׵�λ��:");
		scanf("%d%d", &x, &y);//����Ҫɨ����������
		if (x < 1 || x>9 || y < 1 || y>9)//����������ж�
		{
			printf("�������λ�ò��Ϸ������������룺\n");
			goto flag;//������Ϸ���������
		}
		if (mine[x][y] == '1')
		{
			if (tmp == 0)
			{
				SetMine(mine, ROW, COL, 1);
				mine[x][y] = '0';
			}
			else
			{
				show[x][y] = '@';
				system("cls");
				PrintBoard(show, ROW, COL);
				printf("ը���ˣ���Ϸ������\n");
				return 0;
			}
		}
		if (mine[x][y] == '0')
		{
			if (show[x][y] == '*')
			{
				if (GetMineCount(mine, x, y) == 0)
				{

					show[x][y] = ' ';
					spread(mine, show, x, y);
				}
				else
				{
					show[x][y] = '0' + GetMineCount(mine, x, y);//�ַ�'0'������n�����ַ�'n',��ΪGetMineCount����ֵΪint���Լ��ַ�0
				}
			}
			else
			{
				printf("��λ���Ѿ�ɨ�����ˣ����������룺");//����������ֵ��Ϊ* ����λ���Ѿ�ɨ������
				goto flag;//�ص�ǰ��flag����������������
			}
		}
		tmp = 1;//���й�һ��ɨ��֮��tmp��ֵ��Ϊ1
	}
	printf("ɨ�׳ɹ���\n");//������whileѭ��ʱ����ɨ�׳ɹ�
}

int GetMineCount(char board[ROWS][COLS], int x, int y)//��ȡ��ǰ������Χ�׵ĸ���
{
	int count = 0;
	count = (board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1] + board[x][y + 1] + board[x + 1][y + 1] + board[x + 1][y] + board[x + 1][y - 1] + board[x][y - 1]) - 8 * '0';
	return count;
}

int Get(char board[ROWS][COLS])//��ȡδ֪����ĸ���
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1; i <= ROW; i++)
	{
		for (j = 1; j <= COL; j++)
		{
			if (board[i][j] == '*')
				count++;
		}
	}
	return count;
}

void spread(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y) //����Χ���������չ��
{

	int i = -1;
	int j = -1;
	for (i = -1; i <= 1; i++) //�߽�
	{
		for (j = -1; j <= 1; j++)
		{
			if (i != 0 || j != 0) // �����ŵ��Լ�ע��˴����߼���ϵ
			{
				if (x + i >= 1 && x + i <= ROW && y + j >= 1 && y + j <= COL) //x y�����Ƿ�Ϸ�
				{
					if (show[x + i][y + j] == '*'&&mine[x + i][y + j] != '1')
					{

						int count = GetMineCount(mine, x + i, y + j);
						if (count != 0)
						{
							show[x + i][y + j] = count + '0';
						}
						else
						{
							show[x + i][y + j] = ' ';
							spread(mine, show, x + i, y + j);
						}

					}

				}
			}
		}
	}
}
