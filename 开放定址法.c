#include<stdio.h>
#include<stdlib.h>
enum kindofentry {legitimate,empty,delete};
#define mintablesize 10
struct hashentry {
	int element;
	enum kindofentry info;
};
typedef struct hashentry cell;
struct hashtbl {
	int tablesize;
	cell* thecells;
};
typedef struct hashtbl date;
date* inithashtable(int tablesize);
int nextprime(int tablesize);                 //求大于传入值的下一个素数；
unsigned int find(int key, date* h);
void insert(int key, date* h);
int nextprime(int tablesize);
int hash(int key, int tablesize);
int main()
{
	return 0;
}
date* inithashtable(int tablesize)
{
	date* h;
	int i;
	if (tablesize < mintablesize)
		printf("the size is too small!");
	h = (date*)malloc(sizeof(date));
	if (h == NULL)
		printf("out of space!");
	h->tablesize = nextprime(tablesize);
	h->thecells = (cell*)malloc(sizeof(struct hashentry) * h->tablesize);
	if (h->thecells == NULL)
		printf("out of space!");
	for (i = 0; i < h->tablesize; i++)
	{
		(h->thecells[i]).info = empty;      
	}
	return h;
}
unsigned int find(int key, date* h)
{
	unsigned int currentpos;
	int collisionnum;
	collisionnum = 0;
	currentpos = hash(key, h->tablesize);
	while (h->thecells[currentpos].info != empty && h->thecells[currentpos].element != key)
	{
		currentpos += 2 * ++collisionnum - 1;
		if (currentpos > h->tablesize)
			currentpos -= h->tablesize;
	}
	return currentpos;
}
void insert(int key, date* h)
{
	unsigned int pos;
	pos = find(key, h);
	if (h->thecells[pos].info != legitimate)
	{
		h->thecells[pos].element = key;
		h->thecells[pos].info = legitimate;
	}
}
int nextprime(int tablesize)
{
	while (1)
	{
		for (int i = 2; i < tablesize - 1; i++)
		{
			if (tablesize / i == 0)
				break;
			else
				return tablesize;
		}
		tablesize++;
	}
}
int hash(int key, int tablesize)
{
	return key % tablesize;
}