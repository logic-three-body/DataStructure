#pragma once
#ifndef STACK_H_
#define STACK_H_
#endif // !STACK_H_
#include"global.h"
typedef unsigned long Item;

class Stack
{
public:
	Stack();
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
	enum {Max=10};//constant specific to class
	Item items[Max];//hold stack items
	int top;//index for top stack item
};




