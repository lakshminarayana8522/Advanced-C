/**
 * This program will reverse the linked list
 * Input List :  1 --> 2 --> 3 --> 4 --> 5
 * After reverse : 5 --> 4 --> 3 --> 2 --> 1
 *
 * filename : reverse_list.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 18 Sep 2021
 */

/*! include headers */
#include<stdio.h>    /*! required for printf() scanf() */
#include<stdlib.h>   /*! required for malloc() */

/*! Linked list node structure */
typedef struct node{
	int data;
	struct node *next;
}NODE;

/**
 * This function will add a new node at last 
 * @param[in] head
 * @param[in] val
 * @param[out] head
 */
NODE *add_node(NODE *head,int val)
{
	NODE *new = (NODE *)malloc(sizeof(NODE));
	new->data = val;
	new->next = NULL;

	NODE *temp = head;

	if(temp == NULL)
	{
		head = new;
	}
	else
	{
		while(temp->next)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
	return head;
}

/**
 * This function will display list 
 * @param[in] head
 */
void display(NODE *head)
{
	NODE *temp = head;

	if(temp)
	{
		do{
			printf("%d ",temp->data);
			temp = temp->next;
		}while(temp);
		printf("\n");
	}
}

/**
 * This function will reverse the list
 * @param[in] head
 * @param[out] head
 */
NODE *reverse_list(NODE *head)
{
	NODE *current = head,*prev = NULL,*next = NULL;
	while(current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}



/*! main program starts */
int main()
{
	NODE *head = NULL;
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	for(i=0;i<n;i++)
	{
		head = add_node(head,arr[i]);
	}

	display(head);

	head = reverse_list(head);

	display(head);

	return 0;
}

