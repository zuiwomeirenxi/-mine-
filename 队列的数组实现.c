#include<stdio.h>
#include<stdlib.h>
struct queuerecord {
	int capacity;
	int front;
	int rear;
	int size;
	int* array;
};
typedef struct queuerecord date;
date* creatqueue(int x);
int isempty(date* q);
void makeempty(date* q);
static int succ(int value, date* q);   //valueΪ��ʱrear��ֵ���˺����ĵ��������ж��Ƿ���Ҫ���㿪ʼ���Դ˽�Լ���пռ䣩��
void enqueue(int x, date* q);
int isfull(date* q);
int main()
{

}
date* creatqueue(int x)
{
	date* q;
	if (x == 0)
		printf("����Ϊ�գ�");
	q = (date*)malloc(sizeof(date));
	if (q == NULL)
		printf("out of space!");
	q->array = (int*)malloc(sizeof(int) * x);
	if (q->array == NULL)
		printf("out of space!");
	q->capacity = x - 1;
	return q;
}
int isempty(date* q)
{
	return q->size == 0;
}
void makeempty(date* q)
{
	q->size = 0;
	q->front = 1;
	q->rear = 0;
}
static int succ(int value, date* q)
{
	if (++value == q->capacity)
		value = 0;
		return value;
}
void enqueue(int x, date* q)
{
	if (isfull(q))
		printf("full queue!");
	else
	{
		q->size++;
		q->rear = succ(q->rear, q);
		q->array[q->rear] = x;
	}

}
int isfull(date* q)
{
	return q->size == q->capacity;
}