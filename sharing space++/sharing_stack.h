#pragma once
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
typedef unsigned long Item;
class sharing_stack
{
public:
	sharing_stack();
	/* 把S置为空栈 */
	void ClearStack();
	/* 返回S的元素个数，即栈的长度 */
	int stackLength();
	/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
	Status GetTop(SElemType*);
	/* 从栈底到栈顶依次对栈中每个元素显示 */
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

