#include"main.h"
Status isEqual(ElemType a, ElemType b);

int main()
{
	sqList a = { NULL, 0, 0 };
	sqList b = { NULL, 0, 0 };
	sqList c = { NULL, 0, 0 };
	InitList(&a);
	InitList(&b);
	InitList(&c);
	for (int ii = 0; ii <5; ii++)
	{
		ListInsert(&a, 1, ii);
	}
	for (int ii = 5; ii < 10; ii++)
	{
		ListInsert(&b, 1, ii);
	}

	ElemType temp = 0;
	ListDelete(&a, 1, &temp);

	int temp2=LocateElem(&a, 13, &isEqual);

	MergeList(&a, &b, &c);

	return 0;
}

