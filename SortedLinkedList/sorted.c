/**
 * This program implements the sorted single linked list
 *
 * filename : sorted.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 21 Sep 2021
 */


/*! include headers */
#include<stdio.h>    		/*! required for printf() */
#include<stdlib.h>              /*! required for malloc() */

/*! node structure */
typedef struct node{
	int data;
	struct node *next;
}NODE;

/*! adding a node to list */

NODE *add_node(NODE *head,int val)
{
	NODE *new = (NODE *)malloc(sizeof(NODE));
	new->data = val;
	new->next = NULL;

	NODE *current = head;

	if(current == NULL || current->data > val)     /*! insertion at front */
	{
		new->next = head;
		head = new;

	}
	else
	{

		while((current->next != NULL) && (current->next->data < val))  /*! inserting at middle and end based on val */
		{
	
			current = current->next;
		}
		new->next = current->next;
		
		current->next = new;
	}


	return head;
}


/*! display the list */

void display(NODE *head)
{
	NODE *current = head;
	if(current)
	{
		do{
			printf("%d ",current->data);
			current = current->next;
		}while(current);

		printf("\n");
	}
}

/*! main function starts */
int main()
{
	NODE *head = NULL;
	int arr[5] = {9,3,10,40,3};
	int i;
	for(i=0;i<5;i++)
	{
		head = add_node(head,arr[i]);
	}
	head = add_node(head,2);

	display(head);

	return 0;
}

