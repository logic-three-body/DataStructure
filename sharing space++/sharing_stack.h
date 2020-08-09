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
typedef unsigned long Item;
class sharing_stack
{
public:
	sharing_stack();
	/* ��S��Ϊ��ջ */
	void ClearStack();
	/* ����S��Ԫ�ظ�������ջ�ĳ��� */
	int stackLength();
	/* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
	Status GetTop(SElemType*);
	/* ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ����ʾ */
	Status stackTraverse();
	bool isempty() const;
	bool isfull() const;
	//push returns false if stack already is full,true otherwise
	bool push(const Item &item);//add item to stack
	//pop()returns false if stacks already is empty,true otherwise
	bool pop(Item&item);//pop into them

private:
	enum { Max = 10 };//constant specific to class
	Item items[Max];//hold stack items
	int top1;//index for top stack item front
	int top2;//index for top stack item behind
};

