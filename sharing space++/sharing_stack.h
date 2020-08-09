#pragma once
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
/* ��ջ����ռ�ṹ */
typedef struct
{
	SElemType data[MAXSIZE];
	int top1;	/* ջ1ջ��ָ�� */
	int top2;	/* ջ2ջ��ָ�� */
}SqDoubleStack;
class sharing_stack
{
public:
	sharing_stack();
	/* ��S��Ϊ��ջ */
	void ClearStack();
	/* ����S��Ԫ�ظ�������ջ�ĳ��� */
	int stackLength();
	/* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
	SElemType *GetTop1();
	SElemType *GetTop2();
	/* ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ����ʾ */
	Status stackTraverse();
	bool isempty() const;
	bool isfull() const;
	//push returns false if stack already is full,true otherwise
	bool push(SElemType,int);//add item to stack
	//pop()returns false if stacks already is empty,true otherwise
	bool pop(SElemType &, int );//pop into them

private:
	
	SqDoubleStack sqtack;

};

