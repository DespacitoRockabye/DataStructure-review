#include"main.h"
void test_LinearTable1();
void test_LinearTable2();
void test_stack();
void test_seqQueue();
int main()
{
	//test_LinearTable1();
	//test_LinearTable2();
	//test_stack();
	test_seqQueue();
	return 0;
}

void test_LinearTable1()
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

	L1ElemType temp = 0;
	ListDelete(&a, 1, &temp);

	int temp2 = LocateElem(&a, 13, &isEqual);

	MergeList(&a, &b, &c);
}

void test_LinearTable2()
{
	LinkList a,b,c;
	L2ElemType e;
	int num[5]={ 0, 0, 0, 0, 0 };
	int num1[2] = { 1, 2 };
	int num2[3] = { 5, 6, 7 };
	CreateList(&b, 2, num1);
	CreateList(&c, 3, num2);
	MergeList_L(&b, &c, &a);
	//GetElem(&a, 3, &e);
	//ListInsert_L(&a, 2, 99);
	//ListDelete_L(&a, 2, &e);
}

void test_stack()
{
	sqStack s;
	STElemType e;
	int status_t = 0;
	status_t = InitStack(&s);
	status_t = StackEmpty(s);
	status_t = Push(&s, 1);
	status_t = GetTop(s, &e);
	status_t = Pop(&s, &e);
}

void test_seqQueue(){
	SqQueue Q;
	int temp = 0;
	temp=InitSeqQueue(&Q);
	for (int i = 0; i < 5; i++)
	{
		EnSeqQueue(&Q, i);
	}
	for (int i = 0; i < 3; i++)
	{
		DeSeqQueue(&Q, &temp);
	}
	EnSeqQueue(&Q, 99);

}