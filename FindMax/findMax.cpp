#include <iostream>//Find Max Node By Stack
#include<string.h>//For metset
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

const int FIND = 1;

typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;/* ElemType���͸���ʵ������������������Ϊint */
typedef struct LNode {
	int data;
	struct LNode *next;
}LNode, *LinkList;

void InitList(LinkList &L)
{
	L = new LNode;
	L->next = NULL;
	return;
}

/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��β�巨�� */
void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	*L = (LinkList)malloc(sizeof(LNode)); /* LΪ�������Ա� */
	r = *L;                                /* rΪָ��β���Ľ�� */
	for (i = 0; i < n; i++)
	{
		p = (LNode *)malloc(sizeof(LNode)); /*  �����½�� */
		std::cin >> p->data;
		r->next = p;                        /* ����β�ն˽���ָ��ָ���½�� */
		r = p;                            /* ����ǰ���½�㶨��Ϊ��β�ն˽�� */
	}
	r->next = nullptr;                       /* ��ʾ��ǰ������� */
}

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
Status ListTraverse(LinkList& L)
{
	LinkList p = L->next;
	std::cout << (p->data);
	p = p->next;
	while (p)
	{
		std::cout << " ";
		std::cout << p->data;
		p = p->next;
	}
	printf("\n");
	return OK;
}

ElemType FindMax(LinkList &L)
{
	int max = L->data;
	if (!L->next)
	{
		return L->data;
	}
	max = FindMax(L->next);
	return L->data >= max ? L->data:max;
}

int main()
{
	LinkList list;
	while (true)
	{
		InitList(list);
		int num = 0;
		std::cin >> num;
		if (!num)
		{
			break;
		}
		CreateListTail(&list, num);
		std::cout<<FindMax(list->next)<<std::endl;		
	}
	return 0;
}
