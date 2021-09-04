/**
 * This program implements the Binary search tree
 * filename : bst1.c
 * author   : Lakshmi narayana S
 * email    : narayana8522@gmail.com
 * date     : 4 Sep 2021
 */

/*! include headers */
#include<stdio.h>
#include<stdlib.h>

/*! BST node structure */
typedef struct bstnode{
	int data;
	struct bstnode *left;
	struct bstnode *right;
}*BstNodePtr;

typedef struct bst{
	BstNodePtr root;
}BST;

/**
 * inserting nodes to BST 
 * @param[in] self
 * @param[in] data
 * @param[out] self
 */
BstNodePtr insert_node(BstNodePtr self,int data)
{
	if(self == NULL)
	{
		self= malloc(sizeof(*self));
		self->data = data;
		self->left = self->right = NULL;

	}
	else if(data < self->data)
	{
		self->left = insert_node(self->left,data);
	}
	else if(data > self->data)
	{
		self->right = insert_node(self->right,data);
	}
	return self;
}
/*
 * function to call insert_node() to insert node
 * @param[in] self
 * @param[in] data
 */
void insert_bst(BST *self,int data)
{
	self->root = insert_node(self->root,data);
}
/**
 * function to display node in preorder 
 * @param[in] self
 */
void preorder(BstNodePtr self)
{
	if(self!= NULL)
	{
	printf("%d ",self->data);
	preorder(self->left);
	preorder(self->right);
	}
}
/**
 * function to display nodes in inorder 
 * @param[in] self
 */
void inorder(BstNodePtr self)
{
	if(self)
	{
		inorder(self->left);
		printf("%d ",self->data);
		inorder(self->right);
	}
}
/**
 * function to display nodes in postorder
 * @param[in] self
 */
void postorder(BstNodePtr self)
{
	if(self)
	{
		postorder(self->left);
		postorder(self->right);
		printf("%d ",self->data);
	}
}

/**
 * function to find min value node 
 * @param[in] self
 */
BstNodePtr find_min(BstNodePtr self)
{
	BstNodePtr current = self;
	while(current->left)
	{
		current= current->left;
	}
	return current;
}
/**
 * function to delete the node from tree
 * @param[in] self
 * @param[in] data
 */
BstNodePtr delete_node(BstNodePtr self,int data)
{
	if(self)
	{
		if( data == self->data)
		{
			/*! incase od node with 2 childrens */
			if(self->left != NULL && self->right != NULL)
			{
				BstNodePtr Successor = find_min(self->right);
				self->data = Successor->data;
				self->right = delete_node(self->right,self->data);
			}
			else
			{      
				/*! in case of node with single child or zero */
				BstNodePtr to_free = self;
				if(self->left)
				{
					self= self->left;
				}
				else
				{
					self = self->right;
				}
				free(to_free);
			}
		}
		else if(data <self->data)
		{
			self->left = delete_node(self->left,data);
		}
		else
		{
			self->right = delete_node(self->right,data);
		}
	}
	return self;
}
/**
 * function to call delete_node
 * @param[in] self
 * @param[in] data
 */
void delete_Bst(BST *self,int data)
{
	self->root = delete_node(self->root,data);
}
	
/*! main program starts */
int main()
{
	BST self;
	self.root = NULL;
	int arr[] = {3,1,2,8,5,4,7,9,11,12},i;
	for(i=0;i<10;i++)
	{
		insert_bst(&self, arr[i]);
	}
	delete_Bst(&self,11);
	preorder(self.root);
	printf("\n");
	inorder(self.root);
	printf("\n");
	postorder(self.root);
	printf("\n");

	return 0;
}


