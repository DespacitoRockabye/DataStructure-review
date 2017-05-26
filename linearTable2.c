//线性表的链式存储结构
#include"basicSetting.h"
#include"linearTable2.h"

void CreateList(LinkList *L1, int n, int source[])
{
	LinkList L = *L1;
	LinkList p;
	int i = 0;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (i = n-1; i >= 0; i--)
	{
		p = (LinkList)malloc(sizeof(LNode));
		p->next = L->next;
		L->next = p;
		p->data = source[i];
	}
	*L1 = L;
}

Status GetElem(LinkList *L1, int i, L2ElemType *e)
{
	LinkList L = *L1;
	L2ElemType ee = *e;

	LinkList p = L->next;
	int j = 0;

	while (p&&j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p || j>i - 1)return ERROR;
	ee = p->data;
	*e = ee;

	return OK;
}

Status ListInsert_L(LinkList *L1, int i, L2ElemType e)
{
	LinkList L = *L1;
	LinkList p = L;
	LinkList q;
	int j = 0;
	while (p&&j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p || j>i - 1)return ERROR;
	q = (LinkList)malloc(sizeof(LNode));
	q->data = e;
	q->next = p->next;
	p->next = q;

	*L1 = L;
	return OK;
}

Status ListDelete_L(LinkList *L1, int i, L2ElemType *e)
{
	LinkList L = *L1;
	LinkList p = L;
	LinkList q;
	int j = 0;
	while (p&&j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p || j>i - 1)return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	*L1 = L;
	return OK;
}

void MergeList_L(LinkList *L1, LinkList *L2, LinkList *L3)
{
	LinkList la = *L1;
	LinkList lb = *L2;
	LinkList lc = *L3;

	LinkList p = la->next;
	LinkList q = lb->next;
	lc = la;

	while (p&&q)
	{
		if (p->data <= q->data)
		{
			lc->next = p;
			p = p->next;
		}
		else
		{
			lc->next = q;
			q = q->next;
		}
		lc = lc->next;
	}
	if (p)
		lc->next = p;
	if (q) 
		lc->next = q;

	free(lb);

	*L3 = la;
}