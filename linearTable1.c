//线性表的顺序存储结构
#include"basicSetting.h"
#include"linearTable1.h"
//初始化线性表
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
//线性表插入项
//输入：线性表头指针，插入第i个数，插入的数值
//返回：返回状态
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
	
	L1ElemType *p, *q;//p为插入点，q从末尾开始移动
	p = &L.elem[i - 1];
	for (q = &L.elem[L.length - 1]; q >= p; --q)
		*(q+1) = *q;
	*p = e;
	++L.length;

	*L1 = L;
	return OK;
}

//线性表删除项
//输入：线性表头指针，删除第i位项，删除项的值
//返回：返回状态
Status ListDelete(sqList *L1, int i, L1ElemType *e)
{
	sqList L = *L1;
	L1ElemType *p, *q;
	if (i<1 || i>L.length + 1) return ERROR;

	int counti=L.length-i;
	*e = L.elem[i - 1];
	p = &L.elem[i - 1];
	q = &L.elem[L.length - 1];//q标识序列末元素；
	//for (p = &L.elem[i - 1]; counti > 0; counti--,p++)
	//	*p = *(p + 1);

	for (++p; p <= q; p++)
		*(p - 1) = *p;

	L.length--;
	*L1 = L;

	return OK;
}

//定位元素
//输入：线性表头指针，待定位元素，比较函数
//输出：待定位元素在第i位处; 找不到返回0
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

//比较函数-相等
//输入：待比较元素两个
//输出：相等1； 不相等0
Status isEqual(L1ElemType a, L1ElemType b)
{
	return a == b ? 1 : 0;
}

//顺序表合并
//输入：顺序表1表头，顺序表2表头，合并表3表头
//返回：空
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


