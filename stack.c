#include"basicSetting.h"
#include"stack.h"

Status InitStack(sqStack *S)
{
	sqStack s = *S;
	if (!(s.base = (STElemType*)malloc(STACK_INIT_SIZE*sizeof(STElemType))))exit(OVERFLOW);
	s.top = s.base;
	s.stacksize = STACK_INIT_SIZE;
	*S = s;
	return OK;
}
Status StackEmpty(sqStack s)
{
	return (s.base == s.top) ? TRUE : FALSE;
}
int StackLength(sqStack s)
{
	return s.top - s.base;
}
Status GetTop(sqStack s, STElemType *e)
{
	if (StackEmpty(s))return ERROR;
	*e = *(s.top-1);
	return OK;
}
Status Push(sqStack *S, STElemType e)
{
	sqStack s = *S;
	if (s.top - s.base >= s.stacksize)
	{
		if (!(s.base = (STElemType *)realloc(s.base, s.stacksize + STACKINCREMENT))) exit(OVERFLOW);
		s.top = s.base + s.stacksize;
		s.stacksize += STACKINCREMENT;
	}
	*s.top++ = e;
	*S = s;
	return OK;
}
Status Pop(sqStack *S, STElemType *e)
{
	sqStack s = *S;
	if (StackEmpty(s))return ERROR;
	*e = *(--s.top);
	*S = s;
	return OK;
}
Status StackTraverse(sqStack S, Status(*visit)());
Status visit();
Status DestroyStack(sqStack *S);
Status ClearStack(sqStack *s);
