#include<iostream>
#include<stack>



#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */


typedef int Status;
typedef int SElemType; /* SElemType���͸���ʵ������������������Ϊint */

const int Expection = -1;//������־

/* ��ջ�ṹ */
typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;


typedef struct
{
	LinkStackPtr top;
	int count;
}LinkStack;

Status visit(SElemType c)
{
	printf("%d ", c);
	return OK;
}

/*  ����һ����ջS */
Status InitStack(LinkStack *S)
{
	S->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!S->top)
		return ERROR;
	S->top = NULL;
	S->count = 0;
	return OK;
}

/* ��S��Ϊ��ջ */
Status ClearStack(LinkStack *S)
{
	LinkStackPtr p, q;
	p = S->top;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	S->count = 0;
	return OK;
}

/* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
Status StackEmpty(LinkStack S)
{
	if (S.count == 0)
		return TRUE;
	else
		return FALSE;
}

/* ����S��Ԫ�ظ�������ջ�ĳ��� */
int StackLength(LinkStack S)
{
	return S.count;
}

/* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
Status GetTop(LinkStack S, SElemType *e)
{
	if (S.top == NULL)
		return ERROR;
	else
		*e = S.top->data;
	return OK;
}

/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
Status Push(LinkStack *S, SElemType e)
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s->data = e;
	s->next = S->top;	/* �ѵ�ǰ��ջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ�̣���ͼ�Т� */
	S->top = s;         /* ���µĽ��s��ֵ��ջ��ָ�룬��ͼ�Т� */
	S->count++;
	return OK;
}

/* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
Status Pop(LinkStack *S, SElemType *e)
{
	LinkStackPtr p;
	if (StackEmpty(*S))
		return ERROR;
	*e = S->top->data;
	p = S->top;					/* ��ջ����㸳ֵ��p����ͼ�Т� */
	S->top = S->top->next;    /* ʹ��ջ��ָ������һλ��ָ���һ��㣬��ͼ�Т� */
	free(p);                    /* �ͷŽ��p */
	S->count--;
	return OK;
}

Status StackTraverse(LinkStack S)
{
	LinkStackPtr p;
	p = S.top;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

int main()
{
	LinkStack stack;
	int flag = OK;
	while (true)
	{
		InitStack(&stack);
		int times = 0;
		std::cin >> times;
		if (!times)
		{
			break;
		}
		while (times--)
		{
			int elem = 0;
			std::cin >> elem;
			if (Expection != elem)
			{
				Push(&stack, elem);
			}
			else
			{
				int GetTop = 0;
				if (Pop(&stack, &GetTop))
				{
					std::cout << GetTop << std::endl;
				}
				else
				{
					std::cout << "POP ERROR" << std::endl;
					while (times--)
					{
						LinkStack tmp;//��������
						std::cin >> elem;
						Push(&tmp, elem);
						Pop(&tmp, &elem);
					}
					break;
				}
			}
		}
	}
	return 0;
}