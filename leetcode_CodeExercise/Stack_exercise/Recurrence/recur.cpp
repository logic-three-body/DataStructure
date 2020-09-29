#include<iostream>
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


/*  建立带表头结点的单链线性表L（尾插法） */
void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	*L = (LinkList)malloc(sizeof(LNode)); /* L为整个线性表 */
	(*L)->data = n;
	r = *L;                                /* r为指向尾部的结点 */
	for (i = 0; i < n; i++)
	{
		p = (LNode *)malloc(sizeof(LNode)); /*  生成新结点 */
		std::cin >> p->data;           /*  随机生成100以内的数字 */
		r->next = p;                        /* 将表尾终端结点的指针指向新结点 */
		r = p;                            /* 将当前的新结点定义为表尾终端结点 */
	}
	r->next = nullptr;                       /* 表示当前链表结束 */
}
ElemType Aver(LinkList L)
{
	if (L->next==nullptr)
	{
		return L->data;
	}

	return (Aver(L->next) + L->data);

}

int main()
{
	LinkList L;
	int n,length;
	double Average;
	std::cin >> n;
	while (n)
	{
		CreateListTail(&L, n);
		LinkList p = L->next;
		Average = Aver(p);
		printf("%.2f\n", Average / n);
		std::cin >> n;
	}
	system("pause");
	return 0;

}