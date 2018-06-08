#include <stdio.h>
#include <stdlib.h>
struct node
{	int data;
	struct node *next;
};
struct node *head;//has address of starting node of linkedlist.
int createLinkedlist()
{	
	struct node *newnode,*temp;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\n\nenter data into linkedlist");
	scanf("%d",&newnode -> data);
	newnode -> next=NULL;
	if(head==NULL)
	{
		head=newnode;
		return 1;
	}
	else
	{
		temp=head;
		while(temp -> next !=NULL )
		{
			temp=temp->next;
		}
		temp->next = newnode;
		return 1;
	}
}
void display()
{
	struct node *temp;
	if(head!=NULL)
	{
		for(temp=head;temp!=NULL;temp=temp->next)
		{
			printf("%d",temp->data);
		}
	}
	else
		printf("list is empty");
	}
int main()
{
	int ch;
	head=NULL;//to check whether it has addresss or not
	do
	{
	printf("\n 1.create linkedlist");
	printf("\n 2.display linkedlist");
	printf("\n 3.exit");
	printf("\n Enter ur option");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
			createLinkedlist();
			break;
	case 2:
			display();
			break;
	case 3:
			break;
	default:
		printf("enter correct option");
	}
	}while(ch!=3);
	return 0;
}
