#include<stdio.h>
struct node {
	int element;
	int next;
};
typedef struct node date;
date  cursor[11];
static int cursoralloc(void);     //ִ��malloc���ܣ�
static void cursorfree(int p);     //ִ��free���ܣ�
void init(void);           //��ʼ��
int isempty(int L);        //�ж������Ƿ�Ϊ�գ�
int islast(int L, int p);  //����p�ǲ����������һλ��
int find(int x, int L);    //���ң����ز���Ԫ�ص�ַ��
void delete(int x, int L);  //ִ��ɾ�����ܣ�
int findprevious(int x, int L);//Ѱ��ǰ��Ԫ��
void insert(int x, int L, int p); //���루����p�ĺ��棩��
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