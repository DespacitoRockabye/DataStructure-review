typedef  int QUElemType;
typedef struct QNode{
	QUElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct{
	QueuePtr front;//��ͷ
	QueuePtr rear;//��β
}LinkQueue;

Status InitQueue(LinkQueue *Q);
Status DestroyQueue(LinkQueue *Q);
Status ClearQueue(LinkQueue *Q);
Status QueueEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
Status GetHead(LinkQueue Q, QUElemType *e);
Status EnQueue(LinkQueue *Q, QUElemType e);//����eΪ�¶�β
Status DeQueue(LinkQueue *Q, QUElemType *e);//ɾ��Q��ͷ������e
Status QueueTraverse(LinkQueue Q, Status(*visit)());