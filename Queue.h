typedef  int QUElemType;
typedef struct QNode{
	QUElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct{
	QueuePtr front;//队头
	QueuePtr rear;//队尾
}LinkQueue;

Status InitQueue(LinkQueue *Q);
Status DestroyQueue(LinkQueue *Q);
Status ClearQueue(LinkQueue *Q);
Status QueueEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
Status GetHead(LinkQueue Q, QUElemType *e);
Status EnQueue(LinkQueue *Q, QUElemType e);//插入e为新队尾
Status DeQueue(LinkQueue *Q, QUElemType *e);//删除Q队头并赋给e
Status QueueTraverse(LinkQueue Q, Status(*visit)());