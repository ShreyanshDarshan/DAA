#include<stdio.h>
#include<stdlib.h>

#define BLACK 0
#define RED 1

#define RIGHT 1
#define LEFT 0

struct node
{
    int val;
    int color;
    int isLeaf;
    int parent_dir;
    struct node *parent;
    struct node *rightchild;
    struct node *leftchild;
};
typedef struct node node;

node* newLeaf(node *p, int whichChild)
{
    node *newL = (node*) malloc (sizeof(node));
    newL->color = BLACK;
    newL->isLeaf = 1;
    newL->parent_dir = !whichChild;
    newL->parent = p;
    if (whichChild==LEFT)
    {
        p->leftchild = newL;
    }
    else
    {
        p->rightchild = newL;
    }
    return newL;
}

node* newNode (node *p, int val, int whichChild)
{
    node *newN = (node*) malloc (sizeof(node));
    newN->val=val;
    newN->color = RED;
    newN->isLeaf = 0;
    newN->parent_dir = !whichChild;
    newN->parent = p;
    newN->leftchild = newLeaf(newN, LEFT);
    newN->rightchild = newLeaf(newN, RIGHT);
    if (whichChild==LEFT)
    {
        p->leftchild = newN;
    }
    else
    {
        p->rightchild = newN;
    }
    return newN;
}

void rotate(node *z)
{
    node *p = z->parent;
    node *gp = p->parent;
    int z_old_parent_dir = z->parent_dir;
    if (p->parent_dir == RIGHT)
    {
        gp->leftchild = z;
    }
    else
    {
        gp->rightchild = z;
    }
    z->parent = gp;
    z->parent_dir = p->parent_dir;

    if (z_old_parent_dir == LEFT)
    {
        p->rightchild = z->leftchild;
        z->leftchild = p;
        p->parent_dir = RIGHT;
    }
    else
    {
        p->leftchild = z->rightchild;
        z->rightchild = p;
        p->parent_dir = LEFT;
    }
    p->parent = z;
}

void correct (node* z)
{
    node *p = z->parent;
    if (p->color == RED)
    {
        
    }
}

void insert(node** top, int val)
{
    if (!(*top))
    {
        node *newN = (node*) malloc (sizeof(node));
        newN->val=val;
        newN->color = BLACK;
        newN->isLeaf = 0;
        newN->parent = NULL;
        newN->leftchild = newLeaf(newN, LEFT);
        newN->rightchild = newLeaf(newN, RIGHT);
        *top = newN;
    }   
    else if ((*top)->isLeaf)
    {
        *top = newNode((*top)->parent, val, !(*top)->parent_dir);
    }
    else if (val>(*top)->val)
    {   
        insert(&(*top)->rightchild, val);
    }
    else
    {
        insert(&(*top)->leftchild, val);
    }    
}

void show_color(int col)
{
	if (col == RED)
	{
		printf ("RED\t");
	}
	else
	{
		printf ("BLACK\t");
	}
}

void show(struct node** head)
{
	printf ("%d\t", (*head)->val);
	show_color ((*head)->color);
	printf (":\t");
	if (((*head)->leftchild)->isLeaf == 0)
	{
		printf ("%d\t", ((*head)->leftchild)->val);
		show_color (((*head)->leftchild)->color);
	}
	else
	{
		printf ("\t\t");
	}
	if (((*head)->rightchild)->isLeaf == 0)
	{
		printf ("%d\t", ((*head)->rightchild)->val);
		show_color (((*head)->rightchild)->color);
	}
	else
	{
		printf ("\t\t");
	}
	printf ("\n");
	
	if (((*head)->leftchild)->isLeaf == 0)
	{
		show(&(*head)->leftchild);
	}
	if (((*head)->rightchild)->isLeaf == 0)
	{
		show(&(*head)->rightchild);
	}
}

int main()
{
	struct node* head;
	head=NULL;
	int choice = 1;
	while (choice == 1)
	{
		int val;
		printf ("\n\nEnter choice (1:insert, 2:exit): ");
		scanf ("%d", &choice);
		if (choice==1)
		{	
			printf ("Enter value: ");	
			scanf ("%d", &val);
			insert (&head, val);
		}
		printf ("\nTree in form of PARENT: \tLEFT CHILD \tRIGHT CHILD\n");
		//printf ("\n%d\n", head->val);
        show (&head);
	}	

    printf ("\n");
    rotate((head->rightchild)->rightchild);
    show(&head);

	return 0;
}