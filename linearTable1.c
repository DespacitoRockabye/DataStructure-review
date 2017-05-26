//���Ա��˳��洢�ṹ
#include"basicSetting.h"
#include"linearTable1.h"
//��ʼ�����Ա�
Status InitList(sqList *L1)
{
	sqList L ;
	L.elem = (L1ElemType *)malloc(LIST_INIT_SIZE*sizeof(L1ElemType));
	if (!L.elem)exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	*L1 = L;
	return OK;
}
//���Ա������
//���룺���Ա�ͷָ�룬�����i�������������ֵ
//���أ�����״̬
Status ListInsert(sqList *L1, int i, L1ElemType e)
{
	sqList L = *L1;
	L1ElemType *newbase = L.elem;
	
	if (i<1 || i>L.length + 1) return ERROR;
	
	//int *newbase;
	if (L.length >= L.listsize)
	{
		newbase = (L1ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT)*sizeof(L1ElemType));
		if (!newbase)exit(OVERFLOW);
		L.elem = newbase;
		L.listsize = L.listsize + LISTINCREMENT;
	}
	
	L1ElemType *p, *q;//pΪ����㣬q��ĩβ��ʼ�ƶ�
	p = &L.elem[i - 1];
	for (q = &L.elem[L.length - 1]; q >= p; --q)
		*(q+1) = *q;
	*p = e;
	++L.length;

	*L1 = L;
	return OK;
}

//���Ա�ɾ����
//���룺���Ա�ͷָ�룬ɾ����iλ�ɾ�����ֵ
//���أ�����״̬
Status ListDelete(sqList *L1, int i, L1ElemType *e)
{
	sqList L = *L1;
	L1ElemType *p, *q;
	if (i<1 || i>L.length + 1) return ERROR;

	int counti=L.length-i;
	*e = L.elem[i - 1];
	p = &L.elem[i - 1];
	q = &L.elem[L.length - 1];//q��ʶ����ĩԪ�أ�
	//for (p = &L.elem[i - 1]; counti > 0; counti--,p++)
	//	*p = *(p + 1);

	for (++p; p <= q; p++)
		*(p - 1) = *p;

	L.length--;
	*L1 = L;

	return OK;
}

//��λԪ��
//���룺���Ա�ͷָ�룬����λԪ�أ��ȽϺ���
//���������λԪ���ڵ�iλ��; �Ҳ�������0
int LocateElem(sqList *L1, L1ElemType e, Status(*compare)(L1ElemType, L1ElemType))
{
	sqList L = *L1;
	L1ElemType *q, *p;
	int count = 1;

	for (count = 1; count <= L.length && !(compare(L.elem[count - 1], e)); count ++);

	*L1 = L;
	if (count <= L.length)
		return count;
	else
		return 0;
}

//�ȽϺ���-���
//���룺���Ƚ�Ԫ������
//��������1�� �����0
Status isEqual(L1ElemType a, L1ElemType b)
{
	return a == b ? 1 : 0;
}

//˳���ϲ�
//���룺˳���1��ͷ��˳���2��ͷ���ϲ���3��ͷ
//���أ���
void MergeList(sqList *L1_in, sqList *L2_in, sqList *L3)
{
	sqList L = *L3;
	sqList L1 = *L1_in;
	sqList L2 = *L2_in;
	L1ElemType *p, *p_end, *q, *q_end, *r, *r_end;
	p = &L1.elem[0];
	p_end = &L1.elem[L1.length - 1];
	q = &L2.elem[0];
	q_end = &L2.elem[L2.length - 1];
	L.listsize = L1.length + L2.length;
	L.length = L.listsize;
	L.elem = (L1ElemType *)malloc(L.listsize*sizeof(L1ElemType));
	if (!L.elem) exit(OVERFLOW);
	r = &L.elem[0];
	r_end = &L.elem[L.length - 1];
	
	while ( p <= p_end&&q <= q_end&&r <= r_end)
	{
		if (*p <= *q) *r++ = *p++;
		else *r++ = *q++;
	}

	while (p <= p_end) *r++ = *p++;
	while (q <= q_end) *r++ = *q++;

	*L3 = L;
}


