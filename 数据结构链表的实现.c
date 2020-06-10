#include<stdio.h>
#include<stdlib.h>
struct node {
	int element;
	struct node* next;
};
typedef struct node date;
int isempty(date* L);
int islast(date* p, date* List);
date* find(int x, date* List);
void delete(int x, date* List);
date* findprevious(int x, date* List);
void insert(int x, date* List, date* p);
void deletelist(date* List);
int main()
{
	date* head, * p2;
	date* p1;
	p1 = NULL;
	int n;
	p2=head = (date*)malloc(sizeof(date));
	printf("请输入要输入的数据个数\n");
	scanf_s("%d", &n);
	while (n--)
	{
		p1= (date*)malloc(sizeof(date));
		scanf_s("%d", &p1->element);
		p2->next = p1;
		p2 = p1;
	}
	p1->next = NULL;
	deletelist(head);
	return 0;
}
int isempty(date* L)
{
	return L->next == NULL;
}
int islast(date* p, date* List)
{
	return p->next == NULL;
}
date* find(int x, date* List)
{
	date* p;
	p = List->next;
	if (p->element != x&&p!=NULL)
		p = p->next;
	return p;
}
void delete(int x, date* List)
{
	date* p,*tmp;
	p = findprevious(x, List);
	if (!islast(p, List))
	{
		tmp = p->next;
		p->next = p->next->next;
		free(tmp);
	}
}
date* findprevious(int x, date* List)
{
	date* p;
	p = List;
	while (p->next != NULL && p->next->element != x)
		p = p->next;
	return p;
}
void insert(int x, date* List, date* p)
{
	date* newcell;
	newcell = (date*)malloc(sizeof(date));
	if (newcell == NULL)
		printf("out of space!");
	newcell->element = x;
	newcell->next = p->next;
	p->next = newcell;            //插在p的后面
}
void deletelist(date* List)
{
	date* p,*tmp;
	tmp = NULL;
	p = List->next;
	List->next = NULL;
	while (p != NULL)
	{
		tmp = p->next;
		free(p);
		p = tmp;
	}
}