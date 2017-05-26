#include"basicSetting.h"
#include"seqQueue.h"
Status InitSeqQueue(SqQueue *Q){
	SqQueue q = *Q;
	q.base = (QElemType *)malloc(seqQueueMaxsize*sizeof(QElemType));
	if (!q.base)exit(OVERFLOW);
	q.front = 0;
	q.rear = 0;
	*Q = q;
	return OK;
}
int QueueLength(SqQueue Q){
	// return Q.front < Q.rear ? (Q.rear - Q.front) : (seqQueueMaxsize - Q.front + 1 + Q.rear);
	return (Q.rear - Q.front + seqQueueMaxsize) % seqQueueMaxsize;
}
Status EnSeqQueue(SqQueue *Q, QElemType e){
	SqQueue q = *Q;
	if ((q.rear+1)%seqQueueMaxsize == q.front)return ERROR;
	*(q.base + q.rear) = e;
	q.rear=(q.rear+1)%seqQueueMaxsize;
	*Q = q;
	return OK;
}
Status DeSeqQueue(SqQueue *Q, QElemType *e){
	SqQueue q = *Q;
	if (q.rear == q.front)return ERROR;
	*e = *(q.base + q.front);
	q.front = (q.front + 1) % seqQueueMaxsize;
	*Q = q;
	return OK;
}