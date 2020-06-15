#include<stdio.h>
#include<stdlib.h>
struct avltree {
	int element;
	struct avltree* left;
	struct avltree* right;
	int height;
};
typedef struct avltree date;
static int height(date* p);                 /*计算avl树节点高度*/
static date* singlerotatewithleft(date* k2);         //该例程只能应对左旋，如需左旋只需改动少量，下面的双旋例程也同样；
static date* doublerotatewithright(date* k3);
date* insert(int x, date* t);                  //AVL树插入例程，一定要注意递归思想，最后返回值t返回的是整颗树的根节点；
int main()
{

}
static int height(date* p)
{
	if (p == NULL)
		return -1;
	else
		return p->height;
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
			t->element = x; t->height = 0;
			t->left = t->right = NULL;
		}
	}
	else
		if (x < t->element)
		{
			t->left = insert(x, t->left);
			if (height(t->right) - height(t->left) == 2)
			{
				if (x < t->left->element)
					t = singlerotatewithleft(t);
				else
					t = doublerotatewithright(t);
			}
		}
		else
			if (x > t->element)
			{
				t->right = insert(x, t->right);
				if (height(t->right) - height(t->left) == 2)
				{
					if (x > t->right->element)
						t = singlerotatewithleft(t);
					else
						t = doublerotatewithright(t);
				}
			}
	t->height = max(height(t->left), height(t->right)) + 1;
	return t;
}
 date* singlerotatewithleft(date* k2)
{
	date* k1;
	k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max(height(k2->left), height(k2->right))+1;
	k1->height = max(height(k1->left), k2->height) + 1;
	return k1;
}
date* doublerotatewithright(date* k3)
{
	k3->left = singlerotatewithleft(k3->left);         //此地方建议画图，简洁明了；
	return singlerotatewithleft(k3);
}
void b(date* t)
{
	if (b)
	{
		b(t->left);
		printf(t->element);
		b(t->right);
	}
}