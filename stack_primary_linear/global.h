#pragma once
#include "stdio.h" 
#include<iostream>
#include<cctype>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */
typedef int Status;
typedef unsigned long SElemType; /* SElemType���͸���ʵ������������������Ϊint */

inline Status visit(SElemType c)
{
	std::cout << c << "\t";
	return OK;
}