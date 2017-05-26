#define seqQueueMaxsize 5
typedef int QElemType;
typedef struct{
	QElemType *base;
	int front;
	int rear;
}SqQueue;

Status InitSeqQueue(SqQueue *Q);
int QueueLength(SqQueue Q);
Status EnSeqQueue(SqQueue *Q, QElemType e);
Status DeSeqQueue(SqQueue *Q, QElemType *e);