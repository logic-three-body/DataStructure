// 2020-test1.cpp : Defines the entry point for the console application.

//2020-test1.cpp

//#include "stdafx.h"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"2020-test1.h"

#define MAX_ROW  12
#define MAX_COL  14

#define Road 0
#define Wall 1
#define Trace 2
#define Star 3
using namespace std;

int maze[MAX_ROW][MAX_COL] = {
    Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall,
    Wall, Road, Wall, Road, Road, Road, Wall, Road, Wall, Wall, Road, Wall, Wall, Wall,
    Wall, Road, Wall, Road, Wall, Road, Wall, Road, Road, Road, Road, Road, Wall, Wall,
    Wall, Road, Road, Road, Wall, Road, Road, Road, Wall, Wall, Wall, Road, Road, Wall,
    Wall, Road, Wall, Wall, Wall, Road, Wall, Road, Road, Road, Wall, Road, Wall, Wall,
    Wall, Road, Road, Road, Wall, Wall, Wall, Wall, Road, Wall, Wall, Road, Road, Wall,
    Wall, Wall, Road, Road, Wall, Road, Wall, Wall, Road, Wall, Road, Wall, Wall, Wall,
    Wall, Wall, Road, Wall, Road, Wall, Road, Wall, Wall, Road, Road, Road, Road, Wall,
    Wall, Road, Road, Road, Road, Wall ,Road ,Road, Road ,Road ,Wall ,Road ,Wall ,Wall,
    Wall, Wall, Road, Road, Wall, Wall, Road, Wall, Wall, Wall, Wall, Road, Road, Wall,
    Wall, Road, Wall, Road, Road, Road, Road, Wall, Road, Road, Road, Road, Road, Wall,
    Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall
};

void print_line()
{
    system("cls");
    printf("�Թ����¡���������ǽ,���� ���ߡ����ʾ·��\n");
    int i, j;
    for (i = 0; i < MAX_ROW; i++){
        for (j = 0; j < MAX_COL; j++)
            if (maze[i][j] == Wall)       printf("��");
            else if (maze[i][j] >= Star){//�������ĵ�Ϊ·��
               // printf("%2d", maze[i][j] - 2);
                if (i == MAX_ROW-2 && j == MAX_COL-2)  printf("��");
                else                   printf("��");
            }
            else  printf("  ");
            printf("\n");
        }
    printf("�ѵ������...\n");
    printf("�ɼ�ʹ��ջ�����·����������·��������������̽���ķ���ͬ�����Ҳ����ͬ\n");
}

void visit(mark p,int sign, PSeqStack S)
{
    Push_SeqStack(S,p);
    switch (sign)
    {
    case 1: p.col++; Push_SeqStack(S, p); maze[p.row][p.col] = Trace; break;//����
    case 2: p.row++; Push_SeqStack(S, p); maze[p.row][p.col] = Trace; break;//����
    case 3: p.col--; Push_SeqStack(S, p); maze[p.row][p.col] = Trace; break;//����
    case 4: p.row--; Push_SeqStack(S, p); maze[p.row][p.col] = Trace; break;//����
    }
}

int main()
{
    struct point p = { 1, 1 };
    maze[p.row][p.col] = Trace;//�������ĵ�����Ϊ2
    PSeqStack S = Init_SeqStack();
    Push_SeqStack(S,p);
    while (!Empty_SeqStack(S))
    {
        Pop_SeqStack(S, &p);//��ջ
        if (p.row == MAX_ROW - 2 && p.col == MAX_COL - 2)
            break;
        if (p.col + 1 < MAX_COL - 1 && maze[p.row][p.col + 1] == Road)//����
        {
            visit(p, 1, S);
            continue;
        }
        if (p.row + 1 < MAX_ROW - 1 && maze[p.row + 1][p.col] == Road)//����
        {
            visit(p, 2, S);
            continue;
        }
        if (p.col - 1 >= 1 && maze[p.row][p.col - 1] == Road)//����
        {
            visit(p, 3, S);
            continue;
        }
        if (p.row - 1 >= 1 && maze[p.row - 1][p.col] == Road)//����
        {
            visit(p, 4, S);
            continue;
        }//�����Ƕ��Թ����ĸ�������в���
    }
    if (p.row == MAX_ROW - 2 && p.col == MAX_COL - 2)//�Ƿ�Ϊ����
    {
        int count = GetLength_SeqStack(S)+Star;//Ϊ�����Թ�0,1,2(Road,Wall,Trace)���������Ի���Ҫ��3(Star)��ʼ
        printf("�ɹ��ҵ����ڣ�·�����������\n");
        printf("(%d,%d)\n", p.row, p.col);
        maze[p.row][p.col] = count;
        while (!Empty_SeqStack(S))//����ǰ�����в���
        {
            count--;
            Pop_SeqStack(S, &p);
            maze[p.row][p.col] = count;
            printf("(%d,%d)\n", p.row, p.col);
        }
        printf("3����ӡ·��......");
        Sleep(3000);
        print_line();
    }
    else {
        printf("û�г�·\n");
    }
    system("pause");
    return 0;
}
//end 2020-test1.cpp