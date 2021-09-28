#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *prev;
	struct node *next;
}NODE;


NODE *add_node(NODE *head,int val)
{
	NODE *current,*new,*prev = NULL;

	new = (NODE *)malloc(sizeof(NODE));
	new->data = val;
	new->next = new->prev = NULL;

	if(head==NULL)
	{
		head = new;
	}
	else
	{
	current = head;
	while(current && current->data < val)
	{
		prev = current;
		current = current->next;
	}
	if(current==head)
	{
		new->next = current;
		current->prev = new;
		head = new;

	}
	else if(current)
	{
		current->prev->next = new;
		new->prev = current->prev;
		current->prev = new;
		new->next = current;
	}
	else
	{
		prev->next = new;
		new->prev = prev;
	}

	}
	return head;
}
void display_list(NODE *head)
{
	NODE *temp = head;
	if(temp)
	{
		do
		{
		printf("%d ",temp->data);
		temp = temp->next;
		}while(temp);
	}
	printf("\n");
}

NODE *reverse_list(NODE *head)
{
	NODE *current = head,*prevv=NULL;
	while(current->next)
	{
		current = current->next;
	}
	head = current;
	prevv = current->next;
	current->next = current->prev;
	current->prev = prevv;
	while(current->next)
	{
		current = current->next;
		prevv = current->next;
		current->next = current->prev;
		current->prev = prevv;
	}
	return head;
	
}

int main()
{
	NODE *head = NULL;
	int i,val;
	for(i=0;i<10;i++)
	{
		val = rand()%101;
		head = add_node(head,val);
	}

	display_list(head);

	head = reverse_list(head);

	display_list(head);

	return 0;
}

