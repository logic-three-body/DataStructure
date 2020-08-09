#pragma once
#include "stdio.h" 
#include<iostream>
#include<cctype>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */
typedef int Status;
typedef unsigned long SElemType; /* SElemType类型根据实际情况而定，这里假设为int */

inline Status visit(SElemType c)
{
	std::cout << c << "\t";
	return OK;
}