#include<stdio.h>
struct node {
	int element;
	int next;
};
typedef struct node date;
date  cursor[11];
static int cursoralloc(void);     //执行malloc功能；
static void cursorfree(int p);     //执行free功能；
void init(void);           //初始化
int isempty(int L);        //判断链表是否为空；
int islast(int L, int p);  //测试p是不是链表最后一位；
int find(int x, int L);    //查找，返回查找元素地址；
void delete(int x, int L);  //执行删除功能；
int findprevious(int x, int L);//寻找前驱元；
void insert(int x, int L, int p); //插入（插在p的后面）；
int main()
{
	
}
int cursoralloc(void)
{
	int p;
	p = cursor[0].next;
	cursor[0].next = cursor[p].next;
	return p;
}
void cursorfree(int p)
{
	cursor[p].next = cursor[0].next;
	cursor[0].next = p;
}
void init(void)
{
	for (int i = 0; i < 10; i++)
	{
		cursor[i].next = i + 1;
	}
	cursor[10].next = 0;
}
int isempty(int L)
{
	return cursor[L].next == 0;
}
int islat(int L, int p)
{
	return cursor[p].next == 0;
}
int find(int x, int L)
{
	int p;
	p = cursor[L].next;
	while (p && cursor[p].element != x)
		p = cursor[p].next;
	return p;
}
void delete(int x, int L)
{
	int p, tmp;
	p = findprevious(x, L);
	if (!islast(p, L))
	{
		tmp = cursor[p].next;
		cursor[p].next = cursor[cursor[p].next].next;
		cursorfree(tmp);
	}
}
int findprevious(int x, int L)
{
	int p;
	p = cursor[L].next;
	if (cursor[p].next && cursor[cursor[p].next].element != x)
		p = cursor[p].next;
	return p;
}
void insert(int x, int L, int p)
{
	int tmp;
	tmp = cursoralloc();
	cursor[tmp].element = x;
	cursor[tmp].next = cursor[p].next;
	cursor[p].next = tmp;
}