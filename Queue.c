#include"basicSetting.h"
#include"Queue.h"

Status InitQueue(LinkQueue *Q)
{
	LinkQueue q = *Q;
	q.front = (QueuePtr)malloc(sizeof(QNode));
	q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q.front || !q.rear)exit(OVERFLOW);
	q.front->next = NULL;
	*Q = q;
	return OK;
}
Status DestroyQueue(LinkQueue *Q);
Status ClearQueue(LinkQueue *Q);
Status QueueEmpty(LinkQueue Q)
{
	return (Q.front == Q.rear) ? TRUE : FALSE;
}
int QueueLength(LinkQueue Q);
Status GetHead(LinkQueue Q, QUElemType *e);
Status EnQueue(LinkQueue *Q, QUElemType e)//插入e为新队尾
{
	LinkQueue q = *Q;
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	q.rear->next = p;
	q.rear = p;

	*Q = q;
	return OK;
}
Status DeQueue(LinkQueue *Q, QUElemType *e)//删除Q队头并赋给e
{
	LinkQueue q = *Q;
	QueuePtr p;
	if (QueueEmpty(q))return ERROR;
	p = q.front->next;
	*e = p->data;
	q.front->next = p->next;
	if (q.rear == p)q.rear = q.front;
	free(p);
	*Q = q;
}
Status QueueTraverse(LinkQueue Q, Status(*visit)());