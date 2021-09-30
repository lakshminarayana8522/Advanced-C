


class Node {
	public:
        int val;
        Node* prev;
        Node* next;
        Node* child;
};


class Solution {
	public:
        Node* flatten(Node* head) {
        Node *temp = head,*temp1=NULL;
        
        while(temp->next)
        {
                if(temp->child)
                {
		        temp1 = temp;
		        temp= temp->child;
		        while(temp->next)
		        {
			        temp = temp->next;
			}
														                  
                        temp->next = temp1->next;
                        temp1->next->prev = temp;
			temp1->next = temp1->child;
                        temp1->child = NULL;
                        temp1->next->prev = temp1;
                        temp = temp1->next;
																								                  }
                 else
                 {
 	                temp = temp->next;
	         }
	}
	return head;
}
