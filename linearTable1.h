#define LIST_INIT_SIZE 5
#define LISTINCREMENT 1
typedef  int L1ElemType;
typedef struct
{
	L1ElemType *elem;
	int length;//���г���
	int listsize;//�ܷ��䳤��
}sqList;