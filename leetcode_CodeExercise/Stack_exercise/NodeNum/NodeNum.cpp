#include<iostream>
#define ElemType int
#define Status int
#define OK 1
#define ERROR 0


typedef struct LNode
{
	ElemType data;
	LNode *next;
}LNode, *LinkList;


Status ListTraverse(LinkList& L)
{
	LinkList p = L->next;
	while (p)
	{
		std::cout << (p->data) << " ";
		p = p->next;
	}
	printf("\n");
	return OK;
}


/*  ��������ͷ���ĵ������Ա�L��β�巨�� */
void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	*L = (LinkList)malloc(sizeof(LNode)); /* LΪ�������Ա� */
	(*L)->data = n;
	r = *L;                                /* rΪָ��β���Ľ�� */
	for (i = 0; i < n; i++)
	{
		p = (LNode *)malloc(sizeof(LNode)); /*  �����½�� */
		std::cin >> p->data;           /*  �������100���ڵ����� */
		r->next = p;                        /* ����β�ն˽���ָ��ָ���½�� */
		r = p;                            /* ����ǰ���½�㶨��Ϊ��β�ն˽�� */
	}
	r->next = nullptr;                       /* ��ʾ��ǰ������� */
}
ElemType NodeNum(LinkList L)
{
	if (L->next == nullptr)
	{
		return 1;
	}

	return NodeNum(L->next)+1;

}

int main()
{
	LinkList L;
	int n;
	int Num;
	std::cin >> n;
	while (n)
	{
		CreateListTail(&L, n);
		LinkList p = L->next;
		Num = NodeNum(p);
		printf("%d\n", Num );
		std::cin >> n;
	}
	return 0;

}