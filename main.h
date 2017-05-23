#include<stdio.h>
#include<stdlib.h>

#define LIST_INIT_SIZE 5
#define LISTINCREMENT 1

typedef int Status;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2


typedef  int ElemType;
typedef struct
{
	ElemType *elem;
	int length;//现有长度
	int listsize;//总分配长度
}sqList;