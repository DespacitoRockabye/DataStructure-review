#define LIST_INIT_SIZE 5
#define LISTINCREMENT 1
typedef  int L1ElemType;
typedef struct
{
	L1ElemType *elem;
	int length;//现有长度
	int listsize;//总分配长度
}sqList;