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
    printf("迷宫如下‘■’代表墙,数字 或者‘☆’表示路径\n");
    int i, j;
    for (i = 0; i < MAX_ROW; i++){
        for (j = 0; j < MAX_COL; j++)
            if (maze[i][j] == Wall)       printf("■");
            else if (maze[i][j] >= Star){//大于三的点为路径
               // printf("%2d", maze[i][j] - 2);
                if (i == MAX_ROW-2 && j == MAX_COL-2)  printf("★");
                else                   printf("☆");
            }
            else  printf("  ");
            printf("\n");
        }
    printf("已到达出口...\n");
    printf("可见使用栈求出的路径并非最优路径，根据我依次探索的方向不同，结果也将不同\n");
}

void visit(mark p,int sign, PSeqStack S)
{
    Push_SeqStack(S,p);
    switch (sign)
    {
    case 1: p.col++; Push_SeqStack(S, p); maze[p.row][p.col] = Trace; break;//向右
    case 2: p.row++; Push_SeqStack(S, p); maze[p.row][p.col] = Trace; break;//向下
    case 3: p.col--; Push_SeqStack(S, p); maze[p.row][p.col] = Trace; break;//向左
    case 4: p.row--; Push_SeqStack(S, p); maze[p.row][p.col] = Trace; break;//向上
    }
}

int main()
{
    struct point p = { 1, 1 };
    maze[p.row][p.col] = Trace;//遍历过的点设置为2
    PSeqStack S = Init_SeqStack();
    Push_SeqStack(S,p);
    while (!Empty_SeqStack(S))
    {
        Pop_SeqStack(S, &p);//弹栈
        if (p.row == MAX_ROW - 2 && p.col == MAX_COL - 2)
            break;
        if (p.col + 1 < MAX_COL - 1 && maze[p.row][p.col + 1] == Road)//向右
        {
            visit(p, 1, S);
            continue;
        }
        if (p.row + 1 < MAX_ROW - 1 && maze[p.row + 1][p.col] == Road)//向下
        {
            visit(p, 2, S);
            continue;
        }
        if (p.col - 1 >= 1 && maze[p.row][p.col - 1] == Road)//向左
        {
            visit(p, 3, S);
            continue;
        }
        if (p.row - 1 >= 1 && maze[p.row - 1][p.col] == Road)//向上
        {
            visit(p, 4, S);
            continue;
        }//以上是对迷宫的四个方向进行操作
    }
    if (p.row == MAX_ROW - 2 && p.col == MAX_COL - 2)//是否为出口
    {
        int count = GetLength_SeqStack(S)+Star;//为了与迷宫0,1,2(Road,Wall,Trace)的区别所以基数要以3(Star)开始
        printf("成功找到出口，路径倒序输出：\n");
        printf("(%d,%d)\n", p.row, p.col);
        maze[p.row][p.col] = count;
        while (!Empty_SeqStack(S))//按照前驱进行查找
        {
            count--;
            Pop_SeqStack(S, &p);
            maze[p.row][p.col] = count;
            printf("(%d,%d)\n", p.row, p.col);
        }
        printf("3秒后打印路径......");
        Sleep(3000);
        print_line();
    }
    else {
        printf("没有出路\n");
    }
    system("pause");
    return 0;
}
//end 2020-test1.cpp