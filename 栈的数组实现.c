#include<stdio.h>
#include<stdlib.h>
#define minstacksize 5
#define emptytos -1
struct stackrecord {
	int capacity;
	int topofstack;
	int* array;
};
typedef struct stackrecord date;
date* creatstack(int maxelements);
date* makeempty(date* s);
void disposestack(date* s);
int isempty(date* s);
void push(int x,date* s);
int isfull(date* s);
int top(date* s);
int pop(date* s);
int main()
{

}
date* creatstack(int maxelements)
{
	date* s;
	if (maxelements < minstacksize)
		printf("stack size is too small");
	s = (date*)malloc(sizeof(date));
	if (s == NULL)
		printf("out of space!");
	s->array = (int*)malloc(sizeof(int) * maxelements);
	if (s->array == NULL)
		printf("out of space!");
	s->capacity = maxelements;
	makeempty(s);
}
date* makeempty(date* s)
{
	s->topofstack = emptytos;
}
void disposestack(date* s)
{
	if (s != NULL)
	{
		free(s->array);
		free(s);
	}
}
int isempty(date* s)
{
	return s->topofstack == emptytos;
}
void push(int x, date* s)
{
	if (isfull(s))
		printf("stack is full");
	else
		s->array[++s->topofstack] = x;
}
int isfull(date* s)
{
	return s->topofstack == s->capacity - 1;
}
int top(date* s)
{
	if (!isempty(s))
		return s->array[s->topofstack];
	else
		return 0;
}
int pop(date* s)
{
	if (isempty(s))
		printf("empty stack");
	else
		return s->array[s->topofstack--];
}