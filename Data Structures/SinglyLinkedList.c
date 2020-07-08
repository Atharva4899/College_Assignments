/*
 ============================================================================
 Name        : SinglyLinkedList.c
 Author      : Atharva Kulkarni,23329,F11
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node* add(struct node *);
void display(struct node *);
struct node* getNode();
struct node* insert(struct node*,int);
struct node* delete(struct node*,int);
void reverse(struct node*);
struct node* revert(struct node*);
struct node*deleteData(struct node*,int);

int main(void)
{
	setvbuf( stdout, NULL, _IONBF, 0 );
	struct node *head=NULL;
	int no,pos,cont,choice,delchoice,deldata;
	do
	{
		printf("How many records to be entered?\t");
		scanf("%d",&no);
		if(no<=0)
		{
			printf("\t---Invalid Input---\n");
		}
	}while(no<=0);
	for(int i=0;i<no;i++)
	{
		head=add(head);
	}
	do
	{
		printf("\n\t---MENU---\n\n");
		printf("\t1.Display\n\t2.Insert Element\n\t3.Delete Element\n\t4.Display Reverse\n\t5.Revert List\n\t6.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				display(head);
				printf("\n\n\tEnter 1 for Main Menu, any other key to exit:\t");
				scanf("%d",&cont);
				break;
			case 2:
				printf("\nEnter position to insert element(0 for beginning,-1 for end):\t");
				scanf("%d",&pos);
				head=insert(head,pos);
				display(head);
				printf("\n\n\tEnter 1 for Main Menu, any other key to exit:\t");
				scanf("%d",&cont);
				break;
			case 3:
				if(head!=NULL)
				{
					printf("\nDelete by\n\t1.Position\n\t2.Data\n");
					scanf("%d",&delchoice);
					if(delchoice==1)
					{
						printf("\nEnter position to delete element(0 for beginning,-1 for end):\t");
						scanf("%d",&pos);
						head=delete(head,pos);
						display(head);
					}
					else if(delchoice==2)
					{
						printf("\nEnter Data to delete:\t");
						scanf("%d",&deldata);
						head=deleteData(head,deldata);
						display(head);
					}
					else
					{
						printf("\t---Invalid Choice---\n");
					}
				}
				else
				{
					printf("\t---No Data!---\n");
				}
				printf("\n\n\tEnter 1 for Main Menu, any other key to exit:\t");
				scanf("%d",&cont);
				break;
			case 4:
				if(head!=NULL)
				{
					reverse(head);
				}
				else
				{
					printf("\t---No Data!---\n");
				}
				printf("\n\n\tEnter 1 for Main Menu, any other key to exit:\t");
				scanf("%d",&cont);
				break;
			case 5:
				head=revert(head);
				display(head);
				printf("\n\n\tEnter 1 for Main Menu, any other key to exit:\t");
				scanf("%d",&cont);
				break;
			case 6:
				cont=0;
				break;
			default:
				printf("\t---Invalid Input!---\n");
				cont=1;
		}
	}while(cont==1);
	return EXIT_SUCCESS;
}

struct node* getNode()
{
	struct node *temp=NULL;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter an integer:\t");
	scanf("%d",&temp->data);
	temp->next=NULL;
	return temp;
}

struct node* add(struct node *head)
{
	struct node *temp=NULL;
	temp=getNode();
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		struct node * t;
		t=head;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=temp;
	}
	return head;
}

void display(struct node *head)
{
	if(head==NULL)
	{
		printf("\n\t---No Data!---\n");
	}
	else
	{
		printf("\n:---LIST---:\n");
		struct node *t=head;
		printf("\n");
		while(t!=NULL)
		{
			printf("%d\t",t->data);
			t=t->next;
		}
	}
}

struct node* insert(struct node* head,int pos)
{
	struct node* temp,*t;
	t=head;
	int flag=0;
	if(pos==0)
	{
		temp=getNode();
		temp->next=head;
		head=temp;
	}
	else if(pos==-1)
	{
		head=add(head);
	}
	else
	{
		for(int i=0;i<pos-1;i++)
		{
			flag=0;
			t=t->next;
			if(t==NULL)
			{
				printf("\n\t---This Position does not exist!---\n");
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			temp=getNode();
			temp->next=t->next;
			t->next=temp;
		}
	}
	return head;
}

struct node* delete(struct node* head,int pos)
{
	struct node* temp,*current;
	int flag=0;
	if(pos==0)
	{
		temp=head->next;
		free(head);
		head=temp;
	}
	else if(pos==-1)
	{
		if(head->next==NULL)
		{
			free(head);
			head=NULL;
		}
		else
		{
			temp=head;
			current=temp;
			while(current->next!=NULL)
			{
				temp=current;
				current=current->next;
			}
			temp->next=NULL;
			free(current);
		}
	}
	else
	{
		current=head;
		for(int i=0;i<pos-1;i++)
		{
			flag=0;
			current=current->next;
			if(current==NULL)
			{
				printf("\n\t---This Position does not exist!---\n");
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			temp=current->next;
			current->next=temp->next;
			free(temp);
		}
	}
	return head;
}

void reverse(struct node* head)
{
	if(head!=NULL)
	{
		reverse(head->next);
		printf("%d\t",head->data);
	}
}

struct node* revert(struct node* head)
{
	struct node* result=NULL;
	struct node* temp=head;
	struct node* current=head;
	while(current!=NULL)
	{
		temp=current->next;
		current->next=result;
		result=current;
		current=temp;
	}
	head=result;
	return head;
}

struct node* deleteData(struct node* head,int data)
{
	struct node* temp,*current;
	temp=head;
	current=head;
	if(head->data==data)
	{
		head=head->next;
		free(temp);
	}
	else
	{
		while(current->data!=data&&current->next!=NULL)
		{
			temp=current;
			current=current->next;
		}
		if(current->data==data)
		{
			temp->next=current->next;
			free(current);
		}
		else
		{
			printf("\n\t---Data not found!---");
		}
	}
	return head;
}
