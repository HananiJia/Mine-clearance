#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10
#define HARD_COUNT 20

void welcome();//��ʼ��
void menu();//���˵�
void game();//��Ϸ�˵�
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);//�����ʼ��
void PrintBoard(char board[ROWS][COLS], int row, int col);//��ӡ����
void SetMine(char board[ROWS][COLS], int row, int col,int count);//�����ף�ը����
void ClearMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//ɨ��
int GetMineCount(char board[ROWS][COLS], int x, int y);//��ȡ��ǰ������Χ�׵ĸ���
int Get(char board[ROWS][COLS]);//��ȡδ֪����ĸ���
void spread(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);//����Χ���������չ��

#endif //__GAME_H__
