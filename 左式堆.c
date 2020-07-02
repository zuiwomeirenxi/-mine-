#include<stdio.h>
struct treenode {
	int element;
	struct treenode* left;
	struct treenode* right;
	int npl;
};
typedef struct treenode date;
date* merge(date* h1, date* h2);
date* merge1(date* h1, date* h2);
void swapchildren(date* h);
int main()
{

}
date* merge(date* h1, date* h2)
{
	if (h1 == NULL)
		return h2;
	if (h2 == NULL)
		return h1;
	if (h1->element< h2->element)
		return merge1(h1, h2);
	else
		return merge1(h2, h1);
}
static date* merge1(date* h1, date* h2)            //一定要进行画图，这是一个递归过程，将图画出来以后便十分简单明了！！！！！
{
	if (h1->left == NULL)
		h1->left = h2;
	else
	{
		h1->right = merge(h1->right, h2);
		if (h1->left->npl < h1->right->npl)
			swapchildren(h1);
		h1->npl = h1->right->npl + 1;
	}
	return h1;
}
void swapchildren(date* h)
{
	date* tmp;
	tmp = h->left;
	h->left = h->right;
	h->right = tmp;
}