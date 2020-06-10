#include<stdio.h>
#include<stdlib.h>
struct node {
	int element;
	struct node* next;
};
typedef  struct node date;
date* creatstack(void);                        //´´½¨¿ÕÕ»£»
void makeempty(date* s);                      //Çå¿ÕÕ»£»
void pop(date* s);                           //³öÕ»£»
void push(int x, date* s);                  //½øÕ»;
int top(date* s);                                //·µ»ØÕ»¶¥ÔªËØ£»
int isempty(date* s);                      //ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ£»
int main()
{

}
date* creatstack(void)
{
	date* s;
	s = (date*)malloc(sizeof(date));
	if (s == NULL)
		printf("out of space!");
	s->next = NULL;
	makeempty(s);
	return s;
}
void makeempty(date* s)
{
	if (s == NULL)
		printf("must use creatstack first!");
	else
		while (!isempty(s))
			pop(s);
}
void pop(date* s)
{
	date* firstcell;
	if (isempty(s))
		printf("error empty stack");
	else
	{
		firstcell = s->next;
		s->next = s->next->next;
		free(firstcell);
	}
}
void push(int x, date* s)
{
	date* tmp;
	tmp = (date*)malloc(sizeof(date));
	if (tmp == NULL)
		printf("out of space!");
	tmp->element = x;
	tmp->next = s->next;
	s->next = tmp;
}
int top(date* s)
{
	if (!isempty(s))
		return s->next->element;
	printf("error empty stack!");
	return 0;
}
int isempty(date* s)
{
	return s->next == NULL;
}