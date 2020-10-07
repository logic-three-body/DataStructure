#define _CRT_SECURE_NO_WARNINGS //put in first line
//help:https://zhuanlan.zhihu.com/p/129053984
#include<stdio.h>
#define MAXSIZE 100
/*定义一个结构体存储m和n*/
typedef struct Data {
	int m;
	int n;
};
/*定义栈*/
typedef struct Stack {
	Data data[MAXSIZE];
	int top;
}Stack;
/*初始化栈*/
void initStack(Stack &s) {
	s.top = -1;
}
/*压栈操作*/
void StackPush(Stack &s, Data e) {
	if (s.top < MAXSIZE - 1) {
		s.top++;
		s.data[s.top] = e;
	}
}

/*判断栈是否为空*/
int isEmpty(Stack s) {
	if (s.top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

/*获取当前栈顶的元素*/
Data getTopElem(Stack s) {
	if (!isEmpty(s)) {
		return s.data[s.top];
	}
	else { //栈为空时，返回的特殊值
		Data e;
		e.m = e.n = -1;
		return e;
	}
}
/*出栈*/
void StackPop(Stack &s) {
	if (s.top != -1) {
		s.top--;
	}
}
/*非递归算法*/
int Ackerman(int m, int n) {
	if (m < 0 || n < 0 || m >= 4) {//数据范围检查
		return  -1;
	}
	int result = 0;//存储中间的计算结果，函数结束时，返回最终的结果
	Stack stackor;
	initStack(stackor);
	Data elem;
	elem.m = m;
	elem.n = n;
	StackPush(stackor, elem);
	while (!isEmpty(stackor)) {
		elem = getTopElem(stackor);
		/*对应第一部分*/
		while (elem.m > 0 && elem.n > 0) {
			elem.n--;
			StackPush(stackor, elem);
		}
		/*对应第二部分*/
		while (elem.m > 0 && elem.n == 0) {
			StackPop(stackor);
			elem = getTopElem(stackor);
			elem.m--;
			elem.n = 1;
			StackPush(stackor, elem);
		}
		/*对应第三部分*/
		while (elem.m == 0) {
			result = elem.n + 1; //获取边界结果
			StackPop(stackor);           //弹出序对(0,n)
			elem = getTopElem(stackor);//获取栈顶的元素
			if (elem.m == -1) {//表明栈已空
				break;
			}
			//栈不空时，返回上一层调用
			elem.m--;
			elem.n = result;
			StackPop(stackor);
			StackPush(stackor, elem);
		}
	}
	return result;
}
int main() {
	int m, n;
	while (scanf("%d%d",&m,&n))
	{
		if (!m&&!n)
		{
			break;
		}
		printf("%d\n", Ackerman(m, n));
	}
	return 0;
}