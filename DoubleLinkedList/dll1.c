/**
 * This program implement the double linked list 
 * filename : dll1.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 8 Sep 2021
 */

/*! include headers */
#include<stdio.h>      /*! required for printf() */
#include<stdlib.h>    /*! required for structures */

/*! defining node structure */
typedef struct node{
	int data;
	struct node *prev;
	struct node *next;
}NODE;

/**
 *  This function add new node at first
 *  @param[in] head
 *  @param[in] n
 *  @param[out] head
 */

NODE *add_first(NODE *head,int n)
{
	NODE *current;
	current = (NODE *)malloc(sizeof(NODE));
	current->data = 0;
	current->next = current->prev = NULL;

	if(head == NULL)       /*! for empty list */
	{
		current->data = n;
		head = current;
	}
	else                           
	{
		current->data = n;
		current->prev = NULL;
		current->next = head;
		head = current;
	}
	return head;

}

/**
 * This function add new node at last
 * @param[in] head
 * @param[in] n
 * @param[out] head
 */
NODE *add_last(NODE *head,int n)
{
	NODE *current;
	current = (NODE *)malloc(sizeof(NODE));
	current->data = 0;
	current->next = current->prev = NULL;

	if(head == NULL)                  /*! for empty list */
	{
		current->data = n;
		head = current;
	}
	else
	{
		NODE *temp = head;
		while(temp->next)      /*! traversing to last node */
		{
			temp = temp->next;
		}
		current->data = n;
		temp->next = current;            //forward linking
		current->prev = temp;            //backward linking
	}
	return head;

}

/**
 * This function deletes the node with value
 * @param[in] head
 * @param[in] n
 * @param[out] head
 */

NODE *del_node(NODE *head,int n)
{
	if(head == NULL)      /*! if List is empty */
	{
		printf("list is empty\n");
		return NULL;
	}

	NODE *current = head;
	if(current->data == n && current->prev==NULL)    /*! delete at first */
	{
		current = current->next;
		if(current)
		{
			current->prev = NULL;
			return current;
		}
	}

	while(current)               /*! delete at lst and middle */
	{
		if(current->data == n)
		{
			current->prev->next = current->next;
			free(current);
		}
		current = current->next;
	}
	
	return head;
}




/**
 * This function will display all node in list
 * @param[in] head
 */

void display(NODE *head)
{
	if(head == NULL)
	{
		printf("List is empty...\n");
	}
	else
	{
		NODE *temp = head;
		while(temp)
		{
			printf("%d ",temp->data);
			temp = temp->next;
		}
	}
}

/*! main program starts */
int main()
{
	/*! hold the reference to list */
	NODE *head = NULL;
	/*! calling display function */
	display(head);
	/*! adding node at last */
	head = add_last(head,10);
	head = add_last(head,20);
	head = add_last(head,30);
	head = add_last(head,40);
	/*! adding nodes at first */
	head = add_first(head,5);
	head = add_first(head,1);
	head = add_first(head,3);
	head = add_first(head,5);
	/*! calling display function */
	display(head);
	head = del_node(head,5);
	display(head);
	head = del_node(head,40);
	display(head);
	head = del_node(head,10);
	display(head);

	return 0;
}





