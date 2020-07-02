#include<stdio.h>
#include<stdlib.h>
#define minpqsize 10
#define mindate 0
struct heapstruct {
	int capacity;
	int size;
	int* elements;
};
typedef struct heapstruct date;
date* initialize(int maxelement);
void insert(int x, date* h);
int isfull(date* h);
int deletemin(date* h);
int isempety(date* h);
int main()
{
	return 0;
}
date* initialize(int maxelement)
{
	date* h;
	if (maxelement < minpqsize)
		printf("priority queue size is too small");
	h = (date*)malloc(sizeof(date));
	if (h == NULL)
		printf("out of space");
	h->elements = (int*)malloc(sizeof(int) * (maxelement + 1));
	if (h->elements == NULL)
		printf("out of space!");
	h->capacity = maxelement;
	h->size = 0;
	h->elements[0] = mindate;
	return h;
}
void insert(int x, date* h)
{
	int i;
	if (isfull(h))
	{
		printf("priority queue is full");
		return;
	}
	for (i = ++h->size; h->elements[i / 2] > x; i /= 2)
		h->elements[i] = h->elements[i / 2];
	h->elements[i] = x;
}
isfull(date* h)
{
	return h->size == h->capacity;
}
int deletemin(date* h)
{
	int i, child;
	int minelement, lastelement;
	if (isempty(h))
		printf("priority queue is empty");
	minelement = h->elements[1];
	lastelement = h->elements[h->size--];
	for (i = 0; i * 2 <= h->size; i = child)
	{
		child = i * 2;
		if (child != h->size && h->elements[child + 1] < h->elements[child])
			child++;
		if (lastelement > h->elements[child])
			h->elements[i] = h->elements[child];
		else
			break;
	}
	h->elements[i] = lastelement;
	return minelement;
}
int isempty(date* h)
{
	return h->size == 0;
}