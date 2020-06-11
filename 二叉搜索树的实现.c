#include<stdio.h>
#include<stdlib.h>
struct treenode {
	int element;
	int* left;
	int* right;
};
typedef struct treenode date;
date* creattree(int x);                     //创造根节点；
date* makeempty(date* t);                      //释放树；
date* find(int x, date* t);
date* findmin(date* t);                       //寻找最大值只需微修改；
date* insert(int x, date* t);                 //此函数其实已经包括了创造根节点的函数的作用；
date* delete(int x, date* t);                  //如进行少量修改建议使用懒惰删除；
int main()
{

}
date* creat(int x)
{
	date* t;
	t = (date*)malloc(sizeof(date));
	if (t == NULL)
		printf("out of space!");
	t->left = NULL;
	t->right == NULL;
	t->element = x;
	return t;
}
date* makeempty(date* t)
{
	if (t!=NULL)
	{
		makeempty(t->left);
		makeempty(t->right);
		free(t);
	}
	return NULL;
}
date* find(int x, date* t)
{
	if (t == NULL)
		return NULL;
	if (x < t->element)
		find(x, t->left);
	else if (x > t->element)
		find(x, t->right);
	else
		return t;
}
date* findmin(date* t)
{
	if (t == NULL)
		return NULL;
	else if (t->left == NULL)
		return t;
	else
		return findmin(t->left);
}
date* insert(int x, date* t)
{
	if (t == NULL)
	{
		t = (date*)malloc(sizeof(date));
		if (t == NULL)
			printf("out of space!");
		else
		{
			t->element = x;
			t->left = NULL;
			t->right = NULL;
		}
	}
	else
	{
		if (x < t->element)
			insert(x, t->left);
		else if (x > t->right)
			insert(x, t->right);
	}
	return t;
}
date* delete(int x, date* t)
{
	date* tmpcell;
	if (t == NULL)
		printf("element not found");
	else
		if (x > t->element)
			delete(x, t->right);
		else if (x < t->element)
			delete(x, t->left);
		else if(t->left&&t->right)
		{
			tmpcell = findmin(t->right);
			t->element = tmpcell->element;
			t->right = delete(t->element, t->right);
		}
		else
		{
			tmpcell = t;
			if (t->left == NULL)
				t = t->right;
			else if(t->right == NULL)
				t = t->left;
			free(tmpcell);
		}
	return t;
}
