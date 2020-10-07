#define _CRT_SECURE_NO_WARNINGS //put in first line
//help:https://zhuanlan.zhihu.com/p/129053984
#include<stdio.h>
#define MAXSIZE 100
/*����һ���ṹ��洢m��n*/
typedef struct Data {
	int m;
	int n;
};
/*����ջ*/
typedef struct Stack {
	Data data[MAXSIZE];
	int top;
}Stack;
/*��ʼ��ջ*/
void initStack(Stack &s) {
	s.top = -1;
}
/*ѹջ����*/
void StackPush(Stack &s, Data e) {
	if (s.top < MAXSIZE - 1) {
		s.top++;
		s.data[s.top] = e;
	}
}

/*�ж�ջ�Ƿ�Ϊ��*/
int isEmpty(Stack s) {
	if (s.top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

/*��ȡ��ǰջ����Ԫ��*/
Data getTopElem(Stack s) {
	if (!isEmpty(s)) {
		return s.data[s.top];
	}
	else { //ջΪ��ʱ�����ص�����ֵ
		Data e;
		e.m = e.n = -1;
		return e;
	}
}
/*��ջ*/
void StackPop(Stack &s) {
	if (s.top != -1) {
		s.top--;
	}
}
/*�ǵݹ��㷨*/
int Ackerman(int m, int n) {
	if (m < 0 || n < 0 || m >= 4) {//���ݷ�Χ���
		return  -1;
	}
	int result = 0;//�洢�м�ļ���������������ʱ���������յĽ��
	Stack stackor;
	initStack(stackor);
	Data elem;
	elem.m = m;
	elem.n = n;
	StackPush(stackor, elem);
	while (!isEmpty(stackor)) {
		elem = getTopElem(stackor);
		/*��Ӧ��һ����*/
		while (elem.m > 0 && elem.n > 0) {
			elem.n--;
			StackPush(stackor, elem);
		}
		/*��Ӧ�ڶ�����*/
		while (elem.m > 0 && elem.n == 0) {
			StackPop(stackor);
			elem = getTopElem(stackor);
			elem.m--;
			elem.n = 1;
			StackPush(stackor, elem);
		}
		/*��Ӧ��������*/
		while (elem.m == 0) {
			result = elem.n + 1; //��ȡ�߽���
			StackPop(stackor);           //�������(0,n)
			elem = getTopElem(stackor);//��ȡջ����Ԫ��
			if (elem.m == -1) {//����ջ�ѿ�
				break;
			}
			//ջ����ʱ��������һ�����
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