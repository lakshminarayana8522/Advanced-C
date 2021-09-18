#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}NODE;

NODE *add_node(NODE *head,int val)
{
	NODE *new_node = (NODE *)malloc(sizeof(NODE));
	new_node->data = val;
	new_node->next = NULL;
	if(head == NULL)
	{
		head = new_node;
	}
	else
	{
		NODE *temp = head;
		while(temp->next)
		{
			temp = temp->next;
		}

		temp->next = new_node;
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
}

NODE *reverse_list(NODE *head)
{
	NODE *current = head,*temp = NULL;
	while(current)
	{
		if((current->data%2 == 0))
		{
			NODE *start,*prev,*next,*end;
			start = current;
			next = current->next;
			while((next!=NULL) && (next->data %2 ==0))
			{
				prev = next;
				next = next->next;
			}
			temp->next = prev;
			prev->next = 

		       	

		}
		else
		{
			temp = current;
			current = current->next;
		}
	}
	return head;
}



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

	head = reverse_list(head);
	display_list(head);

	return 0;


}
