#define LIST_INIT_SIZE 5
#define LISTINCREMENT 1
typedef  int L2ElemType;
typedef struct LNode{
	L2ElemType data;
	struct LNode *next;
}LNode, *LinkList;