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
	int length;//���г���
	int listsize;//�ܷ��䳤��
}sqList;