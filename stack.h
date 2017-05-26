#define STACK_INIT_SIZE 5
#define STACKINCREMENT 1
typedef  int STElemType;
typedef struct {
	STElemType *base;
	STElemType *top;
	int stacksize;
}sqStack;

Status InitStack(sqStack *S);
Status DestroyStack(sqStack *s);
Status ClearStack(sqStack *s);
Status StackEmpty(sqStack s);
int StackLength(sqStack s);
Status GetTop(sqStack s, STElemType *e);
Status Push(sqStack *s, STElemType e);
Status Pop(sqStack *s, STElemType *e);
Status StackTraverse(sqStack S, Status(*visit)());
Status visit();

