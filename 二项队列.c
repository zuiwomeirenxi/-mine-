#include<stdio.h>
#include<stdlib.h>
#define maxtrees 10
#define capacity maxtrees
#define infinity 1
struct binnode {
	int element;
	struct binnode* leftchild;
	struct binnode* nextsibling;
};
struct collection {
	int currentsize;
	struct binnode* thetrees[maxtrees];
};
typedef struct binnode bintree;
typedef struct collection binqueue;
bintree* combinetrees(bintree* t1, bintree* t2);
binqueue* merge(binqueue* h1, binqueue* h2);
binqueue* initialize();
int isempty(binqueue* q);
int deletemin(binqueue* h);
int main()
{
	return 0;
}
bintree* combinetrees(bintree* t1, bintree* t2)
{
	if (t1->element > t2->element)
		return combinetrees(t2, t1);
	t2->nextsibling = t1->leftchild;
	t1->leftchild = t2;
	return t1;
}
binqueue* merge(binqueue* h1, binqueue* h2)
{
	bintree* t1, *t2, *carry = NULL;
	int i, j;
	if (h1->currentsize + h2->currentsize > capacity)
		printf("merge would exceed capacity!");
	h1->currentsize += h2->currentsize;
	for (i = 0, j = 1; j <= h1->currentsize; i++, j *= 2)
	{
		t1 = h1->thetrees[i]; t2 = h2->thetrees[i];
		switch (!!t1+2*!!t2+4*!!carry)
		{
		case 0:
		case 1:break;
		case 2:h1->thetrees[i] = t2;
			h2->thetrees[i] = NULL;
			break;
		case 4:h1->thetrees[i] = carry;
			carry = NULL;
			break;
		case 3:carry = combinetrees(t1, t2);
			h1->thetrees[i] = h2->thetrees[i] = NULL;
			break;
		case 5:carry = combinetrees(t1, carry);
			h1->thetrees[i] = NULL;
			break;
		case 6:carry = combinetrees(t2, carry);
			h2->thetrees[i] = NULL;
			break;
		case 7:h1->thetrees[i] = carry;
			carry = combinetrees(t1, t2);
			h2->thetrees[i] = NULL;
			break;
		default:
			break;
		}
	}
	return h1;
}
int deletemin(binqueue* h)
{
	int i, j;
	int mintree;
	binqueue* deletedqueue;
	bintree* deletedtree, *oldroot;
	int minitem;
	if (isempty(h))
	{
		printf("empty binomial queue");
		return -infinity;
	}
	minitem = infinity;
	for (i = 0; i < maxtrees; i++)
	{
		if (h->thetrees[i] && h->thetrees[i]->element < minitem)
		{
			minitem = h->thetrees[i]->element;
			mintree = i;
		}
	}
	deletedtree = h->thetrees[mintree];
	oldroot = deletedtree;
	deletedtree = deletedtree->leftchild;
	free(oldroot);
	deletedqueue = initialize();
	deletedqueue->currentsize = (1 << mintree) - 1;
	for (j = mintree * 1; j >= 0; j--)
	{
		deletedqueue->thetrees[j] = deletedtree;
		deletedtree = deletedtree->nextsibling;
		deletedqueue->thetrees[j]->nextsibling = NULL;
	}
	h->thetrees[mintree] = NULL;
	h->currentsize -= deletedqueue->currentsize + 1;
	merge(h, deletedqueue);
	return minitem;
}
binqueue* initialize()
{
	binqueue* q1;
	q1 = (binqueue*)malloc(sizeof(binqueue));
	if (q1 == NULL)
		printf("out of space");
	q1->currentsize = 0;
	return q1;
}
int isempty(binqueue* q)
{
	return q->currentsize == 0;
}